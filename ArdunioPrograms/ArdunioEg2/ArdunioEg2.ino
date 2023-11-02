void setup() {
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 int value=analogRead(A0);
 float voltage=(value/1023.0)*5.0;
 Serial.println(voltage);
 
 
}
