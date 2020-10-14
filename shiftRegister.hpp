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

    ShiftRegisterUtils(int CLK,int SER,int RCLK){//74HC595_Not use reset pin
        CLK_PIN=CLK;
        SERIAL_DATA_PIN=SER;
        RESISTER_CLOCK_PIN=RCLK;
    };
    ShiftRegisterUtils(int CLK,int SER,int RCLK,int SRCLR){//74HC595_Use Reset
        CLK_PIN=CLK;
        SERIAL_DATA_PIN=SER;
        RESISTER_CLOCK_PIN=RCLK;
        SRCLR_PIN=SRCLR;
        digitalWrite(SRCLR_PIN,LOW);
    };
    ShiftRegisterUtils(int CLK,int SER,int RCLK,int SRCLR,int OE){//74HC595 All Control Pin 
        CLK_PIN=CLK;
        SERIAL_DATA_PIN=SER;
        RESISTER_CLOCK_PIN=RCLK;
        SRCLR_PIN=SRCLR;
        OE_PIN=OE;
    };

    // 74HC165 Additional
    ShiftRegisterUtils(int CLK,int SER){//74HC165 simplest
        CLK_PIN=CLK;
        SERIAL_DATA_PIN=SER;
    };
    //Util Programs
    void setCascade(int num){CASCADE_NUM=num;};//Cascade Connection ICs Number
    void insertData(unsigned char data){
        if(CASCADE_NUM==1&&RESISTER_CLOCK_PIN!=0){//74HC595 Single
            digitalWrite(RESISTER_CLOCK_PIN,LOW);
            for(int bit=0;bit<8;bit++){
                digitalWrite(CLK_PIN,LOW);
                digitalWrite(SERIAL_DATA_PIN,data&0b00000001<<bit);
                digitalWrite(CLK_PIN,HIGH);
            }
            digitalWrite(RESISTER_CLOCK_PIN,HIGH);
        }
        else if(CASCADE_NUM==1&&RESISTER_CLOCK_PIN==0){//74HC165 Single
            for(int bit=0;bit<8;bit++){
                digitalWrite(CLK_PIN,LOW);
                digitalWrite(SERIAL_DATA_PIN,data&0b00000001<<bit);
                digitalWrite(CLK_PIN,HIGH);
            }
        }
    };//data insert for ShiftRegister
    void insertDataInverse(unsigned char data){
        if(CASCADE_NUM==1&&RESISTER_CLOCK_PIN!=0){//74HC595 Single
            digitalWrite(RESISTER_CLOCK_PIN,LOW);
            for(int bit=0;bit<8;bit++){
                digitalWrite(CLK_PIN,LOW);
                digitalWrite(SERIAL_DATA_PIN,data&(0b10000000>>bit));
                digitalWrite(CLK_PIN,HIGH);
            }
            digitalWrite(RESISTER_CLOCK_PIN,HIGH);
        }
        else if(CASCADE_NUM==1&&RESISTER_CLOCK_PIN==0){//74HC165 Single
            for(int bit=0;bit<8;bit++){
                digitalWrite(CLK_PIN,LOW);
                digitalWrite(SERIAL_DATA_PIN,data&(0b10000000>>bit));
                digitalWrite(CLK_PIN,HIGH);
            }
        }
    };
    void insertDataCascade(unsigned char data[]){
        size_t arrSize = sizeof(*data)/sizeof(unsigned char);
        for(unsigned int itr=0;itr<arrSize;itr++)this->insertData(data[itr]);
    };//data insert for Cascade Connected shift resisters
    void insertDataCascade(unsigned char data[],unsigned int arrSize){
        for(unsigned int itr=0;itr<arrSize;itr++)this->insertData(data[itr]);
    };
    void insertDataCascade(char* data){};//data insert for Cascade Connected shift resiters
    void reset(){};//data clear
    void high_impedance(){};//high-impedance

};

#endif //SHIFTREGISTER_HPP
