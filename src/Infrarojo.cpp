//Output
#include <Arduino.h>
int OutputIR= 4;
float ir_m;
void ir_med(){
    ir_m = analogRead(OutputIR);
    Serial.println(ir_m);
}