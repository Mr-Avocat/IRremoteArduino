// Créé par Camille Jouhet le 6 février 2020

#include <IRremote.h> //Import of the libraries
#include <SoftwareSerial.h>

SoftwareSerial HC06(10, 11); //Virtual RX et TX of the Arduino's board
IRsend irsend;

const char mode_power = 'A', mode_source = 'B', mode_pointer = 'C', mode_freeze = 'D', mode_help = 'E'; //Variables who keeps the bluetooth letter of the remote button
const char mode_zoomPlus = 'F', mode_zoomMoins = 'G';
char mode = mode_power; //Buffer variable 

void setup() {
  HC06.begin(9600); //Bluetooth initialisation (bauds)
}

void loop() {
  if (HC06.available()) { //If Bluetooth message is received
    char mode_char = HC06.read(); //The bluetooth letter

    switch (mode_char) { //Switch loop
      case mode_power:
        {
          mode = mode_power; //Buffer variable
          irsend.sendNEC(/*your IRremote button's code*/, 32); //Send the IR signal encode with 32Bits
          break;
        }
      case mode_source:
        {
          mode = mode_source;
          irsend.sendNEC(/*your IRremote button's code*/, 32);
          break;
        }
      case mode_pointer:
        {
          mode = mode_pointer;
          irsend.sendNEC(/*your IRremote button's code*/, 32);
          break;
        }
      case mode_freeze:
        {
          mode = mode_freeze;
          irsend.sendNEC(/*your IRremote button's code*/, 32);
          break;
        }
      case mode_help:
        {
          mode = mode_help;
          irsend.sendNEC(/*your IRremote button's code*/, 32);
          break;
        }
      case mode_zoomPlus:
        {
          mode = mode_zoomPlus;
          irsend.sendNEC(/*your IRremote button's code*/, 32);
          break;
        }
      case mode_zoomMoins:
        {
          mode = mode_zoomMoins;
          irsend.sendNEC(/*your IRremote button's code*/, 32);
        }
    }
    delay(40);
  }
}
