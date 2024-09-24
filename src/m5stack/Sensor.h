// pm1.h
#pragma once

#include <SensirionI2CSen5x.h>
#include <Wire.h>
#include "ui/ui.h"

#define MAXBUF_REQUIREMENT 48

#if (defined(I2C_BUFFER_LENGTH) &&                 \
     (I2C_BUFFER_LENGTH >= MAXBUF_REQUIREMENT)) || \
    (defined(BUFFER_LENGTH) && BUFFER_LENGTH >= MAXBUF_REQUIREMENT)
#define USE_PRODUCT_INFO
#endif

SensirionI2CSen5x sen5x;

void printModuleVersions() {
    uint16_t error;
    char errorMessage[256];

    unsigned char productName[32];
    uint8_t productNameSize = 32;

    error = sen5x.getProductName(productName, productNameSize);

    if (error) {
        Serial.print("Error trying to execute getProductName(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("ProductName:");
        Serial.println((char*)productName);
    }

    uint8_t firmwareMajor;
    uint8_t firmwareMinor;
    bool firmwareDebug;
    uint8_t hardwareMajor;
    uint8_t hardwareMinor;
    uint8_t protocolMajor;
    uint8_t protocolMinor;

    error = sen5x.getVersion(firmwareMajor, firmwareMinor, firmwareDebug,
                             hardwareMajor, hardwareMinor, protocolMajor,
                             protocolMinor);
    if (error) {
        Serial.print("Error trying to execute getVersion(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("Firmware: ");
        Serial.print(firmwareMajor);
        Serial.print(".");
        Serial.print(firmwareMinor);
        Serial.print(", ");

        Serial.print("Hardware: ");
        Serial.print(hardwareMajor);
        Serial.print(".");
        Serial.println(hardwareMinor);
    }
}

void printSerialNumber() {
    uint16_t error;
    char errorMessage[256];
    unsigned char serialNumber[32];
    uint8_t serialNumberSize = 32;

    error = sen5x.getSerialNumber(serialNumber, serialNumberSize);
    if (error) {
        Serial.print("Error trying to execute getSerialNumber(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("SerialNumber:");
        Serial.println((char*)serialNumber);
    }
}

void sensorData(void *params)
{
      Wire.begin(2, 1, 100000L);
      sen5x.begin(Wire);

      uint16_t error;
      char errorMessage[256];
      error = sen5x.deviceReset();
      if (error) {
          Serial.print("Error trying to execute deviceReset(): ");
          errorToString(error, errorMessage, 256);
          Serial.println(errorMessage);
      }

  // Print SEN55 module information if i2c buffers are large enough
  #ifdef USE_PRODUCT_INFO
      printSerialNumber();
      printModuleVersions();
  #endif

      float tempOffset = 0.0;
      error = sen5x.setTemperatureOffsetSimple(tempOffset);
      if (error) {
          Serial.print("Error trying to execute setTemperatureOffsetSimple(): ");
          errorToString(error, errorMessage, 256);
          Serial.println(errorMessage);
      } else {
          Serial.print("Temperature Offset set to ");
          Serial.print(tempOffset);
          Serial.println(" deg. Celsius (SEN54/SEN55 only");
      }

      // Start Measurement
      error = sen5x.startMeasurement();
      if (error) {
          Serial.print("Error trying to execute startMeasurement(): ");
          errorToString(error, errorMessage, 256);
          Serial.println(errorMessage);
      }

  while(1)
  {
    uint16_t error;
    char errorMessage[256];

    // Read Measurement
    float massConcentrationPm1p0;
    float massConcentrationPm2p5;
    float massConcentrationPm4p0;
    float massConcentrationPm10p0;
    float ambientHumidity;
    float ambientTemperature;
    float vocIndex;
    float noxIndex;

    error = sen5x.readMeasuredValues(
        massConcentrationPm1p0, massConcentrationPm2p5, massConcentrationPm4p0,
        massConcentrationPm10p0, ambientHumidity, ambientTemperature, vocIndex,
        noxIndex);

    if (error) {
        Serial.print("Error trying to execute readMeasuredValues(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        char pm1buffer[6] = {0};
        dtostrf(massConcentrationPm1p0, 6, 1, pm1buffer);
        lv_label_set_text(ui_pm1label, pm1buffer);
        Serial.print("PM1: ");
        Serial.println(massConcentrationPm1p0);
        
        char pm2buffer[6] = {0};
        dtostrf(massConcentrationPm2p5, 6, 1, pm2buffer);
        lv_label_set_text(ui_pm25label, pm2buffer);
        Serial.print("PM2.5: ");
        Serial.println(massConcentrationPm2p5);

        char pm4buffer[6] = {0};
        dtostrf(massConcentrationPm4p0, 6, 1, pm4buffer);
        lv_label_set_text(ui_pm4label, pm4buffer);
        Serial.print("PM4.0: ");
        Serial.println(massConcentrationPm4p0);

        char pm10buffer[6] = {0};
        dtostrf(massConcentrationPm10p0, 6, 1, pm10buffer);
        lv_label_set_text(ui_pm10label, pm10buffer);
        Serial.print("PM10: ");
        Serial.println(massConcentrationPm10p0);

        // lv_chart_set_ext_y_array(ui_Chart3, ui_Chart3_series_1, array1);
        
        char humbuffer[4] = {0};
        Serial.print("HUM: ");
        if (isnan(ambientHumidity)) {
            Serial.println("n/a");
        } else {
            dtostrf(ambientHumidity, 4, 1, humbuffer);
            lv_label_set_text(ui_RHlabel, humbuffer);
            Serial.println(ambientHumidity);
        }

        char tempbuffer[4] = {0};
        Serial.print("TEMP: ");
        if (isnan(ambientTemperature)) {
            Serial.println("n/a");
        } else {
            dtostrf(ambientTemperature, 4, 1, tempbuffer);
            lv_label_set_text(ui_templabel, tempbuffer);
            Serial.println(ambientTemperature);
        }     

        char vocbuffer[6] = {0};
        Serial.print("Voc: ");
        if (isnan(vocIndex)) {
            Serial.println("n/a");
        } else {
            dtostrf(vocIndex, 6, 1, vocbuffer);
            lv_label_set_text(ui_tvoclabel, vocbuffer);
            Serial.println(vocIndex);
        }
        Serial.println("--------------");
    }
    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}




