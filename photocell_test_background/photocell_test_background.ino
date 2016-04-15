/*== == == == == == == == == == == == == == == == == == == == === == ==
*
*        photocell_test_background.ino
*        Created : 4 / 15 / 2016
*        Compiler : Arduino 1.0.6
*        IDE:sublime text 2
*        Hardware: Arduino UNO
*        OS : windows 10
*        Author : 張舜傑(xcv123321@gmail.com)
*        Organization : Punplace
*        Description : For Maker Fair Taipei 2016
*
* == == == == == == == == == == == == == == == == == == == == == == == ==*/

int photocellPin = 2; // 光敏電阻 (photocell) 接在 anallog pin 2
int photocellVal = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	photocellVal = analogRead(photocellPin);

	Serial.println(photocellVal); 

	delay(1000);      

}

