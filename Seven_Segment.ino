void setup(){
    pinMode(2,OUTPUT);//Serial Clock
    pinMode(3,OUTPUT);//Ratch Clock
    pinMode(4,OUTPUT);//Serial Data
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
    // for(int i=0;i<10;i++){ //テスト用
    //     digitalWrite(3,LOW);
    //     for(int8_t bit=0;bit<8;bit++){
    //         digitalWrite(2,LOW);
    //         digitalWrite(4,sevenSegNumArr[i]&0b00000001<<bit);
    //         digitalWrite(2,HIGH);
    //     }
    //     digitalWrite(3,HIGH);
    //     delay(500);
    // }
    for(uint8_t time=180;time>0;time--){ //3分ラーメンたいまー.誤差?しらん
        int8_t min=time/60;
        digitalWrite(3,LOW);
        for(int8_t bit=0;bit<8;bit++){
            digitalWrite(2,LOW);
            digitalWrite(4,sevenSegNumArr[0]&0b00000001<<bit);
            digitalWrite(2,HIGH);
        }
        digitalWrite(3,HIGH);
        digitalWrite(3,LOW);
        for(int8_t bit=0;bit<8;bit++){
            digitalWrite(2,LOW);
            digitalWrite(4,sevenSegNumArr[min]&0b00000001<<bit);
            digitalWrite(2,HIGH);
        }
        digitalWrite(3,HIGH);
        int8_t sec=time-60*min;
        digitalWrite(3,LOW);
        for(int8_t bit=0;bit<8;bit++){
            digitalWrite(2,LOW);
            digitalWrite(4,sevenSegNumArr[sec/10]&0b00000001<<bit);
            digitalWrite(2,HIGH);
        }
        digitalWrite(3,HIGH);
        digitalWrite(3,LOW);
        for(int8_t bit=0;bit<8;bit++){
            digitalWrite(2,LOW);
            digitalWrite(4,sevenSegNumArr[sec%10]&0b00000001<<bit);
            digitalWrite(2,HIGH);
        }
        digitalWrite(3,HIGH);
    delay(980);
    }
}