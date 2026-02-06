/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "custom.h"

extern bool AclockisValid;
extern int AClock_Hour_Value;
extern int AClock_Min_Value;
extern int AClock_Sec_Value;
uint8_t start_car = 0;

static void home_analog_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.home_analog_nxp_log, 500, 200, lv_obj_get_x(guider_ui.home_analog_nxp_log), 350, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        if (!AclockisValid) {
            ui_animation(guider_ui.home_analog_img_Sec, 800, 100, 0, (AClock_Sec_Value * 60), &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_image_set_rotation, NULL, NULL, NULL);
            ui_animation(guider_ui.home_analog_img_Min, 800, 100, 0, (AClock_Min_Value * 60), &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_image_set_rotation, NULL, NULL, NULL);
            ui_animation(guider_ui.home_analog_img_Hour, 800, 100, 0, (AClock_Hour_Value * 300), &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_image_set_rotation, NULL, analog_clock_ready_cb, NULL);
        }
        break;
    }
    case LV_EVENT_SCREEN_UNLOAD_START:
    {
        AclockisValid = false;
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.home_analog_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.contact_list, guider_ui.contact_list_del, &guider_ui.home_analog_del, setup_scr_contact_list, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.weather, guider_ui.weather_del, &guider_ui.home_analog_del, setup_scr_weather, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void home_analog_weather_icon_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.weather, guider_ui.weather_del, &guider_ui.home_analog_del, setup_scr_weather, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void home_analog_battery_text_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.battery, guider_ui.battery_del, &guider_ui.home_analog_del, setup_scr_battery, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void home_analog_message_icon_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.message_info, guider_ui.message_info_del, &guider_ui.home_analog_del, setup_scr_message_info, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void home_analog_sport_icon_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.fitness, guider_ui.fitness_del, &guider_ui.home_analog_del, setup_scr_fitness, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void home_analog_message_text_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.message_info, guider_ui.message_info_del, &guider_ui.home_analog_del, setup_scr_message_info, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void home_analog_sport_text_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.fitness, guider_ui.fitness_del, &guider_ui.home_analog_del, setup_scr_fitness, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_home_analog (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_analog, home_analog_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_analog_weather_icon, home_analog_weather_icon_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_analog_battery_text, home_analog_battery_text_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_analog_message_icon, home_analog_message_icon_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_analog_sport_icon, home_analog_sport_icon_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_analog_message_text, home_analog_message_text_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_analog_sport_text, home_analog_sport_text_event_handler, LV_EVENT_ALL, ui);
}

static void home_digital_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.home_digital_label_min, 500, 0, lv_obj_get_y(guider_ui.home_digital_label_min), 208, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.home_digital_label_hour, 500, 0, lv_obj_get_y(guider_ui.home_digital_label_hour), 82, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.home_digital_img_NXP, 500, 200, lv_obj_get_x(guider_ui.home_digital_img_NXP), 350, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.home_digital_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.home_digital_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.weather, guider_ui.weather_del, &guider_ui.home_digital_del, setup_scr_weather, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void home_digital_img_bell_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.message_info, guider_ui.message_info_del, &guider_ui.home_digital_del, setup_scr_message_info, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void home_digital_img_msg_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.message_info, guider_ui.message_info_del, &guider_ui.home_digital_del, setup_scr_message_info, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_home_digital (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home_digital, home_digital_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_digital_img_bell, home_digital_img_bell_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_digital_img_msg, home_digital_img_msg_event_handler, LV_EVENT_ALL, ui);
}

static void contact_list_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.contact_list_label_title, 600, 0, lv_obj_get_y(guider_ui.contact_list_label_title), 0, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.contact_list_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.contact_list_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void contact_list_cont_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.call, guider_ui.call_del, &guider_ui.contact_list_del, setup_scr_call, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void contact_list_img_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.contact_list_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_contact_list (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->contact_list, contact_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->contact_list_cont_2, contact_list_cont_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->contact_list_img_home, contact_list_img_home_event_handler, LV_EVENT_ALL, ui);
}

