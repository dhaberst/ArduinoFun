/*
  Advertising LED

  A simple program that turns multiple leds on/off in a fun way
*/
int ledPin0 = 2; // define pin 0
int ledPin1 = 3; // define pin 1
int ledPin2 = 4; // define pin 2
int ledPin3 = 5; // define pin 3
int ledPin4 = 6; // define pin 4
int ledPin5 = 7; // define pin 5

void setup() {
  Serial.begin(9600);
  
  // set LEDS pin mode to OUTPUT
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

void loop() {
  for (int i = ledPin0; i < ledPin5 + 1; i++) {
    // Light up current LED
    digitalWrite(i, HIGH);

    // Turn off previous LED
    if (i == ledPin0) {
      digitalWrite(ledPin5, LOW);
    }
    else {
      digitalWrite(i-1, LOW);
    }
    
    delay(70);
  }
}
