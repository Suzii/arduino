const int sensorPin = A0;
const int outPin = 8;
const int ledPin = 13;
const int buttonPin = 7;

int on = 1;
int sensorLow = 1023;
int sensorHigh = 0;
int sensorValue;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  digitalWrite(ledPin, HIGH);
  // calibration
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;  
    }
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;  
    }
  }

  digitalWrite(ledPin, LOW);
}

void loop() {
  on = digitalRead(buttonPin);

  if (on) {
    sensorValue = analogRead(sensorPin);
    int pitch = map(sensorValue, sensorLow, sensorHigh, 40, 4000);
    tone(outPin, pitch, 20);
  }
  delay(10);
}
