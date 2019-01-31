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
    analogWrite(ledPin, analogRead(lightPin)/4);  //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   delay(100); //short delay for faster response to light.

   digitalWrite(LED_BUILTIN, HIGH);
     // Get the current time
  DateTime now = RTC.now();   


  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
  // set alarm time here
 if(now.hour() == 7 && now.minute() > 29) && now.minutes() < 31){
  
  
   if (analogRead(lightPin) > 201){
      noTone(8);

   }
   if (analogRead(lightPin) < 200){
     //Serial.print("test");
     digitalWrite(LED_BUILTIN, LOW);

      tone(8, 31);

   }
}
}
