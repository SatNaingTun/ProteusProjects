int ledPin=13;
void setup() {
 Serial.begin(9600);
 pinMode(ledPin,OUTPUT);

}

void loop() {
 
char value;
if(Serial.available()>0)
{
 value= Serial.read();
 if(value=='1')
 {
  digitalWrite(ledPin,HIGH);
 }
 if(value=='0')
 {
  digitalWrite(ledPin,LOW);
 }
 
 }
 
}
