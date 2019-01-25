int lightPin = 0;  //define a pin for Photo resistor
int ledPin=11;     //define a pin for LED

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( ledPin, OUTPUT );
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
    analogWrite(ledPin, analogRead(lightPin)/4);  //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   delay(100); //short delay for faster response to light.
   //tone(8, 31);
   digitalWrite(LED_BUILTIN, HIGH);
   if (analogRead(lightPin) > 201){
      noTone(8);

   }
   if (analogRead(lightPin) < 200){
     //Serial.print("test");
     digitalWrite(LED_BUILTIN, LOW);

      tone(8, 31);

   }

}
