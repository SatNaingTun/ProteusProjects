#include <SimpleDHT.h>
int pinDHT11=A0;
SimpleDHT11  dht11(pinDHT11);

void setup() {
Serial.begin(9600);
delay(500);
Serial.print("DHT11 Temperature and Humidity \n \n");

delay(1000);

}

void loop() {
  byte temperature =0;
  byte humidity= 0;
  dht11.read(pinDHT11, &temperature, &humidity, NULL);
  Serial.println();
  Serial.print("Temperature & Humidity:");
  Serial.print((int)temperature);
  Serial.print(" *C &");
  Serial.print((int)humidity);
  Serial.print(" %H \n\n");
  delay(2000);
  

}
