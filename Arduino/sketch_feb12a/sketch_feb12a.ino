#include <VarSpeedServo.h>
#include <MsTimer2.h>
VarSpeedServo myservo1;  //2番。ハンド開閉（60：閉じる、100：開く）
VarSpeedServo myservo2; //3番。ハンド持ち上げ(30:下げ、125:上げ)
VarSpeedServo myservo3; //13番。仕分け皿（85：中心、145：青、25：赤）
VarSpeedServo myservo4; //4番。青箱
VarSpeedServo myservo5; //5番。黄箱
VarSpeedServo myservo6; //6番。赤箱

void setup() {
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(8);
  myservo4.attach(4);
  myservo5.attach(5);
  myservo6.attach(6);
}
void loop() {
 /*delay(4000);
  myservo1.write (20, 20, true); //ハンドを閉じる
  myservo2.write (125, 20, true); //ハンドを上げる
  myservo3.write (85, 20, true); //受け皿は真ん中
  myservo4.write (150, 20, true);
  myservo5.write (150, 20, true);
  myservo6.write (150, 20, true);
delay(1000);
   myservo1.write (85, 20, true); //ハンドを閉じる
  myservo2.write (105, 20, true); //ハンドを上げる
  myservo3.write (65, 20, true); //受け皿は真ん中
  myservo4.write (80, 20, true);
  myservo5.write (80, 20, true);
  myservo6.write (80, 20, true);

*/
  for (int x = 0; x < 5; x++) {
              myservo1.write (60, 120, true); //ハンドをひらく
              myservo3.write (55, 120, true);
              delay(200);
              //myservo1.write (45, 80, true);
              myservo3.write (95, 100, true);
              delay(200);
              myservo1.write (20, 80, true);
              delay(800);
            }
}
