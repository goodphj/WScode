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



void setup_scr_position(lv_ui *ui)
{
    //Write codes position
    ui->position = lv_obj_create(NULL);
    lv_obj_set_size(ui->position, 466, 466);
    lv_obj_set_scrollbar_mode(ui->position, LV_SCROLLBAR_MODE_OFF);

    //Write style for position, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->position, &_img_map_RGB565_466x466, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->position, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->position, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes position_title
    ui->position_title = lv_label_create(ui->position);
    lv_obj_set_pos(ui->position_title, -3, -60);
    lv_obj_set_size(ui->position_title, 466, 89);
    lv_obj_add_flag(ui->position_title, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->position_title, "Your Position\n\n");
    lv_label_set_long_mode(ui->position_title, LV_LABEL_LONG_WRAP);

    //Write style for position_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->position_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->position_title, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->position_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->position_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->position_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->position_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->position_title, &_img_header_bg_ARGB8888_466x89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->position_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui->position_title, lv_color_hex(0x3155EE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->position_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->position_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes position_location_icon
    ui->position_location_icon = lv_button_create(ui->position);
    lv_obj_set_pos(ui->position_location_icon, 221, 221);
    lv_obj_set_size(ui->position_location_icon, 23, 23);
    lv_obj_add_flag(ui->position_location_icon, LV_OBJ_FLAG_GESTURE_BUBBLE);
    ui->position_location_icon_label = lv_label_create(ui->position_location_icon);
    lv_label_set_text(ui->position_location_icon_label, "");
    lv_label_set_long_mode(ui->position_location_icon_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->position_location_icon_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->position_location_icon, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->position_location_icon_label, LV_PCT(100));

    //Write style for position_location_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->position_location_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->position_location_icon, lv_color_hex(0x00E2FF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->position_location_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->position_location_icon, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->position_location_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->position_location_icon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->position_location_icon, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->position_location_icon, 17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->position_location_icon, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->position_location_icon, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->position_location_icon, 110, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->position_location_icon, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->position_location_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->position_location_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->position_location_icon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->position_location_icon, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->position_location_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->position_location_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes position_bottom
    ui->position_bottom = lv_obj_create(ui->position);
    lv_obj_set_pos(ui->position_bottom, 115, 470);
    lv_obj_set_size(ui->position_bottom, 250, 250);
    lv_obj_set_scrollbar_mode(ui->position_bottom, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->position_bottom, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->position_bottom, LV_OBJ_FLAG_GESTURE_BUBBLE);

    //Write style for position_bottom, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->position_bottom, 250, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->position_bottom, 90, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->position_bottom, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->position_bottom, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->position_bottom, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes position_label_1
    ui->position_label_1 = lv_label_create(ui->position_bottom);
    lv_obj_set_pos(ui->position_label_1, 87, 36);
    lv_obj_set_size(ui->position_label_1, 108, 47);
    lv_obj_add_flag(ui->position_label_1, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->position_label_1, "Turn Right\n200m\n");
    lv_label_set_long_mode(ui->position_label_1, LV_LABEL_LONG_WRAP);

    //Write style for position_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->position_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->position_label_1, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->position_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->position_label_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->position_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->position_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes position_img_1
    ui->position_img_1 = lv_image_create(ui->position_bottom);
    lv_obj_set_pos(ui->position_img_1, 45, 32);
    lv_obj_set_size(ui->position_img_1, 40, 45);
    lv_obj_add_flag(ui->position_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->position_img_1, &_img_small_nav_1_ARGB8888_40x45);
    lv_image_set_pivot(ui->position_img_1, 50,50);
    lv_image_set_rotation(ui->position_img_1, 0);

    //Write style for position_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->position_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->position_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes position_img_2
    ui->position_img_2 = lv_image_create(ui->position);
    lv_obj_set_pos(ui->position_img_2, 391, 319);
    lv_obj_set_size(ui->position_img_2, 45, 60);
    lv_obj_add_flag(ui->position_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->position_img_2, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->position_img_2, 50,50);
    lv_image_set_rotation(ui->position_img_2, 0);

    //Write style for position_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->position_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->position_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes position_img_4
    ui->position_img_4 = lv_image_create(ui->position);
    lv_obj_set_pos(ui->position_img_4, 6, 214);
    lv_obj_set_size(ui->position_img_4, 12, 38);
    lv_obj_add_flag(ui->position_img_4, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->position_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->position_img_4, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->position_img_4, 50,50);
    lv_image_set_rotation(ui->position_img_4, 0);

    //Write style for position_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->position_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->position_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes position_img_3
    ui->position_img_3 = lv_image_create(ui->position);
    lv_obj_set_pos(ui->position_img_3, 448, 214);
    lv_obj_set_size(ui->position_img_3, 12, 38);
    lv_obj_add_flag(ui->position_img_3, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->position_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->position_img_3, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->position_img_3, 50,50);
    lv_image_set_rotation(ui->position_img_3, 0);

    //Write style for position_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->position_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->position_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of position.


    //Update current screen layout.
    lv_obj_update_layout(ui->position);

    //Init events for screen.
    events_init_position(ui);
}
