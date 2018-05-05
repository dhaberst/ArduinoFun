/*
  Fade LED

  A simple program that fades an led on and off
*/
int brightness = 0; // original value of led brightness
int fadeAmount = 5; // amount of brightness variation
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT); // define pin as output
}

void loop() {
  analogWrite(ledPin, brightness);

  brightness += fadeAmount;

  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount; // change the direction of the brightness
  }

  delay(30);
}
