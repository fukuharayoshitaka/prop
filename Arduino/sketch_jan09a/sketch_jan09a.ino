const int stepPin1 = 30;
const int dirPin1 = 41;
const int stepPin2 = 36;
const int dirPin2 = 40;



void setup() {
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}
void loop() {

  digitalWrite(dirPin1, HIGH); //モーター正負回転方向指定
  digitalWrite(dirPin2, LOW);

  for (int x = 0; x < 1697; x++) {
    digitalWrite (stepPin2, HIGH);
    digitalWrite (stepPin1, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin2, LOW);
    digitalWrite (stepPin1, LOW);
    delayMicroseconds(400);
  }
  for (int x = 0; x < 6971; x++) {
    digitalWrite (stepPin2, HIGH);
    digitalWrite (stepPin1, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin2, LOW);
    digitalWrite (stepPin1, LOW);
    delayMicroseconds(400);
  }
   for (int x = 0; x < 1697; x++) {
    digitalWrite (stepPin2, HIGH);
    digitalWrite (stepPin1, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin2, LOW);
    digitalWrite (stepPin1, LOW);
    delayMicroseconds(400);
  }
  

  delay(5000);
  digitalWrite(dirPin1, LOW); //モーター正負回転方向指定
  digitalWrite(dirPin2, HIGH);
 for (int x = 0; x < 1697; x++) {
    digitalWrite (stepPin2, HIGH);
    digitalWrite (stepPin1, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin2, LOW);
    digitalWrite (stepPin1, LOW);
    delayMicroseconds(400);
  }
  for (int x = 0; x < 6971; x++) {
    digitalWrite (stepPin2, HIGH);
    digitalWrite (stepPin1, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin2, LOW);
    digitalWrite (stepPin1, LOW);
    delayMicroseconds(400);
  }
   for (int x = 0; x < 1697; x++) {
    digitalWrite (stepPin2, HIGH);
    digitalWrite (stepPin1, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin2, LOW);
    digitalWrite (stepPin1, LOW);
    delayMicroseconds(400);
  } delay(5000);
}
