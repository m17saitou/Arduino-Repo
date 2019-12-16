#include "saitoRobo.hpp"
void setup(){
    pinMode(1,OUTPUT);
}

void loop(){
    SaitoRobo drive = SaitoRobo(1);
    drive.pinOut();
}