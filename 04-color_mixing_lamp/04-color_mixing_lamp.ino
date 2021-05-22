const int redLedPin = 11;
const int greenLedPin = 9;
const int blueLedPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int inR = 0;
int inG = 0;
int inB = 0;

void setup() {
  Serial.begin(9600);

  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);}

void loop() {
  inR = analogRead(redSensorPin);
  delay(10);
  inG = analogRead(greenSensorPin);
  delay(10);
  inB = analogRead(blueSensorPin);

  Serial.print("in -- R: ");
  Serial.print(inR);
  Serial.print("\t G: ");
  Serial.print(inG);
  Serial.print("\t B: ");
  Serial.println(inB8);

  analogWrite(redLedPin, inR/4);
  analogWrite(greenLedPin, inG/4);
  analogWrite(blueLedPin, inB/4);
}
