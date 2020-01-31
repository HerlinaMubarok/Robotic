/*
o  o o--o   O  o-o    o-o      o   o o--o  
|  | |     / \ |  \  |         |   | |   | 
O--O O-o  o---o|   O  o-o      |   | O--o  
|  | |    |   ||  /      |     |   | |     
o  o o--o o   oo-o   o--o       o-o  o     
                                           
1. If you have a new ATmega328P , you’ll need to burn the bootloader onto the chip first.
Please follow our instructions in the following tutorial:
https://www.circuito.io/blog/atmega328p-bootloader/                                      

2. After uploading the sketches onto the ATMega328P, open the serial monitor and reboot the ATMega328P to view the test code menu.
*/
// Include Libraries
#include "Arduino.h"
#include "LED.h"
#include "Switchable.h"
#include "Button.h"
#include "IRremote.h"
#include "IR.h"
#include "IRremoteInt.h"


// Pin Definitions
#define LEDY_PIN_VIN  3
#define PUSHBUTTON_PIN_2  4
#define IR_PIN_OUT  5
#define PULLPUSHSOLENOIDLARGE_PIN_COIL1 2



// Global variables and defines

// object initialization
LED ledY(LEDY_PIN_VIN);
Button pushButton(PUSHBUTTON_PIN_2);
IR ir(IR_PIN_OUT);



// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pushButton.init();
    // initialize IR device
    ir.init();
    pinMode(PULLPUSHSOLENOIDLARGE_PIN_COIL1, OUTPUT);
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // LED - Basic Yellow 5mm - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
        ledY.dim(i);                      // 1. Dim Led 
        delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledY.off();                        // 3. turns off
    }
    else if(menuOption == '2') {
    // Mini Pushbutton Switch - Test Code
    //Read pushbutton state. 
    //if button is pressed function will return HIGH (1). if not function will return LOW (0). 
    //for debounce funtionality try also pushButton.onPress(), .onRelease() and .onChange().
    //if debounce is not working properly try changing 'debounceDelay' variable in Button.h
    bool pushButtonVal = pushButton.read();
    Serial.print(F("Val: ")); Serial.println(pushButtonVal);

    }
    else if(menuOption == '3') {
    // IR Receiver Diode - TSOP38238 - Test Code
    //Receive IR code into irCode
    long irCode =  ir.detect();
    // if a code was received print it to serial monitor, note that the code is of type long but printed in HEX
    // Consider changing the if statment to something like: if(irCode == "YOUR IR CODE")
    if(irCode)
    {
        Serial.print("0x");
        Serial.println(irCode, HEX);
    }
    }
    else if(menuOption == '4') {
    // Large Push-Pull Solenoid - Test Code
    digitalWrite(PULLPUSHSOLENOIDLARGE_PIN_COIL1, HIGH); //Turn Solenoid on. 
    delay(1000);  //waits 1000 milliseconds (1 sec). change the value in the brackets (1000) for a longer or shorter delay in milliseconds.
    digitalWrite(PULLPUSHSOLENOIDLARGE_PIN_COIL1, LOW); //Turn Solenoid off. 
    delay(1000);  //waits 1000 milliseconds (1 sec). change the value in the brackets (1000) for a longer or shorter delay in milliseconds.
    }
    
    
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) LED - Basic Yellow 5mm"));
    Serial.println(F("(2) Mini Pushbutton Switch"));
    Serial.println(F("(3) IR Receiver Diode - TSOP38238"));
    Serial.println(F("(4) Large Push-Pull Solenoid"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {
            if(c == '1') 
          Serial.println(F("Now Testing LED - Basic Yellow 5mm"));
        else if(c == '2') 
          Serial.println(F("Now Testing Mini Pushbutton Switch"));
        else if(c == '3') 
          Serial.println(F("Now Testing IR Receiver Diode - TSOP38238"));
        else if(c == '4') 
          Serial.println(F("Now Testing Large Push-Pull Solenoid"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/
