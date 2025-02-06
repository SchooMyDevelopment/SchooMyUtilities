/* Copyright (c) 2020-2023 SchooMy, inc.  All rights reserved. */

#ifndef SchooMyUtilities_h
  #define SchooMyUtilities_h
  #include "Arduino.h"

  class SchooMyUtilities {
    public:
      SchooMyUtilities();
      void serialPlotterPrint(int value, int upperLimit, int lowerLimit);
      void serialPlotterPrintMultiple(int upperLimit, int lowerLimit, int numValues, ...);
      boolean _sbeIsValidRange(int lower_value, int upper_value);
      void soundSensorBegin(int echoPin);
      int soundSensorPlotterAnalogRead(int echoPin);
      String getChipId(uint64_t mac);
      void speakerDefine();
      static const int F_C2 = 131;
      static const int F_CS2 = 139;
      static const int F_D2 = 147;
      static const int F_DS2 = 156;
      static const int F_E2 = 165;
      static const int F_ES2 = 175;
      static const int F_F2 = 175;
      static const int F_FS2 = 185;
      static const int F_G2 =196;
      static const int F_GS2 = 208;
      static const int F_A2 = 220;
      static const int F_AS2 = 233;
      static const int F_B2 = 247;
      static const int F_BS2 = 262;
      static const int F_C3 = 262;
      static const int F_CS3 = 277;
      static const int F_D3 = 294;
      static const int F_DS3 = 311;
      static const int F_E3 = 330;
      static const int F_ES3 = 349;
      static const int F_F3 = 349;
      static const int F_FS3 = 370;
      static const int F_G3 = 392;
      static const int F_GS3 = 415;
      static const int F_A3 = 440;
      static const int F_AS3 = 466;
      static const int F_B3 = 494;
      static const int F_BS3 = 523;
      static const int F_C4 = 523;
      static const int F_CS4 = 554;
      static const int F_D4 = 587;
      static const int F_DS4 = 622;
      static const int F_E4 = 659;
      static const int F_ES4 = 698;
      static const int F_F4 = 698;
      static const int F_FS4 = 740;
      static const int F_G4 = 784;
      static const int F_GS4 = 831;
      static const int F_A4 = 880;
      static const int F_AS4 = 932;
      static const int F_B4 = 988;
      static const int F_BS4 = 1047;
      static const int F_C5 = 1047;
      static const int F_CS5 = 1109;
      static const int F_D5 = 1175;
      static const int F_DS5 = 1245;
      static const int F_E5 = 1319;
      static const int F_ES5 = 1397;
      static const int F_F5 = 1397;
      static const int F_FS5 = 1480;
      static const int F_G5 = 1568;
      static const int F_GS5 = 1661;
      static const int F_A5 = 1760;
      static const int F_AS5 = 1865;
      static const int F_B5 = 1976;
      static const int F_BS5 = 2093;
    private:
      int _plotAdjust;
      int _getSoundSensorPlotterAdjustValue(int echoPin);
  };
#endif
