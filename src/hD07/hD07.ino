//Script to make Hexy work out of an Arudino nano
//If using a different Arudino varient edit the Makefile
//before you upload your binaries

#include <Wire.h>
#include "Unlv.h"       //E.nice, sugar, spice
#include "Menu.h"      //menu

int input, switchVar;
long temps;  //milliseconds
char junk = ' ';

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  menuStart();
}

void loop()
{
    menuOne();
    while(Serial.available() == 0)
    {  //wait  until input buffer has a char
         // by default -1 if no serial data is available
        input = Serial.parseFloat();   //input value, int
        while (Serial.available() > 0)
        {//paraseFloat() can leave non-numberic char
            junk = Serial.read();       //clear the keyboard buffer
        }
            if (input == 1)
            {
                response1();
            }
            else if (input == 2)
            {
                response2();
                oneServoTest();
            }
            else if (input == 3)
            {
               rangeTest(128);
            }
            else if (input == 4)    //This is a test for a compact function
            {
                //doubleCompactOneServoTest();
                Serial.println("twoTest");
                twoTest();
            }
            else if (input == 5)
            {
                Serial.println("bankTest");
                //bankTest();
                bankTest3();
            }
            else if (input == 6)
            {
                Serial.println("Home Robot");
                homeRobot();
            }
            else if (input == 7)
            {
                Serial.print("Home 2");
                cornerset();
            }
    }
}
