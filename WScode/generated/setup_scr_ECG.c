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



void setup_scr_ECG(lv_ui *ui)
{
    //Write codes ECG
    ui->ECG = lv_obj_create(NULL);
    lv_obj_set_size(ui->ECG, 466, 466);
    lv_obj_set_scrollbar_mode(ui->ECG, LV_SCROLLBAR_MODE_OFF);

    //Write style for ECG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ECG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->ECG, &_img_bg_health_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->ECG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->ECG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_title
    ui->ECG_title = lv_label_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_title, 0, -60);
    lv_obj_set_size(ui->ECG_title, 466, 89);
    lv_obj_add_flag(ui->ECG_title, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->ECG_title, "ECG");
    lv_label_set_long_mode(ui->ECG_title, LV_LABEL_LONG_WRAP);

    //Write style for ECG_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ECG_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ECG_title, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ECG_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ECG_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ECG_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ECG_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->ECG_title, &_img_header_bg_ARGB8888_466x89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->ECG_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui->ECG_title, lv_color_hex(0xBD1C39), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->ECG_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_cont_1
    ui->ECG_cont_1 = lv_obj_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_cont_1, 126, 400);
    lv_obj_set_size(ui->ECG_cont_1, 213, 109);
    lv_obj_set_scrollbar_mode(ui->ECG_cont_1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->ECG_cont_1, LV_OBJ_FLAG_FLOATING);

    //Write style for ECG_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_label_bmp
    ui->ECG_label_bmp = lv_label_create(ui->ECG_cont_1);
    lv_obj_set_pos(ui->ECG_label_bmp, 127, 39);
    lv_obj_set_size(ui->ECG_label_bmp, 63, 57);
    lv_label_set_text(ui->ECG_label_bmp, "67\n\n\n\n\n");
    lv_label_set_long_mode(ui->ECG_label_bmp, LV_LABEL_LONG_WRAP);

    //Write style for ECG_label_bmp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ECG_label_bmp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ECG_label_bmp, &lv_font_montserratMedium_29, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ECG_label_bmp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ECG_label_bmp, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_label_bmp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_label_pulse
    ui->ECG_label_pulse = lv_label_create(ui->ECG_cont_1);
    lv_obj_set_pos(ui->ECG_label_pulse, 123, 9);
    lv_obj_set_size(ui->ECG_label_pulse, 68, 22);
    lv_label_set_text(ui->ECG_label_pulse, "PULSE");
    lv_label_set_long_mode(ui->ECG_label_pulse, LV_LABEL_LONG_WRAP);

    //Write style for ECG_label_pulse, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ECG_label_pulse, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ECG_label_pulse, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ECG_label_pulse, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ECG_label_pulse, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_label_pulse, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_img_healthy
    ui->ECG_img_healthy = lv_image_create(ui->ECG_cont_1);
    lv_obj_set_pos(ui->ECG_img_healthy, 36, 28);
    lv_obj_set_size(ui->ECG_img_healthy, 60, 51);
    lv_obj_add_flag(ui->ECG_img_healthy, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ECG_img_healthy, &_img_heart_ARGB8888_60x51);
    lv_image_set_pivot(ui->ECG_img_healthy, 25,22);
    lv_image_set_rotation(ui->ECG_img_healthy, 0);

    //Write style for ECG_img_healthy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ECG_img_healthy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ECG_img_healthy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_label_uint
    ui->ECG_label_uint = lv_label_create(ui->ECG_cont_1);
    lv_obj_set_pos(ui->ECG_label_uint, 127, 67);
    lv_obj_set_size(ui->ECG_label_uint, 63, 57);
    lv_label_set_text(ui->ECG_label_uint, "bpm\n\n\n\n\n");
    lv_label_set_long_mode(ui->ECG_label_uint, LV_LABEL_LONG_WRAP);

    //Write style for ECG_label_uint, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ECG_label_uint, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ECG_label_uint, &lv_font_montserratMedium_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ECG_label_uint, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ECG_label_uint, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_label_uint, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_cont_2
    ui->ECG_cont_2 = lv_obj_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_cont_2, 0, 160);
    lv_obj_set_size(ui->ECG_cont_2, 605, 135);
    lv_obj_set_scrollbar_mode(ui->ECG_cont_2, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->ECG_cont_2, LV_OBJ_FLAG_FLOATING);

    //Write style for ECG_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_img_2
    ui->ECG_img_2 = lv_image_create(ui->ECG_cont_2);
    lv_obj_set_pos(ui->ECG_img_2, 0, 0);
    lv_obj_set_size(ui->ECG_img_2, 152, 134);
    lv_obj_add_flag(ui->ECG_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ECG_img_2, &_img_ekg_ARGB8888_152x134);
    lv_image_set_pivot(ui->ECG_img_2, 50,50);
    lv_image_set_rotation(ui->ECG_img_2, 0);

    //Write style for ECG_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ECG_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ECG_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_img_3
    ui->ECG_img_3 = lv_image_create(ui->ECG_cont_2);
    lv_obj_set_pos(ui->ECG_img_3, 152, 0);
    lv_obj_set_size(ui->ECG_img_3, 152, 134);
    lv_obj_add_flag(ui->ECG_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ECG_img_3, &_img_ekg_ARGB8888_152x134);
    lv_image_set_pivot(ui->ECG_img_3, 50,50);
    lv_image_set_rotation(ui->ECG_img_3, 0);

    //Write style for ECG_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ECG_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ECG_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_img_4
    ui->ECG_img_4 = lv_image_create(ui->ECG_cont_2);
    lv_obj_set_pos(ui->ECG_img_4, 304, 0);
    lv_obj_set_size(ui->ECG_img_4, 152, 134);
    lv_obj_add_flag(ui->ECG_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ECG_img_4, &_img_ekg_ARGB8888_152x134);
    lv_image_set_pivot(ui->ECG_img_4, 50,50);
    lv_image_set_rotation(ui->ECG_img_4, 0);

    //Write style for ECG_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ECG_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ECG_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_img_5
    ui->ECG_img_5 = lv_image_create(ui->ECG_cont_2);
    lv_obj_set_pos(ui->ECG_img_5, 456, 0);
    lv_obj_set_size(ui->ECG_img_5, 152, 134);
    lv_obj_add_flag(ui->ECG_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ECG_img_5, &_img_ekg_ARGB8888_152x134);
    lv_image_set_pivot(ui->ECG_img_5, 50,50);
    lv_image_set_rotation(ui->ECG_img_5, 0);

    //Write style for ECG_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ECG_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ECG_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_label_RR_text
    ui->ECG_label_RR_text = lv_label_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_label_RR_text, 53, 87);
    lv_obj_set_size(ui->ECG_label_RR_text, 149, 26);
    lv_obj_add_flag(ui->ECG_label_RR_text, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->ECG_label_RR_text, "R-R INTERVAL");
    lv_label_set_long_mode(ui->ECG_label_RR_text, LV_LABEL_LONG_WRAP);

    //Write style for ECG_label_RR_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ECG_label_RR_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ECG_label_RR_text, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ECG_label_RR_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ECG_label_RR_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_label_RR_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_label_count_text
    ui->ECG_label_count_text = lv_label_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_label_count_text, 279, 87);
    lv_obj_set_size(ui->ECG_label_count_text, 149, 26);
    lv_obj_add_flag(ui->ECG_label_count_text, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->ECG_label_count_text, "BEAT COUNT");
    lv_label_set_long_mode(ui->ECG_label_count_text, LV_LABEL_LONG_WRAP);

    //Write style for ECG_label_count_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ECG_label_count_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ECG_label_count_text, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ECG_label_count_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ECG_label_count_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_label_count_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_label_RR_interval
    ui->ECG_label_RR_interval = lv_label_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_label_RR_interval, 95, 114);
    lv_obj_set_size(ui->ECG_label_RR_interval, 67, 28);
    lv_obj_add_flag(ui->ECG_label_RR_interval, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->ECG_label_RR_interval, "940\n\n\n\n");
    lv_label_set_long_mode(ui->ECG_label_RR_interval, LV_LABEL_LONG_WRAP);

    //Write style for ECG_label_RR_interval, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ECG_label_RR_interval, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ECG_label_RR_interval, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ECG_label_RR_interval, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ECG_label_RR_interval, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_label_RR_interval, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_label_count
    ui->ECG_label_count = lv_label_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_label_count, 320, 114);
    lv_obj_set_size(ui->ECG_label_count, 67, 28);
    lv_obj_add_flag(ui->ECG_label_count, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->ECG_label_count, "320\n\n\n\n");
    lv_label_set_long_mode(ui->ECG_label_count, LV_LABEL_LONG_WRAP);

    //Write style for ECG_label_count, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ECG_label_count, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ECG_label_count, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ECG_label_count, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ECG_label_count, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ECG_label_count, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_img_6
    ui->ECG_img_6 = lv_image_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_img_6, 391, 319);
    lv_obj_set_size(ui->ECG_img_6, 45, 60);
    lv_obj_add_flag(ui->ECG_img_6, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ECG_img_6, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->ECG_img_6, 50,50);
    lv_image_set_rotation(ui->ECG_img_6, 0);

    //Write style for ECG_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ECG_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ECG_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_img_8
    ui->ECG_img_8 = lv_image_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_img_8, 448, 214);
    lv_obj_set_size(ui->ECG_img_8, 12, 38);
    lv_obj_add_flag(ui->ECG_img_8, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->ECG_img_8, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ECG_img_8, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->ECG_img_8, 50,50);
    lv_image_set_rotation(ui->ECG_img_8, 0);

    //Write style for ECG_img_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ECG_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ECG_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ECG_img_7
    ui->ECG_img_7 = lv_image_create(ui->ECG);
    lv_obj_set_pos(ui->ECG_img_7, 6, 214);
    lv_obj_set_size(ui->ECG_img_7, 12, 38);
    lv_obj_add_flag(ui->ECG_img_7, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->ECG_img_7, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ECG_img_7, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->ECG_img_7, 50,50);
    lv_image_set_rotation(ui->ECG_img_7, 0);

    //Write style for ECG_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ECG_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ECG_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of ECG.


    //Update current screen layout.
    lv_obj_update_layout(ui->ECG);

    //Init events for screen.
    events_init_ECG(ui);
}
