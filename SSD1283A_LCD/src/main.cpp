// nano_130x130_TFT_SSD1283A_graphic_functions
// Floris Wouterlood
// 14 february 2020
// see: https://github.com/gitcnd/LCDWIKI_GUI/blob/master/Document/LCDWIKI%20GUI%20lib%20Manual.pdf
// demo of several functions suppied by the LCDWIKI.GUI
// public domain

#include <LCDWIKI_GUI.h>     // core graphics library
#include <LCDWIKI_SPI.h>    // hardware-specific library
#include <Wire.h>
//parameters define
#define MODEL SSD1283A
#define CS 10
#define CD 9
#define SDA 11
#define MOSI SDA
#define SCK 13
#define RST 8
#define LED -1     //if you don’t need to control the LED pin,you should set it to -1 and set it to 3.3V

LCDWIKI_SPI mylcd (MODEL,CS,CD, MISO, MOSI, RST, SCK, LED);

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

void printToLCD(float tempHumidArr[2]);
void getTempHumid(float tempHumidArr[2]);

void setup(){
    mylcd.Init_LCD ();
    mylcd.Fill_Screen (0x00FFFF);
    mylcd.Set_Text_Mode (0);
    Wire.begin();
    delay(100);
}

void loop (){
    mylcd.Set_Text_colour (BLACK);
    mylcd.Set_Text_Back_colour(WHITE);
    mylcd.Set_Text_Size (2);
    mylcd.Print_String ("Temperature", 2, 2);
    mylcd.Print_String("Humidity",2,44);
    float tempHum[2];
    getTempHumid(tempHum);
    printToLCD(tempHum);
    delay(1500);
}

void printToLCD(float tempHumidArr[2]){
    mylcd.Set_Text_Size(3);
    mylcd.Set_Text_colour(GREEN);
    mylcd.Print_Number_Float(tempHumidArr[0],2,10,18,'.',5,' ');
    mylcd.Set_Text_colour(MAGENTA);
    mylcd.Print_Number_Float(tempHumidArr[1],2,10,62,'.',5,' ');
}

void getTempHumid(float arr[2]){
    unsigned char sensorData[7];
    Wire.beginTransmission(0x44);
    Wire.write(0x2C);
    Wire.write(0x06);
    Wire.endTransmission();
    delay(50);
    Wire.requestFrom(0x44,6);
    for(unsigned char i = 0; Wire.available() > 0; i++)sensorData[i] = Wire.read();
    arr[0] = ((((sensorData[0] * 256.0) + sensorData[1]) * 175) / 65535.0) - 45;//Temperature
    arr[1] = ((((sensorData[3] * 256.0) + sensorData[4]) * 100) / 65535.0);
}