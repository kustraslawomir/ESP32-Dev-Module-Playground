#include <Arduino.h>

int ledBuiltIn = 2;

void setup() {
  pinMode(ledBuiltIn, OUTPUT);
}

void loop() {
  digitalWrite(ledBuiltIn, HIGH);
  delay(1000);
  digitalWrite(ledBuiltIn, LOW);
  delay(1000);
}

void blinkBlueLed(){

}
