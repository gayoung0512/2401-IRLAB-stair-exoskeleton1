/* 기울기 센서 GY-521(MPU6050) 기초 실습 #1 (RAW 데이터 얻기)                            */ 
/* 아래 코드관련 실습에 대한 설명과 회로도 및 자료는 https://rasino.tistory.com/ 에 있습니다 */
#include<Wire.h>
#include <SoftwareSerial.h>                // Serial 통신을 하기 위해 선언
SoftwareSerial BTSerial(8, 7);             // HC-06모듈 7=TXD , 8=RXD 핀 선언

const int MPU_ADDR = 0x68;    // I2C통신을 위한 MPU6050의 주소

int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;   // 가속도(Acceleration) 와 각속도(Gyro)
void getRawData();  // 센서값 얻는 서브함수의 프로토타입 선언 

void setup() {
  initSensor();
  Serial.begin(115200);
  BTSerial.begin(115200);//HC-06 모듈 통신 선언
  //delay(200);
}

void loop() {
  getRawData();          // 센서값 얻어오는 함수 호출

  // 데이터를 Bluetooth 통신을 통해 전송
  BTSerial.print("AcX:");
  BTSerial.print(AcX);
  BTSerial.print("   AcY:");
  BTSerial.print(AcY);
  BTSerial.print("   AcZ:");
  BTSerial.print(AcZ);
  BTSerial.print("   GyX:");
  BTSerial.print(GyX);
  BTSerial.print("   GyY:");
  BTSerial.print(GyY);
  BTSerial.print("   GyZ:");
  BTSerial.print(GyZ);
  BTSerial.println();//data을 bluetooth로 전송
  
  Serial.print("AcX:");
  Serial.print(AcX);
  Serial.print("   AcY:");
  Serial.print(AcY);
  Serial.print("   AcZ:");
  Serial.print(AcZ);
  Serial.print("   GyX:");
  Serial.print(GyX);
  Serial.print("   GyY:");
  Serial.print(GyY);
  Serial.print("   GyZ:");
  Serial.print(GyZ);
  Serial.println();
  //delay(300);  
}
void initSensor() {
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR);   // I2C 통신용 어드레스(주소)
  Wire.write(0x6B);    // MPU6050과 통신을 시작하기 위해서는 0x6B번지에    
  Wire.write(0);       // MPU6050을 동작 대기 모드로 변경
  Wire.endTransmission(true);
}
void getRawData() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B);   // AcX 레지스터 위치(주소)를 지칭합니다
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 14, true);  // AcX 주소 이후의 14byte의 데이터를 요청

  AcX = Wire.read() << 8 | Wire.read(); //두 개의 나뉘어진 바이트를 하나로 이어 붙여서 각 변수에 저장
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  Tmp = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();
}
