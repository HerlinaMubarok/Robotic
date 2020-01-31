#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);
int adc;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
lcd.setBacklight(125);
}

void loop() {
  // put your main code here, to run repeatedly:
adc=analogRead(A3); 
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Nilai=");
lcd.print(adc);
delay(200);

}
