int Left_motor_back=8;     //좌측모터후진(IN1)
int Left_motor_go=9;     //좌측모터전진(IN2)

int Right_motor_go=10;    // 우측모터전진(IN3)
int Right_motor_back=11;    // 우측모터후진(IN4)

const int SensorRight = 3;     //우측센서
const int SensorLeft = 4;       //좌측센서

int SL;    //좌측센서 상태
int SR;    //우측센서 상태

void setup()
{
  //모터구동을을 위한 초기화
  pinMode(Left_motor_go,OUTPUT); // PIN 8 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 10 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 11 (PWM)
  pinMode(SensorRight, INPUT); //우측센서포트를 입력으로 정의
  pinMode(SensorLeft, INPUT); //좌측센서포트를 입력으로 정의
}
void run()     // 전진
{
  digitalWrite(Right_motor_go,HIGH);  // 우측모터전진
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,50);//PWM값 0~255 조정,모터의 회전속도 조절.
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  // 좌측모터전진
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,50);//PWM값 0~255 조정,모터의 회전속도 조절.
  analogWrite(Left_motor_back,0);
  //delay(time * 100);   //딜레이  
}

void brake()         //제동, 정지
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  //delay(time * 100);//딜레이  
}

void left()         //좌회전(좌측정지，우측직진)
{
  digitalWrite(Right_motor_go,HIGH);  // 우측모터전진
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,50); 
  analogWrite(Right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
  digitalWrite(Left_motor_go,LOW);   //좌측모터정지
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
  //delay(time * 100);  //딜레이  
}

void spin_left(int time)         //좌측스핀(좌측후진，우측직진)
{
  digitalWrite(Right_motor_go,HIGH);  // 우측모터전진
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
  digitalWrite(Left_motor_go,LOW);   //좌측모터후진
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.
  delay(time * 100);  //딜레이  
}

void right()        //우회전(우측정지, 좌측직진)
{
  digitalWrite(Right_motor_go,LOW);   //우측모터정지
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
  digitalWrite(Left_motor_go,HIGH);//좌측모터전진
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,50); 
  analogWrite(Left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
  //delay(time * 100);  //딜레이  
}

void spin_right(int time)        //우측스핀(우측후진, 좌측전진)
{
  digitalWrite(Right_motor_go,LOW);   //우측모터후진
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,200);//PWM값 0~255 조정,모터의 회전속도 조절.
  digitalWrite(Left_motor_go,HIGH);//좌측모터전진
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);//PWM값 0~255 조정,모터의 회전속도 조절.
  delay(time * 100);  //딜레이  
}

void back(int time)          //후진
{
  digitalWrite(Right_motor_go,LOW);  //우측모터후진
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,150);//PWM값 0~255 조정,모터의 회전속도 조절.
  digitalWrite(Left_motor_go,LOW);  //좌측모터후진
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,150);//PWM값 0~255 조정,모터의 회전속도 조절.
  delay(time * 100);     //딜레이  
}

void loop()
{
  while(1)
  {
  //신호가 있으면 LOW  신호가 없으면 HIGH
  SR = digitalRead(SensorRight);
  SL = digitalRead(SensorLeft);
  if (SL == LOW&&SR==LOW)
    run();   //전진
  else if (SL == HIGH & SR == LOW)// 좌회전 
    left();
  else if (SR == HIGH & SL == LOW) // 우회전  
    right();
  else // 정지
  brake();
  }
}
