// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.6
// Project name: example_project

#include "../ui.h"

void ui_owl_screen_init(void)
{
ui_owl = lv_obj_create(NULL);
lv_obj_clear_flag( ui_owl, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_owl, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_owl, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Container1 = lv_obj_create(ui_owl);
lv_obj_remove_style_all(ui_Container1);
lv_obj_set_width( ui_Container1, 130);
lv_obj_set_height( ui_Container1, 130);
lv_obj_set_x( ui_Container1, -90 );
lv_obj_set_y( ui_Container1, -20 );
lv_obj_set_align( ui_Container1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Container1, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Container1, 65, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Container1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Container1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Container2 = lv_obj_create(ui_owl);
lv_obj_remove_style_all(ui_Container2);
lv_obj_set_width( ui_Container2, 130);
lv_obj_set_height( ui_Container2, 130);
lv_obj_set_x( ui_Container2, 90 );
lv_obj_set_y( ui_Container2, -20 );
lv_obj_set_align( ui_Container2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Container2, 65, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Container2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Container2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Container3 = lv_obj_create(ui_owl);
lv_obj_remove_style_all(ui_Container3);
lv_obj_set_width( ui_Container3, 60);
lv_obj_set_height( ui_Container3, 60);
lv_obj_set_x( ui_Container3, 90 );
lv_obj_set_y( ui_Container3, -20 );
lv_obj_set_align( ui_Container3, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Container3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Container3, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Container3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Container3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Container4 = lv_obj_create(ui_owl);
lv_obj_remove_style_all(ui_Container4);
lv_obj_set_width( ui_Container4, 60);
lv_obj_set_height( ui_Container4, 60);
lv_obj_set_x( ui_Container4, -90 );
lv_obj_set_y( ui_Container4, -20 );
lv_obj_set_align( ui_Container4, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Container4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Container4, 30, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Container4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Container4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image1 = lv_img_create(ui_owl);
lv_img_set_src(ui_Image1, &ui_img_26368195);
lv_obj_set_width( ui_Image1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image1, -1 );
lv_obj_set_y( ui_Image1, 57 );
lv_obj_set_align( ui_Image1, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image1, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image1,128);

lv_obj_add_event_cb(ui_owl, ui_event_owl, LV_EVENT_ALL, NULL);

}