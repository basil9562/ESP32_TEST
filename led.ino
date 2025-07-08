const int buttonPin = 34;   // SWITCH1
const int redLed = 4;     // RGB_R
const int greenLed = 2;   // RGB_G
const int blueLed = 13;    // RGB_B

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {  // button pressed
    unsigned long pressStart = millis();
    while (digitalRead(buttonPin) == LOW) {
      // wait until button released
    }
    unsigned long pressDuration = millis() - pressStart;

    if (pressDuration >= 10000) {
      blinkLed(redLed);
    } else if (pressDuration >= 5000) {
      blinkLed(blueLed);
    } else if (pressDuration >= 1000) {
      blinkLed(greenLed);
    }
  }
}

void blinkLed(int ledPin) {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
}
