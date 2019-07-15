const int stepPin1 = 8;
const int dirPin1 = 9;
const int ms1 = 2;
const int ms2 = 3;
const int ms3 = 4;
void setup() {

  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(ms1, OUTPUT);
  pinMode(ms2, OUTPUT);
  pinMode(ms3, OUTPUT);
}

void loop() {


  digitalWrite(dirPin1, HIGH); //モーター正負回転方向指定

  for (int x = 0; x < 200 ; x++) {
 //  digitalWrite(ms1, HIGH);
  // digitalWrite(ms2, HIGH);
  // digitalWrite(ms3, HIGH);
    digitalWrite (stepPin1, HIGH);
    delayMicroseconds(300);

    digitalWrite (stepPin1, LOW);
    delayMicroseconds(300);
  }

  delay(3000);

}
