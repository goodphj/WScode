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



void setup_scr_home_digital(lv_ui *ui)
{
    //Write codes home_digital
    ui->home_digital = lv_obj_create(NULL);
    lv_obj_set_size(ui->home_digital, 466, 466);
    lv_obj_set_scrollbar_mode(ui->home_digital, LV_SCROLLBAR_MODE_OFF);

    //Write style for home_digital, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->home_digital, &_img_bg_digital_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->home_digital, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->home_digital, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_dialDot
    ui->home_digital_img_dialDot = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_dialDot, 433, 166);
    lv_obj_set_size(ui->home_digital_img_dialDot, 13, 139);
    lv_obj_add_flag(ui->home_digital_img_dialDot, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_dialDot, &_img_menu_ARGB8888_13x139);
    lv_image_set_pivot(ui->home_digital_img_dialDot, 50,50);
    lv_image_set_rotation(ui->home_digital_img_dialDot, 0);

    //Write style for home_digital_img_dialDot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_dialDot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_dialDot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_min
    ui->home_digital_label_min = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_label_min, 158, 477);
    lv_obj_set_size(ui->home_digital_label_min, 180, 123);
    lv_label_set_text(ui->home_digital_label_min, "32");
    lv_label_set_long_mode(ui->home_digital_label_min, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_label_min, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_min, lv_color_hex(0xFF4818), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_min, &lv_font_montserratMedium_130, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_min, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_min, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_min, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_hour
    ui->home_digital_label_hour = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_label_hour, 165, -153);
    lv_obj_set_size(ui->home_digital_label_hour, 178, 145);
    lv_label_set_text(ui->home_digital_label_hour, "15");
    lv_label_set_long_mode(ui->home_digital_label_hour, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_label_hour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_hour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_hour, &lv_font_montserratMedium_142, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_hour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_hour, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_hour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_dot
    ui->home_digital_img_dot = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_dot, 433, 166);
    lv_obj_set_size(ui->home_digital_img_dot, 9, 9);
    lv_obj_add_flag(ui->home_digital_img_dot, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_dot, &_dot_ARGB8888_9x9);
    lv_image_set_pivot(ui->home_digital_img_dot, 50,50);
    lv_image_set_rotation(ui->home_digital_img_dot, 0);

    //Write style for home_digital_img_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_dot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_arc_steps
    ui->home_digital_arc_steps = lv_arc_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_arc_steps, 58, 99);
    lv_obj_set_size(ui->home_digital_arc_steps, 383, 356);
    lv_arc_set_mode(ui->home_digital_arc_steps, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->home_digital_arc_steps, 0, 100);
    lv_arc_set_bg_angles(ui->home_digital_arc_steps, 60, 120);
    lv_arc_set_value(ui->home_digital_arc_steps, 70);
    lv_arc_set_rotation(ui->home_digital_arc_steps, 0);

    //Write style for home_digital_arc_steps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital_arc_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->home_digital_arc_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->home_digital_arc_steps, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_digital_arc_steps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_digital_arc_steps, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_digital_arc_steps, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_arc_steps, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_arc_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_arc_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_arc_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_arc_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_arc_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_digital_arc_steps, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->home_digital_arc_steps, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_digital_arc_steps, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_digital_arc_steps, lv_color_hex(0xFF4818), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_digital_arc_steps, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for home_digital_arc_steps, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital_arc_steps, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->home_digital_arc_steps, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes home_digital_arc_battery
    ui->home_digital_arc_battery = lv_arc_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_arc_battery, 58, 5);
    lv_obj_set_size(ui->home_digital_arc_battery, 388, 356);
    lv_arc_set_mode(ui->home_digital_arc_battery, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->home_digital_arc_battery, 0, 100);
    lv_arc_set_bg_angles(ui->home_digital_arc_battery, 238, 300);
    lv_arc_set_value(ui->home_digital_arc_battery, 70);
    lv_arc_set_rotation(ui->home_digital_arc_battery, 0);

    //Write style for home_digital_arc_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital_arc_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->home_digital_arc_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->home_digital_arc_battery, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_digital_arc_battery, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_digital_arc_battery, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_digital_arc_battery, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_arc_battery, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_arc_battery, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_arc_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_arc_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_arc_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_arc_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for home_digital_arc_battery, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->home_digital_arc_battery, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->home_digital_arc_battery, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->home_digital_arc_battery, lv_color_hex(0x1000ff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->home_digital_arc_battery, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for home_digital_arc_battery, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->home_digital_arc_battery, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->home_digital_arc_battery, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes home_digital_img_walk
    ui->home_digital_img_walk = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_walk, 356, 121);
    lv_obj_set_size(ui->home_digital_img_walk, 23, 29);
    lv_obj_add_flag(ui->home_digital_img_walk, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_walk, &_icn_sport_ARGB8888_23x29);
    lv_image_set_pivot(ui->home_digital_img_walk, 50,50);
    lv_image_set_rotation(ui->home_digital_img_walk, 0);

    //Write style for home_digital_img_walk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_walk, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_walk, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_NXP
    ui->home_digital_img_NXP = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_NXP, 477, 206);
    lv_obj_set_size(ui->home_digital_img_NXP, 100, 49);
    lv_obj_add_flag(ui->home_digital_img_NXP, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_NXP, &_NXP_Logo_ARGB8888_100x49);
    lv_image_set_pivot(ui->home_digital_img_NXP, 50,50);
    lv_image_set_rotation(ui->home_digital_img_NXP, 0);

    //Write style for home_digital_img_NXP, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_NXP, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_NXP, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_step
    ui->home_digital_img_step = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_step, 193, 401);
    lv_obj_set_size(ui->home_digital_img_step, 20, 24);
    lv_obj_add_flag(ui->home_digital_img_step, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_step, &_icn_step_red_ARGB8888_20x24);
    lv_image_set_pivot(ui->home_digital_img_step, 50,50);
    lv_image_set_rotation(ui->home_digital_img_step, 0);

    //Write style for home_digital_img_step, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_step, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_steps
    ui->home_digital_label_steps = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_label_steps, 221, 401);
    lv_obj_set_size(ui->home_digital_label_steps, 70, 24);
    lv_label_set_text(ui->home_digital_label_steps, "1526");
    lv_label_set_long_mode(ui->home_digital_label_steps, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_label_steps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_steps, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_steps, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_steps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_steps, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_temp
    ui->home_digital_label_temp = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_label_temp, 78, 297);
    lv_obj_set_size(ui->home_digital_label_temp, 55, 24);
    lv_label_set_text(ui->home_digital_label_temp, "26°");
    lv_label_set_long_mode(ui->home_digital_label_temp, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_label_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_temp, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_temp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_weather
    ui->home_digital_img_weather = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_weather, 72, 248);
    lv_obj_set_size(ui->home_digital_img_weather, 48, 39);
    lv_obj_add_flag(ui->home_digital_img_weather, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_weather, &_icn_weather_1_ARGB8888_48x39);
    lv_image_set_pivot(ui->home_digital_img_weather, 50,50);
    lv_image_set_rotation(ui->home_digital_img_weather, 0);

    //Write style for home_digital_img_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_recolor(ui->home_digital_img_weather, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_week
    ui->home_digital_label_week = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_label_week, 64, 171);
    lv_obj_set_size(ui->home_digital_label_week, 79, 29);
    lv_label_set_text(ui->home_digital_label_week, "WED");
    lv_label_set_long_mode(ui->home_digital_label_week, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_label_week, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_week, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_week, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_week, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_week, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_week, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_date
    ui->home_digital_label_date = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_label_date, 64, 141);
    lv_obj_set_size(ui->home_digital_label_date, 87, 24);
    lv_label_set_text(ui->home_digital_label_date, "05/15");
    lv_label_set_long_mode(ui->home_digital_label_date, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_label_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_date, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_date, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_date, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_sport
    ui->home_digital_img_sport = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_sport, 376, 91);
    lv_obj_set_size(ui->home_digital_img_sport, 59, 59);
    lv_obj_add_flag(ui->home_digital_img_sport, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_sport, &_text_sport_ARGB8888_59x59);
    lv_image_set_pivot(ui->home_digital_img_sport, 50,50);
    lv_image_set_rotation(ui->home_digital_img_sport, 60);

    //Write style for home_digital_img_sport, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_sport, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_sport, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_bell
    ui->home_digital_img_bell = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_bell, 356, 319);
    lv_obj_set_size(ui->home_digital_img_bell, 23, 29);
    lv_obj_add_flag(ui->home_digital_img_bell, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_bell, &_icn_message_ARGB8888_23x29);
    lv_image_set_pivot(ui->home_digital_img_bell, 50,50);
    lv_image_set_rotation(ui->home_digital_img_bell, 0);

    //Write style for home_digital_img_bell, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_bell, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_bell, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_battery
    ui->home_digital_img_battery = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_battery, 185, 41);
    lv_obj_set_size(ui->home_digital_img_battery, 20, 24);
    lv_obj_add_flag(ui->home_digital_img_battery, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_battery, &_icn_flash_blue_ARGB8888_20x24);
    lv_image_set_pivot(ui->home_digital_img_battery, 50,50);
    lv_image_set_rotation(ui->home_digital_img_battery, 0);

    //Write style for home_digital_img_battery, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_battery, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_battery, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_label_battery_test
    ui->home_digital_label_battery_test = lv_label_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_label_battery_test, 221, 41);
    lv_obj_set_size(ui->home_digital_label_battery_test, 70, 24);
    lv_obj_add_flag(ui->home_digital_label_battery_test, LV_OBJ_FLAG_CLICKABLE);
    lv_label_set_text(ui->home_digital_label_battery_test, "86%");
    lv_label_set_long_mode(ui->home_digital_label_battery_test, LV_LABEL_LONG_WRAP);

    //Write style for home_digital_label_battery_test, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->home_digital_label_battery_test, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->home_digital_label_battery_test, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->home_digital_label_battery_test, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->home_digital_label_battery_test, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->home_digital_label_battery_test, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_dot_list
    ui->home_digital_img_dot_list = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_dot_list, 433, 166);
    lv_obj_set_size(ui->home_digital_img_dot_list, 13, 139);
    lv_obj_add_flag(ui->home_digital_img_dot_list, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_dot_list, &_img_menu_ARGB8888_13x139);
    lv_image_set_pivot(ui->home_digital_img_dot_list, 50,50);
    lv_image_set_rotation(ui->home_digital_img_dot_list, 0);

    //Write style for home_digital_img_dot_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_dot_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_dot_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes home_digital_img_msg
    ui->home_digital_img_msg = lv_image_create(ui->home_digital);
    lv_obj_set_pos(ui->home_digital_img_msg, 354, 324);
    lv_obj_set_size(ui->home_digital_img_msg, 83, 83);
    lv_obj_add_flag(ui->home_digital_img_msg, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->home_digital_img_msg, &_text_message_ARGB8888_83x83);
    lv_image_set_pivot(ui->home_digital_img_msg, 50,50);
    lv_image_set_rotation(ui->home_digital_img_msg, -30);

    //Write style for home_digital_img_msg, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->home_digital_img_msg, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->home_digital_img_msg, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of home_digital.


    //Update current screen layout.
    lv_obj_update_layout(ui->home_digital);

    //Init events for screen.
    events_init_home_digital(ui);
}
