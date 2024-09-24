// pm1.h
#pragma once

#include <SensirionI2CSen5x.h>
#include <Wire.h>
#include "ui/ui.h"

#define MAXBUF_REQUIREMENT 48
#define CHART_DATA_LENGTH 15
#define DATA_FREQ 5

#if (defined(I2C_BUFFER_LENGTH) &&                 \
     (I2C_BUFFER_LENGTH >= MAXBUF_REQUIREMENT)) || \
    (defined(BUFFER_LENGTH) && BUFFER_LENGTH >= MAXBUF_REQUIREMENT)
#endif

typedef struct{
    float pm1 = 0;
    float pm25 = 0;
    float pm10 = 0;
    float pm4 = 0;
    float tvoc = 0;
    int pm1_max = 0;
    int pm25_max = 0;
    int pm10_max = 0;
    int pm4_max = 0;
    int tvoc_max = 0;
    int count = 0;
} Sensor_t;

SensirionI2CSen5x sen5x;
Sensor_t sensor_data;

lv_chart_series_t * ui_PM1chart_series_1 = { 0 };
static lv_coord_t ui_PM1chart_series_1_array[CHART_DATA_LENGTH] = { 9, 10, 12, 9, 12, 24, 8, 10, 10, 39, 11, 14, 15, 16, 17 };
        
lv_chart_series_t * ui_PM25chart_series_1 = { 0 };
static lv_coord_t ui_PM25chart_series_1_array[CHART_DATA_LENGTH] = { 9, 10, 12, 9, 12, 24, 8, 10, 10, 39, 11, 14, 15, 16, 17 };

lv_chart_series_t * ui_PM4chart_series_1 = { 0 };
static lv_coord_t ui_PM4chart_series_1_array[CHART_DATA_LENGTH] = { 9, 10, 12, 9, 12, 24, 8, 10, 10, 39, 11, 14, 15, 16, 17 };

lv_chart_series_t * ui_PM10chart_series_1 = { 0 };
static lv_coord_t ui_PM10chart_series_1_array[CHART_DATA_LENGTH] = { 9, 10, 12, 9, 12, 24, 8, 10, 10, 39, 11, 14, 15, 16, 17 };

lv_chart_series_t * ui_TVOCchart_series_1 = { 0 };
static lv_coord_t ui_TVOCchart_series_1_array[CHART_DATA_LENGTH] = { 9, 10, 12, 9, 12, 24, 8, 10, 10, 39, 11, 14, 15, 16, 17 };

