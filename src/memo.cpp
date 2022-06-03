#include "DHT22.h"
#include "infrarojo.h"

#include "FS.h"
//Crear un archivo
#include <SPI.h>		// incluye libreria interfaz SPI
#include <SD.h>			// incluye libreria para tarjetas SD

#define SSpin 10		// Slave Select en pin digital 10

File archivo;			// objeto archivo del tipo File
//--------Inicializar/Comprobar memoria SD----------------//
void initmicroSDCard(){
  if(!SD.begin()){
    Serial.println("Initialization Failed");
    //Detenemos la ejecución en el caso de que tengamosproblemas con la MicroSD
    return;
  }
  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE){
    Serial.println("SD card is not present!");
    return;
  }
  Serial.print("SD Card Type: ");
  if(cardType == CARD_MMC){
    Serial.println("MMC");
  } else if(cardType == CARD_SD){
    Serial.println("SDSC");
  } else if(cardType == CARD_SDHC){
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }
  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD Card Size: %lluMB\n", cardSize);
}
void apertura(){
  Serial.println("inicializacion correcta");	// inicializacion correcta
  archivo = SD.open("/datos.csv", FILE_WRITE);	// apertura 
  if (archivo) {
    archivo.println("Time,Presencia,ValorPromAnalogTemp,Humedad,Solar");	// escritura en la primera linea del archivo
    Serial.println("Escribiendo en archivo prueba.txt...");	
    archivo.close();// cierre del archivo
    Serial.println("escritura correcta");
  } else {
    Serial.println("error en apertura de prueba.txt");	// texto de falla en apertura de archivo
  }
}
//---------------------Agregar registro en el archivo ------------------------------//
void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);
  File file = fs.open("/datos.csv", FILE_APPEND);
  if(!file) {
    Serial.println("Failed to open file for appending");
    return;
  }
  if(file.print(message)) {
    Serial.println("Mensaje ha sido agregado");
  } else {
    Serial.println("error al agregar");
  }
  file.close();
}
//----------------------------------------------------------------//
void logSDCard() {
  ///Colocar las  variables a escribir "Time,Presencia,ValorPromAnalogTemp,Humedad,Solar en un STRING"
    String dataMessage = String(1)+ "," + String(1) + String(1)  +"\r\n"; //+ variables a mostrar
    Serial.print("Save data: ");
    Serial.println(dataMessage);
    appendFile(SD,String("/datos.csv").c_str(), dataMessage.c_str());
}