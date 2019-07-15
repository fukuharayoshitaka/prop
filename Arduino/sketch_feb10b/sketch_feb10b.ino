 const int stepPin1 = 32;
const int dirPin1 = 41;
//stepMotor2
const int stepPin2 = 36;
const int dirPin2 = 40;
  void setup() {
    
    pinMode(stepPin1, OUTPUT);
    pinMode(dirPin1, OUTPUT);
    pinMode(stepPin2, OUTPUT);
    pinMode(dirPin2, OUTPUT);

    digitalWrite(dirPin1, HIGH);//左モータ前進
    digitalWrite(dirPin2, LOW);//右モータ前進

  }
  void loop() {

  for (int cou = 0; cou < 400; cou++) {
          digitalWrite (stepPin1, HIGH);
          digitalWrite (stepPin2, HIGH);
          delayMicroseconds(200);
          digitalWrite (stepPin1, LOW);
          digitalWrite (stepPin2, LOW);
          delayMicroseconds(200);
        }
        delay(4000);}
