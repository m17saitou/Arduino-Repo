#include <Arduino.h>
#include <Wire.h>
#include "LCD_SC1602.h"
//PIN 8 = LCD Resister  =purple 
#define RS 11
//PIN 6 = Serial-Data   =White
#define Si 10
//PIN 4 = Ratch Clock  =Yellow
#define RCLK_E 9
//PIN 2 = Serial Clock   =Green
#define SCLK 8

void setup(){
    pinMode(RS,OUTPUT);
    pinMode(Si,OUTPUT);
    pinMode(SCLK,OUTPUT);
    pinMode(RCLK_E,OUTPUT);
    digitalWrite(RS,LOW);
    LCD_SC1602 lcd(Si,SCLK,RCLK_E,RS);
    Wire.begin(0x38);
    Wire.beginTransmission(0x38);
    Wire.write(0xE1);
    Wire.write(0x08);
    Wire.write(0x00);
    Wire.endTransmission();
    delay(100);
}

void loop(){
    LCD_SC1602 lcd(Si,SCLK,RCLK_E,RS);
    unsigned char sensorData[6];
    
    Wire.beginTransmission(0x38);
    Wire.write(0xAC);
    Wire.write(0x33);
    Wire.write(0x00);
    Wire.endTransmission();
    delay(150);
    Wire.requestFrom(0x38,6);
    delay(80);
    for(unsigned char i = 0; Wire.available() > 0; i++)sensorData[i] = Wire.read();
    unsigned long humidData = ((sensorData[1]<<16) | sensorData[2]<<8 | sensorData[3])>>4;
    unsigned long tempData = ((sensorData[3]&0x0F<<16) | sensorData[4]<<8) | sensorData[5];
    float humidValue = (humidData*100)>>20;
    unsigned long tempValue = ((tempData*200)>>20)-50;
    String trans = "Temperature:" + String(tempValue) + "     ";
    unsigned char str[17];
    trans.getBytes(str,17);
    lcd.writeLine(str);
    trans = "Humid:" + String(humidValue) +"%         ";
    unsigned char str2[17];
    trans.getBytes(str2,17);
    lcd.writeLine(str2);
	delay(1000);
    // lcd.initializer();
    // Wire.beginTransmission(0x38);
    // Wire.write(0xBA);
    // Wire.endTransmission();
    // delay(200);
}

// void setup(){
//     pinMode(2,OUTPUT);
//     pinMode(3,OUTPUT);
//     pinMode(4,OUTPUT);
// }

// void loop(){
//     ShiftRegisterUtils s(2,3,4);
//     //s.setCascade(24);
//     for(int i=0;i<2;i++){
//         s.insertData(0xff);
//         delay(50);
//     }
//     for(int i=0;i<2;i++){
//         s.insertData(0x00);
//         delay(50);
//     }
// }