void setupCharts()
{
    ui_PM1chart_series_1 = lv_chart_add_series(ui_PM1chart, lv_color_hex(0x086003), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_ext_y_array(ui_PM1chart, ui_PM1chart_series_1, ui_PM1chart_series_1_array);
    lv_chart_set_range( ui_PM1chart, LV_CHART_AXIS_PRIMARY_Y, 0, 50);

    ui_PM25chart_series_1 = lv_chart_add_series(ui_PM25chart, lv_color_hex(0x086003), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_ext_y_array(ui_PM25chart, ui_PM25chart_series_1, ui_PM25chart_series_1_array);
    lv_chart_set_range( ui_PM25chart, LV_CHART_AXIS_PRIMARY_Y, 0, 50);

    ui_PM10chart_series_1 = lv_chart_add_series(ui_PM10chart, lv_color_hex(0x086003), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_ext_y_array(ui_PM10chart, ui_PM10chart_series_1, ui_PM10chart_series_1_array);
    lv_chart_set_range( ui_PM10chart, LV_CHART_AXIS_PRIMARY_Y, 0, 50);

    ui_PM4chart_series_1 = lv_chart_add_series(ui_PM4chart, lv_color_hex(0x086003), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_ext_y_array(ui_PM4chart, ui_PM4chart_series_1, ui_PM4chart_series_1_array);
    lv_chart_set_range( ui_PM4chart, LV_CHART_AXIS_PRIMARY_Y, 0, 50);

    ui_TVOCchart_series_1 = lv_chart_add_series(ui_TVOCchart, lv_color_hex(0x086003), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_set_ext_y_array(ui_TVOCchart, ui_TVOCchart_series_1, ui_TVOCchart_series_1_array);
    lv_chart_set_range( ui_TVOCchart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
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

      setupCharts();

  while(1)
  {
    uint16_t error;
    char errorMessage[256];

    // Read Measurement
    float t_pm1;
    float t_pm25;
    float t_pm4;
    float t_pm10;
    float t_hum;
    float t_temp;
    float vocIndex;
    float noxIndex;

    error = sen5x.readMeasuredValues(
        t_pm1, t_pm25, t_pm4,
        t_pm10, t_hum, t_temp, vocIndex,
        noxIndex);

    if (error) {
        Serial.print("Error trying to execute readMeasuredValues(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        
        sensor_data.pm1 += t_pm1;
        sensor_data.pm25 += t_pm25;
        sensor_data.pm10 += t_pm10;
        sensor_data.pm4 += t_pm4;
        sensor_data.count++;

        char pm1buffer[6] = {0};
        dtostrf(t_pm1, 6, 1, pm1buffer);
        lv_label_set_text(ui_pm1label, pm1buffer);

        char pm25buffer[6] = {0};
        dtostrf(t_pm25, 6, 1, pm25buffer);
        lv_label_set_text(ui_pm25label, pm25buffer);

        char pm4buffer[6] = {0};
        dtostrf(t_pm4, 6, 1, pm4buffer);
        lv_label_set_text(ui_pm4label, pm4buffer);

        char pm10buffer[6] = {0};
        dtostrf(t_pm10, 6, 1, pm10buffer);
        lv_label_set_text(ui_pm10label, pm10buffer);

        char tvocbuffer[6] = {0};
        if (isnan(vocIndex)) {
            Serial.println("n/a");
        } else {
            sensor_data.tvoc += vocIndex;
            dtostrf(vocIndex, 6, 1, tvocbuffer);
            lv_label_set_text(ui_tvoclabel, tvocbuffer);
        }

        char humbuffer[4] = {0};
        if (isnan(t_hum)) {
            Serial.println("n/a");
        } else {
            dtostrf(t_hum, 4, 1, humbuffer);
            lv_label_set_text(ui_RHlabel, humbuffer);
        }

        char tempbuffer[4] = {0};
        if (isnan(t_temp)) {
            Serial.println("n/a");
        } else {
            dtostrf(t_temp, 4, 1, tempbuffer);
            lv_label_set_text(ui_templabel, tempbuffer);
        } 

        if(sensor_data.count == DATA_FREQ)
        {

            //shift the other values to the left
            memcpy(ui_PM1chart_series_1_array, ui_PM1chart_series_1_array + 1, (CHART_DATA_LENGTH - 1)*sizeof(lv_coord_t));
            if(sensor_data.pm1_max < (sensor_data.pm1 / sensor_data.count))
            {
                sensor_data.pm1_max = int(sensor_data.pm1 / sensor_data.count);
                if(sensor_data.pm1_max > 50)
                    lv_chart_set_range( ui_PM1chart, LV_CHART_AXIS_PRIMARY_Y, 0, sensor_data.pm1_max);
            }
            //Insert new value 
            ui_PM1chart_series_1_array[CHART_DATA_LENGTH - 1] = (uint16_t) (sensor_data.pm1 / sensor_data.count);
            lv_chart_set_ext_y_array(ui_PM1chart, ui_PM1chart_series_1, ui_PM1chart_series_1_array);

            //shift the other values to the left
            memcpy(ui_PM25chart_series_1_array, ui_PM25chart_series_1_array + 1, (CHART_DATA_LENGTH - 1)*sizeof(lv_coord_t));
            if(sensor_data.pm25_max < (sensor_data.pm25 / sensor_data.count))
            {
                sensor_data.pm25_max = int(sensor_data.pm25 / sensor_data.count);
                if(sensor_data.pm25_max > 50)
                    lv_chart_set_range( ui_PM25chart, LV_CHART_AXIS_PRIMARY_Y, 0, sensor_data.pm25_max);
            }
            //Insert new value 
            ui_PM25chart_series_1_array[CHART_DATA_LENGTH - 1] = (uint16_t) (sensor_data.pm25 / sensor_data.count);
            lv_chart_set_ext_y_array(ui_PM25chart, ui_PM25chart_series_1, ui_PM25chart_series_1_array);

            //shift the other values to the left
            memcpy(ui_PM10chart_series_1_array, ui_PM10chart_series_1_array + 1, (CHART_DATA_LENGTH - 1)*sizeof(lv_coord_t));
            if(sensor_data.pm10_max < (sensor_data.pm10 / sensor_data.count))
            {
                sensor_data.pm10_max = int(sensor_data.pm10 / sensor_data.count);
                if(sensor_data.pm10_max > 50)
                    lv_chart_set_range( ui_PM10chart, LV_CHART_AXIS_PRIMARY_Y, 0, sensor_data.pm10_max);
            }
            //Insert new value 
            ui_PM10chart_series_1_array[CHART_DATA_LENGTH - 1] = (uint16_t) (sensor_data.pm10 / sensor_data.count);
            lv_chart_set_ext_y_array(ui_PM10chart, ui_PM10chart_series_1, ui_PM10chart_series_1_array);

            //shift the other values to the left
            memcpy(ui_PM4chart_series_1_array, ui_PM4chart_series_1_array + 1, (CHART_DATA_LENGTH - 1)*sizeof(lv_coord_t));
            if(sensor_data.pm4_max < (sensor_data.pm4 / sensor_data.count))
            {
                sensor_data.pm4_max = int(sensor_data.pm4 / sensor_data.count);
                if(sensor_data.pm4_max > 50)
                    lv_chart_set_range( ui_PM4chart, LV_CHART_AXIS_PRIMARY_Y, 0, sensor_data.pm4_max);
            }
            //Insert new value 
            ui_PM4chart_series_1_array[CHART_DATA_LENGTH - 1] = (uint16_t) (sensor_data.pm4 / sensor_data.count);
            lv_chart_set_ext_y_array(ui_PM4chart, ui_PM4chart_series_1, ui_PM4chart_series_1_array);

            //shift the other values to the left
            memcpy(ui_TVOCchart_series_1_array, ui_TVOCchart_series_1_array + 1, (CHART_DATA_LENGTH - 1)*sizeof(lv_coord_t));
            if(sensor_data.tvoc_max < (sensor_data.tvoc / sensor_data.count))
            {
                sensor_data.tvoc_max = int(sensor_data.tvoc / sensor_data.count);
                if(sensor_data.tvoc_max > 100)
                    lv_chart_set_range( ui_TVOCchart, LV_CHART_AXIS_PRIMARY_Y, 0, sensor_data.tvoc_max);
            }
            //Insert new value 
            ui_TVOCchart_series_1_array[CHART_DATA_LENGTH - 1] = (uint16_t) (sensor_data.tvoc / sensor_data.count);
            lv_chart_set_ext_y_array(ui_TVOCchart, ui_TVOCchart_series_1, ui_TVOCchart_series_1_array);

            sensor_data.count = 0;
            sensor_data.pm1 = 0;
            sensor_data.pm25 = 0;
            sensor_data.pm10 = 0;
            sensor_data.pm4 = 0;
            sensor_data.tvoc = 0;
        }   
    }
    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}