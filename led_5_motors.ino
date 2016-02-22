#define LED1_PIN 2 // RedBear Blend & RFduino
#define LED2_PIN 3
#define LED3_PIN 4
#define LED4_PIN 5
#define LED5_PIN 6

// #define LED_PIN A3 // RedBear Nano

// Import libraries (BLEPeripheral depends on SPI)
#include <SPI.h>
#include <BLEPeripheral.h>

// define pins (varies per shield/board)
// https://github.com/sandeepmistry/arduino-BLEPeripheral#pinouts
// Blend
#define BLE_REQ     9
#define BLE_RDY     8
#define BLE_RST     5

// create peripheral instance, see pinouts above
BLEPeripheral blePeripheral = BLEPeripheral(BLE_REQ, BLE_RDY, BLE_RST);

// create service
BLEService ledService = BLEService("AAB4");

// create switch characteristic
BLECharCharacteristic switchCharacteristic = BLECharCharacteristic("AAB5", BLERead | BLEWrite);
BLEDescriptor switchDescriptor = BLEDescriptor("2901", "Pattern");


void setup() {
  Serial.begin(9600);

  // set LED pin to output mode
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  pinMode(LED5_PIN, OUTPUT);

  // set advertised local name and service UUID
  blePeripheral.setLocalName("COSO");
  blePeripheral.setDeviceName("COSO");
  blePeripheral.setAdvertisedServiceUuid(ledService.uuid());

  // add service and characteristics
  blePeripheral.addAttribute(ledService);
  blePeripheral.addAttribute(switchCharacteristic);
  blePeripheral.addAttribute(switchDescriptor);


  // assign event handlers for characteristic
  switchCharacteristic.setEventHandler(BLEWritten, switchCharacteristicWritten);

  // begin initialization
  blePeripheral.begin();

  Serial.println(F("Bluetooth LED"));
}

void loop() {
  // Tell the bluetooth radio to do whatever it should be working on	
  blePeripheral.poll();
}

void switchCharacteristicWritten(BLECentral& central, BLECharacteristic& characteristic) {
  // central wrote new value to characteristic, update LED
//  Serial.print(F("Characteristic event, written: "));


  if (switchCharacteristic.value() == 1) {
    Serial.println(switchCharacteristic.value());
    Serial.println(F("LED 1 on"));
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
    delay(1000);
    digitalWrite(LED1_PIN, LOW);

  } else if (switchCharacteristic.value() == 2) {
    Serial.println(switchCharacteristic.value());
    Serial.println(F("LED 2 on"));
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
    delay(1000);
    digitalWrite(LED2_PIN, LOW);
    
  } else if (switchCharacteristic.value() == 3) {
    Serial.println(switchCharacteristic.value());
    Serial.println(F("LED 2 on"));
    digitalWrite(LED3_PIN, HIGH);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
    delay(1000);
    digitalWrite(LED3_PIN, LOW);
    
  } else if (switchCharacteristic.value() == 4) {
    Serial.println(switchCharacteristic.value());
    Serial.println(F("LED 2 on"));
    digitalWrite(LED4_PIN, HIGH);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED5_PIN, LOW);
    delay(1000);
    digitalWrite(LED4_PIN, LOW);
    
  } else if (switchCharacteristic.value() == 5) {
    Serial.println(switchCharacteristic.value());
    Serial.println(F("LED 2 on"));
    digitalWrite(LED5_PIN, HIGH);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
    delay(1000);
    digitalWrite(LED5_PIN, LOW);
  }


  
}








