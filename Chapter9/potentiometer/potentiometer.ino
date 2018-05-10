/*
  Potentiometer

  A simple program that takes input from a potentiometer
  and lights an LED depending on the value
*/
int potpin = 0; // define analog pin0
int ledPinRed = 13; // define red led pin13
int ledPinGreen = 12; // define green led pin12
int val = 0; // poteniometer input value

void setup() {
  Serial.begin(9600); // set baud rate 9600
  pinMode(ledPinRed, OUTPUT); // set pin13 output
  pinMode(ledPinGreen, OUTPUT); // set pin12 output
}

void loop() {
  val = analogRead(potpin);// give the value of pin0 to val

  // If the vale is greater or equal to 512 then we switch
  // the green pin off, and the red pin on and vice versa
  if (val >= 512) {
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinGreen, LOW);
  }
  else {
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinGreen, HIGH);
  }
  
  // Serial.println(val) ; // print val
}
