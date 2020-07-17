void setup(){
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
}

void loop(){
    unsigned char helloWorld[5][4];
    helloWorld[0][0] = 0b11111110;
    helloWorld[0][1] = 0b00010000;
    helloWorld[0][2] = 0b00010000;
    helloWorld[0][3] = 0b11111110;
    helloWorld[1][0] = 0b11111110;
    helloWorld[1][1] = 0b10010010;
    helloWorld[1][2] = 0b10010010;
    helloWorld[1][3] = 0b10010010;
    helloWorld[2][0] = 0b11111111;
    helloWorld[2][1] = 0b00000001;
    helloWorld[2][2] = 0b00000001;
    helloWorld[2][3] = 0b00000001;
    helloWorld[3][0] = 0b11111111;
    helloWorld[3][1] = 0b00000001;
    helloWorld[3][2] = 0b00000001;
    helloWorld[3][3] = 0b00000001;
    helloWorld[4][0] = 0b01111110;
    helloWorld[4][1] = 0b10000001;
    helloWorld[4][2] = 0b10000001;
    helloWorld[4][3] = 0b01111110;

    for(int8_t i=0;i<5;i++){
        digitalWrite(3,LOW);
        for(int8_t bitnum=0;bitnum<8;bitnum++){
            digitalWrite(2,LOW);
            digitalWrite(7,helloWorld[i][0]&0b10000000>>bitnum);
            digitalWrite(6,helloWorld[i][1]&0b10000000>>bitnum);
            digitalWrite(5,helloWorld[i][2]&0b10000000>>bitnum);
            digitalWrite(4,helloWorld[i][3]&0b10000000>>bitnum);
            digitalWrite(2,HIGH);
        }
        digitalWrite(3,HIGH);
        delay(750);
    }
}
