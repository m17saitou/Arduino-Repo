#ifndef SHIFTREGISTER_HPP
#define SHIFTREGISTER_HPP

class ShiftRegisterUtils{
public :
    int CLK_PIN;//IC CLK PIN 
    int SERIAL_DATA_PIN;//IC SERIAL DATA PIN
    int RESISTER_CLOCK_PIN=0;//(RCLK)IC LATCH PIN
    int SRCLR_PIN=0;//74HC595 Serial-Data Clear PIN(Negative-Logic)
    int OE_PIN=0;//74HC595 High-Impedance PIN(Negatice-Logic) 3-State Control
    int CASCADE_NUM=1;//QH PIN -> next IC's SER Pin Cascade Connection IC number
    ShiftRegisterUtils(int CLK,int SER,int RCLK);//74HC595_Not use reset pin
    ShiftRegisterUtils(int CLK,int SER,int RCLK,int SRCLR);//74HC595_Use Reset
    ShiftRegisterUtils(int CLK,int SER,int RCLK,int SRCLR,int OE);//74HC595 All Control Pin 
    // 74HC165 Additional
    int SH_LD_PIN=0;// 74HC165 IC's I/O Change
    ShiftRegisterUtils(int CLK,int SDATA);//74HC165 simplest
    ShiftRegisterUtils(int CLK,int SDATA,int SH_LD);//I/O Changable
    //Util Programs
    void setCascade(int num);//Cascade Connection ICs Number
    void insertData(unsigned char data);//data insert for ShiftRegister
    void insertDataCascade(unsigned char data[]);//data insert for Cascade Connected shift resisters
    void insertDataCascade(char* data);//data insert for Cascade Connected shift resiters
    void reset();//data clear
    void high_impedance();//high-impedance

};

#endif //SHIFTREGISTER_HPP
