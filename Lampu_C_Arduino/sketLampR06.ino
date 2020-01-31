#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
lcd.setBacklight(125);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" SELAMAT DATANG ");
lcd.setCursor(0,1);
lcd.print("  Di Stt Nf ");
delay(3000);

  // put your main code here, to run repeatedly:
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" Hey ");
lcd.setCursor(0,1);
lcd.print("  Arlina ");
delay(3000);
}
