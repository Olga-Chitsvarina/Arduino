
#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);


// Declare components that will control LED
const int LED = 9;
bool ELECTRICITY_IS_ON = false;
bool LIGHT_IS_ON = false;
const int BUTTON = 8;
int LAST_BUTTON_STATE = 0;
float time = 0;


// Declare components that will control LCD
const int LCD_BUTTON = 10;
float lcd_time = 0;
bool lcd_is_on = false;


void setup() {
  lcd.begin(16, 2);
  pinMode (LED, OUTPUT);
  pinMode (BUTTON, INPUT);
}


void loop() {  
  // If someone pushed the button, then check last button state
  // If it was off, then turn it on, prepare for blinking, update state
  // If it was on, just update the state:
  
  if(digitalRead(BUTTON)==HIGH){
    if(LAST_BUTTON_STATE == 0){
     ELECTRICITY_IS_ON = !ELECTRICITY_IS_ON;
     digitalWrite(LED, ELECTRICITY_IS_ON);
     LIGHT_IS_ON = true;
     delay(100);
     time = 0;
     LAST_BUTTON_STATE = 1;
    }  
  }else{
    LAST_BUTTON_STATE = 0;
  }

  // Make LED blinking, if it should be working:

  if(ELECTRICITY_IS_ON){
    if(time >= 500){
      LIGHT_IS_ON = !LIGHT_IS_ON;
      digitalWrite(LED, LIGHT_IS_ON);
      time = 0;
    }
    time = time + 0.03f;
  }

  // If LCD button was pressed and LCD does not show any text, then set text, otherwise do nothing
  // To set text: Go to (position, row) and type first half of the message
  // Go to next line, (position, row), type second half of the message
  // Remember that LCD shows text:
  
  if(digitalRead(LCD_BUTTON)==HIGH && !lcd_is_on){
   lcd.clear();
   lcd.setCursor(4, 0);
   lcd.print("THANK YOU");
   lcd.setCursor(0, 1);
   lcd.print("HAVE A GOOD DAY!");
    
   lcd_is_on = true;
   lcd_time = 0;
  }

  // If LCD shows text, then check counter, otherwise do nothing
  // If counter <= 5000 then increment counter
  // If counter > 5000 then clear LCD screen, remember that LCD does not show text:
   
  if(lcd_is_on){
    if (lcd_time <= 5000){
      lcd_time = lcd_time + 0.01f;  
    }else{
      lcd_is_on = false;
      lcd.clear();
    }
  }
      
  
}
