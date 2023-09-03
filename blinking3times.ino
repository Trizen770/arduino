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
    // Serial.println("Received Value");
    // IrReceiver.printIRResultShort(&Serial);
    // IrReceiver.printIRSendUsage(&Serial);

    // Power Button Pressed  
    if (IrReceiver.decodedIRData.command == 0x45)
    {
      Serial.println("POWER BUTTON PRESSED!");

      //
      if (state == 0)
      {
        Serial.println("TURNING ON LED");
        // Turn on the first led
        digitalWrite(pinLed, HIGH);
        digitalWrite(pinLed2, HIGH);
        digitalWrite(pinLed3, HIGH);
        state = 1;
      }
      else if (state == 1)
      {
        // Turn off the first led
        digitalWrite(pinLed, LOW);
        digitalWrite(pinLed2, LOW);
        digitalWrite(pinLed3, LOW);

        // Update the state of the led
        state = 0;
      }
      delay(100);
    }

    // Volume Up 
    if (IrReceiver.decodedIRData.command == 0x46){
      Serial.println("VOLUME UP");
    }

    // Func/stop
    if (IrReceiver.decodedIRData.command == 0x47){
      Serial.println("FUNC/STOP");
    }

    // Fast forward backward 
    if (IrReceiver.decodedIRData.command == 0x44){
      Serial.println("FFB"); 
    }

    // Play/Pause
    if (IrReceiver.decodedIRData.command == 0x40){
      Serial.println("PLAY/PAUSE");
    }

    // Fast forward forward 
    if (IrReceiver.decodedIRData.command == 0x43){
      Serial.println("FFF");
    }

    // Down button 
    if (IrReceiver.decodedIRData.command == 0x7){
      Serial.println("DOWN");
    }

    // Volume down
    if (IrReceiver.decodedIRData.command == 0x15){
      Serial.println("VOLUME DOWN");
    }

    // Up button
    if (IrReceiver.decodedIRData.command == 0x9){
      Serial.println("UP");
    }

    // Button 0
    if (IrReceiver.decodedIRData.command == 0x16){
      Serial.println("0");
    }

    // EQ 
    if (IrReceiver.decodedIRData.command == 0x19){
      Serial.println("EQ");
    }

    // ST/REPT 
    if (IrReceiver.decodedIRData.command == 0xD){
      Serial.println("ST/REPT");
    }

    // Button 1 
    if (IrReceiver.decodedIRData.command == 0xC){
      Serial.println("1");
    }

    // Button 2
    if (IrReceiver.decodedIRData.command == 0x18){
      Serial.println("2");
    }

    // Button 3
    if (IrReceiver.decodedIRData.command == 0x5E){
      Serial.println("3");
    }

    // Button 4
    if (IrReceiver.decodedIRData.command == 0x8){
      Serial.println("4");
    }

    // Button 5
    if (IrReceiver.decodedIRData.command == 0x1C){
      Serial.println("5");
    }

    // Button 6
    if (IrReceiver.decodedIRData.command == 0x5A){
      Serial.println("6");
    }

    // Button 7
    if (IrReceiver.decodedIRData.command == 0x42){
      Serial.println("7");
    }

    // Button 8
    if (IrReceiver.decodedIRData.command == 0x52){
      Serial.println("8");
    }

    // Button 9
    if (IrReceiver.decodedIRData.command == 0x4A){
      Serial.println("9");
    }
    

    /*
      45
      46
      47
      
      44
      40
      43

      7
      15
      9

      16
      19
      D

      C
      18
      5E

      8
      1C
      5A

      42
      52
      4A
    */

  }


  IrReceiver.resume();
}