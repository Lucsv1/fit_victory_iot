
#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqttServer = "test.mosquitto.org";


WiFiClient  espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
float temp = 0;
float pot = 0;

unsigned long myChannelNumber = 1;

unsigned long lastTime = 0;


unsigned long timerDelay = 30000;


float temperatura;


int valorPot;


#define dhtPin 5


#define DHTTYPE DHT22


DHT dht(dhtPin, DHTTYPE);

void setup_wifi() { 
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void callback(char* topic, byte* payload, unsigned int length) { 
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) { 
    Serial.print((char)payload[i]);
  }}
void reconnect() { 
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      client.publish("/ThinkIOT/Publish", "Welcome");
      client.subscribe("/ThinkIOT/Subscribe"); 
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }}
}


void setup() {
 
  Serial.begin(115200);
  pinMode(2, OUTPUT);  
  setup_wifi(); 
  client.setServer(mqttServer, 1883);
  client.setCallback(callback); 
  dht.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) { 
    lastMsg = now;

   
    float temperatura = dht.readTemperature();

    
    int valorPot = analogRead(34);

    String temp = String(temperatura, 2);
    client.publish("/ThinkIOT/temp", temp.c_str()); 
    String hum = String(valorPot); 
    client.publish("/ThinkIOT/hum", hum.c_str());   

    Serial.print("Temperature: ");
    Serial.println(temp);
    Serial.print("Potentiometer Value: ");
    Serial.println(valorPot);
  }
}

