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
#define BT_RX 3  //D3
#define RE_TX 5  //D5
#define R_pos 6  //D6
#define R_ant 9  //D9
#define L_pos 10 //D10
#define L_ant 11 //D11

#define photocell 14   //A0

#define led_1 7 //D7
#define led_2 8 //D8
#define led_3 12 //D12

#define laser 13 //D13

#define res_pin 2 //D2

#define photo_limit 950

SoftwareSerial BTSerial(BT_RX,RE_TX);

int BTinput;
int HP = 3;
unsigned long HP_time = 0;
unsigned long laser_time = 0;
void setup() {
	Serial.begin(9600);
	BTSerial.begin(9600);
	pinMode(R_pos, OUTPUT);
    pinMode(R_ant, OUTPUT);
    pinMode(L_pos, OUTPUT);
    pinMode(L_ant, OUTPUT);
    pinMode(led_1, OUTPUT);
    pinMode(led_2, OUTPUT);
    pinMode(led_3, OUTPUT);
    pinMode(laser, OUTPUT);
    pinMode(res_pin, INPUT);
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);

}

void loop() {
	if(BTSerial.available() > 0){
	    BTinput = BTSerial.read();
	}
	switch (BTinput) {
	    case '1': //forward
	    analogWrite(R_pos, 225);
        analogWrite(R_ant, 0);
        analogWrite(L_pos, 225);
        analogWrite(L_ant, 0);
	      break;

	    case '2': //back
	    analogWrite(R_pos, 0);
        analogWrite(R_ant, 225);
        analogWrite(L_pos, 0);
        analogWrite(L_ant, 225);
	      break;

	    case '3': //right
	    analogWrite(R_pos, 0);
        analogWrite(R_ant, 225);
        analogWrite(L_pos, 225);
        analogWrite(L_ant, 0);
	      break;

	    case '4': //left
	    analogWrite(R_pos, 255);
        analogWrite(R_ant, 0);
        analogWrite(L_pos, 0);
        analogWrite(L_ant, 255);
	      break;

	    case '5': //stop
	    analogWrite(R_pos, 0);
        analogWrite(R_ant, 0);
        analogWrite(L_pos, 0);
        analogWrite(L_ant, 0);

	      break;

	    case '6': //laser
	    digitalWrite(laser, HIGH);
	    delay(1000);  
	    digitalWrite(laser, LOW);
	      break;

	}

	if(analogRead(photocell) > photo_limit && millis()-2000 > HP_time){
		HP_time = millis();
		HP -= 1;
		switch (HP) {
		    case 2:
		      digitalWrite(led_1, LOW);
		      break;
		    case 1:
		      digitalWrite(led_2, LOW);
		      break;
		    case 0:
		      digitalWrite(led_3, LOW);
		      HP = 3;
		      while(true){
		      	if(digitalRead(res_pin) == HIGH){
		      	  break;
		      	}
		      	digitalWrite(led_1, HIGH);
		      	digitalWrite(led_2, HIGH);
		      	digitalWrite(led_3, HIGH);
		      	delay(500);
		      	digitalWrite(led_1, HIGH);
		      	digitalWrite(led_2, HIGH);
		      	digitalWrite(led_3, HIGH);
		      	delay(500);
		      }
		      HP_time = millis();

		      break;

		}
	}
	delay(500);
}

