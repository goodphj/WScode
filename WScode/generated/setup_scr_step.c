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



void setup_scr_step(lv_ui *ui)
{
    //Write codes step
    ui->step = lv_obj_create(NULL);
    lv_obj_set_size(ui->step, 466, 466);
    lv_obj_set_scrollbar_mode(ui->step, LV_SCROLLBAR_MODE_OFF);

    //Write style for step, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->step, &_img_bg_2_RGB565_466x466_tresh, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->step, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes step_arc_step
    ui->step_arc_step = lv_arc_create(ui->step);
    lv_obj_set_pos(ui->step_arc_step, 13, 90);
    lv_obj_set_size(ui->step_arc_step, 439, 439);
    lv_obj_add_flag(ui->step_arc_step, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_arc_set_mode(ui->step_arc_step, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->step_arc_step, 0, 100);
    lv_arc_set_bg_angles(ui->step_arc_step, 48, 212);
    lv_arc_set_value(ui->step_arc_step, 70);
    lv_arc_set_rotation(ui->step_arc_step, 0);

    //Write style for step_arc_step, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->step_arc_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->step_arc_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->step_arc_step, 17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->step_arc_step, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->step_arc_step, lv_color_hex(0x777777), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->step_arc_step, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->step_arc_step, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->step_arc_step, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->step_arc_step, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->step_arc_step, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->step_arc_step, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->step_arc_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for step_arc_step, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->step_arc_step, 17, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->step_arc_step, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->step_arc_step, lv_color_hex(0x29CE08), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->step_arc_step, true, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for step_arc_step, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->step_arc_step, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->step_arc_step, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes step_label_current_steps
    ui->step_label_current_steps = lv_label_create(ui->step);
    lv_obj_set_pos(ui->step_label_current_steps, 90, 164);
    lv_obj_set_size(ui->step_label_current_steps, 286, 137);
    lv_obj_add_flag(ui->step_label_current_steps, LV_OBJ_FLAG_GESTURE_BUBBLE);
    lv_label_set_text(ui->step_label_current_steps, "5.8K");
    lv_label_set_long_mode(ui->step_label_current_steps, LV_LABEL_LONG_WRAP);

    //Write style for step_label_current_steps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->step_label_current_steps, lv_color_hex(0x00DB0e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->step_label_current_steps, &lv_font_montserratMedium_118, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->step_label_current_steps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->step_label_current_steps, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->step_label_current_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes step_icon_step
    ui->step_icon_step = lv_image_create(ui->step);
    lv_obj_set_pos(ui->step_icon_step, 216, 10);
    lv_obj_set_size(ui->step_icon_step, 33, 53);
    lv_obj_add_flag(ui->step_icon_step, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->step_icon_step, &_img_step_small_ARGB8888_33x53);
    lv_image_set_pivot(ui->step_icon_step, 50,50);
    lv_image_set_rotation(ui->step_icon_step, 0);

    //Write style for step_icon_step, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->step_icon_step, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->step_icon_step, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes step_title
    ui->step_title = lv_label_create(ui->step);
    lv_obj_set_pos(ui->step_title, 0, -60);
    lv_obj_set_size(ui->step_title, 466, 89);
    lv_obj_add_flag(ui->step_title, LV_OBJ_FLAG_FLOATING);
    lv_label_set_text(ui->step_title, "Step count");
    lv_label_set_long_mode(ui->step_title, LV_LABEL_LONG_WRAP);

    //Write style for step_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->step_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->step_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->step_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->step_title, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->step_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->step_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->step_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->step_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->step_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->step_title, 27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->step_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->step_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->step_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->step_title, &_img_header_bg_ARGB8888_466x89, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->step_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui->step_title, lv_color_hex(0xBD1C39), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->step_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->step_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes step_cont_1
    ui->step_cont_1 = lv_obj_create(ui->step);
    lv_obj_set_pos(ui->step_cont_1, 131, 458);
    lv_obj_set_size(ui->step_cont_1, 202, 98);
    lv_obj_set_scrollbar_mode(ui->step_cont_1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->step_cont_1, LV_OBJ_FLAG_FLOATING);

    //Write style for step_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->step_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->step_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->step_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->step_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->step_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->step_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->step_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->step_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes step_label_goals_steps
    ui->step_label_goals_steps = lv_label_create(ui->step_cont_1);
    lv_obj_set_pos(ui->step_label_goals_steps, 45, 43);
    lv_obj_set_size(ui->step_label_goals_steps, 129, 40);
    lv_label_set_text(ui->step_label_goals_steps, "10 000\n\n\n\n\n");
    lv_label_set_long_mode(ui->step_label_goals_steps, LV_LABEL_LONG_WRAP);

    //Write style for step_label_goals_steps, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->step_label_goals_steps, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->step_label_goals_steps, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->step_label_goals_steps, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->step_label_goals_steps, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->step_label_goals_steps, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes step_label_goal
    ui->step_label_goal = lv_label_create(ui->step_cont_1);
    lv_obj_set_pos(ui->step_label_goal, 43, 15);
    lv_obj_set_size(ui->step_label_goal, 128, 23);
    lv_label_set_text(ui->step_label_goal, "DAILY GOAL");
    lv_label_set_long_mode(ui->step_label_goal, LV_LABEL_LONG_WRAP);

    //Write style for step_label_goal, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->step_label_goal, lv_color_hex(0x757575), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->step_label_goal, &lv_font_montserratMedium_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->step_label_goal, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->step_label_goal, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->step_label_goal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes step_img_1
    ui->step_img_1 = lv_image_create(ui->step);
    lv_obj_set_pos(ui->step_img_1, 391, 319);
    lv_obj_set_size(ui->step_img_1, 45, 60);
    lv_obj_add_flag(ui->step_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->step_img_1, &_text_home_ARGB8888_45x60);
    lv_image_set_pivot(ui->step_img_1, 50,50);
    lv_image_set_rotation(ui->step_img_1, 0);

    //Write style for step_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->step_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->step_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes step_img_3
    ui->step_img_3 = lv_image_create(ui->step);
    lv_obj_set_pos(ui->step_img_3, 6, 214);
    lv_obj_set_size(ui->step_img_3, 12, 38);
    lv_obj_add_flag(ui->step_img_3, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->step_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->step_img_3, &_img_arrow_left_ARGB8888_12x38);
    lv_image_set_pivot(ui->step_img_3, 50,50);
    lv_image_set_rotation(ui->step_img_3, 0);

    //Write style for step_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->step_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->step_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes step_img_2
    ui->step_img_2 = lv_image_create(ui->step);
    lv_obj_set_pos(ui->step_img_2, 448, 214);
    lv_obj_set_size(ui->step_img_2, 12, 38);
    lv_obj_add_flag(ui->step_img_2, LV_OBJ_FLAG_FLOATING);
    lv_obj_add_flag(ui->step_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->step_img_2, &_img_arrow_right_ARGB8888_12x38);
    lv_image_set_pivot(ui->step_img_2, 50,50);
    lv_image_set_rotation(ui->step_img_2, 0);

    //Write style for step_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->step_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->step_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of step.


    //Update current screen layout.
    lv_obj_update_layout(ui->step);

    //Init events for screen.
    events_init_step(ui);
}
