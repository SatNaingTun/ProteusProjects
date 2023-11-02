#define ultrasonic 8
double duration,distance;
void setup() {
 
Serial.begin(9600);

}

void loop() {
  pinMode(ultrasonic,OUTPUT);
  digitalWrite(ultrasonic,LOW); //triggering
  delayMicroseconds(3);
  digitalWrite(ultrasonic,HIGH);
  delayMicroseconds(3);
 duration= pulseIn(ultrasonic,HIGH);
 distance=duration/58.2; //speed of sound
 Serial.println(distance);
  

}
