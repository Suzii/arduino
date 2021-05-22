const int pinLed1 = 2;
const int pinLed2 = 3;
const int pinLed3 = 4;
const int sensorPin = A1;

const float baseTemp = 11.0;

void lightUp(int numberOfPins) {
  digitalWrite(pinLed1, numberOfPins >= 1);
  digitalWrite(pinLed2, numberOfPins >= 2);
  digitalWrite(pinLed3, numberOfPins >= 3);
}

void setup() {
  Serial.begin(9600);
  
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);

  lightUp(0);
}


void loop() {
  float sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal / 1024.0) * 5.0;
  float temp = (voltage - 0.5) * 100;

  int numberOfLeds = (temp - baseTemp) / 1.5;
  lightUp(numberOfLeds);

  Serial.print("Sensor: ");
  Serial.print(sensorVal);
  Serial.print(" Voltage: ");
  Serial.print(voltage);
  Serial.print(" Temp: ");
  Serial.print(temp);
  Serial.print(" -- ");
  Serial.print(numberOfLeds);
  Serial.println("");

  delay(250);
}
