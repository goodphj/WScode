/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_home_analog(lv_ui *ui)
{
    //Write codes home_analog
    ui->home_analog = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_analog, 466, 466);
    lv_obj_set_scrollbar_mode(ui->home_analog, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_analog, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->home_analog, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->home_analog, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->home_analog, &_img_bg_analog_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->home_analog, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->home_analog, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_step_arc
    ui->home_analog_step_arc = lv_arc_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_step_arc, 58, 99);
    lv_obj_set_size(ui->home_analog_step_arc, 383, 356);
    lv_obj_add_flag(ui->home_analog_step_arc, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_arc_set_mode(ui->home_analog_step_arc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->home_analog_step_arc, 0, 100);
    lv_arc_set_bg_angles(ui->home_analog_step_arc, 60, 120);
    lv_arc_set_value(ui->home_analog_step_arc, 70);
    lv_arc_set_rotation(ui->home_analog_step_arc, 0);

    //Write style for home_analog_step_arc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_step_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->home_analog_step_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->home_analog_step_arc, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_analog_step_arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_analog_step_arc, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_analog_step_arc, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_step_arc, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_step_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_step_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_step_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_step_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_step_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_analog_step_arc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->home_analog_step_arc, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_analog_step_arc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_analog_step_arc, lv_color_hex(0xFF4818), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_analog_step_arc, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for home_analog_step_arc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_step_arc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->home_analog_step_arc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes home_analog_battery_arc
    ui->home_analog_battery_arc = lv_arc_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_battery_arc, 58, 5);
    lv_obj_set_size(ui->home_analog_battery_arc, 388, 356);
    lv_obj_add_flag(ui->home_analog_battery_arc, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_arc_set_mode(ui->home_analog_battery_arc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->home_analog_battery_arc, 0, 100);
    lv_arc_set_bg_angles(ui->home_analog_battery_arc, 238, 300);
    lv_arc_set_value(ui->home_analog_battery_arc, 70);
    lv_arc_set_rotation(ui->home_analog_battery_arc, 0);

    //Write style for home_analog_battery_arc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->home_analog_battery_arc, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_analog_battery_arc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_analog_battery_arc, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_analog_battery_arc, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_battery_arc, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_battery_arc, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_battery_arc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_analog_battery_arc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->home_analog_battery_arc, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_analog_battery_arc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_analog_battery_arc, lv_color_hex(0x1000ff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_analog_battery_arc, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for home_analog_battery_arc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_analog_battery_arc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->home_analog_battery_arc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes home_analog_nxp_log
    ui->home_analog_nxp_log = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_nxp_log, 477, 206);
    lv_obj_set_size(ui->home_analog_nxp_log, 100, 49);
    lv_obj_add_flag(ui->home_analog_nxp_log, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_nxp_log, &_NXP_Logo_ARGB8888_100x49);
    lv_image_set_pivot(ui->home_analog_nxp_log, 50,50);
    lv_image_set_rotation(ui->home_analog_nxp_log, 0);

    //Write style for home_analog_nxp_log, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_nxp_log, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_nxp_log, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_step_icon
    ui->home_analog_step_icon = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_step_icon, 193, 401);
    lv_obj_set_size(ui->home_analog_step_icon, 20, 24);
    lv_obj_add_flag(ui->home_analog_step_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_step_icon, &_icn_step_red_ARGB8888_20x24);
    lv_image_set_pivot(ui->home_analog_step_icon, 50,50);
    lv_image_set_rotation(ui->home_analog_step_icon, 0);

    //Write style for home_analog_step_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_step_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_step_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_step_text
    ui->home_analog_step_text = lv_label_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_step_text, 221, 401);
    lv_obj_set_size(ui->home_analog_step_text, 70, 24);
    lv_label_set_text(ui->home_analog_step_text, "1526");
    lv_label_set_long_mode(ui->home_analog_step_text, LV_LABEL_LONG_WRAP);

    //Write style for home_analog_step_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_step_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_step_text, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_step_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_step_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_step_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_temp_text
    ui->home_analog_temp_text = lv_label_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_temp_text, 78, 297);
    lv_obj_set_size(ui->home_analog_temp_text, 55, 24);
    lv_label_set_text(ui->home_analog_temp_text, "26°");
    lv_label_set_long_mode(ui->home_analog_temp_text, LV_LABEL_LONG_WRAP);

    //Write style for home_analog_temp_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_temp_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_temp_text, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_temp_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_temp_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_temp_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_weather_icon
    ui->home_analog_weather_icon = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_weather_icon, 72, 248);
    lv_obj_set_size(ui->home_analog_weather_icon, 48, 39);
    lv_obj_add_flag(ui->home_analog_weather_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_weather_icon, &_icn_weather_1_ARGB8888_48x39);
    lv_image_set_pivot(ui->home_analog_weather_icon, 50,50);
    lv_image_set_rotation(ui->home_analog_weather_icon, 0);

    //Write style for home_analog_weather_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_weather_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->home_analog_weather_icon, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_weather_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_week_day
    ui->home_analog_week_day = lv_label_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_week_day, 64, 171);
    lv_obj_set_size(ui->home_analog_week_day, 79, 29);
    lv_label_set_text(ui->home_analog_week_day, "WED");
    lv_label_set_long_mode(ui->home_analog_week_day, LV_LABEL_LONG_WRAP);

    //Write style for home_analog_week_day, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_week_day, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_week_day, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_week_day, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_week_day, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_week_day, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_date_text
    ui->home_analog_date_text = lv_label_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_date_text, 64, 141);
    lv_obj_set_size(ui->home_analog_date_text, 87, 24);
    lv_label_set_text(ui->home_analog_date_text, "05/15");
    lv_label_set_long_mode(ui->home_analog_date_text, LV_LABEL_LONG_WRAP);

    //Write style for home_analog_date_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_date_text, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_date_text, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_date_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_date_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_date_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_battery_icon
    ui->home_analog_battery_icon = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_battery_icon, 185, 41);
    lv_obj_set_size(ui->home_analog_battery_icon, 20, 24);
    lv_obj_add_flag(ui->home_analog_battery_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_battery_icon, &_icn_flash_blue_ARGB8888_20x24);
    lv_image_set_pivot(ui->home_analog_battery_icon, 50,50);
    lv_image_set_rotation(ui->home_analog_battery_icon, 0);

    //Write style for home_analog_battery_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_battery_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_battery_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_battery_text
    ui->home_analog_battery_text = lv_label_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_battery_text, 221, 41);
    lv_obj_set_size(ui->home_analog_battery_text, 70, 24);
    lv_obj_add_flag(ui->home_analog_battery_text, LV_OBJ_FLAG_CLICKABLE);
    lv_label_set_text(ui->home_analog_battery_text, "86%");
    lv_label_set_long_mode(ui->home_analog_battery_text, LV_LABEL_LONG_WRAP);

    //Write style for home_analog_battery_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_analog_battery_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_analog_battery_text, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_analog_battery_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_analog_battery_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_analog_battery_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_dot_list
    ui->home_analog_dot_list = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_dot_list, 433, 166);
    lv_obj_set_size(ui->home_analog_dot_list, 13, 139);
    lv_obj_add_flag(ui->home_analog_dot_list, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_dot_list, &_img_menu_ARGB8888_13x139);
    lv_image_set_pivot(ui->home_analog_dot_list, 50,50);
    lv_image_set_rotation(ui->home_analog_dot_list, 0);

    //Write style for home_analog_dot_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_dot_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_dot_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_img_dot
    ui->home_analog_img_dot = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_img_dot, 433, 166);
    lv_obj_set_size(ui->home_analog_img_dot, 9, 9);
    lv_obj_add_flag(ui->home_analog_img_dot, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_img_dot, &_dot_ARGB8888_9x9);
    lv_image_set_pivot(ui->home_analog_img_dot, 50,50);
    lv_image_set_rotation(ui->home_analog_img_dot, 0);

    //Write style for home_analog_img_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_img_dot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_img_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_message_icon
    ui->home_analog_message_icon = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_message_icon, 356, 319);
    lv_obj_set_size(ui->home_analog_message_icon, 23, 29);
    lv_obj_add_flag(ui->home_analog_message_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_message_icon, &_icn_message_ARGB8888_23x29);
    lv_image_set_pivot(ui->home_analog_message_icon, 50,50);
    lv_image_set_rotation(ui->home_analog_message_icon, 0);

    //Write style for home_analog_message_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_message_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_message_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_sport_icon
    ui->home_analog_sport_icon = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_sport_icon, 356, 121);
    lv_obj_set_size(ui->home_analog_sport_icon, 23, 29);
    lv_obj_add_flag(ui->home_analog_sport_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_sport_icon, &_icn_sport_ARGB8888_23x29);
    lv_image_set_pivot(ui->home_analog_sport_icon, 50,50);
    lv_image_set_rotation(ui->home_analog_sport_icon, 0);

    //Write style for home_analog_sport_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_sport_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_sport_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_message_text
    ui->home_analog_message_text = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_message_text, 354, 324);
    lv_obj_set_size(ui->home_analog_message_text, 83, 83);
    lv_obj_add_flag(ui->home_analog_message_text, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_message_text, &_text_message_ARGB8888_83x83);
    lv_image_set_pivot(ui->home_analog_message_text, 50,50);
    lv_image_set_rotation(ui->home_analog_message_text, -30);

    //Write style for home_analog_message_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_message_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_message_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_sport_text
    ui->home_analog_sport_text = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_sport_text, 376, 91);
    lv_obj_set_size(ui->home_analog_sport_text, 59, 59);
    lv_obj_add_flag(ui->home_analog_sport_text, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_sport_text, &_text_sport_ARGB8888_59x59);
    lv_image_set_pivot(ui->home_analog_sport_text, 50,50);
    lv_image_set_rotation(ui->home_analog_sport_text, 60);

    //Write style for home_analog_sport_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_sport_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_sport_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_img_Sec
    ui->home_analog_img_Sec = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_img_Sec, 218, 77);
    lv_obj_set_size(ui->home_analog_img_Sec, 30, 180);
    lv_obj_add_flag(ui->home_analog_img_Sec, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_img_Sec, &_img_clockwise_sec_ARGB8888_30x180);
    lv_image_set_pivot(ui->home_analog_img_Sec, 15,156);
    lv_image_set_rotation(ui->home_analog_img_Sec, 0);

    //Write style for home_analog_img_Sec, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_img_Sec, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_img_Sec, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_img_Min
    ui->home_analog_img_Min = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_img_Min, 224, 76);
    lv_obj_set_size(ui->home_analog_img_Min, 18, 157);
    lv_obj_add_flag(ui->home_analog_img_Min, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_img_Min, &_img_clockwise_min_ARGB8888_18x157);
    lv_image_set_pivot(ui->home_analog_img_Min, 9,157);
    lv_image_set_rotation(ui->home_analog_img_Min, 0);

    //Write style for home_analog_img_Min, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_img_Min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_img_Min, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_analog_img_Hour
    ui->home_analog_img_Hour = lv_image_create(ui->home_analog);
    lv_obj_set_pos(ui->home_analog_img_Hour, 224, 135);
    lv_obj_set_size(ui->home_analog_img_Hour, 18, 98);
    lv_obj_add_flag(ui->home_analog_img_Hour, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_analog_img_Hour, &_img_clockwise_hour_ARGB8888_18x98);
    lv_image_set_pivot(ui->home_analog_img_Hour, 9,98);
    lv_image_set_rotation(ui->home_analog_img_Hour, 0);

    //Write style for home_analog_img_Hour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_analog_img_Hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_analog_img_Hour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of home_analog.


    //Update current screen layout.
    lv_obj_update_layout(ui->home_analog);

    //Init events for screen.
    events_init_home_analog(ui);
}
