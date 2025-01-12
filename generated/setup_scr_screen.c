/*
* Copyright 2025 NXP
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



void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x0d2c73), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->screen, lv_color_hex(0x0063ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_box
    ui->screen_cont_box = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_box, 2, 1);
    lv_obj_set_size(ui->screen_cont_box, 478, 319);
    lv_obj_set_scrollbar_mode(ui->screen_cont_box, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cont_box, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_box, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_box, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_box, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_box, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_bpn
    ui->screen_label_bpn = lv_label_create(ui->screen_cont_box);
    lv_label_set_text(ui->screen_label_bpn, "bpm");
    lv_label_set_long_mode(ui->screen_label_bpn, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_bpn, 201, 247);
    lv_obj_set_size(ui->screen_label_bpn, 100, 32);

    //Write style for screen_label_bpn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_bpn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_bpn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_bpn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_bpn, &lv_font_montserratMedium_34, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_bpn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_bpn, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_bpn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_bpn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_bpn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_bpn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_bpn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_bpn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_bpn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_bpn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ppg_chart
    ui->screen_ppg_chart = lv_chart_create(ui->screen_cont_box);
    lv_chart_set_type(ui->screen_ppg_chart, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->screen_ppg_chart, 3, 5);
    lv_chart_set_point_count(ui->screen_ppg_chart, 19);
    lv_chart_set_range(ui->screen_ppg_chart, LV_CHART_AXIS_PRIMARY_Y, 0, 120);
    lv_chart_set_range(ui->screen_ppg_chart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    lv_chart_set_zoom_x(ui->screen_ppg_chart, 256);
    lv_chart_set_zoom_y(ui->screen_ppg_chart, 256);
    ui->screen_ppg_chart_0 = lv_chart_add_series(ui->screen_ppg_chart, lv_color_hex(0x28bd76), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
    lv_chart_set_next_value(ui->screen_ppg_chart, ui->screen_ppg_chart_0, 0);
#endif
    lv_obj_set_pos(ui->screen_ppg_chart, 11, 10);
    lv_obj_set_size(ui->screen_ppg_chart, 446, 148);
    lv_obj_set_scrollbar_mode(ui->screen_ppg_chart, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_ppg_chart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_ppg_chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ppg_chart, lv_color_hex(0x0a66a2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ppg_chart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_ppg_chart, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ppg_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ppg_chart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ppg_chart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ppg_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_ppg_chart, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_ppg_chart, lv_color_hex(0x1b5aa9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_ppg_chart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ppg_chart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_ppg_chart, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_ppg_chart, lv_color_hex(0x151212), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ppg_chart, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ppg_chart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->screen_ppg_chart, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->screen_ppg_chart, lv_color_hex(0xe8e8e8), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->screen_ppg_chart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write codes screen_label_bpm_value
    ui->screen_label_bpm_value = lv_label_create(ui->screen_cont_box);
    lv_label_set_text(ui->screen_label_bpm_value, "0\n");
    lv_label_set_long_mode(ui->screen_label_bpm_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_bpm_value, 184, 194);
    lv_obj_set_size(ui->screen_label_bpm_value, 109, 60);

    //Write style for screen_label_bpm_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_bpm_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_bpm_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_bpm_value, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_bpm_value, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_bpm_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_bpm_value, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_bpm_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_bpm_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_bpm_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_bpm_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_bpm_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_bpm_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_bpm_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_bpm_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_nxp_image
    ui->screen_nxp_image = lv_img_create(ui->screen_cont_box);
    lv_obj_add_flag(ui->screen_nxp_image, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_nxp_image, &_NXP_logo_alpha_130x75);
    lv_img_set_pivot(ui->screen_nxp_image, 50,50);
    lv_img_set_angle(ui->screen_nxp_image, 0);
    lv_obj_set_pos(ui->screen_nxp_image, 327, 209);
    lv_obj_set_size(ui->screen_nxp_image, 130, 75);

    //Write style for screen_nxp_image, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_nxp_image, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_nxp_image, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_nxp_image, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_nxp_image, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meter_bpm
    ui->screen_meter_bpm = lv_meter_create(ui->screen_cont_box);
    // add scale ui->screen_meter_bpm_scale_0
    ui->screen_meter_bpm_scale_0 = lv_meter_add_scale(ui->screen_meter_bpm);
    lv_meter_set_scale_ticks(ui->screen_meter_bpm, ui->screen_meter_bpm_scale_0, 41, 2, 10, lv_color_hex(0x02cb2f));
    lv_meter_set_scale_major_ticks(ui->screen_meter_bpm, ui->screen_meter_bpm_scale_0, 8, 5, 15, lv_color_hex(0xffffff), 10);
    lv_meter_set_scale_range(ui->screen_meter_bpm, ui->screen_meter_bpm_scale_0, 0, 100, 300, 90);

    // add needle line for ui->screen_meter_bpm_scale_0.
    ui->screen_meter_bpm_scale_0_ndline_0 = lv_meter_add_needle_line(ui->screen_meter_bpm, ui->screen_meter_bpm_scale_0, 5, lv_color_hex(0x258640), -10);
    lv_meter_set_indicator_value(ui->screen_meter_bpm, ui->screen_meter_bpm_scale_0_ndline_0, 0);
    lv_obj_set_pos(ui->screen_meter_bpm, 15, 165);
    lv_obj_set_size(ui->screen_meter_bpm, 143, 143);

    //Write style for screen_meter_bpm, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meter_bpm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meter_bpm, lv_color_hex(0x1926aa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meter_bpm, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_meter_bpm, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_meter_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_meter_bpm, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_meter_bpm, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_meter_bpm, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_meter_bpm, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meter_bpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_meter_bpm, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_meter_bpm, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_meter_bpm, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_meter_bpm, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for screen_meter_bpm, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meter_bpm, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meter_bpm, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meter_bpm, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

    //Init events for screen.
    events_init_screen(ui);
}
