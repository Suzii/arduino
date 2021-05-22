// pins
int redLedA = 2;
int redLedB = 3;
int greenLed = 4;
int switchA = 12;

void setup() {
  pinMode(redLedA, OUTPUT);
  pinMode(redLedB, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchA, INPUT);

}

int switchStateA = LOW;

void loop() {
  switchStateA = digitalRead(switchA);

  if (switchStateA == LOW) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLedA, LOW);
    digitalWrite(redLedB, LOW);
  }
  else {
    digitalWrite(greenLed, LOW);

    // toggle two red switches
    digitalWrite(redLedA, HIGH);
    digitalWrite(redLedB, LOW);

    delay(250);

    digitalWrite(redLedA, LOW);
    digitalWrite(redLedB, HIGH);

    delay(250);
  }
}
