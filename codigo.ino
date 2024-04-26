#include <ArduinoJson.h>
 
unsigned long previousMillis = 0; 
const long interval = 4000;
 
int ldrPin = A0;
int ldrValue = 0;
 
int cm = 0;
int triggerPin = 7;
int echoPin = 8;
 
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);  
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{  
  unsigned long currentMillis = millis();
  cm = 0.01723 * readUltrasonicDistance(triggerPin, echoPin);
  int ldrValue = analogRead(ldrPin);
 
  StaticJsonDocument<50> doc;
  doc["distance_cm"] = cm;
  doc["lumens_cm3"] = ldrValue;
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    serializeJson(doc, Serial);
    Serial.println();
  }
}