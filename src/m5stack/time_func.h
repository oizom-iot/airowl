#pragma once

#include <Arduino.h>
#include "ui/ui.h"

//  #define NTP_TIMEZONE  "IST-5:30"
//  #define NTP_SERVER1   "0.pool.ntp.org"
//  #define NTP_SERVER2   "1.pool.ntp.org"
//  #define NTP_SERVER3   "2.pool.ntp.org"

 #if __has_include (<esp_sntp.h>)
  #include <esp_sntp.h>
  #define SNTP_ENABLED 1
 #elif __has_include (<sntp.h>)
  #include <sntp.h>
  #define SNTP_ENABLED 1
 #endif

#ifndef SNTP_ENABLED
#define SNTP_ENABLED 0
#endif

#include <M5Unified.h>
#include <WiFi.h>

void time_init()
{
    if(WiFi.status() == WL_CONNECTED){
        WiFiManagerNS::configTime();
        lv_img_set_src(ui_nose, &ui_img_airowl_2_png);
    }
    else
    {
        lv_img_set_src(ui_nose, &ui_img_airowl_1_png);
    }
    // if (WiFi.status() == WL_CONNECTED) {
    //     configTzTime(NTP_TIMEZONE, NTP_SERVER1, NTP_SERVER2, NTP_SERVER3);
    //     lv_img_set_src(ui_nose, &ui_img_airowl_2_png);
    //     M5.Log.println("\r\nWiFi Connected.");
    //     M5.Log.print("NTP:");
    // #if SNTP_ENABLED
    //     while (sntp_get_sync_status() != SNTP_SYNC_STATUS_COMPLETED)
    //     {
    //     M5.Log.print(".");
    //     delay(1000);
    //     }
    // #else
    //     delay(1600);
    //     struct tm timeInfo;
    //     while (!getLocalTime(&timeInfo, 1000))
    //     {
    //     M5.Log.print('.');
    //     };
    // #endif
    //     M5.Log.println("\r\nNTP Connected.");

    //     time_t t = time(nullptr)+1; // Advance one second.
    //     while (t > time(nullptr));  /// Synchronization in seconds
    //     M5.Rtc.setDateTime( gmtime( &t ) );
    // }
    // else
    // {
    //     lv_img_set_src(ui_nose, &ui_img_airowl_1_png);
    //     M5.Log.println("\r\nWiFi none...");
    // }
}

void update_time()
{   
    auto t = time(nullptr);
    auto tm = localtime(&t); 

    char time_buf[9];

    // Format the time string
    sprintf(time_buf, "%02d:%02d:%02d", tm->tm_hour, tm->tm_min, tm->tm_sec);
    lv_label_set_text(ui_clock2, time_buf);
}
