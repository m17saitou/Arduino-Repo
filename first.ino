#include "saitoRobo.hpp"
void setup(){
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(8,INPUT);
    pinMode(9,INPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
}



void loop(){
	SaitoRobo Robo = SaitoRobo(2,3,4,5,11);
	digitalWrite(2,1);
	Robo.turnLeft();
}