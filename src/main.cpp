#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <Arduino.h>
// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
char incomingByte;
int  LED = 2;

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");

  BLEDevice::init("ESP_LAMP");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setValue("Hello World says Neil");
  pService->start();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  Serial.println("Characteristic defined! Now you can read it in your phone!");

  Serial.begin(9600);
pinMode(LED, OUTPUT);
Serial.println("Press 1 to LED ON or 0 to LED OFF...");

}

void loop() {

  if (Serial.available() > 0) {
   incomingByte = Serial.read();
   if(incomingByte == '0') {
      digitalWrite(LED, LOW);
      Serial.println("LED OFF. Press 1 to LED ON!");
   }
   if(incomingByte == '1') {
      digitalWrite(LED, HIGH);
      Serial.println("LED ON. Press 0 to LED OFF!");
   }
 }
 delay(2000);
}
