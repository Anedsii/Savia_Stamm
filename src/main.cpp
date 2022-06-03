#include <Arduino.h>
#include "temporizador.h"
#include "./Library/DHT.h"
#include "DHT22.h"
#include "infrarojo.h"
#include "memo.h"
void setup()
{
  Serial.begin(9600);
  tiempotimer=1000000;
  initmicroSDCard(); //Inicio de memoria SD
  apertura();
  timerconfig();//configuracion inicial del timercounter

  //Pines de salida 
  pinMode(OutputIR,OUTPUT);  
  declararT();
  

}

void loop(){
  if (contador > 0) {
  tiempo();
  Read_TempHum();
  ir_med();
 
  //Cambiar frecuencia de muestreo guardado 
  if(ir_m<600){
    bandera=0;
  }
  if (ir_m>600){
    bandera=1;
  }
  logSDCard();
  }

}