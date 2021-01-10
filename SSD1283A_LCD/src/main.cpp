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

void setup(){
    mylcd.Init_LCD ();
    mylcd.Fill_Screen (0x00FFFF);
}

void loop (){
    mylcd.Set_Text_Mode (0);

    mylcd.Fill_Screen (0x00FFFF);
    mylcd.Set_Text_colour (RED);
    mylcd.Set_Text_Back_colour (CYAN);
    mylcd.Set_Text_Size (2);
    mylcd.Print_String ("Hello Kasagone", 0, 0);

    delay (2000);
}