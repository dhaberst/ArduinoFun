/*
  Buzzer Siren

  A simple program that generates a siren from a buzzer
*/
int buzzer = 7;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT); // define pin as output
}

void loop() {
  while(1) {
    for (int i = 0; i < 256; i++) {
      digitalWrite(buzzer, i);
    }
    for (int i = 255; i >= 0; i--) {
      digitalWrite(buzzer, i);
    }
  }
}
