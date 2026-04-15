#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL33SoDi5Cj"
#define BLYNK_TEMPLATE_NAME "smartplantmonitoring"
#define BLYNK_AUTH_TOKEN "VeSmaTxDIT3DsYeEzyivtOI_z4DY2tV9"
#define DHTPIN 4
#define DHTTYPE DHT11

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
DHT dht(DHTPIN, DHTTYPE);
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "realme6pro";
char pass[] = "12345678";

void setup()
{
  // Debug console
  pinMode(33,INPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
}
void dht11() {
     int soil = analogRead(33);
  Serial.println(soil);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  }
  else {

    Serial.print("Temp=");
    Serial.print(t);
    Serial.println(" *C");

    Serial.print("Humidity=");
    Serial.print(h);
    Serial.println("% ");
    
Serial.print("soilmoist=");
    Serial.print(soil);
    Serial.println("% ");

    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Blynk.virtualWrite(V3, soil);

 

    if(soil>4000){
    digitalWrite(2,LOW);
  }
  else{
  digitalWrite(2,HIGH);
}
   
    delay(500);
}}

void loop(){

  dht11();
  Blynk.run();
}
  