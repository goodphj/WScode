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



void setup_scr_not_recognized(lv_ui *ui)
{
    //Write codes not_recognized
    ui->not_recognized = lv_obj_create(NULL);
    lv_obj_set_size(ui->not_recognized, 466, 466);
    lv_obj_set_scrollbar_mode(ui->not_recognized, LV_SCROLLBAR_MODE_OFF);

    //Write style for not_recognized, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->not_recognized, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->not_recognized, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->not_recognized, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->not_recognized, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes not_recognized_command_text
    ui->not_recognized_command_text = lv_label_create(ui->not_recognized);
    lv_obj_set_pos(ui->not_recognized_command_text, 140, 400);
    lv_obj_set_size(ui->not_recognized_command_text, 186, 54);
    lv_label_set_text(ui->not_recognized_command_text, "Command not recognized");
    lv_label_set_long_mode(ui->not_recognized_command_text, LV_LABEL_LONG_WRAP);

    //Write style for not_recognized_command_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->not_recognized_command_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->not_recognized_command_text, &lv_font_montserratMedium_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->not_recognized_command_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->not_recognized_command_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->not_recognized_command_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes not_recognized_no_mic_icon
    ui->not_recognized_no_mic_icon = lv_image_create(ui->not_recognized);
    lv_obj_set_pos(ui->not_recognized_no_mic_icon, 115, 20);
    lv_obj_set_size(ui->not_recognized_no_mic_icon, 225, 231);
    lv_obj_add_flag(ui->not_recognized_no_mic_icon, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->not_recognized_no_mic_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->not_recognized_no_mic_icon, &_img_mic_2_ARGB8888_225x231_tresh);
    lv_image_set_pivot(ui->not_recognized_no_mic_icon, 50,50);
    lv_image_set_rotation(ui->not_recognized_no_mic_icon, 0);

    //Write style for not_recognized_no_mic_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->not_recognized_no_mic_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->not_recognized_no_mic_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes not_recognized_img_1
    ui->not_recognized_img_1 = lv_image_create(ui->not_recognized);
    lv_obj_set_pos(ui->not_recognized_img_1, 391, 319);
    lv_obj_set_size(ui->not_recognized_img_1, 45, 60);
    lv_obj_add_flag(ui->not_recognized_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->not_recognized_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->not_recognized_img_1, 50,50);
    lv_image_set_rotation(ui->not_recognized_img_1, 0);

    //Write style for not_recognized_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->not_recognized_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->not_recognized_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes not_recognized_img_3
    ui->not_recognized_img_3 = lv_image_create(ui->not_recognized);
    lv_obj_set_pos(ui->not_recognized_img_3, 6, 214);
    lv_obj_set_size(ui->not_recognized_img_3, 12, 38);
    lv_obj_add_flag(ui->not_recognized_img_3, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->not_recognized_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->not_recognized_img_3, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->not_recognized_img_3, 50,50);
    lv_image_set_rotation(ui->not_recognized_img_3, 0);

    //Write style for not_recognized_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->not_recognized_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->not_recognized_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes not_recognized_img_2
    ui->not_recognized_img_2 = lv_image_create(ui->not_recognized);
    lv_obj_set_pos(ui->not_recognized_img_2, 448, 214);
    lv_obj_set_size(ui->not_recognized_img_2, 12, 38);
    lv_obj_add_flag(ui->not_recognized_img_2, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->not_recognized_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->not_recognized_img_2, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->not_recognized_img_2, 50,50);
    lv_image_set_rotation(ui->not_recognized_img_2, 0);

    //Write style for not_recognized_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->not_recognized_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->not_recognized_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of not_recognized.


    //Update current screen layout.
    lv_obj_update_layout(ui->not_recognized);

    //Init events for screen.
    events_init_not_recognized(ui);
}
