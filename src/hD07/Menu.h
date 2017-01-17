/* This header file should be used to hold Serial.println items 
 * etc. etc.
 * Julio B. Figueroa
 * University of Nevada, Las Vegas
 * Department of Mechanical Engineering
 */

void menuStart()
{
    Serial.println("Programma du hexapod de joule");
    Serial.println("Please select an item form the menu below");
    Serial.println(" ");
    Serial.flush();
    return;
}

void menuOne()
{
    Serial.println("1: Text one");
    Serial.println("2: Begin wire i2c Transmission");
    Serial.println("3: Bring something different");
    Serial.println("4: Compact 1-servo test");
    Serial.println("5: bank matrix test");
    Serial.println("6: Homeing Test");
    return;
}

void response1()
{
    Serial.println("You look so much better than usual.");
    return;
}

void response2()
{
    Serial.println("Begin wire.tranmission code.");
    Serial.println("Are you ready?");
    return;
}

void response3()
{
    Serial.println("Opps -- you divided by 0, or..");
    return;
}

void response4()
{
    Serial.print("Starting doubleCompactOneServoTest function");
    return;
}

void response5()
{
    Serial.print("Starting bank test function");
}
