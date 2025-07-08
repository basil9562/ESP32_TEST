// Touch sensor GPIOs
#define TOUCH1_PIN 15
#define TOUCH2_PIN 14
#define TOUCH3_PIN 12

// LED output GPIOs
#define LED1_PIN 2
#define LED2_PIN 4
#define LED3_PIN 13

// Touch threshold (adjust if needed)
#define TOUCH_THRESHOLD 40

void setup() {
  Serial.begin(115200);

  // Initialize LED pins as output
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  // Optional: print initial touch values
  Serial.println("Touch sensor initialized...");
}

void loop() {
  int t1 = touchRead(TOUCH1_PIN);
  int t2 = touchRead(TOUCH2_PIN);
  int t3 = touchRead(TOUCH3_PIN);

  // Debugging values
  Serial.printf("T1: %d, T2: %d, T3: %d\n", t1, t2, t3);

  // Control LEDs based on touch value
  digitalWrite(LED1_PIN, t1 < TOUCH_THRESHOLD ? HIGH : LOW);
  digitalWrite(LED2_PIN, t2 < TOUCH_THRESHOLD ? HIGH : LOW);
  digitalWrite(LED3_PIN, t3 < TOUCH_THRESHOLD ? HIGH : LOW);

  delay(100);  // Debounce
}
