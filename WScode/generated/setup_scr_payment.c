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



void setup_scr_payment(lv_ui *ui)
{
    //Write codes payment
    ui->payment = lv_obj_create(NULL);
    lv_obj_set_size(ui->payment, 466, 466);
    lv_obj_set_scrollbar_mode(ui->payment, LV_SCROLLBAR_MODE_OFF);

    //Write style for payment, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->payment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->payment, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->payment, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->payment, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_next_buy
    ui->payment_next_buy = lv_label_create(ui->payment);
    lv_obj_set_pos(ui->payment_next_buy, 116, 50);
    lv_obj_set_size(ui->payment_next_buy, 237, 40);
    lv_obj_add_flag(ui->payment_next_buy, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_label_set_text(ui->payment_next_buy, "Next: West Higgins Rd.");
    lv_label_set_long_mode(ui->payment_next_buy, LV_LABEL_LONG_WRAP);

    //Write style for payment_next_buy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->payment_next_buy, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->payment_next_buy, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->payment_next_buy, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->payment_next_buy, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->payment_next_buy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_amount
    ui->payment_amount = lv_label_create(ui->payment);
    lv_obj_set_pos(ui->payment_amount, 120, 70);
    lv_obj_set_size(ui->payment_amount, 228, 36);
    lv_obj_add_flag(ui->payment_amount, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_label_set_text(ui->payment_amount, "$ 18 8666.49");
    lv_label_set_long_mode(ui->payment_amount, LV_LABEL_LONG_WRAP);

    //Write style for payment_amount, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->payment_amount, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->payment_amount, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->payment_amount, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->payment_amount, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->payment_amount, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_title
    ui->payment_title = lv_label_create(ui->payment);
    lv_obj_set_pos(ui->payment_title, 0, -60);
    lv_obj_set_size(ui->payment_title, 466, 89);
    lv_obj_add_flag(ui->payment_title, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->payment_title, "Payment\n");
    lv_label_set_long_mode(ui->payment_title, LV_LABEL_LONG_WRAP);

    //Write style for payment_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->payment_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->payment_title, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->payment_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->payment_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->payment_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->payment_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->payment_title, &_img_header_bg_ARGB8888_466x89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->payment_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui->payment_title, lv_color_hex(0x6B309C), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->payment_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->payment_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_card_icon
    ui->payment_card_icon = lv_image_create(ui->payment);
    lv_obj_set_pos(ui->payment_card_icon, 68, 167);
    lv_obj_set_size(ui->payment_card_icon, 316, 198);
    lv_obj_add_flag(ui->payment_card_icon, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->payment_card_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->payment_card_icon, &_img_card_1_ARGB8888_316x198_tresh);
    lv_image_set_pivot(ui->payment_card_icon, 50,50);
    lv_image_set_rotation(ui->payment_card_icon, 0);

    //Write style for payment_card_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->payment_card_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->payment_card_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_bank_info
    ui->payment_bank_info = lv_obj_create(ui->payment);
    lv_obj_set_pos(ui->payment_bank_info, 101, 473);
    lv_obj_set_size(ui->payment_bank_info, 269, 79);
    lv_obj_set_scrollbar_mode(ui->payment_bank_info, LV_SCROLLBAR_MODE_OFF);

    //Write style for payment_bank_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->payment_bank_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_label_7
    ui->payment_label_7 = lv_label_create(ui->payment_bank_info);
    lv_obj_set_pos(ui->payment_label_7, 30, 10);
    lv_obj_set_size(ui->payment_label_7, 216, 36);
    lv_label_set_text(ui->payment_label_7, "Mike Susen");
    lv_label_set_long_mode(ui->payment_label_7, LV_LABEL_LONG_WRAP);

    //Write style for payment_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->payment_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->payment_label_7, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->payment_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->payment_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->payment_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_label_6
    ui->payment_label_6 = lv_label_create(ui->payment_bank_info);
    lv_obj_set_pos(ui->payment_label_6, 29, 45);
    lv_obj_set_size(ui->payment_label_6, 209, 27);
    lv_label_set_text(ui->payment_label_6, "NXP Bank Co.");
    lv_label_set_long_mode(ui->payment_label_6, LV_LABEL_LONG_WRAP);

    //Write style for payment_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->payment_label_6, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->payment_label_6, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->payment_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->payment_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->payment_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_tail_number
    ui->payment_tail_number = lv_label_create(ui->payment);
    lv_obj_set_pos(ui->payment_tail_number, 298, 255);
    lv_obj_set_size(ui->payment_tail_number, 55, 21);
    lv_label_set_text(ui->payment_tail_number, "4242");
    lv_label_set_long_mode(ui->payment_tail_number, LV_LABEL_LONG_WRAP);

    //Write style for payment_tail_number, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->payment_tail_number, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->payment_tail_number, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->payment_tail_number, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->payment_tail_number, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->payment_tail_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_expiry_date
    ui->payment_expiry_date = lv_label_create(ui->payment);
    lv_obj_set_pos(ui->payment_expiry_date, 85, 334);
    lv_obj_set_size(ui->payment_expiry_date, 55, 21);
    lv_label_set_text(ui->payment_expiry_date, "25/12");
    lv_label_set_long_mode(ui->payment_expiry_date, LV_LABEL_LONG_WRAP);

    //Write style for payment_expiry_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->payment_expiry_date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->payment_expiry_date, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->payment_expiry_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->payment_expiry_date, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->payment_expiry_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_img_dot
    ui->payment_img_dot = lv_image_create(ui->payment);
    lv_obj_set_pos(ui->payment_img_dot, 439, 254);
    lv_obj_set_size(ui->payment_img_dot, 9, 9);
    lv_obj_add_flag(ui->payment_img_dot, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->payment_img_dot, &_dot_ARGB8888_9x9);
    lv_image_set_pivot(ui->payment_img_dot, 50,50);
    lv_image_set_rotation(ui->payment_img_dot, 0);

    //Write style for payment_img_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->payment_img_dot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->payment_img_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_img_menu
    ui->payment_img_menu = lv_image_create(ui->payment);
    lv_obj_set_pos(ui->payment_img_menu, 433, 173);
    lv_obj_set_size(ui->payment_img_menu, 13, 118);
    lv_obj_add_flag(ui->payment_img_menu, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->payment_img_menu, &_img_menu_ARGB8888_13x118);
    lv_image_set_pivot(ui->payment_img_menu, 50,50);
    lv_image_set_rotation(ui->payment_img_menu, 0);

    //Write style for payment_img_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->payment_img_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->payment_img_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_img_1
    ui->payment_img_1 = lv_image_create(ui->payment);
    lv_obj_set_pos(ui->payment_img_1, 391, 319);
    lv_obj_set_size(ui->payment_img_1, 45, 60);
    lv_obj_add_flag(ui->payment_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->payment_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->payment_img_1, 50,50);
    lv_image_set_rotation(ui->payment_img_1, 0);

    //Write style for payment_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->payment_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->payment_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes payment_img_2
    ui->payment_img_2 = lv_image_create(ui->payment);
    lv_obj_set_pos(ui->payment_img_2, 386, 82);
    lv_obj_set_size(ui->payment_img_2, 50, 66);
    lv_obj_add_flag(ui->payment_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->payment_img_2, &_text_select_ARGB8888_50x66);
    lv_image_set_pivot(ui->payment_img_2, 50,50);
    lv_image_set_rotation(ui->payment_img_2, 0);

    //Write style for payment_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->payment_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->payment_img_2, 163, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of payment.


    //Update current screen layout.
    lv_obj_update_layout(ui->payment);

    //Init events for screen.
    events_init_payment(ui);
}
