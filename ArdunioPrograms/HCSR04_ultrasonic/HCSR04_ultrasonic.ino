

# define trigPin  4
#define echoPin  3
float duration, distance;
void setup () {
  
  Serial.begin(9600);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
}
void loop () {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
//Determine distance from duration
//Use 343 metres per second as speed of sound
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)*0.0343;
  //Send results to Serial Monitor
  Serial.print("Distance =");
  if(distance>=400|| distance<=2)
  {
    Serial.println("Out of range");
  }
  else
  {
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  delay(500);
  
  
  
}
