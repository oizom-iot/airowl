#include <Arduino.h>
#if defined(ARDUINO_M5STACK_Core2)
#include <M5Core2.h>
#endif
#if defined(ARDUINO_M5STACK_CORES3)
// #include <M5CoreS3.h>  // no touch support yet
#include <M5Unified.h>
#endif
#include <FS.h>

#include "time_func.h"
#include "Sensor.h"
#include "ui/lv_setup.h"
#include "ui/ui.h"
#include "config.h"


void setup() {
  Serial.begin(115200);
  M5.begin();  // Initialize the M5Stack peripherals
  lv_begin();  // Initialize LVGL for the Core2 screen
  ui_init();   // Initialize UI generated by Square Line
  time_init(); // Initialize time and date from compiler
  M5.In_I2C.bitOff(AW9523_ADDR, 0x02, 0b100000, 100000L);
  M5.In_I2C.bitOn(AW9523_ADDR, 0x02, 0b000010, 100000L);
  M5.In_I2C.bitOn(AW9523_ADDR, 0x03, 0b10000000, 100000L);  // BOOST_EN
  delay(2000);
  Serial.println("Enabling sensor");
  xTaskCreatePinnedToCore(sensorData, "sensorData", 10000, NULL, 2, NULL, 0);
}

void loop() {  
  lv_handler();  // Update UI
  update_time(); // Update time and date on UI
}