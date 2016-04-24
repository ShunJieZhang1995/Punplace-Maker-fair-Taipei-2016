/*== == == == == == == == == == == == == == == == == == == == === == ==
*
*        arduino_tank_Maker_Fair_2016.ino
*        Created : 4 / 25 / 2016
*        Compiler : Arduino 1.0.6
*        IDE:sublime text 2
*        Hardware: Arduino Nano
*        OS : windows 10
*        Author : 張舜傑(xcv123321@gmail.com)
*        Organization : Punplace
*        Description : For Maker Fair Taipei 2016
*
* == == == == == == == == == == == == == == == == == == == == == == == ==*/
#include "SoftwareSerial.h"
#define BT_RX 3
#define RE_TX 5
#define R_pos 6  //D6
#define R_ant 9  //D9
#define L_pos 10 //D10
#define L_ant 11 //D11
#define photocell 14   //A0
#define photo_limit 950
SoftwareSerial BTSerial(BT_RX,RE_TX);

int BTinput;
int HP = 5;
void setup() {
	Serial.begin(9600);
	BTSerial.begin(9600);
	pinMode(R_pos, OUTPUT);
    pinMode(R_ant, OUTPUT);
    pinMode(L_pos, OUTPUT);
    pinMode(L_ant, OUTPUT);
}

void loop() {
	if(BTSerial.available() > 0){
	    BTinput = BTSerial.read();
	}
	switch (BTinput) {
	    case '1'://forward
	      
	      break;
	    case '2'://back
	      
	      break;
	    case '3'://right
	      
	      break;
	    case '4'://left
	      
	      break;
	    case '5'://stop
	    analogWrite(R_pos, 0);
        analogWrite(R_ant, 0);
        analogWrite(L_pos, 0);
        analogWrite(L_ant, 0);

	      break;
	    case '6'://laser
	      
	      break;

	}

	if(analogRead(photocell) > photo_limit){
		HP -= 1;
	}
}

