#include <MsTimer2.h>

void setup() {

int sensorValue1 = digitalRead(46); //黒線を踏んだら1に、そうでなければ0に。
  int sensorValue2 = digitalRead(48);
  int sensorValue3 = digitalRead(50);
  int sensorValue4 = digitalRead(52);
  int sensorValue5 = digitalRead(47);
  int sensorValue6 = digitalRead(53);
  Serial.begin(9600);
}
void loop() {
  int sensorValue = digitalRead(46);//ここはつないだピン
   int sensorValue2 = digitalRead(48);
    int sensorValue3 = digitalRead(50);
     int sensorValue4 = digitalRead(52);
      int sensorValue5 = digitalRead(47);
       int sensorValue6 = digitalRead(53);
  Serial.print(sensorValue);
   Serial.print(sensorValue2);
    Serial.print(sensorValue3);
     Serial.print(sensorValue4);
      Serial.print(sensorValue5);
       Serial.print(sensorValue6);
  delay(100);
}
