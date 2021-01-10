#ifndef LCD_SC1602_H
#define LCD_SC1602_H

#include "shiftRegister.h"
class ShiftRegisterUtils;
class LCD_SC1602 : public ShiftRegisterUtils{
public:
    int LCD_RS_PIN;
    LCD_SC1602(int ser,int sclk,int rclk,int rs) : ShiftRegisterUtils(sclk,ser,rclk){
        LCD_RS_PIN=rs;
        digitalWrite(LCD_RS_PIN,LOW);
        insertData(0b00011100);
        digitalWrite(RESISTER_CLOCK_PIN,LOW);//初期化するシグナルのためにLOWに落とす必要あり
        delay(4);
        insertData(0b00110000);
        digitalWrite(RESISTER_CLOCK_PIN,LOW);
        delay(4);
        insertData(0b10000000);
        digitalWrite(RESISTER_CLOCK_PIN,LOW);
        delay(4);
        insertData(0b01100000);
        digitalWrite(RESISTER_CLOCK_PIN,LOW);
        delay(4);
    };
    void initializer(){
        digitalWrite(LCD_RS_PIN,LOW);
        insertData(0b00011100);
        digitalWrite(RESISTER_CLOCK_PIN,LOW);//初期化するシグナルのためにLOWに落とす必要あり
        delay(4);
        insertData(0b00110000);
        digitalWrite(RESISTER_CLOCK_PIN,LOW);
        delay(4);
        insertData(0b10000000);
        digitalWrite(RESISTER_CLOCK_PIN,LOW);
        delay(4);
        insertData(0b01100000);
        digitalWrite(RESISTER_CLOCK_PIN,LOW);
        delay(4);
    }
    void writeLine(unsigned char str[16]){
        unsigned char writeToLCD[40];
        for(int itr=0;itr<40;itr++)itr<16? writeToLCD[itr]=str[itr] : writeToLCD[itr] = 0x00;
        for(int i=0;i<40;i++){
            insertDataInverse(writeToLCD[i]);
            digitalWrite(LCD_RS_PIN,HIGH);
            digitalWrite(RESISTER_CLOCK_PIN,HIGH);
            delay(5);
            digitalWrite(RESISTER_CLOCK_PIN,LOW);
            delay(5);
            digitalWrite(LCD_RS_PIN,LOW);
        }
    };
};
#endif //LCD_SC1602_H