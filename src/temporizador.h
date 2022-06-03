#ifndef temporizador_h
#define temporizador_h

void tiempo();
void timerconfig();
extern volatile int contador;
extern int segundos;
extern int minutos;
extern int horas;
 //Configuracion de temporizador
extern portMUX_TYPE timerMux ;
extern hw_timer_t * timer;
extern volatile int tiempotimer;
extern int bandera;
extern String tiemporeloj;

#endif