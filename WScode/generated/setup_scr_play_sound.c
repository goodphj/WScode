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



void setup_scr_play_sound(lv_ui *ui)
{
    //Write codes play_sound
    ui->play_sound = lv_obj_create(NULL);
    lv_obj_set_size(ui->play_sound, 466, 466);
    lv_obj_set_scrollbar_mode(ui->play_sound, LV_SCROLLBAR_MODE_OFF);

    //Write style for play_sound, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->play_sound, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->play_sound, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->play_sound, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->play_sound, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes play_sound_img_find
    ui->play_sound_img_find = lv_image_create(ui->play_sound);
    lv_obj_set_pos(ui->play_sound_img_find, 133, 90);
    lv_obj_set_size(ui->play_sound_img_find, 199, 199);
    lv_obj_add_flag(ui->play_sound_img_find, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->play_sound_img_find, &_img_find_device2_ARGB8888_199x199);
    lv_image_set_pivot(ui->play_sound_img_find, 84,84);
    lv_image_set_rotation(ui->play_sound_img_find, 0);

    //Write style for play_sound_img_find, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->play_sound_img_find, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->play_sound_img_find, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes play_sound_btn_cancel
    ui->play_sound_btn_cancel = lv_button_create(ui->play_sound);
    lv_obj_set_pos(ui->play_sound_btn_cancel, 149, 400);
    lv_obj_set_size(ui->play_sound_btn_cancel, 167, 64);
    ui->play_sound_btn_cancel_label = lv_label_create(ui->play_sound_btn_cancel);
    lv_label_set_text(ui->play_sound_btn_cancel_label, "CANCEL");
    lv_label_set_long_mode(ui->play_sound_btn_cancel_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->play_sound_btn_cancel_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->play_sound_btn_cancel, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->play_sound_btn_cancel_label, LV_PCT(100));

    //Write style for play_sound_btn_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->play_sound_btn_cancel, 171, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->play_sound_btn_cancel, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->play_sound_btn_cancel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->play_sound_btn_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->play_sound_btn_cancel, 32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->play_sound_btn_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->play_sound_btn_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->play_sound_btn_cancel, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->play_sound_btn_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->play_sound_btn_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes play_sound_title
    ui->play_sound_title = lv_label_create(ui->play_sound);
    lv_obj_set_pos(ui->play_sound_title, 38, -35);
    lv_obj_set_size(ui->play_sound_title, 391, 46);
    lv_obj_add_flag(ui->play_sound_title, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->play_sound_title, "Playing Sound\n");
    lv_label_set_long_mode(ui->play_sound_title, LV_LABEL_LONG_WRAP);

    //Write style for play_sound_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->play_sound_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->play_sound_title, &lv_font_montserratMedium_23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->play_sound_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->play_sound_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->play_sound_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->play_sound_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->play_sound_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes play_sound_img_1
    ui->play_sound_img_1 = lv_image_create(ui->play_sound);
    lv_obj_set_pos(ui->play_sound_img_1, 391, 319);
    lv_obj_set_size(ui->play_sound_img_1, 45, 60);
    lv_obj_add_flag(ui->play_sound_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->play_sound_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->play_sound_img_1, 50,50);
    lv_image_set_rotation(ui->play_sound_img_1, 0);

    //Write style for play_sound_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->play_sound_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->play_sound_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes play_sound_img_3
    ui->play_sound_img_3 = lv_image_create(ui->play_sound);
    lv_obj_set_pos(ui->play_sound_img_3, 6, 214);
    lv_obj_set_size(ui->play_sound_img_3, 12, 38);
    lv_obj_add_flag(ui->play_sound_img_3, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->play_sound_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->play_sound_img_3, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->play_sound_img_3, 50,50);
    lv_image_set_rotation(ui->play_sound_img_3, 0);

    //Write style for play_sound_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->play_sound_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->play_sound_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes play_sound_img_2
    ui->play_sound_img_2 = lv_image_create(ui->play_sound);
    lv_obj_set_pos(ui->play_sound_img_2, 448, 214);
    lv_obj_set_size(ui->play_sound_img_2, 12, 38);
    lv_obj_add_flag(ui->play_sound_img_2, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->play_sound_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->play_sound_img_2, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->play_sound_img_2, 50,50);
    lv_image_set_rotation(ui->play_sound_img_2, 0);

    //Write style for play_sound_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->play_sound_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->play_sound_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of play_sound.


    //Update current screen layout.
    lv_obj_update_layout(ui->play_sound);

    //Init events for screen.
    events_init_play_sound(ui);
}
