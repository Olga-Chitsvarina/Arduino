
#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

const int LED = 9;
bool ELECTRICITY_IS_ON = false;
bool LIGHT_IS_ON = false;

const int BUTTON = 8;
int LAST_BUTTON_STATE = 0;

const int LED_BUTTON = 10;
float led_time = 0;
bool LED_IS_ON = false;

float time = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode (LED, OUTPUT);
  pinMode (BUTTON, INPUT);
//  Serial.begin(9600);
}

void loop() {  
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

  if(ELECTRICITY_IS_ON){
    if(time >= 500){
      LIGHT_IS_ON = !LIGHT_IS_ON;
      digitalWrite(LED, LIGHT_IS_ON);
      time = 0;
    }
    time = time + 0.03f;
  }

  if(digitalRead(LED_BUTTON)==HIGH && !LED_IS_ON){
   lcd.clear();
   lcd.setCursor(4, 0);
   lcd.print("THANK YOU");
   lcd.setCursor(0, 1);
   lcd.print("HAVE A GOOD DAY!");
    
   LED_IS_ON = true;
   led_time = 0;
  }

  if(LED_IS_ON){
    if (led_time <= 5000){
      led_time = led_time + 0.01f;  
    }else{
      LED_IS_ON = false;
      lcd.clear();
    }
  }
      
  
}
