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



void setup_scr_car_start(lv_ui *ui)
{
    //Write codes car_start
    ui->car_start = lv_obj_create(NULL);
    lv_obj_set_size(ui->car_start, 466, 466);
    lv_obj_set_scrollbar_mode(ui->car_start, LV_SCROLLBAR_MODE_OFF);

    //Write style for car_start, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->car_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->car_start, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->car_start, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->car_start, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes car_start_car_icon
    ui->car_start_car_icon = lv_image_create(ui->car_start);
    lv_obj_set_pos(ui->car_start_car_icon, 183, -30);
    lv_obj_set_size(ui->car_start_car_icon, 99, 99);
    lv_obj_add_flag(ui->car_start_car_icon, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->car_start_car_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->car_start_car_icon, &_img_car_ARGB8888_99x99);
    lv_image_set_pivot(ui->car_start_car_icon, 50,50);
    lv_image_set_rotation(ui->car_start_car_icon, 0);

    //Write style for car_start_car_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->car_start_car_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->car_start_car_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes car_start_info_text
    ui->car_start_info_text = lv_label_create(ui->car_start);
    lv_obj_set_pos(ui->car_start_info_text, 118, 80);
    lv_obj_set_size(ui->car_start_info_text, 229, 61);
    lv_obj_add_flag(ui->car_start_info_text, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_label_set_text(ui->car_start_info_text, "Press and Hold for Remote start");
    lv_label_set_long_mode(ui->car_start_info_text, LV_LABEL_LONG_WRAP);

    //Write style for car_start_info_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->car_start_info_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->car_start_info_text, &lv_font_montserratMedium_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->car_start_info_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->car_start_info_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->car_start_info_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes car_start_start_imgbtn
    ui->car_start_start_imgbtn = lv_imagebutton_create(ui->car_start);
    lv_obj_set_pos(ui->car_start_start_imgbtn, 126, 290);
    lv_obj_set_size(ui->car_start_start_imgbtn, 218, 218);
    lv_obj_add_flag(ui->car_start_start_imgbtn, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->car_start_start_imgbtn, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->car_start_start_imgbtn, LV_IMAGEBUTTON_STATE_RELEASED, &_img_red_btn_ARGB8888_218x218_tresh, NULL, NULL);
    lv_imagebutton_set_src(ui->car_start_start_imgbtn, LV_IMAGEBUTTON_STATE_PRESSED, &_img_red_btn_ARGB8888_218x218_tresh, NULL, NULL);
    lv_imagebutton_set_src(ui->car_start_start_imgbtn, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_img_green_btn_ARGB8888_218x218_tresh, NULL, NULL);
    lv_imagebutton_set_src(ui->car_start_start_imgbtn, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_img_green_btn_ARGB8888_218x218_tresh, NULL, NULL);
    ui->car_start_start_imgbtn_label = lv_label_create(ui->car_start_start_imgbtn);
    lv_label_set_text(ui->car_start_start_imgbtn_label, "START");
    lv_label_set_long_mode(ui->car_start_start_imgbtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->car_start_start_imgbtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->car_start_start_imgbtn, 0, LV_STATE_DEFAULT);

    //Write style for car_start_start_imgbtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->car_start_start_imgbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->car_start_start_imgbtn, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->car_start_start_imgbtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->car_start_start_imgbtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->car_start_start_imgbtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for car_start_start_imgbtn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->car_start_start_imgbtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->car_start_start_imgbtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->car_start_start_imgbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->car_start_start_imgbtn, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->car_start_start_imgbtn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->car_start_start_imgbtn, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for car_start_start_imgbtn, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->car_start_start_imgbtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->car_start_start_imgbtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->car_start_start_imgbtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->car_start_start_imgbtn, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->car_start_start_imgbtn, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->car_start_start_imgbtn, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for car_start_start_imgbtn, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->car_start_start_imgbtn, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->car_start_start_imgbtn, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes car_start_img_1
    ui->car_start_img_1 = lv_image_create(ui->car_start);
    lv_obj_set_pos(ui->car_start_img_1, 391, 319);
    lv_obj_set_size(ui->car_start_img_1, 45, 60);
    lv_obj_add_flag(ui->car_start_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->car_start_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->car_start_img_1, 50,50);
    lv_image_set_rotation(ui->car_start_img_1, 0);

    //Write style for car_start_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->car_start_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->car_start_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes car_start_img_3
    ui->car_start_img_3 = lv_image_create(ui->car_start);
    lv_obj_set_pos(ui->car_start_img_3, 6, 214);
    lv_obj_set_size(ui->car_start_img_3, 12, 38);
    lv_obj_add_flag(ui->car_start_img_3, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->car_start_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->car_start_img_3, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->car_start_img_3, 50,50);
    lv_image_set_rotation(ui->car_start_img_3, 0);

    //Write style for car_start_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->car_start_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->car_start_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes car_start_img_2
    ui->car_start_img_2 = lv_image_create(ui->car_start);
    lv_obj_set_pos(ui->car_start_img_2, 448, 214);
    lv_obj_set_size(ui->car_start_img_2, 12, 38);
    lv_obj_add_flag(ui->car_start_img_2, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->car_start_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->car_start_img_2, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->car_start_img_2, 50,50);
    lv_image_set_rotation(ui->car_start_img_2, 0);

    //Write style for car_start_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->car_start_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->car_start_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of car_start.


    //Update current screen layout.
    lv_obj_update_layout(ui->car_start);

    //Init events for screen.
    events_init_car_start(ui);
}
