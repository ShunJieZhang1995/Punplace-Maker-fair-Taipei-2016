// BTremote.ino
#include "SoftwareSerial.h"
#define BT_RX 5  //D5
#define BT_TX 3  //D3
#define bottom 14 //A0
#define X 15 //A1
#define Y 16 //A2
SoftwareSerial BTSerial(BT_RX,BT_TX);
void setup() {
	BTSerial.begin(9600);
	Serial.begin(9600);
	pinMode(14, INPUT);
	pinMode(15, INPUT);
	pinMode(16, INPUT);
	delay(1000);
}

void loop() {
	int x,y,b;
	b = analogRead(14);
	x = analogRead(15);
	y = analogRead(16);
	if(b>1000){
	    BTSerial.write('6');
	    delay(600);
	}else if(x>1000){
		BTSerial.write('3');
	}else if(x<100){
		BTSerial.write('4');
	}else if(y>1000){
		BTSerial.write('1');
	}else if(y<100){
        BTSerial.write('2');
	}else{
		BTSerial.write('5');
	}
	delay(600);

}

