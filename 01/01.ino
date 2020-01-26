

const int LED = 9;
bool ELECTRICITY_IS_ON = false;
bool LIGHT_IS_ON = false;

const int BUTTON = 3;
int LAST_BUTTON_STATE = 0;

float time = 0;


void setup() {
  pinMode (LED, OUTPUT);
  pinMode (BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTON) == HIGH) {
    if (LAST_BUTTON_STATE == 0) {
      ELECTRICITY_IS_ON = !ELECTRICITY_IS_ON;
      digitalWrite(LED, ELECTRICITY_IS_ON);
      LIGHT_IS_ON = true;
      delay(100);
      time = 0;
      LAST_BUTTON_STATE = 1;
    }
  } else {
    LAST_BUTTON_STATE = 0;
  }

  if (ELECTRICITY_IS_ON) {
    if (time >= 500) {
      LIGHT_IS_ON = !LIGHT_IS_ON;
      digitalWrite(LED, LIGHT_IS_ON);
      time = 0;
    }
    time = time + 0.03f;
  }

}
