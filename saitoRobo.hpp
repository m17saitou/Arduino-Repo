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
    void turnLeft(){
        digitalWrite(lMF,1);
        digitalWrite(rMR,1);
        delay(1000);
        digitalWrite(lMF,0);
        digitalWrite(rMR,0);
    }
    int rMF,
        rMR,
        lMF,
        lMR,
        Ball;
};

#endif // SAITOROBO_HPP