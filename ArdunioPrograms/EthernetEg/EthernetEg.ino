#include <SPI.h>
#include <Ethernet.h>
int greenled = 4;
int redled = 5;
int whiteled = 6;
int yellowled = 7;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };   //mac address
byte ip[] = { 192, 168, 0, 13 };                      // Lan IP
byte gateway[] = { 192, 168, 0, 1 };                   // gateway IP
byte subnet[] = { 255, 255, 255, 0 };                  
EthernetServer server(80);                             
String buffer;

void setup() {
 Serial.begin(9600);
 pinMode(greenled, OUTPUT);
 pinMode(redled, OUTPUT);
 pinMode(whiteled, OUTPUT);
 pinMode(yellowled, OUTPUT);
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  EthernetClient ethernet_shield = server.available();
  if (ethernet_shield) {
    while (ethernet_shield.connected()) {   
      if (ethernet_shield.available()) {
        char c = ethernet_shield.read();
        if (buffer.length() < 100) {
          buffer += c;
           }

           if (c == '\n') {          
           Serial.println(buffer); 
           ethernet_shield.println("HTTP/1.1 200 OK"); 
           ethernet_shield.println("Content-Type: text/html");
           ethernet_shield.println();     
           ethernet_shield.println("");
           ethernet_shield.println("");
           ethernet_shield.println("Leds Controlled by webpage");
           ethernet_shield.println("");
           ethernet_shield.println(""); 
           ethernet_shield.println("Controlling Leds through Webpage");
ethernet_shield.println("");
ethernet_shield.println("Green LED");
ethernet_shield.println(" ON");
ethernet_shield.println(" OFF");
ethernet_shield.println("");
ethernet_shield.println("Red LED");
ethernet_shield.println(" ON");
ethernet_shield.println(" OFF");
ethernet_shield.println("");
ethernet_shield.println("White LED");
ethernet_shield.println(" ON");
ethernet_shield.println(" OFF");
ethernet_shield.println("");
ethernet_shield.println("Yellow LED");
ethernet_shield.println(" ON");
ethernet_shield.println("OFF");
ethernet_shield.println("");
ethernet_shield.println("");
           ethernet_shield.println("");
     
           delay(1);
           ethernet_shield.stop();
           
           if (buffer.indexOf("?greenledon") >0){
               digitalWrite(greenled, HIGH);
           }
            if (buffer.indexOf("?greenledoff") >0){
               digitalWrite(greenled, LOW);
           }
            if (buffer.indexOf("?redledon") >0){
               digitalWrite(redled, HIGH);
           }
            if (buffer.indexOf("?redledoff") >0){
               digitalWrite(redled, LOW);
           }
            if (buffer.indexOf("?whiteledon") >0){
               digitalWrite(whiteled, HIGH);
           }
            if (buffer.indexOf("?whiteledoff") >0){
               digitalWrite(whiteled, LOW);
           }
            if (buffer.indexOf("?yellowledon") >0){
               digitalWrite(yellowled, HIGH);
           }
            if (buffer.indexOf("?yellowledoff") >0){
               digitalWrite(yellowled, LOW);
           }
            //clearing string for next read
            buffer="";  
           
         }
       }
    }
  }
}
