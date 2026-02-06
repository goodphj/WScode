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



void setup_scr_message_list(lv_ui *ui)
{
    //Write codes message_list
    ui->message_list = lv_obj_create(NULL);
    lv_obj_set_size(ui->message_list, 466, 466);
    lv_obj_set_scrollbar_mode(ui->message_list, LV_SCROLLBAR_MODE_OFF);

    //Write style for message_list, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->message_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->message_list, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->message_list, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->message_list, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_cont_messagesList
    ui->message_list_cont_messagesList = lv_obj_create(ui->message_list);
    lv_obj_set_pos(ui->message_list_cont_messagesList, 54, 8);
    lv_obj_set_size(ui->message_list_cont_messagesList, 356, 450);
    lv_obj_set_scrollbar_mode(ui->message_list_cont_messagesList, LV_SCROLLBAR_MODE_OFF);

    //Write style for message_list_cont_messagesList, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_cont_messagesList, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_label_12
    ui->message_list_label_12 = lv_label_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_label_12, 112, 326);
    lv_obj_set_size(ui->message_list_label_12, 118, 22);
    lv_label_set_text(ui->message_list_label_12, "09:25");
    lv_label_set_long_mode(ui->message_list_label_12, LV_LABEL_LONG_WRAP);

    //Write style for message_list_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_list_label_12, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_list_label_12, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_list_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_list_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_label_11
    ui->message_list_label_11 = lv_label_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_label_11, 70, 296);
    lv_obj_set_size(ui->message_list_label_11, 219, 23);
    lv_label_set_text(ui->message_list_label_11, "Liked your photo");
    lv_label_set_long_mode(ui->message_list_label_11, LV_LABEL_LONG_WRAP);

    //Write style for message_list_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_list_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_list_label_11, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_list_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_list_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_label_10
    ui->message_list_label_10 = lv_label_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_label_10, 96, 259);
    lv_obj_set_size(ui->message_list_label_10, 153, 38);
    lv_label_set_text(ui->message_list_label_10, "Sabrina");
    lv_label_set_long_mode(ui->message_list_label_10, LV_LABEL_LONG_WRAP);

    //Write style for message_list_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_list_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_list_label_10, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_list_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_list_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_img_7
    ui->message_list_img_7 = lv_image_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_img_7, 155, 204);
    lv_obj_set_size(ui->message_list_img_7, 42, 42);
    lv_obj_add_flag(ui->message_list_img_7, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->message_list_img_7, &_icn_insta_ARGB8888_42x42);
    lv_image_set_pivot(ui->message_list_img_7, 50,50);
    lv_image_set_rotation(ui->message_list_img_7, 0);

    //Write style for message_list_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->message_list_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->message_list_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_label_9
    ui->message_list_label_9 = lv_label_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_label_9, 120, 146);
    lv_obj_set_size(ui->message_list_label_9, 118, 30);
    lv_label_set_text(ui->message_list_label_9, "1 min ago");
    lv_label_set_long_mode(ui->message_list_label_9, LV_LABEL_LONG_WRAP);

    //Write style for message_list_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_list_label_9, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_list_label_9, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_list_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_list_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_label_15
    ui->message_list_label_15 = lv_label_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_label_15, 111, 511);
    lv_obj_set_size(ui->message_list_label_15, 118, 30);
    lv_label_set_text(ui->message_list_label_15, "5 min ago");
    lv_label_set_long_mode(ui->message_list_label_15, LV_LABEL_LONG_WRAP);

    //Write style for message_list_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_list_label_15, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_list_label_15, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_list_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_list_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_label_8
    ui->message_list_label_8 = lv_label_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_label_8, 27, 114);
    lv_obj_set_size(ui->message_list_label_8, 307, 23);
    lv_label_set_text(ui->message_list_label_8, "How are you? I will meet with...");
    lv_label_set_long_mode(ui->message_list_label_8, LV_LABEL_LONG_WRAP);

    //Write style for message_list_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_list_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_list_label_8, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_list_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_list_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_label_7
    ui->message_list_label_7 = lv_label_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_label_7, 129, 70);
    lv_obj_set_size(ui->message_list_label_7, 106, 38);
    lv_label_set_text(ui->message_list_label_7, "Elena");
    lv_label_set_long_mode(ui->message_list_label_7, LV_LABEL_LONG_WRAP);

    //Write style for message_list_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_list_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_list_label_7, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_list_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_list_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_app_icon
    ui->message_list_app_icon = lv_image_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_app_icon, 151, -66);
    lv_obj_set_size(ui->message_list_app_icon, 46, 46);
    lv_obj_add_flag(ui->message_list_app_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->message_list_app_icon, &_icn_whatsapp_ARGB8888_46x46);
    lv_image_set_pivot(ui->message_list_app_icon, 50,50);
    lv_image_set_rotation(ui->message_list_app_icon, 0);

    //Write style for message_list_app_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->message_list_app_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->message_list_app_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_img_8
    ui->message_list_img_8 = lv_image_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_img_8, 19, 185);
    lv_obj_set_size(ui->message_list_img_8, 297, 2);
    lv_obj_add_flag(ui->message_list_img_8, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->message_list_img_8, &_img_line_2_ARGB8888_297x2);
    lv_image_set_pivot(ui->message_list_img_8, 50,50);
    lv_image_set_rotation(ui->message_list_img_8, 0);

    //Write style for message_list_img_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->message_list_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->message_list_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_img_9
    ui->message_list_img_9 = lv_image_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_img_9, 47, 369);
    lv_obj_set_size(ui->message_list_img_9, 275, 2);
    lv_obj_add_flag(ui->message_list_img_9, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->message_list_img_9, &_img_line_1_ARGB8888_275x2);
    lv_image_set_pivot(ui->message_list_img_9, 50,50);
    lv_image_set_rotation(ui->message_list_img_9, 0);

    //Write style for message_list_img_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->message_list_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->message_list_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_img_10
    ui->message_list_img_10 = lv_image_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_img_10, 155, 397);
    lv_obj_set_size(ui->message_list_img_10, 42, 42);
    lv_obj_add_flag(ui->message_list_img_10, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->message_list_img_10, &_icn_insta_ARGB8888_42x42);
    lv_image_set_pivot(ui->message_list_img_10, 50,50);
    lv_image_set_rotation(ui->message_list_img_10, 0);

    //Write style for message_list_img_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->message_list_img_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->message_list_img_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_label_13
    ui->message_list_label_13 = lv_label_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_label_13, 122, 446);
    lv_obj_set_size(ui->message_list_label_13, 106, 38);
    lv_label_set_text(ui->message_list_label_13, "Monk");
    lv_label_set_long_mode(ui->message_list_label_13, LV_LABEL_LONG_WRAP);

    //Write style for message_list_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_list_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_list_label_13, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_list_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_list_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_label_14
    ui->message_list_label_14 = lv_label_create(ui->message_list_cont_messagesList);
    lv_obj_set_pos(ui->message_list_label_14, 35, 482);
    lv_obj_set_size(ui->message_list_label_14, 316, 23);
    lv_label_set_text(ui->message_list_label_14, "Do you like to play basketball? ");
    lv_label_set_long_mode(ui->message_list_label_14, LV_LABEL_LONG_WRAP);

    //Write style for message_list_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->message_list_label_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->message_list_label_14, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->message_list_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->message_list_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->message_list_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_img_11
    ui->message_list_img_11 = lv_image_create(ui->message_list);
    lv_obj_set_pos(ui->message_list_img_11, 391, 319);
    lv_obj_set_size(ui->message_list_img_11, 45, 60);
    lv_obj_add_flag(ui->message_list_img_11, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->message_list_img_11, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->message_list_img_11, 50,50);
    lv_image_set_rotation(ui->message_list_img_11, 0);

    //Write style for message_list_img_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->message_list_img_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->message_list_img_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_img_13
    ui->message_list_img_13 = lv_image_create(ui->message_list);
    lv_obj_set_pos(ui->message_list_img_13, 6, 214);
    lv_obj_set_size(ui->message_list_img_13, 12, 38);
    lv_obj_add_flag(ui->message_list_img_13, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->message_list_img_13, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->message_list_img_13, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->message_list_img_13, 50,50);
    lv_image_set_rotation(ui->message_list_img_13, 0);

    //Write style for message_list_img_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->message_list_img_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->message_list_img_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes message_list_img_12
    ui->message_list_img_12 = lv_image_create(ui->message_list);
    lv_obj_set_pos(ui->message_list_img_12, 448, 214);
    lv_obj_set_size(ui->message_list_img_12, 12, 38);
    lv_obj_add_flag(ui->message_list_img_12, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->message_list_img_12, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->message_list_img_12, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->message_list_img_12, 50,50);
    lv_image_set_rotation(ui->message_list_img_12, 0);

    //Write style for message_list_img_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->message_list_img_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->message_list_img_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of message_list.


    //Update current screen layout.
    lv_obj_update_layout(ui->message_list);

    //Init events for screen.
    events_init_message_list(ui);
}
