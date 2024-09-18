#pragma once

#include <Arduino.h>
#include "ui/ui.h"

void time_init()
{
    // Get time and date from compiler
    String timeDate = String(__TIME__) + " " + String(__DATE__);

    // Convert time and date to tm struct
    struct tm timeinfo = {0};
    strptime(timeDate.c_str(), "%H:%M:%S %b %d %Y", &timeinfo);
    Serial.println("Time set to: " + timeDate);

    // Convert tm struct to epoch time
    timeval tv = {
        .tv_sec = mktime(&timeinfo),
        .tv_usec = 0,
    };

    // Set time and date using c standard library
    settimeofday(&tv, NULL);
}

void update_time()
{
    // Update time and date using c standard library
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    // Update time label
    char time_buf[9];
    strftime(time_buf, sizeof(time_buf), "%H:%M:%S", &timeinfo);
    lv_label_set_text(ui_time, time_buf);

    // Update date label
    char date_buf[24];
    strftime(date_buf, sizeof(date_buf), "%a %b %d %Y", &timeinfo);
    lv_label_set_text(ui_date, date_buf);
}