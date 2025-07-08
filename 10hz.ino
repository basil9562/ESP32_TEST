const int ledPin1 = 2;     // GPIO2
const int ledPin2 = 4;     // GPIO4
const int switchPin1 = 35; // GPIO35
const int switchPin2 = 36; // GPIO36
const int switchPin3 = 39; // GPIO39

bool led1Blink = false;
bool led2Blink = false;

unsigned long previousMillisLed1 = 0;
unsigned long previousMillisLed2 = 0;
unsigned long longPressStart = 0;

bool switch2Pressing = false;
bool longPressHandled = false;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  // ----------- switchPin1: Start blinking ledPin2 at 10Hz if ledPin1 is OFF -----------
  if (digitalRead(switchPin1) == LOW && !led1Blink) {
    led2Blink = true;
    led1Blink = false;
    digitalWrite(ledPin1, LOW); // ensure mutual exclusivity
  }

  // ----------- switchPin2: Detect press start -----------
  if (digitalRead(switchPin2) == LOW && !switch2Pressing) {
    switch2Pressing = true;
    longPressStart = currentMillis;
    longPressHandled = false;
  }

  // ----------- switchPin2: While being pressed -----------
  if (switch2Pressing && digitalRead(switchPin2) == LOW) {
    if (!longPressHandled && currentMillis - longPressStart >= 2000) {
      // Handle long press immediately after 2 sec
      led1Blink = false;
      digitalWrite(ledPin1, LOW);
      longPressHandled = true;
    }
  }

  // ----------- switchPin2: On release -----------
  if (switch2Pressing && digitalRead(switchPin2) == HIGH) {
    if (!longPressHandled) {
      // It was a short press
      led2Blink = false;
      digitalWrite(ledPin2, LOW);
    }
    switch2Pressing = false;
    longPressHandled = false;
  }

  // ----------- switchPin3: On release, blink ledPin1 at 2Hz if ledPin2 is OFF -----------
  static bool lastSwitch3State = HIGH;
  bool currentSwitch3State = digitalRead(switchPin3);
  if (lastSwitch3State == LOW && currentSwitch3State == HIGH && !led2Blink) {
    led1Blink = true;
    led2Blink = false;
    digitalWrite(ledPin2, LOW); // ensure mutual exclusivity
  }
  lastSwitch3State = currentSwitch3State;

  // ----------- Blink ledPin2 at 10Hz (50ms) -----------
  if (led2Blink && currentMillis - previousMillisLed2 >= 50) {
    previousMillisLed2 = currentMillis;
    digitalWrite(ledPin2, !digitalRead(ledPin2));
  }

  // ----------- Blink ledPin1 at 2Hz (250ms) -----------
  if (led1Blink && currentMillis - previousMillisLed1 >= 250) {
    previousMillisLed1 = currentMillis;
    digitalWrite(ledPin1, !digitalRead(ledPin1));
  }
}
