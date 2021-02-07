#define TRIGGER 6
#define ECHO 7

int inches, duration;

void setup() {
  Serial.begin(9600);
  for (int i = 8; i <= 13; i++)
    pinMode(i, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  duration = pulseIn(ECHO, HIGH);

  inches = (duration / 2) / 74;
  if (inches < 6) {
    Serial.print("b");
  } else {
    Serial.print("a");
  }

  for (int i = 0; i <= 6; i++) {
    if (inches > i + 1) {
      digitalWrite(i + 8, HIGH);
    } else {
      digitalWrite(i + 8, LOW);
    }
  }

  delay(500);
}
