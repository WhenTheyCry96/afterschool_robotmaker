int SENSOR1 = 2; // SENSOR1라는 변수를 만들고 2를 저장한다. 디지털 핀 2번핀을 이렇게 직관적으로
int motor1A = 5; // motor1A라는 변수를 만들고 5를 저장한다. PWM 핀 5번핀을 이렇게 직관적으로
int motor1B = 6;
int motor2A = 9;
int motor2B = 10;

void setup() {                      

pinMode(SENSOR1, INPUT); // SENSOR1(디지털 2번)핀을 입력모드로 
pinMode(motor1A, OUTPUT); // 5번핀을 출력모드로 설정합니다.
pinMode(motor1B, OUTPUT); // 6번핀을 출력모드로 설정합니다.
pinMode(motor2A, OUTPUT); // 10번핀을 출력모드로 설정합니다.
pinMode(motor2B, OUTPUT);// 11번핀을 출력모드로 설정합니다.
Serial.begin(9600);
}

void loop() {         
bool s1 = digitalRead(SENSOR1);  
Serial.println(s1);
if (s1 == HIGH) {   
// 만약 2번핀에 HIGH가 입력된다면
analogWrite(motor1A, 255); // motor1을 A방향으로 풀파워로 돌린다
analogWrite(motor2A, 255); // motor2을 A방향으로 풀파워로 돌린다
delay(50);
} 

else {     
// 그게 아니라면(2번핀에 HIGH가 입력되지 않는다면)== LOW일 경우
analogWrite(motor1B, 255); // motor1을 B방향으로 풀파워로 돌린다
analogWrite(motor2B, 255); // motor2을 B방향으로 풀파워로 돌린다
delay(50);
}
}
