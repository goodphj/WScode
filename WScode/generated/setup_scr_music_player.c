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



void setup_scr_music_player(lv_ui *ui)
{
    //Write codes music_player
    ui->music_player = lv_obj_create(NULL);
    lv_obj_set_size(ui->music_player, 466, 466);
    lv_obj_set_scrollbar_mode(ui->music_player, LV_SCROLLBAR_MODE_OFF);

    //Write style for music_player, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_player, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->music_player, &_img_audio_album_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->music_player, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->music_player, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_arc_step
    ui->music_player_arc_step = lv_arc_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_arc_step, 13, -37);
    lv_obj_set_size(ui->music_player_arc_step, 439, 439);
    lv_obj_add_flag(ui->music_player_arc_step, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_add_flag(ui->music_player_arc_step, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_arc_set_mode(ui->music_player_arc_step, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->music_player_arc_step, 0, 100);
    lv_arc_set_bg_angles(ui->music_player_arc_step, 0, 172);
    lv_arc_set_value(ui->music_player_arc_step, 70);
    lv_arc_set_rotation(ui->music_player_arc_step, 160);

    //Write style for music_player_arc_step, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_player_arc_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_player_arc_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->music_player_arc_step, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->music_player_arc_step, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->music_player_arc_step, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->music_player_arc_step, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_player_arc_step, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_player_arc_step, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_player_arc_step, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_player_arc_step, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_player_arc_step, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_player_arc_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for music_player_arc_step, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->music_player_arc_step, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->music_player_arc_step, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->music_player_arc_step, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->music_player_arc_step, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for music_player_arc_step, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_player_arc_step, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_player_arc_step, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_player_arc_step, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->music_player_arc_step, 3, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes music_player_arc_volume
    ui->music_player_arc_volume = lv_arc_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_arc_volume, 13, 63);
    lv_obj_set_size(ui->music_player_arc_volume, 439, 439);
    lv_obj_add_flag(ui->music_player_arc_volume, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_add_flag(ui->music_player_arc_volume, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_add_flag(ui->music_player_arc_volume, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_arc_set_mode(ui->music_player_arc_volume, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->music_player_arc_volume, 0, 100);
    lv_arc_set_bg_angles(ui->music_player_arc_volume, 46, 142);
    lv_arc_set_value(ui->music_player_arc_volume, 70);
    lv_arc_set_rotation(ui->music_player_arc_volume, 0);

    //Write style for music_player_arc_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_player_arc_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_player_arc_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->music_player_arc_volume, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->music_player_arc_volume, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->music_player_arc_volume, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->music_player_arc_volume, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_player_arc_volume, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_player_arc_volume, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_player_arc_volume, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_player_arc_volume, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_player_arc_volume, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_player_arc_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for music_player_arc_volume, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->music_player_arc_volume, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->music_player_arc_volume, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->music_player_arc_volume, lv_color_hex(0x08ce08), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->music_player_arc_volume, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for music_player_arc_volume, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_player_arc_volume, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->music_player_arc_volume, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes music_player_img_volume
    ui->music_player_img_volume = lv_image_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_img_volume, 78, 400);
    lv_obj_set_size(ui->music_player_img_volume, 32, 84);
    lv_obj_add_flag(ui->music_player_img_volume, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->music_player_img_volume, &_text_volume_ARGB8888_32x84);
    lv_image_set_pivot(ui->music_player_img_volume, 0,0);
    lv_image_set_rotation(ui->music_player_img_volume, -340);

    //Write style for music_player_img_volume, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->music_player_img_volume, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->music_player_img_volume, 187, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_icon_home
    ui->music_player_icon_home = lv_image_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_icon_home, 375, 307);
    lv_obj_set_size(ui->music_player_icon_home, 30, 28);
    lv_obj_add_flag(ui->music_player_icon_home, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->music_player_icon_home, &_icn_home_ARGB8888_30x28);
    lv_image_set_pivot(ui->music_player_icon_home, 50,50);
    lv_image_set_rotation(ui->music_player_icon_home, 0);

    //Write style for music_player_icon_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->music_player_icon_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->music_player_icon_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_singer
    ui->music_player_singer = lv_label_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_singer, 98, 20);
    lv_obj_set_size(ui->music_player_singer, 269, 48);
    lv_label_set_text(ui->music_player_singer, "Erica Smith");
    lv_label_set_long_mode(ui->music_player_singer, LV_LABEL_LONG_WRAP);

    //Write style for music_player_singer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_player_singer, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_player_singer, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_player_singer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_player_singer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_player_singer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_img_next
    ui->music_player_img_next = lv_image_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_img_next, 362, 217);
    lv_obj_set_size(ui->music_player_img_next, 20, 30);
    lv_obj_add_flag(ui->music_player_img_next, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->music_player_img_next, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->music_player_img_next, &_icn_audio_next_ARGB8888_20x30);
    lv_image_set_pivot(ui->music_player_img_next, 50,50);
    lv_image_set_rotation(ui->music_player_img_next, 0);

    //Write style for music_player_img_next, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->music_player_img_next, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->music_player_img_next, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_img_previous
    ui->music_player_img_previous = lv_image_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_img_previous, 83, 217);
    lv_obj_set_size(ui->music_player_img_previous, 20, 30);
    lv_obj_add_flag(ui->music_player_img_previous, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->music_player_img_previous, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->music_player_img_previous, &_icn_audio_back_ARGB8888_20x30);
    lv_image_set_pivot(ui->music_player_img_previous, 50,50);
    lv_image_set_rotation(ui->music_player_img_previous, 0);

    //Write style for music_player_img_previous, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->music_player_img_previous, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->music_player_img_previous, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_song_name
    ui->music_player_song_name = lv_label_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_song_name, 83, 60);
    lv_obj_set_size(ui->music_player_song_name, 299, 39);
    lv_label_set_text(ui->music_player_song_name, "Dance on the room");
    lv_label_set_long_mode(ui->music_player_song_name, LV_LABEL_LONG_WRAP);

    //Write style for music_player_song_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_player_song_name, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_player_song_name, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_player_song_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_player_song_name, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_player_song_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_duration
    ui->music_player_duration = lv_label_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_duration, 124, 350);
    lv_obj_set_size(ui->music_player_duration, 217, 32);
    lv_label_set_text(ui->music_player_duration, "01:24 | 02:15");
    lv_label_set_long_mode(ui->music_player_duration, LV_LABEL_LONG_WRAP);

    //Write style for music_player_duration, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_player_duration, lv_color_hex(0xbdbdbd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_player_duration, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_player_duration, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->music_player_duration, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_player_duration, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_player_duration, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_mode
    ui->music_player_mode = lv_image_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_mode, 213, 415);
    lv_obj_set_size(ui->music_player_mode, 39, 34);
    lv_obj_add_flag(ui->music_player_mode, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->music_player_mode, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->music_player_mode, &_icn_audio_rnd_ARGB8888_39x34);
    lv_image_set_pivot(ui->music_player_mode, 50,50);
    lv_image_set_rotation(ui->music_player_mode, 0);

    //Write style for music_player_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->music_player_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->music_player_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_btn_background
    ui->music_player_btn_background = lv_button_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_btn_background, 173, 173);
    lv_obj_set_size(ui->music_player_btn_background, 118, 118);
    lv_obj_add_flag(ui->music_player_btn_background, LV_OBJ_FLAG_GESTURE_BUBBLE);
    ui->music_player_btn_background_label = lv_label_create(ui->music_player_btn_background);
    lv_label_set_text(ui->music_player_btn_background_label, "");
    lv_label_set_long_mode(ui->music_player_btn_background_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->music_player_btn_background_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->music_player_btn_background, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->music_player_btn_background_label, LV_PCT(100));

    //Write style for music_player_btn_background, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->music_player_btn_background, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->music_player_btn_background, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->music_player_btn_background, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->music_player_btn_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->music_player_btn_background, 83, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_player_btn_background, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->music_player_btn_background, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_player_btn_background, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_player_btn_background, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_player_btn_background, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_img_dot
    ui->music_player_img_dot = lv_image_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_img_dot, 439, 212);
    lv_obj_set_size(ui->music_player_img_dot, 9, 9);
    lv_obj_add_flag(ui->music_player_img_dot, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->music_player_img_dot, &_dot_ARGB8888_9x9);
    lv_image_set_pivot(ui->music_player_img_dot, 50,50);
    lv_image_set_rotation(ui->music_player_img_dot, 0);

    //Write style for music_player_img_dot, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->music_player_img_dot, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->music_player_img_dot, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_img_menu
    ui->music_player_img_menu = lv_image_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_img_menu, 433, 173);
    lv_obj_set_size(ui->music_player_img_menu, 13, 118);
    lv_obj_add_flag(ui->music_player_img_menu, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->music_player_img_menu, &_img_menu_ARGB8888_13x118);
    lv_image_set_pivot(ui->music_player_img_menu, 50,50);
    lv_image_set_rotation(ui->music_player_img_menu, 0);

    //Write style for music_player_img_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->music_player_img_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->music_player_img_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes music_player_imgbtn_play
    ui->music_player_imgbtn_play = lv_imagebutton_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_imgbtn_play, 222, 209);
    lv_obj_set_size(ui->music_player_imgbtn_play, 28, 45);
    lv_obj_add_flag(ui->music_player_imgbtn_play, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_obj_add_flag(ui->music_player_imgbtn_play, LV_OBJ_FLAG_CHECKABLE);
    lv_imagebutton_set_src(ui->music_player_imgbtn_play, LV_IMAGEBUTTON_STATE_RELEASED, &_icn_audio_play_ARGB8888_28x45, NULL, NULL);
    lv_imagebutton_set_src(ui->music_player_imgbtn_play, LV_IMAGEBUTTON_STATE_PRESSED, &_icn_audio_play_ARGB8888_28x45, NULL, NULL);
    lv_imagebutton_set_src(ui->music_player_imgbtn_play, LV_IMAGEBUTTON_STATE_CHECKED_RELEASED, &_img_pause_ARGB8888_28x45, NULL, NULL);
    lv_imagebutton_set_src(ui->music_player_imgbtn_play, LV_IMAGEBUTTON_STATE_CHECKED_PRESSED, &_img_pause_ARGB8888_28x45, NULL, NULL);
    ui->music_player_imgbtn_play_label = lv_label_create(ui->music_player_imgbtn_play);
    lv_label_set_text(ui->music_player_imgbtn_play_label, "");
    lv_label_set_long_mode(ui->music_player_imgbtn_play_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->music_player_imgbtn_play_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->music_player_imgbtn_play, 0, LV_STATE_DEFAULT);

    //Write style for music_player_imgbtn_play, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->music_player_imgbtn_play, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->music_player_imgbtn_play, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->music_player_imgbtn_play, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->music_player_imgbtn_play, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->music_player_imgbtn_play, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for music_player_imgbtn_play, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_image_recolor_opa(ui->music_player_imgbtn_play, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_image_opa(ui->music_player_imgbtn_play, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->music_player_imgbtn_play, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->music_player_imgbtn_play, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->music_player_imgbtn_play, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->music_player_imgbtn_play, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for music_player_imgbtn_play, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_image_recolor_opa(ui->music_player_imgbtn_play, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_image_opa(ui->music_player_imgbtn_play, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->music_player_imgbtn_play, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->music_player_imgbtn_play, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->music_player_imgbtn_play, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->music_player_imgbtn_play, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for music_player_imgbtn_play, Part: LV_PART_MAIN, State: LV_IMAGEBUTTON_STATE_RELEASED.
    lv_obj_set_style_image_recolor_opa(ui->music_player_imgbtn_play, 0, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);
    lv_obj_set_style_image_opa(ui->music_player_imgbtn_play, 255, LV_PART_MAIN|LV_IMAGEBUTTON_STATE_RELEASED);

    //Write codes music_player_img_1
    ui->music_player_img_1 = lv_image_create(ui->music_player);
    lv_obj_set_pos(ui->music_player_img_1, 391, 319);
    lv_obj_set_size(ui->music_player_img_1, 45, 60);
    lv_obj_add_flag(ui->music_player_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->music_player_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->music_player_img_1, 50,50);
    lv_image_set_rotation(ui->music_player_img_1, 0);

    //Write style for music_player_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->music_player_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->music_player_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of music_player.


    //Update current screen layout.
    lv_obj_update_layout(ui->music_player);

    //Init events for screen.
    events_init_music_player(ui);
}
