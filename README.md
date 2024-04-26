# CP5 EdgeComputing ESPR
|  Name| RM |
|:--------------:| :--------------: |
| Diogo Julio | 553837 |
| Victor Didoff | 552965 |
| Vinicius Silva | 553240 |

# Visão Eletrica
![image](https://github.com/SgT012003/CP5-Edge/assets/82065998/0a580f36-ef34-43d1-9a8a-596c6858d4ce)

# Codigo

> [!CAUTION]
> Feito Durante a Aula usando `millis();`

```cpp
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
```

# Recebendo Informações
## Node-Red

![MicrosoftTeams-image (1)](https://github.com/SgT012003/CP5-Edge/assets/82065998/340f0a07-e407-4caa-9d31-254f698560dd)

## MQTT

![MicrosoftTeams-image (2)](https://github.com/SgT012003/CP5-Edge/assets/82065998/165ca2fb-24ca-47da-9e48-30c08ee9af6d)

## TAGO
