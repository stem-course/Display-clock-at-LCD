/*
Code by: www.munphurid.com
Syed Rafay Hashmi and Wardah Arshad

This is a code for Clock displayed on LCD

Hardware:
Is bought from www.munphurid.com
-Arduino UNO
-16 male to female wires
-Lcd

Connections:

Connect VSS of Lcdpin to GND of Arduino
Connect VDD of Lcdpin to 5V of Arduino
Connect Vo/ VEE(potentiometer) of Lcdpin to GND of Arduino
Connect RS of Lcdpin to pin12 of Arduino
Connect RW of Lcdpin to GND of Arduino
Connect E of Lcdpin to pin11 of Arduino
D0 TO D3 NOT USED
Connect D4 of Lcdpin to PIN5 of Arduino
Connect D5 of Lcdpin to PIN4 of Arduino
Connect D6 of Lcdpin to PIN3 of Arduino
Connect D7 of Lcdpin to PIN2 of Arduino
Connect LED+/A of Lcdpin to 5V of Arduino
Connect LED-/K of Lcdpin to GND of Arduino
*/


#include <LiquidCrystal.h>                    //Including library for controling LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);       // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
int sec = 0;                  // initial value of second is 0
int minu = 0;                 // initial value of minute is 0
int hrs = 0;                  //initial value of hour is 0

void setup() {
  lcd.begin(16,2);            // Initialize lcd parametes for 16 by 2(16x2) LCD
  }

void loop() {
  
  if (sec < 60){              // if the value of sec is less than 60 then this loop will execute
    delay(1000);              // arduino will sleep for 1 second
    sec += 1;                 // after 1 second, value of sec will increase by 1
   if (sec > 59){
    lcd.clear();
     sec = 0;                 // if the value of sec is 60 then sec will become 0
   }
  }
 if (sec == 59){
  minu += 1;                  // if the value of sec is 59 then the val of minu will increase by 1
   if (minu > 59){
    lcd.clear();
    minu = 0;                 // if the value of minu is greater than 59 then the val of minu will become 0
   }
 }
 if (minu == 59){
  hrs += 1;                   // if the value of min is 59 then the val of hrs will increase by 1
  lcd.clear();
   if (hrs > 23){
    lcd.clear();
    hrs = 0;                  // if the value of hrs is greater than 23 then the val of hrs will become 0
  }
}
lcd.setCursor(0,0);           // Set the cursor of LCD to first line

//Below code will print time on LCD

lcd.print("<DIGITAL CLOCK>");
lcd.setCursor(4,1);           // Set the cursor of LCD to second line
lcd.print(hrs);               //Donot edit this line
lcd.print(":");               //Donot edit this line
lcd.print(minu);              //Donot edit this line
lcd.print(":");               //Donot edit this line
lcd.print(sec);               //Donot edit this line

}
