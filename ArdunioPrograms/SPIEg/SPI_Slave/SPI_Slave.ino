#include<SPI.h>
int SlaveReceived=0;
boolean received=false;
int buttonValue=0;
int M=0;
int SlaveSend=0;
void setup() {
 
Serial.begin(115200);
 pinMode(2,INPUT);
 pinMode(3,OUTPUT);
 pinMode(MISO,OUTPUT);
 SPCR |= _BV(SPE);
 received=false;
 
 SPI.attachInterrupt();
 
 SPI.begin();
 SPI.setClockDivider(SPI_CLOCK_DIV8);
 digitalWrite(SS,HIGH);
}

ISR(SI_STC_vect)
{
SlaveReceived=SPDR;
received=true;
}
void loop() {
if(received)
{
   if(SlaveReceived==1) //Master button state
   {
    digitalWrite(3,HIGH);
    Serial.println("Slave LED is On");
   }
   else
   {
     digitalWrite(3,HIGH);
    Serial.println("Slave LED is Off");
   }
   buttonValue=digitalRead(2);// slave button state
   if(buttonValue==HIGH)
   {
    M=1;
    
   }
   else
   {
    M=0;
   }
   SlaveSend=M;
   SPDR=SlaveSend;
   delay(1000);
}


}
