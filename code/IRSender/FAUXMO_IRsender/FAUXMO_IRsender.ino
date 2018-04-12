/************************
*** INCLUDE LIBRARIES ***
*************************/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "fauxmoESP.h"

#define WIFI_SSID "YOUR WIFI NETWORK NAME"//change your Wifi name
#define WIFI_PASS "YOUR WIFI PASSWORD"//Change your Wifi Password
#define SERIAL_BAUDRATE                 115200

fauxmoESP fauxmo;

//declare switching pins
//Change pins according to your NodeMCU pinouts

#define Strip D5
#define Yellow D3

/************************
*** WIFI SETUP ***
*************************/

void wifiSetup() {

    // Set WIFI module to STA mode
    WiFi.mode(WIFI_STA);

    // Connect
    Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    // Wait
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(100);
    }
    Serial.println();

    // Connected!
    Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}
/************************
*** DEVICE CALLBACK ***
*************************/
void callback(uint8_t device_id, const char * device_name, bool state) {
  Serial.print("Device "); Serial.print(device_name); 
  Serial.print(" state: ");
  if (state) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
  //Switching action on detection of device name
  if ( (strcmp(device_name, "Strip") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      turnOnStrip();
    } else {
      turnOffStrip();
    }
  }
  if ( (strcmp(device_name, "Yellow") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(Yellow, HIGH);
    } else {
      digitalWrite(Yellow, LOW);
    }
  }

}

void setup() {
    //Initialize pins to Low on device start
    
    pinMode(Strip, OUTPUT);
    digitalWrite(Strip, LOW);
    pinMode(Yellow, OUTPUT);
    digitalWrite(Yellow, LOW);

    
    // Init serial port and clean garbage
    Serial.begin(SERIAL_BAUDRATE);
    Serial.println("Smart Home Sketch: Strip Lights & TV");
    Serial.println("After connection, ask Alexa/Echo to 'turn <devicename> on' or 'off'");

    // Wifi
    wifiSetup();

    // Device Names for Simulated Wemo switches
    fauxmo.addDevice("Strip");
    fauxmo.addDevice("Yellow");
  
    fauxmo.onMessage(callback);
}

 // This procedure sends a 38KHz pulse to the IRledPin
 // for a certain # of microseconds. We'll use this whenever we need to send codes
 
 void pulseIR(long microsecs) {
   // we'll count down from the number of microseconds we are told to wait

   cli();  // this turns off any background interrupts

   while (microsecs > 0) {
     // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite(Telly, HIGH);  // this takes about 3 microseconds to happen
    delayMicroseconds(10);         // hang out for 10 microseconds
    digitalWrite(Telly, LOW);   // this also takes about 3 microseconds
    delayMicroseconds(10);         // hang out for 10 microseconds

    // so 26 microseconds altogether
    microsecs -= 26;
   }

   sei();  // this turns them back on
 }

*/*************************
  REPLACE WITH YOUR CODES
 ************************/
 
 void turnOnStrip() {
   // TURN ON LED STRIP
   delayMicroseconds(60924);      //Time off (LEFT column)       
   pulseIR(9320);                //Time on (RIGHT column)    <-------DO NOT MIX THESE UP
   delayMicroseconds(4680);
   pulseIR(580);
   delayMicroseconds(600);
   pulseIR(580);
   delayMicroseconds(580);
   pulseIR(600);
   delayMicroseconds(600);
   pulseIR(560);
   delayMicroseconds(580);
   pulseIR(600);
   delayMicroseconds(600);
   pulseIR(560);
   delayMicroseconds(580);
   pulseIR(600);
   delayMicroseconds(600);
   pulseIR(560);
   delayMicroseconds(580);
   pulseIR(560);
   delayMicroseconds(1740);
   pulseIR(560);
   delayMicroseconds(1760);
   pulseIR(580);
   delayMicroseconds(1720);
   pulseIR(600);
   delayMicroseconds(1720);
   pulseIR(580);
   delayMicroseconds(1720);
   pulseIR(600);
   delayMicroseconds(1720);
   pulseIR(580);
   delayMicroseconds(1720);
   pulseIR(620);
   delayMicroseconds(1700);
   pulseIR(580);
   delayMicroseconds(1720);
   pulseIR(600);
   delayMicroseconds(1700);
   pulseIR(600);
   delayMicroseconds(600);
   pulseIR(540);
   delayMicroseconds(620);
   pulseIR(580);
   delayMicroseconds(600);
   pulseIR(540);
   delayMicroseconds(600);
   pulseIR(600);
   delayMicroseconds(600);
   pulseIR(540);
   delayMicroseconds(1740);
   pulseIR(560);
   delayMicroseconds(620);
   pulseIR(580);
   delayMicroseconds(580);
   pulseIR(560);
   delayMicroseconds(1760);
   pulseIR(560);
   delayMicroseconds(1740);
   pulseIR(560);
   delayMicroseconds(1760);
   pulseIR(580);
   delayMicroseconds(1720);
   pulseIR(580);
   delayMicroseconds(1720);
   pulseIR(600);
   delayMicroseconds(600);
   pulseIR(540);
   delayMicroseconds(41200);
   pulseIR(9360);
   delayMicroseconds(2320);
   pulseIR(600);
 } //END turn ON strip

void turnOffStrip() {
   // TURN OFF LED STRIP
   delayMicroseconds(4088);      //Time off (LEFT column)       
   pulseIR(9500);                //Time on (RIGHT column)    <-------DO NOT MIX THESE UP
   delayMicroseconds(4580);
   pulseIR(680);
   delayMicroseconds(520);
   pulseIR(640);
   delayMicroseconds(540);
   pulseIR(640);
   delayMicroseconds(520);
   pulseIR(660);
   delayMicroseconds(520);
   pulseIR(640);
   delayMicroseconds(520);
   pulseIR(660);
   delayMicroseconds(520);
   pulseIR(660);
   delayMicroseconds(520);
   pulseIR(640);
   delayMicroseconds(520);
   pulseIR(660);
   delayMicroseconds(1660);
   pulseIR(640);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(1640);
   pulseIR(660);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(1660);
   pulseIR(640);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(520);
   pulseIR(640);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(520);
   pulseIR(660);
   delayMicroseconds(520);
   pulseIR(640);
   delayMicroseconds(540);
   pulseIR(640);
   delayMicroseconds(520);
   pulseIR(660);
   delayMicroseconds(520);
   pulseIR(640);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(520);
   pulseIR(640);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(1660);
   pulseIR(640);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(1660);
   pulseIR(660);
   delayMicroseconds(1660);
   pulseIR(640);
   delayMicroseconds(520);
   pulseIR(660);
   delayMicroseconds(41060);
   pulseIR(9500);
   delayMicroseconds(2240);
   pulseIR(680);
   delayMicroseconds(33444);
   pulseIR(9520);
   delayMicroseconds(2220);
   pulseIR(680);
 } // END turn OFF strip
 
void loop() {
  fauxmo.handle();
}
/************************
*** END ***
*************************/
