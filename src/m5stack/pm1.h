// pm1.h
#pragma once

#include <Arduino.h>
#include "ui/ui.h"

extern int pm1;

//void setup_pm1();
//void update_pm1();

//lv_chart_series_t * ui_Chart3_series_1 = lv_chart_add_series(ui_Chart3, lv_color_hex(0x086003),
                                                                 //LV_CHART_AXIS_PRIMARY_Y);

void pm1func() {

    int pm1 = 9000;
    int pm25 = 650;
    int pm4 = 5600;
    int pm10 = 3500;
    //int arr[15] = {600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1300, 1200, 1100, 1000, 1300 ,1700};

    String pm1String = String(pm1);
    String pm25String = String(pm25);
    String pm4String = String(pm4);
    String pm10String = String(pm10);
    lv_label_set_text(ui_gpvalue, pm1String.c_str());
    lv_label_set_text(ui_pm1label, pm1String.c_str());
    lv_label_set_text(ui_gpvalue2, pm25String.c_str());
    lv_label_set_text(ui_pm25label, pm25String.c_str());
    lv_label_set_text(ui_gpvalue1, pm4String.c_str());
    lv_label_set_text(ui_pm4label, pm4String.c_str());
    lv_label_set_text(ui_gpvalue3, pm10String.c_str());
    lv_label_set_text(ui_pm10label, pm10String.c_str());
    //lv_chart_set_ext_y_array(ui_Chart3, ui_Chart3_series_1, arr);

    

}




