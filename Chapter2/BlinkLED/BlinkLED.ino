/*
  Blink LED

  A simple program that blinks on and off
*/
int ledPin = 13; // define pin 13

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // define interface as output
}

void loop() {
  digitalWrite(ledPin, HIGH); // light up led light
  delay(1000); // delay 1s
  digitalWrite(ledPin, LOW); // turn off led light
  delay(1000);
}
