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



void setup_scr_stress_level(lv_ui *ui)
{
    //Write codes stress_level
    ui->stress_level = lv_obj_create(NULL);
    lv_obj_set_size(ui->stress_level, 466, 466);
    lv_obj_set_scrollbar_mode(ui->stress_level, LV_SCROLLBAR_MODE_OFF);

    //Write style for stress_level, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->stress_level, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->stress_level, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->stress_level, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->stress_level, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stress_level_arc_stress
    ui->stress_level_arc_stress = lv_arc_create(ui->stress_level);
    lv_obj_set_pos(ui->stress_level_arc_stress, 13, 13);
    lv_obj_set_size(ui->stress_level_arc_stress, 439, 439);
    lv_obj_add_flag(ui->stress_level_arc_stress, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_arc_set_mode(ui->stress_level_arc_stress, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->stress_level_arc_stress, 0, 100);
    lv_arc_set_bg_angles(ui->stress_level_arc_stress, 48, 212);
    lv_arc_set_value(ui->stress_level_arc_stress, 70);
    lv_arc_set_rotation(ui->stress_level_arc_stress, 0);

    //Write style for stress_level_arc_stress, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->stress_level_arc_stress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->stress_level_arc_stress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->stress_level_arc_stress, 12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->stress_level_arc_stress, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->stress_level_arc_stress, lv_color_hex(0x29CE08), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->stress_level_arc_stress, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->stress_level_arc_stress, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->stress_level_arc_stress, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->stress_level_arc_stress, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->stress_level_arc_stress, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->stress_level_arc_stress, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->stress_level_arc_stress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for stress_level_arc_stress, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->stress_level_arc_stress, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->stress_level_arc_stress, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->stress_level_arc_stress, lv_color_hex(0x29CE08), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->stress_level_arc_stress, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for stress_level_arc_stress, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->stress_level_arc_stress, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->stress_level_arc_stress, lv_color_hex(0xFFFFFF), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->stress_level_arc_stress, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->stress_level_arc_stress, 4, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes stress_level_label_ago
    ui->stress_level_label_ago = lv_label_create(ui->stress_level);
    lv_obj_set_pos(ui->stress_level_label_ago, 158, 20);
    lv_obj_set_size(ui->stress_level_label_ago, 150, 38);
    lv_label_set_text(ui->stress_level_label_ago, "1 min ago");
    lv_label_set_long_mode(ui->stress_level_label_ago, LV_LABEL_LONG_WRAP);

    //Write style for stress_level_label_ago, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->stress_level_label_ago, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->stress_level_label_ago, &lv_font_montserratMedium_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->stress_level_label_ago, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->stress_level_label_ago, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->stress_level_label_ago, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stress_level_title
    ui->stress_level_title = lv_label_create(ui->stress_level);
    lv_obj_set_pos(ui->stress_level_title, 0, -60);
    lv_obj_set_size(ui->stress_level_title, 466, 89);
    lv_obj_add_flag(ui->stress_level_title, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->stress_level_title, "Stress level");
    lv_label_set_long_mode(ui->stress_level_title, LV_LABEL_LONG_WRAP);

    //Write style for stress_level_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->stress_level_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->stress_level_title, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->stress_level_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->stress_level_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->stress_level_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->stress_level_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->stress_level_title, &_img_header_bg_ARGB8888_466x89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->stress_level_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui->stress_level_title, lv_color_hex(0xBD1C39), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->stress_level_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->stress_level_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stress_level_stress_icon
    ui->stress_level_stress_icon = lv_image_create(ui->stress_level);
    lv_obj_set_pos(ui->stress_level_stress_icon, 193, 161);
    lv_obj_set_size(ui->stress_level_stress_icon, 79, 124);
    lv_obj_add_flag(ui->stress_level_stress_icon, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->stress_level_stress_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->stress_level_stress_icon, &_img_stress_level_ARGB8888_79x124);
    lv_image_set_pivot(ui->stress_level_stress_icon, 50,50);
    lv_image_set_rotation(ui->stress_level_stress_icon, 0);

    //Write style for stress_level_stress_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->stress_level_stress_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->stress_level_stress_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stress_level_label_average
    ui->stress_level_label_average = lv_label_create(ui->stress_level);
    lv_obj_set_pos(ui->stress_level_label_average, 153, 370);
    lv_obj_set_size(ui->stress_level_label_average, 165, 48);
    lv_label_set_text(ui->stress_level_label_average, "Average");
    lv_label_set_long_mode(ui->stress_level_label_average, LV_LABEL_LONG_WRAP);

    //Write style for stress_level_label_average, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->stress_level_label_average, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->stress_level_label_average, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->stress_level_label_average, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->stress_level_label_average, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->stress_level_label_average, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stress_level_img_3
    ui->stress_level_img_3 = lv_image_create(ui->stress_level);
    lv_obj_set_pos(ui->stress_level_img_3, 391, 319);
    lv_obj_set_size(ui->stress_level_img_3, 45, 60);
    lv_obj_add_flag(ui->stress_level_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->stress_level_img_3, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->stress_level_img_3, 50,50);
    lv_image_set_rotation(ui->stress_level_img_3, 0);

    //Write style for stress_level_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->stress_level_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->stress_level_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stress_level_img_5
    ui->stress_level_img_5 = lv_image_create(ui->stress_level);
    lv_obj_set_pos(ui->stress_level_img_5, 6, 214);
    lv_obj_set_size(ui->stress_level_img_5, 12, 38);
    lv_obj_add_flag(ui->stress_level_img_5, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->stress_level_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->stress_level_img_5, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->stress_level_img_5, 50,50);
    lv_image_set_rotation(ui->stress_level_img_5, 0);

    //Write style for stress_level_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->stress_level_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->stress_level_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stress_level_img_4
    ui->stress_level_img_4 = lv_image_create(ui->stress_level);
    lv_obj_set_pos(ui->stress_level_img_4, 448, 214);
    lv_obj_set_size(ui->stress_level_img_4, 12, 38);
    lv_obj_add_flag(ui->stress_level_img_4, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->stress_level_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->stress_level_img_4, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->stress_level_img_4, 50,50);
    lv_image_set_rotation(ui->stress_level_img_4, 0);

    //Write style for stress_level_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->stress_level_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->stress_level_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of stress_level.


    //Update current screen layout.
    lv_obj_update_layout(ui->stress_level);

    //Init events for screen.
    events_init_stress_level(ui);
}
