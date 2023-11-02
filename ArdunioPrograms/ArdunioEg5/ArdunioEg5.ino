int led;
void setup() {

 for(led=2;led<=6;led++)
 {
  pinMode(led,OUTPUT);
 }
 led=2;
 

}

void loop() {
  
for(led=2;led<=6;led++)
 {
  digitalWrite(led,HIGH);
  delay(100);
 }

   
for(led=6;led>=2;led--)
 {
  digitalWrite(led,LOW);
  delay(100);
 }

}
