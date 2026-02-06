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



void setup_scr_call(lv_ui *ui)
{
    //Write codes call
    ui->call = lv_obj_create(NULL);
    lv_obj_set_size(ui->call, 466, 466);
    lv_obj_set_scrollbar_mode(ui->call, LV_SCROLLBAR_MODE_OFF);

    //Write style for call, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->call, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->call, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->call, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->call, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_img_volume
    ui->call_img_volume = lv_image_create(ui->call);
    lv_obj_set_pos(ui->call_img_volume, 34, 255);
    lv_obj_set_size(ui->call_img_volume, 32, 86);
    lv_obj_add_flag(ui->call_img_volume, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->call_img_volume, &_text_volume_ARGB8888_32x86);
    lv_image_set_pivot(ui->call_img_volume, 50,50);
    lv_image_set_rotation(ui->call_img_volume, 0);

    //Write style for call_img_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->call_img_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->call_img_volume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_arc_volume
    ui->call_arc_volume = lv_arc_create(ui->call);
    lv_obj_set_pos(ui->call_arc_volume, 13, 79);
    lv_obj_set_size(ui->call_arc_volume, 388, 356);
    lv_arc_set_mode(ui->call_arc_volume, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->call_arc_volume, 0, 100);
    lv_arc_set_bg_angles(ui->call_arc_volume, 120, 180);
    lv_arc_set_value(ui->call_arc_volume, 70);
    lv_arc_set_rotation(ui->call_arc_volume, 0);

    //Write style for call_arc_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->call_arc_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->call_arc_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->call_arc_volume, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->call_arc_volume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->call_arc_volume, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->call_arc_volume, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->call_arc_volume, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->call_arc_volume, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->call_arc_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->call_arc_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->call_arc_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->call_arc_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for call_arc_volume, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->call_arc_volume, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->call_arc_volume, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->call_arc_volume, lv_color_hex(0x08ce08), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->call_arc_volume, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for call_arc_volume, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->call_arc_volume, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->call_arc_volume, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes call_img_person
    ui->call_img_person = lv_image_create(ui->call);
    lv_obj_set_pos(ui->call_img_person, 0, -60);
    lv_obj_set_size(ui->call_img_person, 466, 298);
    lv_obj_add_flag(ui->call_img_person, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->call_img_person, &_img_call_erica_ARGB8888_466x298_tresh);
    lv_image_set_pivot(ui->call_img_person, 50,50);
    lv_image_set_rotation(ui->call_img_person, 0);

    //Write style for call_img_person, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->call_img_person, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->call_img_person, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_img_home_icon
    ui->call_img_home_icon = lv_image_create(ui->call);
    lv_obj_set_pos(ui->call_img_home_icon, 367, 319);
    lv_obj_set_size(ui->call_img_home_icon, 30, 27);
    lv_obj_add_flag(ui->call_img_home_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->call_img_home_icon, &_icn_home_ARGB8888_30x27);
    lv_image_set_pivot(ui->call_img_home_icon, 50,50);
    lv_image_set_rotation(ui->call_img_home_icon, 0);

    //Write style for call_img_home_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->call_img_home_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->call_img_home_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_img_end
    ui->call_img_end = lv_image_create(ui->call);
    lv_obj_set_pos(ui->call_img_end, 397, 114);
    lv_obj_set_size(ui->call_img_end, 30, 40);
    lv_obj_add_flag(ui->call_img_end, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->call_img_end, &_text_endcall_ARGB8888_30x40);
    lv_image_set_pivot(ui->call_img_end, 50,50);
    lv_image_set_rotation(ui->call_img_end, 80);

    //Write style for call_img_end, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->call_img_end, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->call_img_end, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_hang_up_btn
    ui->call_hang_up_btn = lv_button_create(ui->call);
    lv_obj_set_pos(ui->call_hang_up_btn, 328, 114);
    lv_obj_set_size(ui->call_hang_up_btn, 71, 71);
    ui->call_hang_up_btn_label = lv_label_create(ui->call_hang_up_btn);
    lv_label_set_text(ui->call_hang_up_btn_label, "");
    lv_label_set_long_mode(ui->call_hang_up_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->call_hang_up_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->call_hang_up_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->call_hang_up_btn_label, LV_PCT(100));

    //Write style for call_hang_up_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->call_hang_up_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->call_hang_up_btn, lv_color_hex(0xe60c08), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->call_hang_up_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->call_hang_up_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->call_hang_up_btn, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->call_hang_up_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->call_hang_up_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->call_hang_up_btn, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->call_hang_up_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->call_hang_up_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_hang_up
    ui->call_hang_up = lv_image_create(ui->call);
    lv_obj_set_pos(ui->call_hang_up, 348, 136);
    lv_obj_set_size(ui->call_hang_up, 31, 25);
    lv_obj_add_flag(ui->call_hang_up, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->call_hang_up, &_icn_phone_ARGB8888_31x25);
    lv_image_set_pivot(ui->call_hang_up, 50,50);
    lv_image_set_rotation(ui->call_hang_up, 0);

    //Write style for call_hang_up, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->call_hang_up, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->call_hang_up, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_caller
    ui->call_caller = lv_label_create(ui->call);
    lv_obj_set_pos(ui->call_caller, 98, 269);
    lv_obj_set_size(ui->call_caller, 269, 38);
    lv_label_set_text(ui->call_caller, "Erica Smith");
    lv_label_set_long_mode(ui->call_caller, LV_LABEL_LONG_WRAP);

    //Write style for call_caller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->call_caller, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->call_caller, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->call_caller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->call_caller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->call_caller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_mute_btn
    ui->call_mute_btn = lv_button_create(ui->call);
    lv_obj_set_pos(ui->call_mute_btn, 203, 461);
    lv_obj_set_size(ui->call_mute_btn, 60, 60);
    ui->call_mute_btn_label = lv_label_create(ui->call_mute_btn);
    lv_label_set_text(ui->call_mute_btn_label, "");
    lv_label_set_long_mode(ui->call_mute_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->call_mute_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->call_mute_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->call_mute_btn_label, LV_PCT(100));

    //Write style for call_mute_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->call_mute_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->call_mute_btn, lv_color_hex(0x292c29), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->call_mute_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->call_mute_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->call_mute_btn, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->call_mute_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->call_mute_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->call_mute_btn, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->call_mute_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->call_mute_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_mute_icon
    ui->call_mute_icon = lv_image_create(ui->call);
    lv_obj_set_pos(ui->call_mute_icon, 213, 380);
    lv_obj_set_size(ui->call_mute_icon, 40, 32);
    lv_obj_add_flag(ui->call_mute_icon, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->call_mute_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->call_mute_icon, &_icn_mute_ARGB8888_40x32);
    lv_image_set_pivot(ui->call_mute_icon, 50,50);
    lv_image_set_rotation(ui->call_mute_icon, 0);

    //Write style for call_mute_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->call_mute_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->call_mute_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_label_time
    ui->call_label_time = lv_label_create(ui->call);
    lv_obj_set_pos(ui->call_label_time, 155, 323);
    lv_obj_set_size(ui->call_label_time, 154, 26);
    lv_label_set_text(ui->call_label_time, "01:20:54");
    lv_label_set_long_mode(ui->call_label_time, LV_LABEL_LONG_WRAP);

    //Write style for call_label_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->call_label_time, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->call_label_time, &lv_font_montserratMedium_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->call_label_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->call_label_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->call_label_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_unmute_icon
    ui->call_unmute_icon = lv_image_create(ui->call);
    lv_obj_set_pos(ui->call_unmute_icon, 213, 474);
    lv_obj_set_size(ui->call_unmute_icon, 40, 32);
    lv_obj_add_flag(ui->call_unmute_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->call_unmute_icon, &_icn_unmute_ARGB8888_40x32);
    lv_image_set_pivot(ui->call_unmute_icon, 50,50);
    lv_image_set_rotation(ui->call_unmute_icon, 0);

    //Write style for call_unmute_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->call_unmute_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->call_unmute_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes call_img_1
    ui->call_img_1 = lv_image_create(ui->call);
    lv_obj_set_pos(ui->call_img_1, 391, 319);
    lv_obj_set_size(ui->call_img_1, 45, 60);
    lv_obj_add_flag(ui->call_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->call_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->call_img_1, 50,50);
    lv_image_set_rotation(ui->call_img_1, 0);

    //Write style for call_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->call_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->call_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of call.


    //Update current screen layout.
    lv_obj_update_layout(ui->call);

    //Init events for screen.
    events_init_call(ui);
}
