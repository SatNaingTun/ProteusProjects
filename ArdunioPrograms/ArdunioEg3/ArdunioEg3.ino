int ledPin=13;
int brightness=0;
int fader=5;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
 analogWrite(ledPin,brightness);
 brightness=brightness+fader;
 if(brightness==0||brightness==255)
 {
  fader=-fader;
 }
 delay(200);
 

 
}
