#include <LiquidCrystal_PCF8574.h>
#include <Keypad.h>
LiquidCrystal_PCF8574 lcd(0x27);
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {6,7,8,9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3,4,5}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
    pinMode(2, OUTPUT);//buzzer
    lcd.begin(16,2);
    lcd.setBacklight(255);
    lcd.clear();
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
  
    lcd.print(key);
    digitalWrite(2,HIGH);
    delay (200);
    digitalWrite(2,LOW);
      }
}
