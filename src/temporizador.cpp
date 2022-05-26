#include <Arduino.h>
//************************************************************************************************
//Variables 
volatile int contador;
int segundos=0;
int minutos;
int horas;
volatile int tiempotimer;
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
int bandera;


void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  contador++;
  portEXIT_CRITICAL_ISR(&timerMux);
}
void timerconfig(){
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, tiempotimer, true);
  timerAlarmEnable(timer);
}

void tiempo(){
   Serial.println("Tiempo: " + String(horas) + " : " + String(minutos) + " : " + String(segundos));
   portENTER_CRITICAL(&timerMux);
   contador--;
   portEXIT_CRITICAL(&timerMux);
   if(bandera == 0){
       Serial.println("Estamos copiando 1seg");
   }
    if(segundos>=59){
     segundos=-1;
     if(bandera==1){
       Serial.println("Estamos 1 m");
     }
     minutos++;
   }
   if(minutos>=60){
     horas++;
     minutos=0;
   }
   if(horas>=0 && horas<=24){
     horas=0;
   }
    segundos++;
}
 