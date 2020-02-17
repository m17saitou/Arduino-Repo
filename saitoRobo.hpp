#ifndef SAITOROBO_HPP
#define SAITOROBO_HPP
#pragma once

class SaitoRobo{
public:
    SaitoRobo(int rF,int rR,int lF,int lR,int B){
        rMF = rF;
        rMR = rR;
        lMF = lF;
        lMR = lR;
        Ball = B;
    }
    void turnRight(){
        digitalWrite(lMF,1);
        digitalWrite(rMR,1);
        delay(1500);
        digitalWrite(lMF,0);
        digitalWrite(rMR,0);
    }
    void turnLeft(){
        digitalWrite(rMF,1);
        digitalWrite(lMR,1);
        delay(1500);
        digitalWrite(rMF,0);
        digitalWrite(lMR,0);
    }
    void ballShot(){
        digitalWrite(Ball,1);
        delay(2000);
        digitalWrite(Ball,0);
    }
    int rMF,
        rMR,
        lMF,
        lMR,
        Ball;
};

#endif // SAITOROBO_HPP