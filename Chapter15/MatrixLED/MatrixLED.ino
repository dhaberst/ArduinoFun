/*
  Matrix LED

  A simple program that loops through each of columns and rows and lights it up.

  Code from: http://arduino-er.blogspot.ca/2015/01/how-to-identify-pin-1-of-8x8-led-matrix.html
  Accessed: 05/14/2018
*/

// 2-dimensional array of row pin numbers:
const int row[8] = {
  2, 7, 19, 5, 13, 18, 12, 16
};

// 2-dimensional array of column pin numbers:
const int col[8] = {
  6, 11, 10, 3, 17, 4, 8, 9
};

// 2-dimensional array of pixels:
int pixels[8][8];

int posX = 7;
int posY = 7;
int count = 30;
bool bg = false;
long previousTime = 0;
long interval = 500;
bool isWinking = false;

void setup()
{
  Serial.begin(9600);
  // initialize the I/O pins as outputs
  // iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
    // take the col pins (i.e. the cathodes) high to ensure that
    // the LEDS are off:
    digitalWrite(col[thisPin], HIGH);
  }

  bg = false;

  setupScreen();
  print(pixels);
}

void print(int matrix[8][8])
{
  int i, j;
  for (i = 0; i < 8; ++i)
  {
    for (j = 0; j < 8; ++j)
      Serial.print(matrix[i][j]);
    Serial.print("\n");
  }
}

void smiley1() {
  int temp[8][8] = {
    {LOW , LOW , HIGH, HIGH, HIGH, HIGH, LOW , LOW },
    {LOW , LOW , HIGH, HIGH, HIGH, HIGH, LOW , LOW },
    {LOW , LOW , HIGH, HIGH, HIGH, HIGH, LOW , LOW },
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
    {HIGH, LOW , HIGH, HIGH, HIGH, HIGH, LOW , HIGH},
    {HIGH, LOW , LOW , LOW , LOW , LOW , LOW , HIGH}
  };

  copyToPixels(temp);
}

void smileyWink() {
  int temp[8][8] = {
    {LOW , LOW , HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
    {LOW , LOW , HIGH, HIGH, HIGH, HIGH, LOW , LOW },
    {LOW , LOW , HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH},
    {HIGH, LOW , HIGH, HIGH, HIGH, HIGH, LOW , HIGH},
    {HIGH, LOW , LOW , LOW , LOW , LOW , LOW , HIGH}
  };

  copyToPixels(temp);
}

void loop()
{
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    previousTime = currentTime;

    if (isWinking) {
      smiley1();
    } else {
      smileyWink();
    }

    isWinking = !isWinking;
  }

  refreshScreen();
}

void copyToPixels(int a[8][8]) {
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = a[x][y];
    }
  }
}

void setupScreen()
{
  if (bg) {
    //ON all others
    for (int x = 0; x < 8; x++) {
      for (int y = 0; y < 8; y++) {
        pixels[x][y] = LOW;
      }
    }
  }
  else {
    //OFF all others
    for (int x = 0; x < 8; x++) {
      for (int y = 0; y < 8; y++) {
        pixels[x][y] = HIGH;
      }
    }
  }
}

void refreshScreen()
{
  // iterate over the rows (anodes):
  for (int thisRow = 0; thisRow < 8; thisRow++) {
    // take the row pin (anode) high:
    digitalWrite(row[thisRow], HIGH);
    // iterate over the cols (cathodes):
    for (int thisCol = 0; thisCol < 8; thisCol++) {
      // get the state of the current pixel;
      int thisPixel = pixels[thisRow][thisCol];
      // when the row is HIGH and the col is LOW,
      // the LED where they meet turns on:
      digitalWrite(col[thisCol], thisPixel);
      // turn the pixel off:
      if (thisPixel == LOW) {
        digitalWrite(col[thisCol], HIGH);
      }
    }
    // take the row pin low to turn off the whole row:
    digitalWrite(row[thisRow], LOW);
  }
}
