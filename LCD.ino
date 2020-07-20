//PIN 8 = LCD Resister  =purple 
#define RS 8
//PIN 6 = Serial-Data   =White
#define Si 6
//PIN 4 = Ratch Clock  =Yellow
#define RCLK_E 4
//PIN 2 = Serial Clock   =Green
#define SCLK 2
void initLCD();
void setup(){
    pinMode(RS,OUTPUT);
    pinMode(Si,OUTPUT);
    pinMode(SCLK,OUTPUT);
    pinMode(RCLK_E,OUTPUT);
    pinMode(3,OUTPUT);
    digitalWrite(RS,LOW);
    initLCD();
}

void loop(){
    digitalWrite(3,HIGH);
    char str[16]={"HN : ｶｻｺﾞﾝ"};
    for(int i=0;i<16;i++){
        digitalWrite(RCLK_E,LOW);
        for(int8_t bit=0;bit<8;bit++){
            digitalWrite(SCLK,LOW);
            digitalWrite(Si,str[i]&0b10000000>>bit);
            digitalWrite(SCLK,HIGH);
        }
        digitalWrite(RS,HIGH);
        digitalWrite(RCLK_E,HIGH);
        delay(10);
        digitalWrite(RCLK_E,LOW);
        delay(10);
        digitalWrite(RS,LOW);
    }
    for(int i=0;i<24;i++){
        digitalWrite(RCLK_E,LOW);
        for(int8_t bit=0;bit<8;bit++){
            digitalWrite(SCLK,LOW);
            digitalWrite(Si,0x00&0b10000000>>bit);
            digitalWrite(SCLK,HIGH);
        }
        digitalWrite(RS,HIGH);
        digitalWrite(RCLK_E,HIGH);
        delay(10);
        digitalWrite(RCLK_E,LOW);
        delay(10);
        digitalWrite(RS,LOW);
    }
    char str2[16]={"Twitter:Kasagone"};
    for(int i=0;i<16;i++){
        digitalWrite(RCLK_E,LOW);
        for(int8_t bit=0;bit<8;bit++){
            digitalWrite(SCLK,LOW);
            digitalWrite(Si,str2[i]&0b10000000>>bit);
            digitalWrite(SCLK,HIGH);
        }
        digitalWrite(RS,HIGH);
        digitalWrite(RCLK_E,HIGH);
        delay(10);
        digitalWrite(RCLK_E,LOW);
        delay(10);
        digitalWrite(RS,LOW);
    }
    digitalWrite(3,LOW);
	delay(500);
	initLCD();
}

void initLCD(){
    digitalWrite(RS,LOW);
    digitalWrite(RCLK_E,LOW);
    for(int8_t i=0;i<8;i++){
        digitalWrite(SCLK,LOW);
        digitalWrite(Si,0b00111000&0b10000000>>i);
        digitalWrite(SCLK,HIGH);
    }
    digitalWrite(RCLK_E,HIGH);
    digitalWrite(RCLK_E,LOW);
    delay(4);
    for(int8_t i=0;i<8;i++){
        digitalWrite(SCLK,LOW);
        digitalWrite(Si,0b00001111&0b10000000>>i);
        digitalWrite(SCLK,HIGH);
    }
    digitalWrite(RCLK_E,HIGH);
    digitalWrite(RCLK_E,LOW);
    delay(4);
    for(int8_t i=0;i<8;i++){
        digitalWrite(SCLK,LOW);
        digitalWrite(Si,0b00000001&0b10000000>>i);
        digitalWrite(SCLK,HIGH);
    }
    digitalWrite(RCLK_E,HIGH);
    digitalWrite(RCLK_E,LOW);
    delay(4);
    for(int8_t i=0;i<8;i++){
        digitalWrite(SCLK,LOW);
        digitalWrite(Si,0b00000110&0b10000000>>i);
        digitalWrite(SCLK,HIGH);
    }
    digitalWrite(RCLK_E,HIGH);
    digitalWrite(RCLK_E,LOW);
    delay(4);
}
