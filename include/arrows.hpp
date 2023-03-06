#ifndef __ARROWS_HPP__
#define __ARROWS_HPP__

#include <Arduino.h>

extern uint8_t *arr_all;
extern uint8_t *arr_all_dis;
extern uint8_t *arr_through;
extern uint8_t *arr_through_dis;
extern uint8_t *arr_through_slightleft;
extern uint8_t *arr_through_slightleft_dis;
extern uint8_t *arr_through_slightright;
extern uint8_t *arr_through_slightright_dis;
extern uint8_t *arr_through_left;
extern uint8_t *arr_through_left_dis;
extern uint8_t *arr_through_right;
extern uint8_t *arr_through_right_dis;
extern uint8_t *arr_left;
extern uint8_t *arr_left_dis;
extern uint8_t *arr_left_uturnleft;
extern uint8_t *arr_left_uturnleft_dis;
extern uint8_t *arr_right;
extern uint8_t *arr_right_dis;
extern uint8_t *arr_right_uturnright;
extern uint8_t *arr_right_uturnright_dis;
extern uint8_t *arr_mergeleft;
extern uint8_t *arr_mergeleft_dis;
extern uint8_t *arr_mergeright;
extern uint8_t *arr_mergeright_dis;
extern uint8_t *arr_slightleft;
extern uint8_t *arr_slightleft_dis;
extern uint8_t *arr_slightright;
extern uint8_t *arr_slightright_dis;
extern uint8_t *arr_slightleftright;
extern uint8_t *arr_slightleftright_dis;
extern uint8_t *arr_uturnleft;
extern uint8_t *arr_uturnleft_dis;
extern uint8_t *arr_uturnright;
extern uint8_t *arr_uturnright_dis;

void ui_load_arrows();

#endif