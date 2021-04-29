#include<LiquidCrystal.h>
#define trigPin 7
#define echoPin 6
#define led1 8
#define led2 13
#define led3 10
#define buzzer 9
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  if(distance<=60&&distance>40)
  {
    digitalWrite(led3,HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    Serial.print("distance=");
    Serial.println(distance);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("distance=");
    lcd.setCursor(2,1);
    lcd.print(distance);
    analogWrite(buzzer,10);
    delay(1000);
  }
  else if(distance<=40&&distance>20)
  {
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led1,LOW);
    Serial.print("distance=");
    Serial.println(distance);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("distance=");
    lcd.setCursor(2,1);
    lcd.print(distance);
    analogWrite(buzzer,100);
    delay(1000);
  }
  else if(distance<=20&&distance>0)
  { 
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    Serial.print("distance=");
    Serial.println(distance);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("distance=");
    lcd.setCursor(2,1);
    lcd.print(distance);
    analogWrite(buzzer,300);
    delay(1000);

  }
  else if(distance>60||distance<0)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    Serial.println("outofrange");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("OUTOFRANGE");
    analogWrite(buzzer,0);
    delay(1000);
  }

}
