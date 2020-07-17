void setup(){
    pinMode(2,OUTPUT);//Serial input
    pinMode(3,OUTPUT);//Latch CLK
    pinMode(4,OUTPUT);//Serial CLK
}
using namespace std;
void loop(){
    unsigned char str[2];
    str[0] = 0xFF;
    str[1] = 0X00;
    for(int i=0;i<8;i++){
        digitalWrite(4,LOW);
        digitalWrite(2,str[0]&0b10000000>>i);
        digitalWrite(4,HIGH);
    }
    delay(500);
    for(int i=0;i<8;i++){
        digitalWrite(4,LOW);
        digitalWrite(2,str[1]&0b10000000>>i);
        digitalWrite(4,HIGH);
    }
    delay(500);
}