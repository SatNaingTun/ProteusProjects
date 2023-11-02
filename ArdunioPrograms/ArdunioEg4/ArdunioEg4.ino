int red=11;
int green=10;
int blue=9;
void setup() {

pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);

}

void loop() {
  
analogWrite(red,255);
analogWrite(green,0);
analogWrite(blue,0);
delay(400);
  
analogWrite(red,0);
analogWrite(green,255);
analogWrite(blue,0);
delay(400);
  
analogWrite(red,0);
analogWrite(green,0);
analogWrite(blue,255);
delay(400);



}
