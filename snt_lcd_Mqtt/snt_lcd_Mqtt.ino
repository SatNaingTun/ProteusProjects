#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#define button 5
bool trigger_status=1;
int i=0;
#define led 23

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 4
#define DHTTYPE DHT22
#define ldr_sensor 36
float ADC_value = 0.0048828125;
int lux;


const char* ssid = "iot-ict-lab24g";
const char* password = "iot#labclass";



const char* mqtt_server="192.168.1.114";
const int mqtt_port=1883;
const char* mqtt_client="espClient";
const char* mqtt_username = "snt";
const char* mqtt_password = "snt";

WiFiClient espClient;
PubSubClient client(espClient);

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  dht.begin();

   digitalWrite(led,1);
   showLogo();

  Serial.begin(9600);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
  delay(250);
  Serial.print(".");
  }
  Serial.println("Wifi Connected!!");
  Serial.println("IP address: ");
  Serial.print(WiFi.localIP());

  client.setServer(mqtt_server,mqtt_port);
  client.setCallback(callback);

}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
 
    if (client.connect(mqtt_client,mqtt_username,mqtt_password)) {
      Serial.println("connected");
      client.subscribe("/mqtt/led/");
      
    } else {
      Serial.print("failed with state");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
 String message;

 for (int i = 0; i < length; i++) {
 message = message + (char)payload[i];
 }
 Serial.println(message);

//  if(String(topic) == "/mqtt/led/") {
//  if(message == "on"){
//   digitalWrite(LED1,0);
//   client.publish("/mqtt/led/device", "LED ON");
//   Serial.println("LED ON");
//     }
//   else if (message == "off"){
//   digitalWrite(LED1,1);
//   client.publish("/mqtt/led/device", "LED OFF");
//   Serial.println("LED OFF");
//     }
//   }
}

void showLogo(){
  lcd.setCursor(0, 0);
  lcd.print("Trained by I-Kit");
}


void loop() {
 
 
 if (!client.connected()) {
 reconnect();
 }
 client.loop();
  
   lcd.clear();
    // showLogo();
    float temp=dht.readTemperature();
    int humidity = dht.readHumidity();
    lcd.setCursor(0, 0);
    lcd.print("Temp="+String(temp)+"C");
    lcd.setCursor(0, 1);
    lcd.print("humid="+String(humidity)+"H");
   
    
  StaticJsonDocument<80> doc;
  char output[80];
  doc["humidity"] = humidity;
  doc["temperature"] = temp;

  serializeJson(doc, output);
  // Serial.println(output2);
   // Safe to return now
  
  
  Serial.println(output);
  client.publish("/mqtt/data", output);
  delay(2000);
  
  

  

}
