//PIN 6 = Serial-Data   =White
//PIN 4 = Serial Clock  =Green
//PIN 2 = Ratch Clock   =Yellow
void initLCD();
void setup(){
    pinMode(6,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(2,OUTPUT);
}

void loop(){
    initLCD();
    char str[6]={"hello"};
    for(int i:str){
        digitalWrite(2,LOW);
        for(int8_t bit=0;bit<8;bit++){
            digitalWrite(4,LOW);
            digitalWrite(6,str[i]&0b10000000>>bit);
            digitalWrite(4,HIGH);
        }
        digitalWrite(2,HIGH);
    }
}

void initLCD(){
    delay(40);
    digitalWrite(2,LOW);
    for(int8_t i=0;i<8;i++){
        digitalWrite(4,LOW);
        digitalWrite(6,0b00111100&0b10000000>>i);
        digitalWrite(4,HIGH);
    }
    digitalWrite(2,HIGH);
    digitalWrite(2,LOW);
    delay(4);
    for(int8_t i=0;i<8;i++){
        digitalWrite(4,LOW);
        digitalWrite(6,0b11110000&0b10000000>>i);
        digitalWrite(4,HIGH);
    }
    digitalWrite(2,HIGH);
    digitalWrite(2,LOW);
    delay(4);
    for(int8_t i=0;i<8;i++){
        digitalWrite(4,LOW);
        digitalWrite(6,0b10000000&0b10000000>>i);
        digitalWrite(4,HIGH);
    }
    digitalWrite(2,HIGH);
    digitalWrite(2,LOW);
    delay(4);
    for(int8_t i=0;i<8;i++){
        digitalWrite(4,LOW);
        digitalWrite(6,0b11100000&0b10000000>>i);
        digitalWrite(4,HIGH);
    }
}