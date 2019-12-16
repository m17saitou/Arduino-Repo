#ifndef SAITOROBO_HPP
#define SAITOROBO_HPP
#pragma once

class SaitoRobo{
public:
    SaitoRobo(int a){
        num=a;
    }
    void pinOut(){
        digitalWrite(SaitoRobo::num,HIGH);
    }
private:
    int num;
};

#endif // SAITOROBO_HPP