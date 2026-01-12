// 아날로그 핀 설정
const int emgPin1 = A0;  // 첫 번째 EMG 센서가 연결된 아날로그 핀
//const int emgPin2 = A1;  // 두 번째 EMG 센서가 연결된 아날로그 핀

int emgValue1 = 0;        // 첫 번째 EMG 센서에서 읽은 값
//int emgValue2 = 0;        // 두 번째 EMG 센서에서 읽은 값

void setup() {
  // 시리얼 통신 초기화
  Serial.begin(115200);  // 시리얼 모니터와 통신을 위해 설정
}

void loop() {
  // 첫 번째 EMG 센서에서 아날로그 값 읽기
  emgValue1 = analogRead(emgPin1);

  // 두 번째 EMG 센서에서 아날로그 값 읽기
//  emgValue2 = analogRead(emgPin2);


  // 두 값을 시리얼 모니터에 출력
  //Serial.print("EMG Sensor 1 Value: ");
  Serial.println(emgValue1);
  //Serial.print("\t");  // 두 값 사이에 탭으로 간격 추가

  //Serial.print("EMG Sensor 2 Value: ");
  //Serial.println(emgValue2);

  // 약간의 지연을 주어 시리얼 통신 안정화
//  delay(100);  // 100ms 지연
}
