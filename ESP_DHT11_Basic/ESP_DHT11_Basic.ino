#include "DHTesp.h"

#ifdef ESP32
#pragma message(THIS EXAMPLE IS FOR ESP8266 ONLY!)
#error Select ESP8266 board.
#endif

//Inicializa sensor
DHTesp dht;

void setup() {
  Serial.begin(115200); // Velocidade - Serial Monitor
  String thisBoard= ARDUINO_BOARD;
  Serial.println(thisBoard);
  dht.setup(16, DHTesp::DHT11); // Connect DHT sensor to GPIO16 - D0 -- Change according the sensor: DHT11 or DHT22
}

void dhtData(){
  delay(dht.getMinimumSamplingPeriod());
  float humid = dht.getHumidity();
  float temp = dht.getTemperature();
  Serial.print(dht.getStatusString());
  Serial.print("\n");
  Serial.print("Umidade:  ");
  Serial.print(humid, 1);
  Serial.print("\t\t");
  Serial.print("Temperatura:  ");
  Serial.print(temp, 1);
  Serial.print("\t\t");
  delay(1000);
}

void loop() {
  dhtData();
}
