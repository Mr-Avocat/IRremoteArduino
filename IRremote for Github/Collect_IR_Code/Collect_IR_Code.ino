#include <IRremote.h> //Import of the library

const int cptInf = 2; //IR sensor pin
const int del = 4; //IR LED pin
IRrecv recepteurIR(cptInf); //Tell to the library the pin of the IR Sensor
decode_results messageRecu; //Create an event
IRsend irsend; //Create an event

void setup()
{
  Serial.begin(9600); //Initialisation if the serial communication (bauds)
  recepteurIR.enableIRIn(); 
  recepteurIR.blink13(true);
}

void loop()
{
  if (recepteurIR.decode(&messageRecu)) //if IR sensor received a msg
  {
    if (messageRecu.decode_type == NEC) //Search for the type of encoded signal
    {
      Serial.print("NEC: ");
    }
    else if (messageRecu.decode_type == SONY)
    {
      Serial.print("SONY: ");
    }
    else if (messageRecu.decode_type == RC5)
    {
      Serial.print("RC5: ");
    }
    else if (messageRecu.decode_type == RC6)
    {
      Serial.print("RC6: ");
    }
    else if (messageRecu.decode_type == UNKNOWN)
    {
      Serial.print("UNKNOWN: ");
    }
    else
    {
      Serial.print(messageRecu.decode_type);
    }
    Serial.println(messageRecu.value, HEX); //Print the value of the signal
    recepteurIR.resume(); //END
  }
}
