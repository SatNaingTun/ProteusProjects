int buzzer=9;
void setup() {
 
pinMode(buzzer,OUTPUT);

}

void loop() {
 //tone(pin no,freq,duration)
tone(buzzer,100,600);

}
