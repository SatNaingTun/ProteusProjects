int sensorValue;
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
}

void loop() {
 sensorValue=analogRead(A0)/2;
 Serial.println(sensorValue);
 double rpm=sensorValue*2.4;
 analogWrite(9,rpm);

}
