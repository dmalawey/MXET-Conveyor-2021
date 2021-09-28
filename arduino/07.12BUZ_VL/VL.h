#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
VL53L0X_RangingMeasurementData_t measure;

void setupVL() {                  // set up the VL sensor
  if (!lox.begin()) {
  Serial.println(F("Failed to boot VL53L0X"));
  while(1);
  }
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}

int vlDist() {                    // function for taking distance readings
  int dist;                       // declare a variable for reading
  Serial.print("VL53L0X reading... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    dist =  measure.RangeMilliMeter; // store distance
    Serial.print("Distance (mm): "); Serial.println(dist);
  } else {
    Serial.println(" out of range ");
    dist = 0;
  }
  return dist;
}
