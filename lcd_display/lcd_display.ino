#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);


void setup() {
  lcd.begin(16, 2);

}

void loop() {
  lcd.setCursor(4, 0);
  lcd.print("THANK YOU");

  lcd.setCursor(0, 1);
  lcd.print("HAVE A GOOD DAY!");
}
