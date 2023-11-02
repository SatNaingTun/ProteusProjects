#include<SPI.h>
int buttonValue=0;
int M=0;
int MasterReceive=0;
int MasterSend=0;

void setup() 
{
 Serial.begin(115200);
 pinMode(2,INPUT);
 pinMode(3,OUTPUT);
 
 SPI.begin();
 SPI.setClockDivider(SPI_CLOCK_DIV8);
 digitalWrite(SS,HIGH);

}

void loop() {
 buttonValue=digitalRead(2);
if(buttonValue==HIGH)
{
M=1;
}
else
{
  M=0;
}
digitalWrite(SS,LOW);
MasterSend=M;

MasterReceive=SPI.transfer(MasterSend);
if(MasterReceive==1)
{
  digitalWrite(3,HIGH);
  Serial.println("Master LED is ON Now");
}
else
{
  digitalWrite(3,LOW);
  Serial.println("Master LED is OFF Now");
}
delay(1000);

}
