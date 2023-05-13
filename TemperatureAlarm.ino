#include <dht11.h>
#define sensorPin 4

float temp;
int blue = 12;
int green = 13;
int red = 11;
int piezo = 7;
dht11 DHT11;

void setup()
{
    pinMode(sensorPin, OUTPUT);
    Serial.begin(9600);
    pinMode(blue, INPUT);
    pinMode(green, INPUT);
    pinMode(red, INPUT);
    pinMode(piezo, INPUT);
    digitalWrite(piezo, 0);
}



void loop()
{

  Serial.println();

  int chk = DHT11.read(sensorPin);
  temp = (float)DHT11.temperature, 2;
  Serial.println(temp);

  delay(2000);

    if (temp < 25)
    {
        analogWrite(blue, 0);
        analogWrite(green, 40);
        analogWrite(red, 200);
        digitalWrite(piezo, 0);
        noTone(piezo);


    }
    else if (temp < 35 && temp >= 25)
    {
        analogWrite(blue, 0);
        analogWrite(green, 20);
        analogWrite(red, 220);
        noTone(piezo);
    }
    else if (temp >= 35 )
    {
        tone(piezo, 1000);
        Serial.println(digitalRead(piezo));
        analogWrite(blue, 0);
        analogWrite(green, 0);
        analogWrite(red, 255);
    }

}