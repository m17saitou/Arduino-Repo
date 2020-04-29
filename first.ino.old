#include "saitoRobo.hpp"
void setup(){
    pinMode(2,OUTPUT);//right side
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);//left side
    pinMode(5,OUTPUT);
    pinMode(8,INPUT);//if Black then, HIGH
    pinMode(9,INPUT);//if White then, LOW
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
}

void loop(){unsigned char blkCnt=0;
	SaitoRobo robo = SaitoRobo(2,3,5,4,10);
    digitalWrite(11,1);
    digitalWrite(10,1);
	while(1){
        if(digitalRead(8)&&digitalRead(9)){
            blkCnt++;
            digitalWrite(robo.lMF,1);
            digitalWrite(robo.rMF,1);
            delay(300);
            if(blkCnt==5) break;
            else continue;
        }
        digitalRead(9)? digitalWrite(robo.rMF,0):digitalWrite(robo.rMF,1);
        digitalRead(8)? digitalWrite(robo.lMF,0):digitalWrite(robo.lMF,1);
        delay(80);
    }
	robo.turnLeft();
    digitalWrite(robo.lMF,1);
    digitalWrite(robo.rMF,1);
    delay(950);
    robo.turnRight();
    digitalWrite(robo.lMF,1);
    digitalWrite(robo.rMF,1);
    delay(1150);
    digitalWrite(robo.lMF,0);
    digitalWrite(robo.rMF,0);
    robo.ballShot();
    digitalWrite(robo.lMR,1);
    digitalWrite(robo.rMR,1);
    delay(1000);
}