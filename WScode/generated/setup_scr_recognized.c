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



void setup_scr_recognized(lv_ui *ui)
{
    //Write codes recognized
    ui->recognized = lv_obj_create(NULL);
    lv_obj_set_size(ui->recognized, 466, 466);
    lv_obj_set_scrollbar_mode(ui->recognized, LV_SCROLLBAR_MODE_OFF);

    //Write style for recognized, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->recognized, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->recognized, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->recognized, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->recognized, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognized_command_text
    ui->recognized_command_text = lv_label_create(ui->recognized);
    lv_obj_set_pos(ui->recognized_command_text, 167, 400);
    lv_obj_set_size(ui->recognized_command_text, 141, 54);
    lv_label_set_text(ui->recognized_command_text, "Command recognized");
    lv_label_set_long_mode(ui->recognized_command_text, LV_LABEL_LONG_WRAP);

    //Write style for recognized_command_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->recognized_command_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->recognized_command_text, &lv_font_montserratMedium_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->recognized_command_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->recognized_command_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognized_done_mic
    ui->recognized_done_mic = lv_image_create(ui->recognized);
    lv_obj_set_pos(ui->recognized_done_mic, 115, 20);
    lv_obj_set_size(ui->recognized_done_mic, 225, 231);
    lv_obj_add_flag(ui->recognized_done_mic, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->recognized_done_mic, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->recognized_done_mic, &_img_mic_3_ARGB8888_225x231_tresh);
    lv_image_set_pivot(ui->recognized_done_mic, 50,50);
    lv_image_set_rotation(ui->recognized_done_mic, 0);

    //Write style for recognized_done_mic, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->recognized_done_mic, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->recognized_done_mic, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognized_img_1
    ui->recognized_img_1 = lv_image_create(ui->recognized);
    lv_obj_set_pos(ui->recognized_img_1, 391, 319);
    lv_obj_set_size(ui->recognized_img_1, 45, 60);
    lv_obj_add_flag(ui->recognized_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->recognized_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->recognized_img_1, 50,50);
    lv_image_set_rotation(ui->recognized_img_1, 0);

    //Write style for recognized_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->recognized_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->recognized_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognized_img_3
    ui->recognized_img_3 = lv_image_create(ui->recognized);
    lv_obj_set_pos(ui->recognized_img_3, 6, 214);
    lv_obj_set_size(ui->recognized_img_3, 12, 38);
    lv_obj_add_flag(ui->recognized_img_3, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->recognized_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->recognized_img_3, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->recognized_img_3, 50,50);
    lv_image_set_rotation(ui->recognized_img_3, 0);

    //Write style for recognized_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->recognized_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->recognized_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes recognized_img_4
    ui->recognized_img_4 = lv_image_create(ui->recognized);
    lv_obj_set_pos(ui->recognized_img_4, 448, 214);
    lv_obj_set_size(ui->recognized_img_4, 12, 38);
    lv_obj_add_flag(ui->recognized_img_4, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->recognized_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->recognized_img_4, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->recognized_img_4, 50,50);
    lv_image_set_rotation(ui->recognized_img_4, 0);

    //Write style for recognized_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->recognized_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->recognized_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of recognized.


    //Update current screen layout.
    lv_obj_update_layout(ui->recognized);

    //Init events for screen.
    events_init_recognized(ui);
}
