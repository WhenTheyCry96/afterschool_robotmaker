#define motorAgo 5
#define motorAback 6
#define motorBgo 9
#define motorBback 10
#define sensorA 2
#define sensorB 3
#define sensorC 4

/*
   아두이노의 PWM신호는 0 ~ 255의 해상도를 가집니다.
   예를들어 5v의 최대전압을 모터에 줄 수 있을 경우 최대속도가 된다면

   0(min)    :  0v, 모터 정지
   ...
   128         :  2.5v, 모터 중간속도
   ...
   255(max)  :  5v, 모터 최대속도
*/

void go() {
  // FIXME6yh7
  // 255를 조정해서 직진하도록 수정
  // delay(50)의 숫자를 조정해서 동작 시간 조정
  analogWrite(motorAgo, 255);
  analogWrite(motorBgo, 255);
  delay(50);
}

void left() {
  // FIXME
  // 255를 조정해서 직진하도록 수정
  // 왼쪽으로 차가 안 돌 경우, motorAgo나 motorBback을 바꿔봄
  // delay(50)의 숫자를 조정해서 동작 시간 조정
  analogWrite(motorAgo, 200); 
  analogWrite(motorBback, 50);
  delay(50);
}

void right() {
  // FIXME
  // 255를 조정해서 직진하도록 수정
  // 오른쪽으로 차가 안 돌 경우, motorAgo나 motorBback을 바꿔봄
  // delay(50)의 숫자를 조정해서 동작 시간 조정
  analogWrite(motorBgo, 200);
  analogWrite(motorAback, 50);
  delay(50);
}

void back() {
  // FIXME
  // 255를 조정해서 직진하도록 수정
  // delay(50)의 숫자를 조정해서 동작 시간 조정
  analogWrite(motorAgo, 150);
  analogWrite(motorBgo, 150);
  delay(50);    
}

void setup() {

  pinMode(motorAgo, OUTPUT); // 5번핀을 출력모드로 설정합니다.
  pinMode(motorAback, OUTPUT); // 6번핀을 출력모드로 설정합니다.
  pinMode(motorBgo, OUTPUT); // 10번핀을 출력모드로 설정합니다.
  pinMode(motorBback, OUTPUT); // 11번핀을 출력모드로 설정합니다.
  
  pinMode(sensorA, INPUT); // 2번핀을 입력모드로 설정합니다.
  pinMode(sensorB, INPUT); // 3번핀을 입력모드로 설정합니다.
  pinMode(sensorC, INPUT); // 4번핀을 입력모드로 설정합니다.

  Serial.begin(9600); // 시리얼 모니터로 무슨 센서값이 들어오는지 확인하기 위하여
}

void loop() {
  // 조도 센서는 어두울 때 = 0, 밝을 때 = 1
  int sA = digitalRead(sensorA); // sensorA(2번핀)의 값을 읽습니다.
  int sB = digitalRead(sensorB); // sensorB(3번핀)의 값을 읽습니다.
  int sC = digitalRead(sensorC); // sensorC(4번핀)의 값을 읽습니다.

  Serial.print("센서A : ");
  Serial.print(sA);
  Serial.print(" 센서B : ");
  Serial.print(sB);
  Serial.print(" 센서C : ");
  Serial.println(sC);
  
  // 아래의 IF ELSE 문은 본인의 로봇 사정에 맞춰서 수정할 수 있음
  if (sA == 1 && sB == 0 && sC == 1) { // 검은선이 중앙에 있을 때
    go();    
  }
  else if (sA == 1 && sB == 1 && sC == 0) { // 검은선이 오른쪽에 있을 때
    right();
  }
  else if (sA == 0 && sB == 1 && sC == 1) { // 검은선이 왼쪽에 있을 때
    left();
  }
  else { // 위의 3가지 경우도 아닌경우
    back();
  }
}

  
