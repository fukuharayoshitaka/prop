#include <MsTimer2.h>



void sensa() {
  int sensorValue1 = digitalRead(46); //黒線を踏んだら1に、そうでなければ0に。
  int sensorValue2 = digitalRead(48);
  int sensorValue3 = digitalRead(50);
  int sensorValue4 = digitalRead(52);
  int sensorValue5 = digitalRead(47);
  int sensorValue6 = digitalRead(53);
  
  Serial.print(sensorValue3);
  Serial.print(sensorValue4);
  Serial.print(sensorValue5);
  Serial.println(sensorValue6);
  Serial.print("ass");
  static boolean output = HIGH;
}

void setup() {
  Serial.begin(9600);
 
  MsTimer2::set(500, sensa);
  MsTimer2::start();
  
}


void loop() {
  Serial.print(sensorValue1);
  Serial.print(sensorValue2);
  
}
