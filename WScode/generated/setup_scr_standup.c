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



void setup_scr_standup(lv_ui *ui)
{
    //Write codes standup
    ui->standup = lv_obj_create(NULL);
    lv_obj_set_size(ui->standup, 466, 466);
    lv_obj_set_scrollbar_mode(ui->standup, LV_SCROLLBAR_MODE_OFF);

    //Write style for standup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->standup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->standup, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->standup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->standup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes standup_stand_icon
    ui->standup_stand_icon = lv_image_create(ui->standup);
    lv_obj_set_pos(ui->standup_stand_icon, 183, -121);
    lv_obj_set_size(ui->standup_stand_icon, 99, 99);
    lv_obj_add_flag(ui->standup_stand_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->standup_stand_icon, &_img_stand_up_ARGB8888_99x99);
    lv_image_set_pivot(ui->standup_stand_icon, 50,50);
    lv_image_set_rotation(ui->standup_stand_icon, 0);

    //Write style for standup_stand_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->standup_stand_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->standup_stand_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes standup_stand_text
    ui->standup_stand_text = lv_label_create(ui->standup);
    lv_obj_set_pos(ui->standup_stand_text, 57, 6);
    lv_obj_set_size(ui->standup_stand_text, 363, 38);
    lv_label_set_text(ui->standup_stand_text, "Time to stand up!");
    lv_label_set_long_mode(ui->standup_stand_text, LV_LABEL_LONG_WRAP);

    //Write style for standup_stand_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->standup_stand_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->standup_stand_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->standup_stand_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->standup_stand_text, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->standup_stand_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->standup_stand_text, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->standup_stand_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->standup_stand_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->standup_stand_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->standup_stand_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->standup_stand_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->standup_stand_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->standup_stand_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->standup_stand_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes standup_stand_time
    ui->standup_stand_time = lv_label_create(ui->standup);
    lv_obj_set_pos(ui->standup_stand_time, 53, 204);
    lv_obj_set_size(ui->standup_stand_time, 360, 58);
    lv_label_set_text(ui->standup_stand_time, "Stand up and move a little for one mitute. ");
    lv_label_set_long_mode(ui->standup_stand_time, LV_LABEL_LONG_WRAP);

    //Write style for standup_stand_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->standup_stand_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->standup_stand_time, &lv_font_montserratMedium_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->standup_stand_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->standup_stand_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->standup_stand_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes standup_time_text
    ui->standup_time_text = lv_label_create(ui->standup);
    lv_obj_set_pos(ui->standup_time_text, 176, 415);
    lv_obj_set_size(ui->standup_time_text, 118, 30);
    lv_label_set_text(ui->standup_time_text, "1 min ago");
    lv_label_set_long_mode(ui->standup_time_text, LV_LABEL_LONG_WRAP);

    //Write style for standup_time_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->standup_time_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->standup_time_text, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->standup_time_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->standup_time_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->standup_time_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes standup_ok_btn
    ui->standup_ok_btn = lv_label_create(ui->standup);
    lv_obj_set_pos(ui->standup_ok_btn, 135, 470);
    lv_obj_set_size(ui->standup_ok_btn, 204, 58);
    lv_obj_add_flag(ui->standup_ok_btn, LV_OBJ_FLAG_CLICKABLE);
    lv_label_set_text(ui->standup_ok_btn, "OK");
    lv_label_set_long_mode(ui->standup_ok_btn, LV_LABEL_LONG_WRAP);

    //Write style for standup_ok_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->standup_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->standup_ok_btn, 23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->standup_ok_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->standup_ok_btn, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->standup_ok_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->standup_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->standup_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->standup_ok_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->standup_ok_btn, 105, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->standup_ok_btn, lv_color_hex(0x414041), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->standup_ok_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->standup_ok_btn, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->standup_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->standup_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->standup_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->standup_ok_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes standup_img_1
    ui->standup_img_1 = lv_image_create(ui->standup);
    lv_obj_set_pos(ui->standup_img_1, 391, 319);
    lv_obj_set_size(ui->standup_img_1, 45, 60);
    lv_obj_add_flag(ui->standup_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->standup_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->standup_img_1, 50,50);
    lv_image_set_rotation(ui->standup_img_1, 0);

    //Write style for standup_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->standup_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->standup_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes standup_img_3
    ui->standup_img_3 = lv_image_create(ui->standup);
    lv_obj_set_pos(ui->standup_img_3, 6, 214);
    lv_obj_set_size(ui->standup_img_3, 12, 38);
    lv_obj_add_flag(ui->standup_img_3, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->standup_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->standup_img_3, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->standup_img_3, 50,50);
    lv_image_set_rotation(ui->standup_img_3, 0);

    //Write style for standup_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->standup_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->standup_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes standup_img_2
    ui->standup_img_2 = lv_image_create(ui->standup);
    lv_obj_set_pos(ui->standup_img_2, 448, 214);
    lv_obj_set_size(ui->standup_img_2, 12, 38);
    lv_obj_add_flag(ui->standup_img_2, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->standup_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->standup_img_2, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->standup_img_2, 50,50);
    lv_image_set_rotation(ui->standup_img_2, 0);

    //Write style for standup_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->standup_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->standup_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of standup.


    //Update current screen layout.
    lv_obj_update_layout(ui->standup);

    //Init events for screen.
    events_init_standup(ui);
}
