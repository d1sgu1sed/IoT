#define PHOTO_SENSOR_PIN A4

void setup() {
  Serial.begin(9600); 
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read(); 

    if (command == 'p') {
      int sensorValue = analogRead(PHOTO_SENSOR_PIN); 
      uint8_t reducedValue = sensorValue / 4; 

      Serial.println(reducedValue);
    }
  }
}