static void call_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.call_img_person, 600, 0, lv_obj_get_y(guider_ui.call_img_person), 0, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.call_unmute_icon, 600, 0, lv_obj_get_y(guider_ui.call_unmute_icon), 380, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.call_mute_btn, 600, 0, lv_obj_get_y(guider_ui.call_mute_btn), 367, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void call_img_home_icon_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.call_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void call_hang_up_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.call_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void call_hang_up_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.call_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void call_mute_icon_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.call_unmute_icon, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.call_mute_icon, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void call_unmute_icon_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.call_mute_icon, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void call_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.call_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_call (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->call, call_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->call_img_home_icon, call_img_home_icon_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->call_hang_up_btn, call_hang_up_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->call_hang_up, call_hang_up_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->call_mute_icon, call_mute_icon_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->call_unmute_icon, call_unmute_icon_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->call_img_1, call_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void weather_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.weather_label_city, 400, 0, lv_obj_get_y(guider_ui.weather_label_city), 30, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.weather_label_maxMin, 400, 0, lv_obj_get_y(guider_ui.weather_label_maxMin), 355, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.weather_img_icon, 400, 0, lv_obj_get_y(guider_ui.weather_img_icon), 274, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.weather_img_bgCloud, 10000, 100, lv_obj_get_x(guider_ui.weather_img_bgCloud), -230, &lv_anim_path_linear, -1, 100, 10000, 100, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.weather_hour, guider_ui.weather_hour_del, &guider_ui.weather_del, setup_scr_weather_hour, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.weather_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.fitness, guider_ui.fitness_del, &guider_ui.weather_del, setup_scr_fitness, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void weather_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.weather_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_weather (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->weather, weather_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->weather_img_1, weather_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void weather_hour_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.weather_hour_title, 500, 0, lv_obj_get_y(guider_ui.weather_hour_title), 0, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.weather_week, guider_ui.weather_week_del, &guider_ui.weather_hour_del, setup_scr_weather_week, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.weather, guider_ui.weather_del, &guider_ui.weather_hour_del, setup_scr_weather, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void weather_hour_img_34_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.weather_hour_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_weather_hour (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->weather_hour, weather_hour_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->weather_hour_img_34, weather_hour_img_34_event_handler, LV_EVENT_ALL, ui);
}

static void weather_week_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.weather_week_week_title, 500, 0, lv_obj_get_y(guider_ui.weather_week_week_title), 0, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.air_quality, guider_ui.air_quality_del, &guider_ui.weather_week_del, setup_scr_air_quality, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.weather_hour, guider_ui.weather_hour_del, &guider_ui.weather_week_del, setup_scr_weather_hour, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void weather_week_img_34_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.weather_week_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_weather_week (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->weather_week, weather_week_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->weather_week_img_34, weather_week_img_34_event_handler, LV_EVENT_ALL, ui);
}

