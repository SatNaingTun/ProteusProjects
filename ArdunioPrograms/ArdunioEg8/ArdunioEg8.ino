#define pirPin 2
#define buzzer 12

    int calibrationTime = 30;
    long unsigned int lowIn;
    long unsigned int pause = 5000;
    boolean lockLow = true;
    boolean takeLowTime;
    int PIRValue = 0;
     

    void setup()
    {
    Serial.begin(9600);
    pinMode(pirPin, INPUT);
    pinMode(buzzer,OUTPUT);
    }

    void loop()
    {
    PIRSensor();
    }

   void PIRSensor()
{
     if(digitalRead(pirPin) == HIGH)
     {       
         if(lockLow)
         {    
             PIRValue = 1;
             lockLow = false;
             Serial.println("Motion detected.");
             tone(buzzer,563);
             
             delay(50);
         }         
         takeLowTime = true;
       }

       if(digitalRead(pirPin) == LOW)
       {       
           
           if(takeLowTime){lowIn = millis();takeLowTime = false;}
           if(!lockLow && millis() - lowIn > pause)
           {
               PIRValue = 0; 
               lockLow = true;                        
               Serial.println("Motion ended.");
               noTone(buzzer);
               delay(50);
           }
       }
}
