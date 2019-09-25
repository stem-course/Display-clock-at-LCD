/*
Code by: 
Syed Rafay Hashmi and Wardah Arshad

This is a code for Clock displayed on LCD

Hardware:
Is bought from www.munphurid.com
-Arduino UNO
-16 male to female wires
-LCD

Connections:

LCD and Arduino
•	Connect pin 1 of LCD to GND of Arduino.
•	Connect pin 2 of LCD to 5V of Arduino.
•	Connect pin 3 of LCD to centre leg of pot. Connect one of the remaining legs of pot (potentiometer) to GND of Arduino 
and the third leg of pot to 5V of Arduino.
•	Connect pin 4 (RS) of LCD to pin 12 of Arduino.
•	Connect pin 5 (RW) of LCD to GND of Arduino.
•	Connect pin 6 (E) of LCD to pin 11 of Arduino.
•	Connect pin 11 (D4) of LCD to pin 5 of Arduino.
•	Connect pin 12 (D5) of LCD to pin 4 of Arduino.
•	Connect pin 13 (D6) of LCD to pin 3 of Arduino.
•	Connect pin 14 (D7) of LCD to pin 2 of Arduino.
•	Connect pin 15 of LCD to pin 5V of Arduino.
•	Connect pin 16 of LCD to pin GND of Arduino.

*/

#include <LiquidCrystal.h>                    //Including library for controling LCD
int RS = 12;     //connect RS of LCD to this pin
int E = 11;      //connect E of LCD to this pin
int D4 = 5;      //connect D4 of LCD to this pin
int D5 = 4;      //connect D5 of LCD to this pin
int D6 = 3;      //connect D6 of LCD to this pin
int D7 = 2;      //connect D7 of LCD to this pin
 
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

int sec = 0;                  // initial value of second is 0
int minu = 0;                 // initial value of minute is 0
int hrs = 0;                  //initial value of hour is 0

void setup() {
  lcd.begin(16,2);            // Type of LCD
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
