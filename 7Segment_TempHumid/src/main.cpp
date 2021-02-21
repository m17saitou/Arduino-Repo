#include <Arduino.h>
#include <ShiftRegister.hpp>
#include <Wire.h>
void setup(){
    pinMode(2,OUTPUT);//Serial Clock
    pinMode(3,OUTPUT);//Ratch Clock
    pinMode(4,OUTPUT);//Serial Data
    Wire.begin(0x38);
    Wire.beginTransmission(0x38);
    Wire.write(0xE1);
    Wire.write(0x08);
    Wire.write(0x00);
    Wire.endTransmission();
}

void loop(){
    uint8_t sevenSegNumArr[10] = {
        /*0*/0b00010010,
        /*1*/0b10011111,
        /*2*/0b00110001,
        /*3*/0b00010101,
        /*4*/0b10011100,
        /*5*/0b01010100,
        /*6*/0b01010000,
        /*7*/0b00011111,
        /*8*/0b00010000,
        /*9*/0b00010100
    };
    ShiftRegisterUtils sr4(2,4,3);

    unsigned long tempResult ,humidResult ,temporary[6];
    Wire.beginTransmission(0x38);//Single-Shot Analyze
    Wire.write(0xAC);
    Wire.write(0x33);
    Wire.write(0x00);
    Wire.endTransmission();
    delay(100);
    Wire.requestFrom(0x38, 6);
    for(unsigned char i = 0; Wire.available() > 0; i++)temporary[i] = Wire.read();
    humidResult = ((temporary[1] << 16) | (temporary[2] << 8) | temporary[3]) >> 4;
    tempResult = ((temporary[3] & 0x0F) << 16) | (temporary[4] << 8) | temporary[5];
    float Temperature = ((200.0 * tempResult) / 1048576) - 50.0;
    float Humidity = humidResult * 100.0 / 1048576;
    int dTemp = int(Temperature);//Displaying Digit
    int dHumid = int(Humidity);//Displaying Digit
    if(Temperature<0.0&&Temperature>-1.0) {
        dTemp=int(Temperature*-10);
        sr4.insertData(0xFD & 0b11101111);//minus dot enable -.1 (-0.1) ~ -.9 (-0.9) Display
    }
    else if(Temperature<0.0){
        dTemp=int(-1*Temperature);
        sr4.insertData(0xFD);//minus -1 ~ -9 Could Display. 
        //if temperature colder than -9 Degree Celcus, then 7-Seg LED is Display Only FIRST DIGIT
    }
    else if (Temperature<10.0){
        dTemp=int(Temperature*10);
        sr4.insertData(sevenSegNumArr[dTemp/10] & 0b11101111);//dot enable
    }
    else sr4.insertData(sevenSegNumArr[dTemp/10]);
    sr4.insertData(sevenSegNumArr[dTemp%10]);
    sr4.insertData(sevenSegNumArr[dHumid/10]);
    sr4.insertData(sevenSegNumArr[dHumid%10]);

    delay(500);
}