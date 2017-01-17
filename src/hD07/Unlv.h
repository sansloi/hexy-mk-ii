/* This header file will hold the motorCtrl's register value
 * & a few necessary functions
 *Author: Julio B. Figueroa
 *University of Nevada, Las Vegas
 *Department of Mechanical Engineering
 */
#include <stdio.h>
#include <stdlib.h>
#define ADDRESS 0x61    //address of the SD21
// Below are the registers used for the SD21 in hex values
// for more information look at register chart in report
//      NAME    HEX      DEC    PIN-VALUE
#define Y1P0    0x3F  // 63     S1      note: bottom yaw
#define Y1P1    0x40  // 64     S2      note: femur
#define Y1P2    0x41  // 65     S3      note: tribia

#define Y2P0    0x42  // 66     S4
#define Y2P1    0x43  // 67     S5
#define Y2P2    0x44  // 68     S6

#define Y3P0    0x45  // 69     S7
#define Y3P1    0x46  // 70     S8
#define Y3P2    0x47  // 71     S9

#define Y4P0    0x48  // 72     S10
#define Y4P1    0x49  // 73     S11
#define Y4P2    0x4a  // 74     S12

#define Y5P0    0x4b  // 75     S13
#define Y5P1    0x4c  // 76     S14
#define Y5P2    0x4d  // 77     S15

#define Y6P0    0x4e  // 78     S16
#define Y6P1    0x4f  // 79     S17
#define Y6P2    0x50  // 80     S18

#define Y7P0    0x51  // 81     S19     note: mount yaw
#define Y7P1    0x52  // 82     S20     note: mount pitch

#define delayVal 5000

/* for low resource MCs eq. is Y = X*6+732,
 * so the Y range goes from 730@X=0 to 2267@X=225
 * Let's try to avoid the extremes, 1500 = center
 * The Y values represent PWM pulse widths in micro-sec
*/
void oneServoTest()
{
    Wire.beginTransmission(ADDRESS);
        Wire.write(Y1P0);           //bottom yaj
        Wire.write(255);            //PWM = 2267 micro-sec = 2.267 ms
    Wire.endTransmission();
    delay(delayVal);

    Wire.beginTransmission(ADDRESS);
        Wire.write(Y1P0);
        Wire.write(128);
    Wire.endTransmission(ADDRESS);
    delay(delayVal);

    Wire.beginTransmission(ADDRESS);
        Wire.write(Y1P0);
        Wire.write((byte)0);
    Wire.endTransmission(ADDRESS);
    delay(delayVal);

    Wire.beginTransmission(ADDRESS);
        Wire.write(Y1P0);
        Wire.write(128);
    Wire.endTransmission();
    delay(delayVal);
    return;
}

void compactOneServoTest(int servoNum, int pos, int delayAmt)
{
    Wire.beginTransmission(ADDRESS);
        Wire.write(servoNum);
        Wire.write(pos);
    Wire.endTransmission();
    delay(delayAmt);
    return;
}

void wire(int servoNum, int pos )   //no delay at end
{
    Wire.beginTransmission(ADDRESS);
        Wire.write(servoNum);
        Wire.write(pos);
    Wire.endTransmission();
    return;
}

void rangeTest(int num)    //use to map outputs for indy motors
{
    Serial.println("Begin Range Test, input num value");
    int countflag = 0; //test var
    while(Serial.available()==0)
    {
        num = Serial.parseFloat();
        Serial.print("num = ");
        Serial.println(num);
        while (Serial.available() > 0)
        {
            if(num <=250 && num >= 0)
            {
                wire(Y1P0, num);
                delay(200);
            }
            Serial.println("run value = ");
            Serial.println(countflag);
            countflag = countflag + 1;
            return;
        }
    }
}

void doubleCompactOneServoTest()
{
    compactOneServoTest(Y1P0, 228, 2000);
    compactOneServoTest(Y1P0, 128, 2000);
    //compactOneServoTest(Y1P0, (byte)0, 2000); //byte 0's, err o.w.
    compactOneServoTest(Y1P0, 28, 2000);
    compactOneServoTest(Y1P0, 128, 2000);     //should reset pos
    return;
}

void twoTest()
{
    compactOneServoTest(Y1P0, 228, 2000);
    compactOneServoTest(Y1P0, 128, 2000);
    compactOneServoTest(Y1P0, 28, 2000);
    compactOneServoTest(Y1P0, 128, 2000);     //should reset pos

    compactOneServoTest(Y1P1, 228, 2000);
    compactOneServoTest(Y1P1, 128, 2000);
    compactOneServoTest(Y1P1, 28, 2000);
    compactOneServoTest(Y1P1, 128, 2000);     //should reset pos
    return;
}

void bankTest()
{
    //int bank[4] = {228, 128, 28, 128};
    int bank[5] = {255, 1, 255, 1, 128};
    for(int ic = 0; ic < 5; ic++)
    {
    compactOneServoTest(Y1P0, bank[ic], 1000);
    Serial.print("ic : ");
    Serial.println(ic);
    }
    return;
}

/* my mirror function, works 99% of the time, iffi 128 = center */
int mir(int mirIn)
{
    int result;
    result = mirIn- 2*mirIn+ 256;
    return result;
}

void bankTest3()
{
//    int bank[4] = {188, 128, 68, 128};
    int bank[4] = {188, 128, 188, 128};
    int bank2[4] = {mir(bank[0]), mir(bank[1]), mir(bank[2]),mir(bank[3])};
    //lesson: initate at 0, but recall at 1 
    for(int ic = 0; ic < 4; ic++)
    {
   // wire(63, bank[ic]);     //Y1P0
    //wire(72, bank2[ic]);    //Y4P0
        wire(64, bank[ic]);
        wire(73, bank2[ic]);
        Serial.print("ic : ");
        Serial.println(ic);
        delay(1000);    //have a delay if using wire function!!!
    }
    return;
}

void homeRobot()
{
    int homeBank[20] = {128};
    //int bank2[4] = {mir(228), mir(128), mir(28),mir(128)};
    for(int ic = 0; ic <= 0; ic++) //just once
    {
        for(int jc = 63; jc <= 82 ; jc ++)
        {
            wire(jc, homeBank[ic]);
            Serial.print("ic :");
            Serial.print(ic);
            Serial.print("jc : ");
            Serial.println(jc);
            //delay(1000);    //have a delay if using wire function!!!
        }
        delay(1000);        //but keep it outside jc set, mistakes were made..
        Serial.print("set complete");
    }
    return;
}

void cornerset()    //make use home plays before this
{
    int h2b =   28;     //forward extreme
        wire(63, h2b);
        wire(69, mir(h2b));
        wire(72, mir(h2b));
        wire(78, h2b);
        delay(1000);
        delay(1000);        //but keep it outside jc set, mistakes were made..
    return;
}

