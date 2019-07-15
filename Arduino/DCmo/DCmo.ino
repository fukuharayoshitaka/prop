void setup() {
 // Serial.begin(9600);
}

void loop() {

  int val = analogRead(A0) / 2; //入力の０～１０２３を０～５１１に変換
 //Serial.println(val,DEC);
  if (val >= 250 && val <= 260) {

    //静止
    analogWrite(10, 0);
    analogWrite(6, 0);

  } else if (val > 260) {

    //正転（逆転）
   analogWrite(6, 0);
    analogWrite(6, val - 256); //6番ピンに５～２５５を出力

  } else {

    //逆転（正転）
    analogWrite(6, 255 - val); //５番ピンに６～２５５を出力
    analogWrite(10, 0);

  }
  delay(20);
}
