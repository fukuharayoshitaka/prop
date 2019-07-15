//const int stepPin1 = 32;
//const int dirPin1 = 41;
const int stepPin1 = 24;
const int dirPin1 = 25;
//stepMotor2
const int stepPin2 = 36;
const int dirPin2 = 40;

void setup() {
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  digitalWrite(dirPin1,HIGH); //モーター正負回転方向指定
  digitalWrite(dirPin2, LOW);
}
void loop() {
 
    digitalWrite (stepPin1, HIGH);
    digitalWrite (stepPin2, HIGH); //ステッピングモータはON、OFFの信号をSTEPピンに送ることで１ステップ回転する
    
    //モーターの動作を0.05秒つづける
    delay(50);
 
}
