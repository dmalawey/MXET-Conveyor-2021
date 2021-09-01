// 2021.07 DPM - This software checks distance and triggers a buzzer
// Notes: successfully tested this code on the ESP8266 nodeMCU
// Connect: buzzer to D5 and GND
// Connect: VL53L0X to i2c terminals
// Board selection for upload: NODEMCU 0.9
// ESP diagram: lastminuteengineers.com/esp8266-nodemcu-arduino-tutorial

#include "VL.h"     // initialize VL before BUZ
#include "BUZ.h"    // initialize buzzer

int myDist = 0;     // global var for distance
int trigger = 100;  // trigger is 10cm and less
bool flag1 = 0;     // global boolean for threshold condition

void setup() {
  Serial.begin(115200);       // make serial com fast, for rapid looping
  setupBZ();                  // set up buzzer
  setupVL();                  // set up distance sensor
  pinMode(D4, OUTPUT);        // set up output pin: D4 = 17 = GPIO2
}

// THIS LOOP RUNS AROUND 50HZ
void loop() {
  myDist = vlDist();          // take a reading (mm)
  digitalWrite(D4,LOW);       // reset output pin
  
  if (myDist !=0) {           // out-of-range returns zeros
    if (myDist <= trigger){   // if the obstacle is detected
    flag1 = HIGH;}}           // raise the flag for object detection
  
  if (flag1 == HIGH){         // if the flag is raised
    digitalWrite(D4, HIGH);   // raise the output pin
    bzChirp(49);              // emit a chirp from buzzer
    delay(50);                // tiny delay - chirp takes time anyway
    flag1 = LOW;}             // reset flag
}
