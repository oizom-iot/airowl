// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.6
// Project name: example_project

#include "../ui.h"

void ui_PM1graph_screen_init(void)
{
ui_PM1graph = lv_obj_create(NULL);
lv_obj_clear_flag( ui_PM1graph, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_PM1graph, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PM1graph, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_PM1chart = lv_chart_create(ui_PM1graph);
lv_obj_set_width( ui_PM1chart, 262);
lv_obj_set_height( ui_PM1chart, 132);
lv_obj_set_x( ui_PM1chart, 13 );
lv_obj_set_y( ui_PM1chart, -9 );
lv_obj_set_align( ui_PM1chart, LV_ALIGN_CENTER );
lv_chart_set_type( ui_PM1chart, LV_CHART_TYPE_BAR);
lv_chart_set_point_count( ui_PM1chart, 15);
lv_chart_set_range( ui_PM1chart, LV_CHART_AXIS_PRIMARY_Y, 500, 1800);
lv_chart_set_div_line_count( ui_PM1chart, 0, 0);
lv_chart_set_axis_tick( ui_PM1chart, LV_CHART_AXIS_PRIMARY_X, 0, 5, 5, 2, false, 50);
lv_chart_set_axis_tick( ui_PM1chart, LV_CHART_AXIS_PRIMARY_Y, 5, 5, 11, 2, true, 50);
lv_chart_set_axis_tick( ui_PM1chart, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 2, false, 25);
lv_obj_set_style_bg_color(ui_PM1chart, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_PM1chart, 255, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_graphparameter = lv_label_create(ui_PM1graph);
lv_obj_set_width( ui_graphparameter, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_graphparameter, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_graphparameter, -121 );
lv_obj_set_y( ui_graphparameter, -99 );
lv_obj_set_align( ui_graphparameter, LV_ALIGN_CENTER );
lv_label_set_text(ui_graphparameter,"PM1.0");
lv_obj_set_style_text_color(ui_graphparameter, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_graphparameter, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_graphparameter, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Container13 = lv_obj_create(ui_PM1graph);
lv_obj_remove_style_all(ui_Container13);
lv_obj_set_width( ui_Container13, 314);
lv_obj_set_height( ui_Container13, 30);
lv_obj_set_x( ui_Container13, 1 );
lv_obj_set_y( ui_Container13, -99 );
lv_obj_set_align( ui_Container13, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Container13, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_border_color(ui_Container13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Container13, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_Container13, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_outline_color(ui_Container13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_outline_opa(ui_Container13, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_gpunit = lv_label_create(ui_PM1graph);
lv_obj_set_width( ui_gpunit, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_gpunit, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_gpunit, -76 );
lv_obj_set_y( ui_gpunit, -98 );
lv_obj_set_align( ui_gpunit, LV_ALIGN_CENTER );
lv_label_set_text(ui_gpunit,"ug/m");
lv_obj_set_style_text_color(ui_gpunit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_gpunit, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_gpunit, &lv_font_montserrat_10, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_pm1cv = lv_label_create(ui_PM1graph);
lv_obj_set_width( ui_pm1cv, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_pm1cv, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_pm1cv, 99 );
lv_obj_set_y( ui_pm1cv, -100 );
lv_obj_set_align( ui_pm1cv, LV_ALIGN_CENTER );
lv_label_set_text(ui_pm1cv,"1200");
lv_obj_set_style_text_color(ui_pm1cv, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_pm1cv, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_pm1cv, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_return = lv_btn_create(ui_PM1graph);
lv_obj_set_width( ui_return, 245);
lv_obj_set_height( ui_return, 37);
lv_obj_set_x( ui_return, 9 );
lv_obj_set_y( ui_return, 85 );
lv_obj_set_align( ui_return, LV_ALIGN_CENTER );
lv_obj_set_style_radius(ui_return, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_return, lv_color_hex(0x086100), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_return, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_return, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_return, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_returnlabel = lv_label_create(ui_PM1graph);
lv_obj_set_width( ui_returnlabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_returnlabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_returnlabel, 6 );
lv_obj_set_y( ui_returnlabel, 86 );
lv_obj_set_align( ui_returnlabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_returnlabel,"RETURN");
lv_obj_set_style_text_color(ui_returnlabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_returnlabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_returnlabel, &lv_font_montserrat_30, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_cube = lv_label_create(ui_PM1graph);
lv_obj_set_width( ui_cube, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_cube, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_cube, -59 );
lv_obj_set_y( ui_cube, -104 );
lv_obj_set_align( ui_cube, LV_ALIGN_CENTER );
lv_label_set_text(ui_cube,"3");
lv_obj_set_style_text_color(ui_cube, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_cube, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_cube, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_cube1 = lv_label_create(ui_PM1graph);
lv_obj_set_width( ui_cube1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_cube1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_cube1, -59 );
lv_obj_set_y( ui_cube1, -104 );
lv_obj_set_align( ui_cube1, LV_ALIGN_CENTER );
lv_label_set_text(ui_cube1,"3");
lv_obj_set_style_text_color(ui_cube1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_cube1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_cube1, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_return, ui_event_return, LV_EVENT_ALL, NULL);

}