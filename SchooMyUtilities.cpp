/* Copyright (c) 2020 SchooMy, inc.  All rights reserved. */

#include "SchooMyUtilities.h"
#define sec_num 15

SchooMyUtilities::SchooMyUtilities() {}

// action

boolean SchooMyUtilities::_sbeIsValidRange(int lower_value, int upper_value) {
  if(1 <= lower_value && lower_value <= 10 && 1 <= upper_value && upper_value <= 10 && lower_value <= upper_value){
    return true;
  } else{
    return false;
  }
}

void SchooMyUtilities::soundSensorBegin(int echoPin) {
  pinMode(echoPin, INPUT);
  _plotAdjust = _getSoundSensorPlotterAdjustValue(echoPin);
}

const int average_count = 10;
int SchooMyUtilities::_getSoundSensorPlotterAdjustValue(int echoPin) {
  int val = 0;
  unsigned int s = 0;
  for (int i = 0; i < average_count; i++) {
    val = analogRead(echoPin);
    delay(20);
    // Some data were excluded for correction.
    if (i == 0) continue;
    s += val;
  }
  return (int) s / (average_count -1) + 100;
}

int secList[sec_num]={0};
int SchooMyUtilities::soundSensorPlotterAnalogRead(int echoPin) {
  float total = 0.0;
  for(int i = sec_num - 1; i > 0; i--) {
    secList[i] = secList[i-1];
    total += secList[i];
  }
  int analogReadAdjust = abs(analogRead(echoPin) - _plotAdjust);
  delay(20);
  secList[0] = analogReadAdjust;
  total += secList[0];
  return (int) total / sec_num;
}

// Wi-Fi

String SchooMyUtilities::getChipId(uint64_t mac) {
    uint32_t id = 0;
    for(int i = 0; i < 17; i = i+8) {
      id |= ((mac >> (40 - i)) & 0xff) << i;
    }
    return String(id);
}

// display

void SchooMyUtilities::serialPlotterPrint(int value, int upperLimit, int lowerLimit) {
  Serial.print(upperLimit);
  Serial.print(",");
  Serial.print(lowerLimit);
  Serial.print(",");
  Serial.print(value);
  Serial.println("");
}

void SchooMyUtilities::serialPlotterPrintMultiple(int upperLimit, int lowerLimit, int numValues, ...) {
  va_list args;
  va_start(args, numValues);
  Serial.print("upperLimit:");
  Serial.print(upperLimit);
  Serial.print(",");
  Serial.print("lowerLimit:");
  Serial.print(lowerLimit);
  Serial.print(",");
  for (int i = 0; i < numValues; i++) {
    double value = va_arg(args, double);
    Serial.print("value");
    Serial.print(i + 1);
    Serial.print(":");
    Serial.print(value);
    if (i < numValues - 1) {
      Serial.print(",");
    }
  }
  Serial.println("");
  va_end(args);
}
