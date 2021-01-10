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
    Wire.begin();
    // Wire.beginTransmission(0x44);
    // Wire.write(0x30);
    // Wire.write(0x6D);
    // Wire.endTransmission();
    delay(100);
    Serial.begin(9600);
}

void loop(){
    LCD_SC1602 lcd(Si,SCLK,RCLK_E,RS);
    unsigned char sensorData[7];
    Wire.beginTransmission(0x44);
    Wire.write(0x2C);
    Wire.write(0x06);
    Wire.endTransmission();
    delay(50);
    Wire.requestFrom(0x44,6);
    for(unsigned char i = 0; Wire.available() > 0; i++)sensorData[i] = Wire.read();
    // int humidData = (sensorData[0]<<8) + sensorData[1];
    // int tempData = (sensorData[3]<<8) + sensorData[4];
    // float humidValue = (humidData*100.0)/65535.0;
    // float tempValue = ((tempData*175.0)/65535.0)-45.0;
    float tempValue = ((((sensorData[0] * 256.0) + sensorData[1]) * 175) / 65535.0) - 45;
    float humidValue = ((((sensorData[3] * 256.0) + sensorData[4]) * 100) / 65535.0);
    char a = 0b11011111;
    String trans = "Temp:" + String(tempValue) + a + "C     ";
    unsigned char str[17];
    trans.getBytes(str,17);
    lcd.writeLine(str);
    trans = "Humid:" + String(humidValue) +"%         ";
    unsigned char str2[17];
    trans.getBytes(str2,17);
    lcd.writeLine(str2);
    Serial.println("humid :\t" + String(humidValue));
    Serial.println("Temp :\t" + String(tempValue));
	delay(300);
    // lcd.initializer();
    // Wire.beginTransmission(0x44);
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