/*
  Potentiometer

  A simple program that takes input from a potentiometer
  and lights an LED depending on the value
*/
// the pin to control ROW
const int row1 = 2; // the number of the row pin 9
const int row2 = 3; // the number of the row pin 14
const int row3 = 4; // the number of the row pin 8
const int row4 = 5; // the number of the row pin 12
const int row5 = 17; // the number of the row pin 1
const int row6 = 16; // the number of the row pin 7
const int row7 = 15; // the number of the row pin 2
const int row8 = 14; // the number of the row pin 5
// the pin to control COl
const int col1 = 6; // the number of the col pin 13
const int col2 = 7; // the number of the col pin 3
const int col3 = 8; // the number of the col pin 4
const int col4 = 9; // the number of the col pin 10
const int col5 = 10; // the number of the col pin 6
const int col6 = 11; // the number of the col pin 11
const int col7 = 12; // the number of the col pin 15
const int col8 = 13; // the number of the col pin 16
void setup() {
  for (int i = 2; i < 18; i++) {
    pinMode(i, OUTPUT);
  }
  
  pinMode(row5, OUTPUT);
  pinMode(row6, OUTPUT);
  pinMode(row7, OUTPUT);
  pinMode(row8, OUTPUT);
 
  for (int i = 2; i < 18; i++) {
    digitalWrite(i, LOW);
  }
 
 digitalWrite(row5, LOW);
 digitalWrite(row6, LOW);
 digitalWrite(row7, LOW);
 digitalWrite(row8, LOW);
}

void loop() {
  digitalWrite(row1, HIGH);
  digitalWrite(row2, HIGH);
  digitalWrite(row3, HIGH);
  digitalWrite(row4, HIGH);
  digitalWrite(row5, HIGH);
  digitalWrite(row6, HIGH);
  digitalWrite(row7, HIGH);
  digitalWrite(row8, HIGH);
  digitalWrite(col1, HIGH);
  digitalWrite(col2, HIGH);
  digitalWrite(col3, HIGH);
  digitalWrite(col4, HIGH);
  digitalWrite(col5, HIGH);
  digitalWrite(col6, HIGH);
  digitalWrite(col7, HIGH);
  digitalWrite(col8, HIGH);
  
  delay(1000);
}
