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



void setup_scr_sleep(lv_ui *ui)
{
    //Write codes sleep
    ui->sleep = lv_obj_create(NULL);
    lv_obj_set_size(ui->sleep, 466, 466);
    lv_obj_set_scrollbar_mode(ui->sleep, LV_SCROLLBAR_MODE_OFF);

    //Write style for sleep, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->sleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->sleep, &_img_bg_health_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->sleep, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->sleep, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes sleep_title
    ui->sleep_title = lv_label_create(ui->sleep);
    lv_obj_set_pos(ui->sleep_title, 0, -60);
    lv_obj_set_size(ui->sleep_title, 466, 89);
    lv_obj_add_flag(ui->sleep_title, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->sleep_title, "Sleep monitor");
    lv_label_set_long_mode(ui->sleep_title, LV_LABEL_LONG_WRAP);

    //Write style for sleep_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->sleep_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->sleep_title, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->sleep_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->sleep_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->sleep_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->sleep_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->sleep_title, &_img_header_bg_ARGB8888_466x89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->sleep_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui->sleep_title, lv_color_hex(0xBD1C39), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->sleep_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->sleep_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes sleep_cont_1
    ui->sleep_cont_1 = lv_obj_create(ui->sleep);
    lv_obj_set_pos(ui->sleep_cont_1, 125, 400);
    lv_obj_set_size(ui->sleep_cont_1, 202, 98);
    lv_obj_set_scrollbar_mode(ui->sleep_cont_1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->sleep_cont_1, LV_OBJ_FLAG_FLOATING);

    //Write style for sleep_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->sleep_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes sleep_label_time
    ui->sleep_label_time = lv_label_create(ui->sleep_cont_1);
    lv_obj_set_pos(ui->sleep_label_time, 63, 42);
    lv_obj_set_size(ui->sleep_label_time, 96, 40);
    lv_label_set_text(ui->sleep_label_time, "17:25\n\n\n\n\n");
    lv_label_set_long_mode(ui->sleep_label_time, LV_LABEL_LONG_WRAP);

    //Write style for sleep_label_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->sleep_label_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->sleep_label_time, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->sleep_label_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->sleep_label_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->sleep_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes sleep_label_today
    ui->sleep_label_today = lv_label_create(ui->sleep_cont_1);
    lv_obj_set_pos(ui->sleep_label_today, 70, 17);
    lv_obj_set_size(ui->sleep_label_today, 82, 23);
    lv_label_set_text(ui->sleep_label_today, "TODAY");
    lv_label_set_long_mode(ui->sleep_label_today, LV_LABEL_LONG_WRAP);

    //Write style for sleep_label_today, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->sleep_label_today, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->sleep_label_today, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->sleep_label_today, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->sleep_label_today, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->sleep_label_today, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes sleep_img_stages
    ui->sleep_img_stages = lv_image_create(ui->sleep);
    lv_obj_set_pos(ui->sleep_img_stages, 33, 143);
    lv_obj_set_size(ui->sleep_img_stages, 399, 160);
    lv_obj_add_flag(ui->sleep_img_stages, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->sleep_img_stages, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->sleep_img_stages, &_img_chart_sleep_ARGB8888_399x160);
    lv_image_set_pivot(ui->sleep_img_stages, 50,50);
    lv_image_set_rotation(ui->sleep_img_stages, 0);

    //Write style for sleep_img_stages, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->sleep_img_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->sleep_img_stages, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes sleep_label_stages
    ui->sleep_label_stages = lv_label_create(ui->sleep);
    lv_obj_set_pos(ui->sleep_label_stages, 133, 11);
    lv_obj_set_size(ui->sleep_label_stages, 199, 39);
    lv_label_set_text(ui->sleep_label_stages, "Sleep stages");
    lv_label_set_long_mode(ui->sleep_label_stages, LV_LABEL_LONG_WRAP);

    //Write style for sleep_label_stages, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->sleep_label_stages, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->sleep_label_stages, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->sleep_label_stages, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->sleep_label_stages, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->sleep_label_stages, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes sleep_img_1
    ui->sleep_img_1 = lv_image_create(ui->sleep);
    lv_obj_set_pos(ui->sleep_img_1, 391, 319);
    lv_obj_set_size(ui->sleep_img_1, 45, 60);
    lv_obj_add_flag(ui->sleep_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->sleep_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->sleep_img_1, 50,50);
    lv_image_set_rotation(ui->sleep_img_1, 0);

    //Write style for sleep_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->sleep_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->sleep_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes sleep_img_3
    ui->sleep_img_3 = lv_image_create(ui->sleep);
    lv_obj_set_pos(ui->sleep_img_3, 6, 214);
    lv_obj_set_size(ui->sleep_img_3, 12, 38);
    lv_obj_add_flag(ui->sleep_img_3, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->sleep_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->sleep_img_3, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->sleep_img_3, 50,50);
    lv_image_set_rotation(ui->sleep_img_3, 0);

    //Write style for sleep_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->sleep_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->sleep_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes sleep_img_2
    ui->sleep_img_2 = lv_image_create(ui->sleep);
    lv_obj_set_pos(ui->sleep_img_2, 448, 214);
    lv_obj_set_size(ui->sleep_img_2, 12, 38);
    lv_obj_add_flag(ui->sleep_img_2, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->sleep_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->sleep_img_2, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->sleep_img_2, 50,50);
    lv_image_set_rotation(ui->sleep_img_2, 0);

    //Write style for sleep_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->sleep_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->sleep_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of sleep.


    //Update current screen layout.
    lv_obj_update_layout(ui->sleep);

    //Init events for screen.
    events_init_sleep(ui);
}
