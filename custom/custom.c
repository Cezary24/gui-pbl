/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdlib.h>
#include "lvgl.h"
#include "custom.h"


/*********************
 *      DEFINES
 *********************/
#define CHART1_POINTS 20
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static int32_t bpn = 0;
static bool is_increase = true;

static int16_t spd_chart[CHART1_POINTS] = {0};
static bool is_up = true;
/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}


void screen_timer_cb(lv_timer_t * t){
    lv_ui * gui = t->user_data;

    count_array(gui->screen_ppg_chart);
    set_meter_bpn(gui->screen_label_bpm_value,gui->screen_meter_bpm, gui->screen_meter_bpm_scale_0_ndline_0);
    lv_chart_refresh(gui->screen_ppg_chart);
}


void set_meter_bpn(lv_obj_t * label,lv_obj_t * meter, lv_obj_t * scale){
    int bpm_value = get_bpm_value();
    lv_label_set_text_fmt(label, "%"LV_PRId32, bpm_value);
    lv_meter_set_indicator_value(meter, scale, bpm_value);
}

int get_bpm_value(){

    if(bpn >= 110) is_increase = false;
    if(bpn <= 70) is_increase = true;

   if(is_increase)
    {
        bpn ++;
    }else
    {
        bpn --;
    }

    return bpn;
}


void count_array(lv_obj_t * chart){
    lv_chart_series_t * ser = lv_chart_get_series_next(chart, NULL);
    lv_coord_t * ser_array = lv_chart_get_y_array(chart, ser);


    for(int i = 0; i < CHART1_POINTS - 1; i++)
    {
        spd_chart[i] = spd_chart[i+1];
        ser_array[i] = spd_chart[i];
    }

    if(spd_chart[CHART1_POINTS - 1] > 110) is_up = false;
    if(spd_chart[CHART1_POINTS - 1] < 70) is_up = true;

    if(is_up)
    {
        spd_chart[CHART1_POINTS - 1] += lv_rand(0, 5);
    }else
    {
        spd_chart[CHART1_POINTS - 1] -= lv_rand(0, 5);
    }
    ser_array[CHART1_POINTS - 1] = spd_chart[CHART1_POINTS - 1];
}
