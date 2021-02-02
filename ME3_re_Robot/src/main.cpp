#include <Arduino.h>
#define time 6
void stepper1(int cycle);
void stepper2(int cycle);
void stepper1_inv(int cycle);
void stepper2_inv(int cycle);
void setup(){
    pinMode(2,OUTPUT);//Right_FrontBack
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);//Left_FrontBack
    pinMode(5,OUTPUT);
    pinMode(8,INPUT);//Input Sensor
    pinMode(9,INPUT);//Input Sensor
    pinMode(10,OUTPUT);//Stepper Motor_1
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);
    pinMode(14,OUTPUT);//Stepper Motor_2
    pinMode(15,OUTPUT);
    pinMode(16,OUTPUT);
    pinMode(17,OUTPUT);
}
void loop(){
    int cnt=0;
    stepper1_inv(570);//down
    while(cnt ==0){
        if(digitalRead(8)&&digitalRead(9)){
            cnt ++;
            digitalWrite(2,1);
            digitalWrite(5,1);
            delay(600);
        }
        digitalRead(9)? digitalWrite(2,0):digitalWrite(2,1);
        digitalRead(8)? digitalWrite(5,0):digitalWrite(5,1);
        delay(100);
    }
    digitalWrite(2,0);
    digitalWrite(5,0);
    stepper2(1500);//open
    while(cnt ==1){
        if(digitalRead(8)&&digitalRead(9)){
            cnt ++;
            digitalWrite(2,1);
            digitalWrite(5,1);
            delay(600);
        }
        digitalRead(9)? digitalWrite(2,0):digitalWrite(2,1);
        digitalRead(8)? digitalWrite(5,0):digitalWrite(5,1);
        delay(100);
    }
    digitalWrite(2,0);
    digitalWrite(5,0);
    stepper2_inv(1300);//close
    while(cnt ==2){
        if(digitalRead(8)&&digitalRead(9)){
            cnt ++;
            digitalWrite(2,1);
            digitalWrite(5,1);
            delay(600);
        }
        digitalRead(9)? digitalWrite(2,0):digitalWrite(2,1);
        digitalRead(8)? digitalWrite(5,0):digitalWrite(5,1);
        delay(100);
    }
    digitalWrite(2,0);
    digitalWrite(5,0);
    stepper1(570); // up
    digitalWrite(2,1);
    digitalWrite(5,1);
    delay(3500);
    digitalWrite(2,0);
    digitalWrite(5,0);
    stepper2(1500);//open

}

void stepper1(int cycle){
    for(int i=0;i<cycle;i++){
        PORTB = 0b00001100;
        delay(time);
        PORTB = 0b00011000;
        delay(time);
        PORTB = 0b00110000;
        delay(time);
        PORTB = 0b00100100;
        delay(time);
    }
}
void stepper1_inv(int cycle){
    for(int i=0;i<cycle;i++){
        PORTB = 0b00110000;
        delay(time);
        PORTB = 0b00011000;
        delay(time);
        PORTB = 0b00001100;
        delay(time);
        PORTB = 0b00100100;
        delay(time);
    }
}
void stepper2(int cycle){
    for(int i=0;i<cycle;i++){
        PORTC = 0B000011;
        delay(time);
        PORTC = 0B000110;
        delay(time);
        PORTC = 0B001100;
        delay(time);
        PORTC = 0B001001;
        delay(time);
    }
}
void stepper2_inv(int cycle){
    for(int i=0;i<cycle;i++){
        PORTC = 0B001100;
        delay(time);
        PORTC = 0B000110;
        delay(time);
        PORTC = 0B000011;
        delay(time);
        PORTC = 0B001001;
        delay(time);
    }
}