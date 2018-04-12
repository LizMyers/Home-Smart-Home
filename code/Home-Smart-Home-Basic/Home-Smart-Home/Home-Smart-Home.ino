/*
HOME-SMART-HOME
by Liz Myers
April 2, 2018
*/

/************************
*** INCLUDE LIBRARIES ***
*************************/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "fauxmoESP.h"

/******************
*** DEFINE PINS ***
*******************/

#define LT_RED    D2
#define LT_GREEN  D3
#define LT_BLUE   D4
#define FAN       D5

#define WIFI_SSID "YOUR WIFI NAME GOES HERE"//Change to your Wifi name
#define WIFI_PASS "YOUR WIFI PASSWORD GOES HERE"//Change to your Wifi Password
#define SERIAL_BAUDRATE    115200

fauxmoESP fauxmo; //instantiate fauxmo library

/*****************
*** SETUP WIFI ***
******************/

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

/***********************
*** CUSTOM FUNCTIONS ***
***********************/

void yourCustomFunctionGoesHere(){
  Serial.println("custom function called");

}

/**********************
*** DEVICE CALLBACK ***
***********************/

void callback(uint8_t device_id, const char * device_name, bool state) {
  Serial.print("Device "); Serial.print(device_name); 
  Serial.print(" state: ");
  if (state) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }
  //Switching action on detection of device name
  
  if ( (strcmp(device_name, "Red") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(LT_RED, HIGH);
    } else {
      digitalWrite(LT_RED, LOW);
    }
  }
  if ( (strcmp(device_name, "Green") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(LT_GREEN, HIGH);
    } else {
      digitalWrite(LT_GREEN, LOW);
    }
  }
  if ( (strcmp(device_name, "Blue") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(LT_BLUE, HIGH);
    } else {
      digitalWrite(LT_BLUE, LOW);
    }
  }
  if ( (strcmp(device_name, "Fan") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(FAN, HIGH);
    } else {
      digitalWrite(FAN, LOW);
    }
  }
}


/**********************
*** SETUP (RUNS ONCE) 
***********************/

void setup() {
  
  // Turn devices 'off'
  pinMode(LT_RED, OUTPUT);
  digitalWrite(LT_RED, LOW);
  pinMode(LT_GREEN, OUTPUT);
  digitalWrite(LT_GREEN, LOW);
  pinMode(LT_BLUE, OUTPUT);
  digitalWrite(LT_BLUE, LOW);
  pinMode(FAN, OUTPUT);
  digitalWrite(FAN, LOW);

  // Init serial port and clean garbage
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println("FauxMo demo sketch");
  Serial.println("After connection, ask Alexa/Echo to 'turn <devicename> on' or 'off'");

  // Connect to Wifi
  wifiSetup();

  // Device names for simulated Wemo switches
  fauxmo.addDevice("Red");
  fauxmo.addDevice("Green");
  fauxmo.addDevice("Blue");
  fauxmo.addDevice("Fan");
  fauxmo.onMessage(callback);
}

/***********************
LOOP (RUNS FOREVER)
************************/

void loop() {
  fauxmo.handle();
}

/***********************
 END BASIC SKETCH
************************/


