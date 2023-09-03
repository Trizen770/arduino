#include <Arduino.h>
#define DECODE_NEC

#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp> // include the library
/*
 * This is defining all the led variables for the program
 */
const int pinLed = 7;
const int pinLed2 = 12;
const int pinLed3 = 8;
// This is the signal that is being sent from the receiver to the receiver pin
const int receiverPin = 3;

void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pinLed, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  Serial.begin(115200);
  // Start the receiver
  IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK);
  printActiveIRProtocols(&Serial);
}

/*
  digitalWrite( PIN, HIGH/LOW );

*/

int state = 0; // 0 = off, 1 = on

// the loop function runs over and over again forever
void loop()
{
  if (IrReceiver.decode())
  {
    Serial.println("Received Value");
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.printIRSendUsage(&Serial);

    // Check if the power button is pressed by seeing if it equals 0x45
    if (IrReceiver.decodedIRData.command == 0x45)
    {
      Serial.println("POWER BUTTON PRESSED!"); 
      
      // 
      if (state == 0){
        Serial.println("TURNING ON LED"); 
        // Turn on the first led 
        digitalWrite(pinLed, HIGH);
        digitalWrite(pinLed2, HIGH);
        digitalWrite(pinLed3, HIGH);
        state = 1;
      } else if (state == 1){
        // Turn off the first led 
        digitalWrite(pinLed, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);


        // Update the state of the led  
        state = 0; 
      }
        delay(100);
    }

    // // in here
    // if (IrReceiver.decodedIRData.command == 0xC)
    // {
    //   Serial.println("LED 1");
    //   digitalWrite(pinLed, HIGH); 
    // }
    // if (IrReceiver.decodedIRData.command == 0x45){
    //   Serial.println("Skip Backward");
    //   digitalWrite(pinLed, LOW); // thisIsCamelCase 
    //   digitalWrite(pinLed2, LOW);
    //   digitalWrite(pinLed3, LOW);
    // }
    // if (IrReceiver.decodedIRData.command == 0x18){
    //   Serial.println("LED 2");
    //   digitalWrite(pinLed2, HIGH);
    // }
    // if (IrReceiver.decodedIRData.command == 0x5E){
    //   Serial.println("LED 3");
    //   digitalWrite(pinLed3, HIGH);


    // }



    IrReceiver.resume();
  }
}

/*


void setup() {
}

void loop() {
  if (IrReceiver.decode()) {
    // Printing remote information
    Serial.println("RECEIVED VALUE!");
    IrReceiver.printIRResultShort(&Serial);
    IrReceiver.printIRSendUsage(&Serial);


    Serial.println("VALUE " + IrReceiver.decodedIRData.command);
    // Magical variable -> IrReceiber.decodedIRData.command

    if (IrReceiver.decodedIRData.command == 0x45) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 0x46) {
      Serial.println("Volume +");
    }
    if (IrReceiver.decodedIRData.command == 71) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 68) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 64) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 67) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 7) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 21) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 9) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 22) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 25) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 13) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 12) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 94) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 8) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 28) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 90) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 66) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 82) {
      Serial.println("Power Button");
    }
    if (IrReceiver.decodedIRData.command == 74) {
      Serial.println("Power Button");
    }


    IrReceiver.resume();  // Enable receiving of the next value

  }
}


*/