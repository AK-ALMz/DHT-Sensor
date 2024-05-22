#include <Arduino.h>
#include <DHT.h>

#define DHTpin 4 //connected to pin 4
#define DHTtype DHT11 //using DHT11.

DHT dht(DHTpin, DHTtype);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Testing DHT11 sensor");
  dht.begin();
  delay(2000);
}

void loop() {
  float temp = dht.readTemperature(); //auto selects celsius
  float humidity = dht.readHumidity();

  if (!isnan(temp)) {
    Serial.print(F("Temp = "));
    Serial.println(temp);
  } else Serial.println("Temp error");
  if (!isnan(humidity)) {
    Serial.print(F("Humidity = "));
    Serial.println(humidity);
  } else Serial.println("Hum. error");
  if(!isnan(humidity) && !isnan(temp)){
    float index = dht.computeHeatIndex(temp, humidity, false);
    //float index = dht.computeHeatIndex(false);
    Serial.print(F("Heat Index = "));
    Serial.println(index);

  }
  delay(2000); //wait between measurements
  Serial.println(F("End of loop"));
  }

