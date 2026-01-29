
#include <Wire.h>

#define mpu_add 0x68  //mpu6050 address



class kalman {
  public :
    double getkalman(double acc, double gyro, double dt) {
      //kalman filter 이용해 각도 계산 및 update
      
      //현재 angle에 gyoscope 값와 bias를 이용해 예측한 각도를 업데이트
      angle += dt * (gyro - bias) ;
      
      //예측한 오차 공분산 행렬을 업데이트
      P[0][0] += dt * (dt * P[1][1] - P[0][1] - P[1][0] + Q_angle) ;
      P[0][1] -= dt * P[1][1] ;
      P[1][0] -= dt * P[1][1] ;
      P[1][1] += Q_gyro * dt ;
      
      //kalman gain 계산
      double S = P[0][0] + R_measure ;
      K[0] = P[0][0] / S ;
      K[1] = P[1][0] / S ;

      //가속도를 이용한 측정값과 예측한 각도 사이의 오차를 이용하여 각도 업데이트
      double y = acc - angle ;
      angle += K[0] * y ;
      bias += K[1] * y ;

      //오차 공분산 행렬 업데이트 

      double P_temp[2] = {P[0][0], P[0][1]} ;
      P[0][0] -= K[0] * P_temp[0] ;
      P[0][1] -= K[0] * P_temp[1] ;
      P[1][0] -= K[1] * P_temp[0] ;
      P[1][1] -= K[1] * P_temp[1] ;
      return angle ;
    } ;

    void init(double angle, double gyro, double measure) {
      //kalman filter의 초기화
      Q_angle = angle ;
      Q_gyro = gyro ;
      R_measure = measure ;
      
      //초기화된 상태로 설정
      angle = 0 ;
      bias = 0 ;
      //초기 오차 공분산 행렬 설정
      P[0][0] = 0 ;
      P[0][1] = 0 ;
      P[1][0] = 0 ;
      P[1][1] = 0 ;
    } ;

    double getvar(int num) {
      //kalman filter 변수 중 특정 변수 값을 반환
      switch (num) {
        case 0 :
          return Q_angle ;
          break ;
        case 1 :
          return Q_gyro ;
          break ;
        case 2 :
          return R_measure ;
          break ;
      }
    } ;

  private :
    double Q_angle, Q_gyro, R_measure ;//kalman filter의 tuning parameter
    double angle, bias ;//현재 각도 및 gyroscope bias
    double P[2][2], K[2] ;//오차 공분산 행렬, kalman gain
} ;



kalman kal ;//kalman 객체 생성
long ac_x, ac_y, ac_z, gy_x, gy_y, gy_z ;//가속도 및 gyroscope data
double deg, dgy_y ;//가속도 이용해 계산된 각도와 gyroscope의 y축 값
double dt ; //시간 간격을 저장하는 변수
uint32_t pasttime ;//이전 시간을 저장하는 변수 - 시간 간격 계산하기 위해 사용

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600) ; //serial 통신 초기화
  Wire.begin() ; //IC2 통신 시작
  Wire.beginTransmission(mpu_add); //MPU와 IC2 통신 시작
  Wire.write(0x6B) ;//MPU의 레지스터 주소에 데이터 작성
  Wire.write(0) ; //전원 관련 설정 해제, 즉 MPU6050 전원 켜기
  Wire.endTransmission(true) ; //IC2 통신 종료 ->true: 전송이 완료될 때까지 기다릴지 여부
  kal.init(0.001, 0.003, 0.03) ;  //init kalman filter 

  //parameter 출력
  Serial.println() ;
  Serial.print("parameter") ;
  Serial.print("\t") ;
  Serial.print(kal.getvar(0), 4) ;
  Serial.print("\t") ;
  Serial.print(kal.getvar(1), 4) ;
  Serial.print("\t") ;
  Serial.println(kal.getvar(2), 4) ;
}



void loop() {
  // put your main code here, to run repeatedly:
  
  //Acceleration Data: IC2 통신 사용해 MPU6050으로 데이터 요청 후 응답 받음
  Wire.beginTransmission(mpu_add) ; 
  Wire.write(0x3B) ;
  Wire.endTransmission(false) ;
  Wire.requestFrom(mpu_add, 6, true) ;

  //acceleration sensor의 X,Y,Z 축 데이터 읽기
  ac_x = Wire.read() << 8 | Wire.read() ;
  ac_y = Wire.read() << 8 | Wire.read() ;
  ac_z = Wire.read() << 8 | Wire.read() ;

  //Gyroscope Data: IC2 통신 사용해 MPU6050으로 데이터 요청 후 응답 받음
  Wire.beginTransmission(mpu_add) ; 
  Wire.write(0x43) ;
  Wire.endTransmission(false) ;
  Wire.requestFrom(mpu_add, 6, true) ;
  gy_x = Wire.read() << 8 | Wire.read() ;
  gy_y = Wire.read() << 8 | Wire.read() ;
  gy_z = Wire.read() << 8 | Wire.read() ;

  deg = atan2(ac_x, ac_z) * 180 / PI ;  //가속도 데이터를 각도로 변환
  dgy_y = gy_y / 131. ;  //gyroscope 의 output을 각속도로 변환

  dt = (double)(micros() - pasttime) / 1000000; //시간 간격 계산
  pasttime = micros();  //이해가능한 data로 변환

  double val = kal.getkalman(deg, dgy_y, dt) ;  //kalman filter로 각도 추정
  Serial.print("kalman degree") ;
  Serial.print("\t") ;
  Serial.println(val) ;
}
