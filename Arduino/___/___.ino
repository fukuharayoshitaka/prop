#include <Servo.h>
#include <MsTimer2.h>
/*// センサに応じて左右のモーターを回転
  const int motorA = 11;
  const int motorB = 10;
  const int PWM_motAB = 6;
  const int motorC = 9;
  const int motorD = 8;
  const int PWM_motCD = 5;
  // led
  const int ledA = 13;
  const int ledB = 2;
  //　フォトトランジスタ
  const int sensorA = 2;
  const int sensorB = 3;
  //　センサから読み取った値（analog）
  int valA = 0;
  int valB = 0;
  //　閾値
  int alpha = 100;
  
*/
const int enable1 = 24;
const int enable2 = 25;
const int stepPin1 = 32;
const int dirPin1 = 41;
//stepMotor2
const int stepPin2 = 36;
const int dirPin2 = 40;
void sensa() {
  //  static boolean runt = HIGH;  // プログラム起動前に１回だけHIGH(1)で初期化される

  int sensorValue1 = digitalRead(46);//ここはつないだピン
  int sensorValue2 = digitalRead(48);//ここはつないだピン
  int sensorValue3 = digitalRead(50);//ここはつないだピン
  int sensorValue4 = digitalRead(52);//ここはつないだピン
  int sensorValue5 = digitalRead(47);//ここはつないだピン
  int sensorValue6 = digitalRead(53);//ここはつないだピン

  static boolean output = HIGH;  // プログラム起動前に１回だけHIGH(1)で初期化される

  // digitalWrite(32, output);      // 13番ピン(LED)に出力する(HIGH>ON LOW>OFF)
  //output = !output;

}
void setup() {
  pinMode(enable1, OUTPUT);
   pinMode(enable2, OUTPUT);
  
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  MsTimer2::set(100, sensa);
  MsTimer2::start();
  Serial.begin(9600);
  digitalWrite(enable1, LOW);
   digitalWrite(enable2, LOW);
  
  digitalWrite(dirPin1, HIGH); //モーター正負回転方向指定
  digitalWrite(dirPin2, LOW);
}

void loop() {
  //ledは常にONにしておく


    digitalWrite (stepPin1, HIGH);
    digitalWrite (stepPin2, HIGH); //ステッピングモータはON、OFFの信号をSTEPピンに送ることで１ステップ回転する
    delayMicroseconds(100);//ここを短くすると速度アップ
    digitalWrite (stepPin1, LOW);
    digitalWrite (stepPin2, LOW);
    delayMicroseconds(100);
    //モーターの動作を0.05秒つづける

}
