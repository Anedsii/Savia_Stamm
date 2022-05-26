#include <./Library/DHT.h>
#include <Arduino.h>

#define DHTTYPE DHT22

//--------Variables de sensor de temperatura-----------//

uint8_t DHTPIN=17;
DHT dht(DHTPIN, DHTTYPE,22);
float Temperature;
float Humidity;

void declararT(){
  //Declarar ensor de temperatura
  pinMode(DHTPIN, INPUT);
  dht.begin();
}

//--------- Funcion example para sensor de temperatura--------------//
void Read_TempHum()
{
  Temperature = dht.readTemperature(); 
  Humidity = dht.readHumidity(); 
  Serial.print("Temperature = ");
  Serial.println(Temperature,1);
  Serial.print("Humidity = ");
  Serial.println(Humidity,1);
} 