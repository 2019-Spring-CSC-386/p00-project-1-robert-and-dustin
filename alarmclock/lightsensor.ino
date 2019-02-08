//Project 0: Robert Hogsed and Dustin Young
//Creates an alarm that will go off at a set time. It can only be turned off by turning on the lights
//preventing the user from falling back asleep.
//Credits:
//Scott Heggen
//Cody Mitchell
//Other references located in the "References" section of the README.

int lightPin = 0;  //define a pin for Photo resistor
int ledPin=11;     //define a pin for LED

#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;
void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( ledPin, OUTPUT );
    pinMode(LED_BUILTIN, OUTPUT);
      Wire.begin();
  RTC.begin();
}

void loop()
{
    Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.

   delay(100); //short delay for faster response to light.

   digitalWrite(LED_BUILTIN, HIGH); // turns on Led
     // Get the current time
  DateTime now = RTC.now();   // gets time


  Serial.print(now.hour(), DEC); //prints hour, minute, second
  Serial.print(':');
  Serial.print(now.minute(), DEC); 
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
  // set alarm time here
 if(now.hour() == 23 && now.minute() > 9 && now.minute() < 20){
  
  
  //if light level is high enough no alarm will sound
   if (analogRead(lightPin) > 201){
      noTone(8);

   }
   // if the light level is too low then the alarm will continue to sound
   if (analogRead(lightPin) < 200){
     //Serial.print("test");
     digitalWrite(LED_BUILTIN, LOW);

      tone(8, 31);

   }
}
}
