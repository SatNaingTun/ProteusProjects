int buzzer =PD4;
int trigPin=PD2;
int echoPin= PD3;
long TempDistance =0;
int counter= 0;

void setup() {
  
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(buzzer,OUTPUT);

}

void loop() {
  
long duration, Distance;
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
Distance=(duration/2)/74;
if(counter<20)
{
  if(Distance>200)
  {
    noTone(buzzer);
  }
  if((Distance>10)&&(Distance<=50))
  {
    tone(buzzer,500);
  }
}
}
