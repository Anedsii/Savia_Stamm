#include "DHT22.h"
#include "infrarojo.h"
#include "SPI.h"
#include "SD.h"
#include "FS.h"
//Crear un archivo

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
//Creamos el archivo por si no existiera



//------------Escribir el archivo-------------------------//
void writeFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);
  File file = fs.open(path, FILE_WRITE);
  if(!file) {
    Serial.println("Failed to open file for writing");
    return;
  }
  if(file.print(message)) {
    Serial.println("File written");
    
  } else {
    Serial.println("Write failed");
  }
  file.close();
}
//------------Funcion recibe nombre del archivo y crea uno -----------------// 
 void guardar2(){
  File dataFile = SD.open("savia.txt");
  if (!dataFile) {
      writeFile(SD,String("savia.txt").c_str(), "Output1,Output2 \r\n"); //lista de primera fila declaro 
}
  }
//---------------------Agregar registro en el archivo ------------------------------//

void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);
  File file = fs.open("savia.txt", FILE_APPEND);
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

//---------------- Funcion para loggear y agregar en el documento seleccionado al poner play se activa ------------------------------//
void logSDCard() {
    
  String dataMessage = String(1)+ "," + String(4)  +"\r\n"; //+ variables a mostrar
    Serial.print("Save data: ");
    Serial.println(dataMessage);
    appendFile(SD,String("savia.txt").c_str(), dataMessage.c_str());

}