int hapticos[] = {5, 6, 9, 10, 11};

void setup() {

  for (int i = 0; i < 5; i++) {
    pinMode(hapticos[i], OUTPUT);
  }
  for (int i = 0; i < 5; i++) {
    digitalWrite(hapticos[i], HIGH);
    delay(500);
    digitalWrite(hapticos[i], LOW);
    delay(500);
  }


}

void loop() {




}