static void air_quality_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.air_quality_air_title, 500, 0, lv_obj_get_y(guider_ui.air_quality_air_title), 0, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.air_quality_ade_text, 500, 0, lv_obj_get_y(guider_ui.air_quality_ade_text), 390, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.weather_week, guider_ui.weather_week_del, &guider_ui.air_quality_del, setup_scr_weather_week, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.weather, guider_ui.weather_del, &guider_ui.air_quality_del, setup_scr_weather, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void air_quality_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.air_quality_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_air_quality (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->air_quality, air_quality_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->air_quality_img_1, air_quality_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void fitness_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.fitness_title, 500, 0, lv_obj_get_y(guider_ui.fitness_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.fitness_calorie_arc, 500, 0, lv_obj_get_y(guider_ui.fitness_calorie_arc), 10, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.fitness_calorie_arc, LV_OBJ_FLAG_CLICKABLE);
        ui_animation(guider_ui.fitness_distance_arc, 500, 0, lv_obj_get_y(guider_ui.fitness_distance_arc), 35, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.fitness_distance_arc, LV_OBJ_FLAG_CLICKABLE);
        ui_animation(guider_ui.fitness_duration_arc, 500, 0, lv_obj_get_y(guider_ui.fitness_duration_arc), 60, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.fitness_duration_arc, LV_OBJ_FLAG_CLICKABLE);
        ui_animation(guider_ui.fitness_pluse_arc, 500, 0, lv_obj_get_y(guider_ui.fitness_pluse_arc), 85, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.fitness_pluse_arc, LV_OBJ_FLAG_CLICKABLE);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.weather, guider_ui.weather_del, &guider_ui.fitness_del, setup_scr_weather, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.music_player, guider_ui.music_player_del, &guider_ui.fitness_del, setup_scr_music_player, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void fitness_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.fitness_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_fitness (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->fitness, fitness_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->fitness_img_1, fitness_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void music_player_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.music_player_duration, 500, 0, lv_obj_get_y(guider_ui.music_player_duration), 300, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.music_player_song_name, 500, 0, lv_obj_get_y(guider_ui.music_player_song_name), 110, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.music_player_singer, 500, 0, lv_obj_get_y(guider_ui.music_player_singer), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.music_player_arc_volume, 500, 0, lv_obj_get_y(guider_ui.music_player_arc_volume), 13, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.music_player_arc_step, 500, 0, lv_obj_get_y(guider_ui.music_player_arc_step), 13, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.music_player_mode, 500, 0, lv_obj_get_y(guider_ui.music_player_mode), 365, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.music_player_img_volume, 500, 0, lv_obj_get_y(guider_ui.music_player_img_volume), 350, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.fitness, guider_ui.fitness_del, &guider_ui.music_player_del, setup_scr_fitness, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.flight, guider_ui.flight_del, &guider_ui.music_player_del, setup_scr_flight, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void music_player_icon_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.music_player_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void music_player_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.music_player_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_music_player (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->music_player, music_player_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->music_player_icon_home, music_player_icon_home_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->music_player_img_1, music_player_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void flight_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.flight_flight_location, 500, 0, lv_obj_get_y(guider_ui.flight_flight_location), 86, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.flight_flight_seat, 500, 0, lv_obj_get_y(guider_ui.flight_flight_seat), 350, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.flight_title, 500, 0, lv_obj_get_y(guider_ui.flight_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.flight_info, guider_ui.flight_info_del, &guider_ui.flight_del, setup_scr_flight_info, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.music_player, guider_ui.music_player_del, &guider_ui.flight_del, setup_scr_music_player, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.navigation, guider_ui.navigation_del, &guider_ui.flight_del, setup_scr_navigation, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void flight_img_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.flight_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_flight (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->flight, flight_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->flight_img_3, flight_img_3_event_handler, LV_EVENT_ALL, ui);
}

static void flight_info_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.flight_info_title, 500, 0, lv_obj_get_y(guider_ui.flight_info_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.flight_info_qrcode, 500, 0, lv_obj_get_y(guider_ui.flight_info_qrcode), 165, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.flight_info_flight_number, 500, 0, lv_obj_get_y(guider_ui.flight_info_flight_number), 110, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.flight_info_number_text, 500, 0, lv_obj_get_y(guider_ui.flight_info_number_text), 90, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.flight, guider_ui.flight_del, &guider_ui.flight_info_del, setup_scr_flight, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.flight, guider_ui.flight_del, &guider_ui.flight_info_del, setup_scr_flight, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void flight_info_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.flight_info_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_flight_info (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->flight_info, flight_info_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->flight_info_img_1, flight_info_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void navigation_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.navigation_indicator, 500, 0, lv_obj_get_y(guider_ui.navigation_indicator), 350, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.navigation_road_name, 500, 0, lv_obj_get_y(guider_ui.navigation_road_name), 90, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.navigation_next_roadName, 500, 0, lv_obj_get_y(guider_ui.navigation_next_roadName), 120, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.navigation_title, 500, 0, lv_obj_get_y(guider_ui.navigation_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.flight, guider_ui.flight_del, &guider_ui.navigation_del, setup_scr_flight, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.position, guider_ui.position_del, &guider_ui.navigation_del, setup_scr_position, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.payment, guider_ui.payment_del, &guider_ui.navigation_del, setup_scr_payment, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void navigation_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.navigation_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_navigation (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->navigation, navigation_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->navigation_img_1, navigation_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void position_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.position_bottom, 500, 0, lv_obj_get_y(guider_ui.position_bottom), 370, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.position_title, 500, 0, lv_obj_get_y(guider_ui.position_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.position_location_icon, LV_OBJ_FLAG_CLICKABLE);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.navigation, guider_ui.navigation_del, &guider_ui.position_del, setup_scr_navigation, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.navigation, guider_ui.navigation_del, &guider_ui.position_del, setup_scr_navigation, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void position_img_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.position_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_position (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->position, position_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->position_img_2, position_img_2_event_handler, LV_EVENT_ALL, ui);
}

static void payment_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.payment_bank_info, 500, 0, lv_obj_get_y(guider_ui.payment_bank_info), 370, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.payment_amount, 500, 0, lv_obj_get_y(guider_ui.payment_amount), 120, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.payment_next_buy, 500, 0, lv_obj_get_y(guider_ui.payment_next_buy), 100, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.payment_title, 500, 0, lv_obj_get_y(guider_ui.payment_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.payment_card_icon, LV_OBJ_FLAG_CLICKABLE);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.navigation, guider_ui.navigation_del, &guider_ui.payment_del, setup_scr_navigation, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.payment_info, guider_ui.payment_info_del, &guider_ui.payment_del, setup_scr_payment_info, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.settings, guider_ui.settings_del, &guider_ui.payment_del, setup_scr_settings, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void payment_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.payment_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_payment (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->payment, payment_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->payment_img_1, payment_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void payment_info_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.payment_info_pay_info, 500, 0, lv_obj_get_y(guider_ui.payment_info_pay_info), 300, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.payment_info_title, 500, 0, lv_obj_get_y(guider_ui.payment_info_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.payment, guider_ui.payment_del, &guider_ui.payment_info_del, setup_scr_payment, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.payment, guider_ui.payment_del, &guider_ui.payment_info_del, setup_scr_payment, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void payment_info_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.payment_info_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_payment_info (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->payment_info, payment_info_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->payment_info_img_1, payment_info_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void message_info_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.message_info_app_icon, 500, 0, lv_obj_get_y(guider_ui.message_info_app_icon), 30, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.message_info_sender, 500, 0, lv_obj_get_y(guider_ui.message_info_sender), 107, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.message_info_time_text, 500, 0, lv_obj_get_y(guider_ui.message_info_time_text), 300, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.message_info_ok_btn, 500, 0, lv_obj_get_y(guider_ui.message_info_ok_btn), 360, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.message_list, guider_ui.message_list_del, &guider_ui.message_info_del, setup_scr_message_list, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.message_info_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void message_info_ok_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.message_info_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void message_info_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.message_info_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_message_info (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->message_info, message_info_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->message_info_ok_btn, message_info_ok_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->message_info_img_1, message_info_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void message_list_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.message_list_app_icon, 500, 0, lv_obj_get_y(guider_ui.message_list_app_icon), 10, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.standup, guider_ui.standup_del, &guider_ui.message_list_del, setup_scr_standup, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.message_info, guider_ui.message_info_del, &guider_ui.message_list_del, setup_scr_message_info, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void message_list_img_11_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.message_list_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_message_list (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->message_list, message_list_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->message_list_img_11, message_list_img_11_event_handler, LV_EVENT_ALL, ui);
}

static void standup_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.standup_stand_icon, 500, 0, lv_obj_get_y(guider_ui.standup_stand_icon), 23, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.standup_ok_btn, 500, 1, lv_obj_get_y(guider_ui.standup_ok_btn), 360, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.standup_time_text, 500, 0, lv_obj_get_y(guider_ui.standup_time_text), 300, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.standup_stand_text, 500, 1, lv_obj_get_y(guider_ui.standup_stand_text), 150, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.car_lock, guider_ui.car_lock_del, &guider_ui.standup_del, setup_scr_car_lock, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.message_list, guider_ui.message_list_del, &guider_ui.standup_del, setup_scr_message_list, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void standup_ok_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.standup_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
        break;
    }
    default:
        break;
    }
}

static void standup_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.standup_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_standup (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->standup, standup_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->standup_ok_btn, standup_ok_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->standup_img_1, standup_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void car_lock_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.car_lock_car_icon, 500, 0, lv_obj_get_y(guider_ui.car_lock_car_icon), 23, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.car_lock_cont_1, 500, 0, lv_obj_get_y(guider_ui.car_lock_cont_1), 250, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.car_lock_lock_icon2, 200, 800, lv_obj_get_y(guider_ui.car_lock_lock_icon2), 30, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.car_lock_time_text, 500, 0, lv_obj_get_y(guider_ui.car_lock_time_text), 205, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.car_lock_car_text, 500, 0, lv_obj_get_y(guider_ui.car_lock_car_text), 150, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.car_start, guider_ui.car_start_del, &guider_ui.car_lock_del, setup_scr_car_start, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.standup, guider_ui.standup_del, &guider_ui.car_lock_del, setup_scr_standup, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void car_lock_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.car_lock_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_car_lock (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->car_lock, car_lock_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->car_lock_img_1, car_lock_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void car_start_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.car_start_start_imgbtn, 500, 0, lv_obj_get_y(guider_ui.car_start_start_imgbtn), 240, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.car_start_car_icon, 500, 0, lv_obj_get_y(guider_ui.car_start_car_icon), 20, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.car_start_info_text, 500, 0, lv_obj_get_y(guider_ui.car_start_info_text), 130, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.listening, guider_ui.listening_del, &guider_ui.car_start_del, setup_scr_listening, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.car_lock, guider_ui.car_lock_del, &guider_ui.car_start_del, setup_scr_car_lock, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void car_start_start_imgbtn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        if (start_car == 0) {
            lv_label_set_text(guider_ui.car_start_start_imgbtn_label, "STOP");
            start_car = 1;
        } else {
            lv_label_set_text(guider_ui.car_start_start_imgbtn_label, "START");
            start_car = 0;
        }
        break;
    }
    default:
        break;
    }
}

static void car_start_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.car_start_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_car_start (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->car_start, car_start_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->car_start_start_imgbtn, car_start_start_imgbtn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->car_start_img_1, car_start_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void listening_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.listening_listen_text, 500, 0, lv_obj_get_y(guider_ui.listening_listen_text), 380, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.not_recognized, guider_ui.not_recognized_del, &guider_ui.listening_del, setup_scr_not_recognized, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.car_start, guider_ui.car_start_del, &guider_ui.listening_del, setup_scr_car_start, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void listening_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.listening_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_listening (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->listening, listening_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->listening_img_1, listening_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void not_recognized_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.not_recognized_no_mic_icon, 500, 0, lv_obj_get_y(guider_ui.not_recognized_no_mic_icon), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.not_recognized_command_text, 500, 0, lv_obj_get_y(guider_ui.not_recognized_command_text), 350, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.recognized, guider_ui.recognized_del, &guider_ui.not_recognized_del, setup_scr_recognized, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.listening, guider_ui.listening_del, &guider_ui.not_recognized_del, setup_scr_listening, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void not_recognized_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.not_recognized_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_not_recognized (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->not_recognized, not_recognized_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->not_recognized_img_1, not_recognized_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void recognized_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.recognized_command_text, 500, 0, lv_obj_get_y(guider_ui.recognized_command_text), 350, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.recognized_done_mic, 500, 0, lv_obj_get_y(guider_ui.recognized_done_mic), 70, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_digital, guider_ui.home_digital_del, &guider_ui.recognized_del, setup_scr_home_digital, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.not_recognized, guider_ui.not_recognized_del, &guider_ui.recognized_del, setup_scr_not_recognized, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void recognized_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.recognized_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_recognized (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->recognized, recognized_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->recognized_img_1, recognized_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void settings_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.settings_setting_info, 500, 0, lv_obj_get_y(guider_ui.settings_setting_info), 85, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.settings_title, 500, 0, lv_obj_get_y(guider_ui.settings_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.payment, guider_ui.payment_del, &guider_ui.settings_del, setup_scr_payment, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.battery, guider_ui.battery_del, &guider_ui.settings_del, setup_scr_battery, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.blood_oxygen, guider_ui.blood_oxygen_del, &guider_ui.settings_del, setup_scr_blood_oxygen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void settings_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.settings_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_settings (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->settings, settings_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->settings_img_1, settings_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void battery_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.battery_setting_info, 500, 0, lv_obj_get_y(guider_ui.battery_setting_info), 80, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.battery_title, 500, 0, lv_obj_get_y(guider_ui.battery_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.settings, guider_ui.settings_del, &guider_ui.battery_del, setup_scr_settings, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.info, guider_ui.info_del, &guider_ui.battery_del, setup_scr_info, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void battery_img_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.battery_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_battery (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->battery, battery_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->battery_img_4, battery_img_4_event_handler, LV_EVENT_ALL, ui);
}

static void info_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.info_title, 500, 0, lv_obj_get_y(guider_ui.info_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.info_label_GUI, 500, 0, lv_obj_get_y(guider_ui.info_label_GUI), 400, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.battery, guider_ui.battery_del, &guider_ui.info_del, setup_scr_battery, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.find_device, guider_ui.find_device_del, &guider_ui.info_del, setup_scr_find_device, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void info_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.info_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_info (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->info, info_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->info_img_1, info_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void find_device_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.find_device_title, 500, 0, lv_obj_get_y(guider_ui.find_device_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.find_device_btn_start, 500, 0, lv_obj_get_y(guider_ui.find_device_btn_start), 360, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.info, guider_ui.info_del, &guider_ui.find_device_del, setup_scr_info, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void find_device_btn_start_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.play_sound, guider_ui.play_sound_del, &guider_ui.find_device_del, setup_scr_play_sound, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void find_device_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.find_device_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_find_device (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->find_device, find_device_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->find_device_btn_start, find_device_btn_start_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->find_device_img_1, find_device_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void play_sound_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.play_sound_btn_cancel, 500, 0, lv_obj_get_y(guider_ui.play_sound_btn_cancel), 350, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.play_sound_title, 500, 0, lv_obj_get_y(guider_ui.play_sound_title), 35, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.play_sound_img_find, 500, 0, lv_image_get_scale(guider_ui.play_sound_img_find), 331, &lv_anim_path_ease_in, LV_ANIM_REPEAT_INFINITE, 0, 500, 0, (lv_anim_exec_xcb_t)lv_image_set_scale, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void play_sound_btn_cancel_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.find_device, guider_ui.find_device_del, &guider_ui.play_sound_del, setup_scr_find_device, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

static void play_sound_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.play_sound_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_play_sound (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->play_sound, play_sound_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->play_sound_btn_cancel, play_sound_btn_cancel_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->play_sound_img_1, play_sound_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void blood_oxygen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.blood_oxygen_title, 500, 0, lv_obj_get_y(guider_ui.blood_oxygen_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.blood_oxygen_arc_blood, 500, 0, lv_obj_get_y(guider_ui.blood_oxygen_arc_blood), 10, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.blood_oxygen_arc_blood, LV_OBJ_FLAG_CLICKABLE);
        ui_animation(guider_ui.blood_oxygen_label_ago, 500, 0, lv_obj_get_y(guider_ui.blood_oxygen_label_ago), 350, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.settings, guider_ui.settings_del, &guider_ui.blood_oxygen_del, setup_scr_settings, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.ECG, guider_ui.ECG_del, &guider_ui.blood_oxygen_del, setup_scr_ECG, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.blood_oxygen_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void blood_oxygen_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.blood_oxygen_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_blood_oxygen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->blood_oxygen, blood_oxygen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->blood_oxygen_img_1, blood_oxygen_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void ECG_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_obj_remove_flag(guider_ui.ECG_cont_2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);
        ui_animation(guider_ui.ECG_cont_2, 2000, 100, lv_obj_get_x(guider_ui.ECG_cont_2), -150, &lv_anim_path_linear, -1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.ECG_cont_1, 500, 0, lv_obj_get_y(guider_ui.ECG_cont_1), 350, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.ECG_title, 500, 0, lv_obj_get_y(guider_ui.ECG_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.ECG_img_healthy, 500, 0, lv_image_get_scale(guider_ui.ECG_img_healthy), 372, &lv_anim_path_ease_in, LV_ANIM_REPEAT_INFINITE, 0, 500, 0, (lv_anim_exec_xcb_t)lv_image_set_scale, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.blood_oxygen, guider_ui.blood_oxygen_del, &guider_ui.ECG_del, setup_scr_blood_oxygen, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.stress_level, guider_ui.stress_level_del, &guider_ui.ECG_del, setup_scr_stress_level, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, false, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void ECG_img_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.ECG_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_ECG (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ECG, ECG_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ECG_img_6, ECG_img_6_event_handler, LV_EVENT_ALL, ui);
}

static void stress_level_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.stress_level_title, 500, 0, lv_obj_get_y(guider_ui.stress_level_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.stress_level_label_average, 500, 0, lv_obj_get_y(guider_ui.stress_level_label_average), 320, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.stress_level_label_ago, 500, 0, lv_obj_get_y(guider_ui.stress_level_label_ago), 90, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.stress_level_arc_stress, LV_OBJ_FLAG_CLICKABLE);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.ECG, guider_ui.ECG_del, &guider_ui.stress_level_del, setup_scr_ECG, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.blood_pressure, guider_ui.blood_pressure_del, &guider_ui.stress_level_del, setup_scr_blood_pressure, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void stress_level_img_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.stress_level_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_stress_level (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->stress_level, stress_level_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->stress_level_img_3, stress_level_img_3_event_handler, LV_EVENT_ALL, ui);
}

static void blood_pressure_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.blood_pressure_cont_1, 500, 0, lv_obj_get_y(guider_ui.blood_pressure_cont_1), 350, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.blood_pressure_arc_stress, 500, 0, lv_obj_get_y(guider_ui.blood_pressure_arc_stress), 10, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.blood_pressure_title, 500, 0, lv_obj_get_y(guider_ui.blood_pressure_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.stress_level, guider_ui.stress_level_del, &guider_ui.blood_pressure_del, setup_scr_stress_level, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.sleep, guider_ui.sleep_del, &guider_ui.blood_pressure_del, setup_scr_sleep, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void blood_pressure_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.blood_pressure_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_blood_pressure (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->blood_pressure, blood_pressure_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->blood_pressure_img_1, blood_pressure_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void sleep_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.sleep_cont_1, 500, 0, lv_obj_get_y(guider_ui.sleep_cont_1), 350, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.sleep_label_stages, 500, 0, lv_obj_get_y(guider_ui.sleep_label_stages), 90, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.sleep_title, 500, 0, lv_obj_get_y(guider_ui.sleep_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.blood_pressure, guider_ui.blood_pressure_del, &guider_ui.sleep_del, setup_scr_blood_pressure, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.step, guider_ui.step_del, &guider_ui.sleep_del, setup_scr_step, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void sleep_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.sleep_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_sleep (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->sleep, sleep_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->sleep_img_1, sleep_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void step_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.step_cont_1, 500, 0, lv_obj_get_y(guider_ui.step_cont_1), 300, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.step_title, 500, 0, lv_obj_get_y(guider_ui.step_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.step_icon_step, 500, 0, lv_obj_get_y(guider_ui.step_icon_step), 93, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.step_arc_step, 500, 0, lv_obj_get_y(guider_ui.step_arc_step), 11, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.step_arc_step, LV_OBJ_FLAG_CLICKABLE);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.sleep, guider_ui.sleep_del, &guider_ui.step_del, setup_scr_sleep, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.menstrual, guider_ui.menstrual_del, &guider_ui.step_del, setup_scr_menstrual, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void step_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.step_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_step (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->step, step_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->step_img_1, step_img_1_event_handler, LV_EVENT_ALL, ui);
}

static void menstrual_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.menstrual_label_cycle, 500, 0, lv_obj_get_y(guider_ui.menstrual_label_cycle), 90, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.menstrual_label_ovulation, 500, 0, lv_obj_get_y(guider_ui.menstrual_label_ovulation), 400, &lv_anim_path_overshoot, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        ui_animation(guider_ui.menstrual_title, 500, 0, lv_obj_get_y(guider_ui.menstrual_title), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_y, NULL, NULL, NULL);
        lv_obj_remove_flag(guider_ui.menstrual_img_ovulation, LV_OBJ_FLAG_CLICKABLE);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_active());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.blood_oxygen, guider_ui.blood_oxygen_del, &guider_ui.menstrual_del, setup_scr_blood_oxygen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_active());
            ui_load_scr_animation(&guider_ui, &guider_ui.step, guider_ui.step_del, &guider_ui.menstrual_del, setup_scr_step, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void menstrual_img_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home_analog, guider_ui.home_analog_del, &guider_ui.menstrual_del, setup_scr_home_analog, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_menstrual (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->menstrual, menstrual_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->menstrual_img_1, menstrual_img_1_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
