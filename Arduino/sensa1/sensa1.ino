
void setup() {

  Serial.begin(9600);
}
void loop() {
  int sensorValue = digitalRead(34
  );//ここはつないだピン
  
// delay();
  Serial.print(sensorValue);
 

  delay(50);
}
