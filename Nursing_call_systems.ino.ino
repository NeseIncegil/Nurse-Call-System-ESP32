const int patientButton = 2;
const int nurseButton = 3;
const int ledPin = 13;

bool callActive = false;

void setup() {
  pinMode(patientButton, INPUT_PULLUP);
  pinMode(nurseButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(patientButton) == LOW) {
    callActive = true;
  }

  if (digitalRead(nurseButton) == LOW) {
    callActive = false;
  }

  digitalWrite(ledPin, callActive ? HIGH : LOW);

  delay(50);
}