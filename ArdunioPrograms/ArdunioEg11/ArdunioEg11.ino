#include<IRremote.h>
int irPin=11;
IRrecv irrecv(irPin);
decode_results results;

void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);
irrecv.enableIRIn();

}

void loop() {
  if(irrecv.decode(&results))
  {
    Serial.println(results.value);
    if(results.value)
    {
      digitalWrite(led,HIGH);
      delay(120);
      digitalWrite(led,LOW);
    }
    irrecv.resume();
  }


}
