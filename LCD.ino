//PIN 8 = LCD Resister  =purple 
#define RS 8
//PIN 6 = Serial-Data   =White
#define Si 6
//PIN 4 = Serial Clock  =Yellow
#define SCLK 2
//PIN 2 = Ratch Clock   =Green
#define RCLK_E 4
void initLCD();
void setup(){
    pinMode(RS,OUTPUT);
    pinMode(Si,OUTPUT);
    pinMode(SCLK,OUTPUT);
    pinMode(RCLK_E,OUTPUT);
    digitalWrite(RS,LOW);
    initLCD();
}

void loop(){
    char str[6]={"hello"};
    for(int i:str){
        delay(2);
        digitalWrite(RCLK_E,LOW); 
        digitalWrite(RS,LOW);
        delay(2);
        for(int8_t bit=0;bit<8;bit++){
            digitalWrite(SCLK,LOW);
            digitalWrite(Si,str[i]&0b10000000>>bit);
            digitalWrite(SCLK,HIGH);
        }
        digitalWrite(RCLK_E,HIGH);
        digitalWrite(RS,HIGH);
    }
}

void initLCD(){
    digitalWrite(RS,LOW);
    digitalWrite(RCLK_E,LOW);
    for(int8_t i=0;i<8;i++){
        digitalWrite(SCLK,LOW);
        digitalWrite(Si,0b00111100&0b10000000>>i);
        digitalWrite(SCLK,HIGH);
    }
    digitalWrite(RCLK_E,HIGH);
    digitalWrite(RCLK_E,LOW);
    delay(4);
    for(int8_t i=0;i<8;i++){
        digitalWrite(SCLK,LOW);
        digitalWrite(Si,0b00010000&0b10000000>>i);
        digitalWrite(SCLK,HIGH);
    }
    digitalWrite(2,HIGH);
    digitalWrite(2,LOW);
    delay(4);
    for(int8_t i=0;i<8;i++){
        digitalWrite(SCLK,LOW);
        digitalWrite(Si,0b10000000&0b10000000>>i);
        digitalWrite(SCLK,HIGH);
    }
    digitalWrite(2,HIGH);
    digitalWrite(2,LOW);
    delay(4);
    for(int8_t i=0;i<8;i++){
        digitalWrite(SCLK,LOW);
        digitalWrite(Si,0b11100000&0b10000000>>i);
        digitalWrite(SCLK,HIGH);
    }
}