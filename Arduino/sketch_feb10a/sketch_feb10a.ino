#include <VarSpeedServo.h>
#include <MsTimer2.h>
VarSpeedServo myservo1;  //2番。ハンド開閉（90：閉じる、120：開く）
VarSpeedServo myservo2; //3番。ハンド持ち上げ(0:下げ、120:上げ)
VarSpeedServo myservo3; //13番。仕分け皿（85：中心、145：青、25：赤）
VarSpeedServo myservo4; //4番。青箱
VarSpeedServo myservo5; //5番。黄箱
VarSpeedServo myservo6; //6番。赤箱

const int stepPin1 = 32;
const int dirPin1 = 41;
//stepMotor2
const int stepPin2 = 36;
const int dirPin2 = 40;



  
int mod = 1; //モード管理（0:待機、1:ライントレース（行き）、2:ボール探し、取る、3:ボールを相手のゴールにｼｭｩｩｩｩｩｩｩｩｳｳｳｳｳｳｳｳｳｳ！）
int n = 0; //黒線カウンタ
int a = 1;
int b = 6;
int c = 12;
int omawari = 0; //ボール探しの際に角度を変えた数
double dat;
double deg; //回転の際の回転角度[°]
double l; //進行距離[mm]
double col; //色情報（1:青 2:黄 3:赤）
int red = 0; //取った赤ボールの数
int blue = 0; //取った青ボールの数
int yellow = 0; //取った黄ボールの数
int redbox = 0; //箱の赤ボールの数
int bluebox = 0; //箱の青ボールの数
int yellowbox = 0; //箱の黃ボールの数

void sensa() {
  int sensorValue1 = digitalRead(46);
  int sensorValue2 = digitalRead(48);
  int sensorValue3 = digitalRead(50);
  int sensorValue4 = digitalRead(52);
  int sensorValue5 = digitalRead(47);
  int sensorValue6 = digitalRead(53);
  static boolean output = HIGH;
}

void setup() {
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(13);
  myservo4.attach(4);
  myservo5.attach(5);
  myservo6.attach(6);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);

  MsTimer2::set(100, sensa);
  MsTimer2::start();
  digitalWrite(dirPin1, HIGH);//左モータ前進
  digitalWrite(dirPin2, LOW);//右モータ前進
  Serial.begin(9600);
}

/*==============================サブルーチン（必ずloop文の前に書くこと）==============================*/
double miri = 23.6882;  //1mm進むために必要なステップ数
double senkai = 58.5013;  //1°回転する際に必要なステップ数

void seri(void) { //受け取った信号を使える形に
  bool minus = 0;
  int data_size = 10;  //適当に10桁
  int i = 0;
  dat = 0;
  byte buf[data_size];
  while (1) {
    if (Serial.available() > 0) {
      buf[i] = Serial.read() - '0';
      if (buf[i] == 253) minus = 1;
      if (buf[i] == 53) break;
      i++;
    }
  }
  double dub = 1;
  for (int n = 0; n < i; n++) {
    Serial.print(buf[n]);
  }
  for (int j = 0; j < (i - minus); j++) {
    dat += double(buf[(i - 1) - j]) * dub;
    dub = dub * 10;
  }
  if (minus)dat *= -1;
}

void zen(double l) {  //l[mm]だけ前進する
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, LOW);
  for (int cou = 0; cou < l * miri ; cou++) {
    digitalWrite (stepPin1, HIGH);
    digitalWrite (stepPin2, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin1, LOW);
    digitalWrite (stepPin2, LOW);
    delayMicroseconds(400);
  }
}

void kou(double l) {  //l[mm]だけ後退する
  digitalWrite(dirPin1, LOW);   //左後退
  digitalWrite(dirPin2, HIGH);  //右後退
  for (int cou = 0; cou < l * miri ; cou++) {
    digitalWrite (stepPin1, HIGH);
    digitalWrite (stepPin2, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin1, LOW);
    digitalWrite (stepPin2, LOW);
    delayMicroseconds(400);
  }
}

void tok(double deg) {  //deg[°]だけ時計回り
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, LOW);
  for (int cou = 0; cou < deg * senkai; cou++) {
    digitalWrite (stepPin1, HIGH);
    digitalWrite (stepPin2, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin1, LOW);
    digitalWrite (stepPin2, LOW);
    delayMicroseconds(400);
  }
}

void han(double deg) {  //deg[°]だけ反時計回り
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin2, HIGH);
  for (int cou = 0; cou < deg * senkai; cou++) {
    digitalWrite (stepPin1, HIGH);
    digitalWrite (stepPin2, HIGH);
    delayMicroseconds(400);
    digitalWrite (stepPin1, LOW);
    digitalWrite (stepPin2, LOW);
    delayMicroseconds(400);
  }
}

void lin(void) {
  int sensorValue1 = digitalRead(46); //黒線を踏んだら1に、そうでなければ0に。
  int sensorValue2 = digitalRead(48);
  int sensorValue3 = digitalRead(50);
  int sensorValue4 = digitalRead(52);
  int sensorValue5 = digitalRead(47);
  int sensorValue6 = digitalRead(53);
  int slope2 = sensorValue1 * c + sensorValue2 * b + sensorValue3 * a;  //右モータ回転数。ライントレースのセンサの値で変動。
  int slope1 = sensorValue4 * a + sensorValue5 * b + sensorValue6 * c;  //左モータ回転数。ライントレースのセンサの値で変動。
  if (slope1 + slope2 == a * 2 + b * 2 + c * 2) { //黒線またぎ
    for (int cou = 0; cou < 400; cou++) {
      digitalWrite (stepPin1, HIGH);
      digitalWrite (stepPin2, HIGH);
      delayMicroseconds(200);
      digitalWrite (stepPin1, LOW);
      digitalWrite (stepPin2, LOW);
      delayMicroseconds(200);
    }
    n = n + 1;
  } else {
    for (int x = 0; x < slope1; x++) {
      digitalWrite (stepPin1, HIGH);
      delayMicroseconds(200);
      digitalWrite (stepPin1, LOW);
      delayMicroseconds(200);
    }
    for (int x = 0; x < slope2; x++) {
      digitalWrite (stepPin2, HIGH);
      delayMicroseconds(200);
      digitalWrite (stepPin2, LOW);
      delayMicroseconds(200);
    }
    digitalWrite (stepPin1, HIGH);
    digitalWrite (stepPin2, HIGH);
    delayMicroseconds(200);
    digitalWrite (stepPin1, LOW);
    digitalWrite (stepPin2, LOW);
    delayMicroseconds(200);
  }
}a

/*==============================================================*/

void loop() {
  myservo1.write (90, 20, true); //ハンドを閉じる
  myservo2.write (40, 50, true); //ハンドを上げる
  myservo3.write (100, 20, true); //受け皿は真ん中
  myservo4.write (50, 20, true);
  myservo5.write (50, 20, true);
  myservo6.write (50, 20, true);
  while (mod == 1) { //ライントレースしながら進む
    lin();
    
    if (n == 5) {
      mod = 4; 
      break;
    }
  }
  while (mod == 4) {delay(1000);
    myservo2.write (120, 50, true); 
    
    //ボールをすべて処理した後の挙動が欲しい場合、何か書いとけ
  }
}
