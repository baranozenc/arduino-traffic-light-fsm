int red = 7;
int yellow = 8;
int green = 9;

unsigned long previousTime = 0;
unsigned long currentTime;
unsigned long stateDuration = 5000;

int state = 0;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {

  currentTime = millis();

  // Time-up check
  if (currentTime - previousTime >= stateDuration) {

    state++;

    if (state > 3) {
      state = 0;
    }

    previousTime = currentTime;
  }

// LED control according to state
  switch (state) {

    case 0:  // RED
      digitalWrite(red, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      stateDuration = 5000;
      break;

    case 1:  // RED + YELLOW
      digitalWrite(red, HIGH);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
      stateDuration = 2000;
      break;

    case 2:  // GREEN
      digitalWrite(red, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, HIGH);
      stateDuration = 5000;
      break;

    case 3:  // YELLOW
      digitalWrite(red, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, LOW);
      stateDuration = 2000;
      break;
  }
}
