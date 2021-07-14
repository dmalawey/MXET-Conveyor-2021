// Notes: successfully tested this code on the ESP8266 nodeMCU
// Connections : buzzer to D5 and GND
// Board selection for upload: NODEMCU 0.9

#include "VL.h"     // initialize VL before BUZ
#include "BUZ.h"    // initialize buzzer

int myDist = 0;     // global var for distance
int trigger = 200;  // trigger is 20cm and less

void setup() {
  Serial.begin(9600);
  setupBZ();  // set up buzzer
  setupVL();  // set up distance sensor
}

void loop() {
  myDist = vlDist();          // take a reading (mm)
  if (myDist !=0) {           // out-of-range returns zeros
    if (myDist <= trigger){   // if the obstacle is detected
    bzChirp(49);}             // emit a chirp from buzzer
  }  
  delay(500);                 // delay 0.5 sec between measuring
}
