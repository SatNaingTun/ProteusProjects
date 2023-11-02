#include<Servo.h>
Servo servo;
int servoPin=9;
int position=0;
void setup() {
 
servo.attach(servoPin);

}

void loop() {
for(position=0;position<180;position++)
{
  servo.write(position);
  delay(150);
}

for(position=1800;position>0;position--)
{
  servo.write(position);
   delay(150);
}


}
