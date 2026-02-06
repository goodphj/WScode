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



void setup_scr_flight_info(lv_ui *ui)
{
    //Write codes flight_info
    ui->flight_info = lv_obj_create(NULL);
    lv_obj_set_size(ui->flight_info, 466, 466);
    lv_obj_set_scrollbar_mode(ui->flight_info, LV_SCROLLBAR_MODE_OFF);

    //Write style for flight_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->flight_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->flight_info, &_img_bg_travel_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->flight_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->flight_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_number_text
    ui->flight_info_number_text = lv_label_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_number_text, 142, 40);
    lv_obj_set_size(ui->flight_info_number_text, 181, 20);
    lv_label_set_text(ui->flight_info_number_text, "FLIGHT NUMBER");
    lv_label_set_long_mode(ui->flight_info_number_text, LV_LABEL_LONG_WRAP);

    //Write style for flight_info_number_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flight_info_number_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->flight_info_number_text, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->flight_info_number_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->flight_info_number_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->flight_info_number_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_flight_number
    ui->flight_info_flight_number = lv_label_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_flight_number, 155, 60);
    lv_obj_set_size(ui->flight_info_flight_number, 160, 36);
    lv_label_set_text(ui->flight_info_flight_number, "LH 2547");
    lv_label_set_long_mode(ui->flight_info_flight_number, LV_LABEL_LONG_WRAP);

    //Write style for flight_info_flight_number, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flight_info_flight_number, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->flight_info_flight_number, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->flight_info_flight_number, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->flight_info_flight_number, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->flight_info_flight_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_title
    ui->flight_info_title = lv_label_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_title, 0, -60);
    lv_obj_set_size(ui->flight_info_title, 466, 89);
    lv_obj_add_flag(ui->flight_info_title, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->flight_info_title, "Your Flight");
    lv_label_set_long_mode(ui->flight_info_title, LV_LABEL_LONG_WRAP);

    //Write style for flight_info_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->flight_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->flight_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flight_info_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->flight_info_title, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->flight_info_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->flight_info_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->flight_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->flight_info_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->flight_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->flight_info_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->flight_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->flight_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->flight_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->flight_info_title, &_img_header_bg_ARGB8888_466x89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->flight_info_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui->flight_info_title, lv_color_hex(0xFFAA10), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->flight_info_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->flight_info_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_gate_number
    ui->flight_info_gate_number = lv_label_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_gate_number, 25, 230);
    lv_obj_set_size(ui->flight_info_gate_number, 84, 36);
    lv_label_set_text(ui->flight_info_gate_number, "A32");
    lv_label_set_long_mode(ui->flight_info_gate_number, LV_LABEL_LONG_WRAP);

    //Write style for flight_info_gate_number, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flight_info_gate_number, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->flight_info_gate_number, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->flight_info_gate_number, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->flight_info_gate_number, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->flight_info_gate_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_gate_text
    ui->flight_info_gate_text = lv_label_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_gate_text, 34, 205);
    lv_obj_set_size(ui->flight_info_gate_text, 68, 20);
    lv_label_set_text(ui->flight_info_gate_text, "GATE");
    lv_label_set_long_mode(ui->flight_info_gate_text, LV_LABEL_LONG_WRAP);

    //Write style for flight_info_gate_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flight_info_gate_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->flight_info_gate_text, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->flight_info_gate_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->flight_info_gate_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->flight_info_gate_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_seat_text
    ui->flight_info_seat_text = lv_label_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_seat_text, 378, 205);
    lv_obj_set_size(ui->flight_info_seat_text, 52, 20);
    lv_label_set_text(ui->flight_info_seat_text, "SEAT");
    lv_label_set_long_mode(ui->flight_info_seat_text, LV_LABEL_LONG_WRAP);

    //Write style for flight_info_seat_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flight_info_seat_text, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->flight_info_seat_text, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->flight_info_seat_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->flight_info_seat_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->flight_info_seat_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_seat_number
    ui->flight_info_seat_number = lv_label_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_seat_number, 370, 230);
    lv_obj_set_size(ui->flight_info_seat_number, 84, 36);
    lv_label_set_text(ui->flight_info_seat_number, "16B");
    lv_label_set_long_mode(ui->flight_info_seat_number, LV_LABEL_LONG_WRAP);

    //Write style for flight_info_seat_number, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->flight_info_seat_number, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->flight_info_seat_number, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->flight_info_seat_number, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->flight_info_seat_number, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->flight_info_seat_number, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_qrcode
    ui->flight_info_qrcode = lv_image_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_qrcode, 113, 225);
    lv_obj_set_size(ui->flight_info_qrcode, 246, 288);
    lv_obj_add_flag(ui->flight_info_qrcode, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->flight_info_qrcode, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->flight_info_qrcode, &_img_qr_code_ARGB8888_246x288);
    lv_image_set_pivot(ui->flight_info_qrcode, 50,50);
    lv_image_set_rotation(ui->flight_info_qrcode, 0);

    //Write style for flight_info_qrcode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->flight_info_qrcode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->flight_info_qrcode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_img_1
    ui->flight_info_img_1 = lv_image_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_img_1, 391, 319);
    lv_obj_set_size(ui->flight_info_img_1, 45, 60);
    lv_obj_add_flag(ui->flight_info_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->flight_info_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->flight_info_img_1, 50,50);
    lv_image_set_rotation(ui->flight_info_img_1, 0);

    //Write style for flight_info_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->flight_info_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->flight_info_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_img_3
    ui->flight_info_img_3 = lv_image_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_img_3, 6, 214);
    lv_obj_set_size(ui->flight_info_img_3, 12, 38);
    lv_obj_add_flag(ui->flight_info_img_3, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->flight_info_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->flight_info_img_3, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->flight_info_img_3, 50,50);
    lv_image_set_rotation(ui->flight_info_img_3, 0);

    //Write style for flight_info_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->flight_info_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->flight_info_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes flight_info_img_2
    ui->flight_info_img_2 = lv_image_create(ui->flight_info);
    lv_obj_set_pos(ui->flight_info_img_2, 448, 214);
    lv_obj_set_size(ui->flight_info_img_2, 12, 38);
    lv_obj_add_flag(ui->flight_info_img_2, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->flight_info_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->flight_info_img_2, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->flight_info_img_2, 50,50);
    lv_image_set_rotation(ui->flight_info_img_2, 0);

    //Write style for flight_info_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->flight_info_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->flight_info_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of flight_info.


    //Update current screen layout.
    lv_obj_update_layout(ui->flight_info);

    //Init events for screen.
    events_init_flight_info(ui);
}
