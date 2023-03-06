#include "arrows.hpp"
#include "storage.hpp"

uint8_t *arr_all;
uint8_t *arr_all_dis;
uint8_t *arr_through;
uint8_t *arr_through_dis;
uint8_t *arr_through_slightleft;
uint8_t *arr_through_slightleft_dis;
uint8_t *arr_through_slightright;
uint8_t *arr_through_slightright_dis;
uint8_t *arr_through_left;
uint8_t *arr_through_left_dis;
uint8_t *arr_through_right;
uint8_t *arr_through_right_dis;
uint8_t *arr_left;
uint8_t *arr_left_dis;
uint8_t *arr_left_uturnleft;
uint8_t *arr_left_uturnleft_dis;
uint8_t *arr_right;
uint8_t *arr_right_dis;
uint8_t *arr_right_uturnright;
uint8_t *arr_right_uturnright_dis;
uint8_t *arr_mergeleft;
uint8_t *arr_mergeleft_dis;
uint8_t *arr_mergeright;
uint8_t *arr_mergeright_dis;
uint8_t *arr_slightleft;
uint8_t *arr_slightleft_dis;
uint8_t *arr_slightright;
uint8_t *arr_slightright_dis;
uint8_t *arr_slightleftright;
uint8_t *arr_slightleftright_dis;
uint8_t *arr_uturnleft;
uint8_t *arr_uturnleft_dis;
uint8_t *arr_uturnright;
uint8_t *arr_uturnright_dis;

void ui_load_arrows()
{
    arr_all = storage_loadBmp("/app/gfx/arr_all.bmp");
    arr_all_dis = storage_loadBmp("/app/gfx/arr_all_dis.bmp");
    arr_left = storage_loadBmp("/app/gfx/arr_left.bmp");
    arr_left_dis = storage_loadBmp("/app/gfx/arr_left_dis.bmp");
    arr_left_uturnleft = storage_loadBmp("/app/gfx/arr_left_uturnleft.bmp");
    arr_left_uturnleft_dis = storage_loadBmp("/app/gfx/arr_left_uturnleft_dis.bmp");
    arr_mergeleft = storage_loadBmp("/app/gfx/arr_mergeleft.bmp");
    arr_mergeleft_dis = storage_loadBmp("/app/gfx/arr_mergeleft_dis.bmp");
    arr_mergeright = storage_loadBmp("/app/gfx/arr_mergeright.bmp");
    arr_mergeright_dis = storage_loadBmp("/app/gfx/arr_mergeright_dis.bmp");
    arr_right = storage_loadBmp("/app/gfx/arr_right.bmp");
    arr_right_dis = storage_loadBmp("/app/gfx/arr_right_dis.bmp");
    arr_right_uturnright = storage_loadBmp("/app/gfx/arr_right_uturnright.bmp");
    arr_right_uturnright_dis = storage_loadBmp("/app/gfx/arr_right_uturnright_dis.bmp");
    arr_slightleft = storage_loadBmp("/app/gfx/arr_slightleft.bmp");
    arr_slightleft_dis = storage_loadBmp("/app/gfx/arr_slightleft_dis.bmp");
    arr_slightleftright = storage_loadBmp("/app/gfx/arr_slightleftright.bmp");
    arr_slightleftright_dis = storage_loadBmp("/app/gfx/arr_slightleftright_dis.bmp");
    arr_slightright = storage_loadBmp("/app/gfx/arr_slightright.bmp");
    arr_slightright_dis = storage_loadBmp("/app/gfx/arr_slightright_dis.bmp");
    arr_through = storage_loadBmp("/app/gfx/arr_through.bmp");
    arr_through_dis = storage_loadBmp("/app/gfx/arr_through_dis.bmp");
    arr_through_left = storage_loadBmp("/app/gfx/arr_through_left.bmp");
    arr_through_left_dis = storage_loadBmp("/app/gfx/arr_through_left_dis.bmp");
    arr_through_right = storage_loadBmp("/app/gfx/arr_through_right.bmp");
    arr_through_right_dis = storage_loadBmp("/app/gfx/arr_through_right_dis.bmp");
    arr_through_slightleft = storage_loadBmp("/app/gfx/arr_through_slightleft.bmp");
    arr_through_slightleft_dis = storage_loadBmp("/app/gfx/arr_through_slightleft_dis.bmp");
    arr_through_slightright = storage_loadBmp("/app/gfx/arr_through_slightright.bmp");
    arr_through_slightright_dis = storage_loadBmp("/app/gfx/arr_through_slightright_dis.bmp");
    arr_uturnleft = storage_loadBmp("/app/gfx/arr_uturnleft.bmp");
    arr_uturnleft_dis = storage_loadBmp("/app/gfx/arr_uturnleft_dis.bmp");
    arr_uturnright = storage_loadBmp("/app/gfx/arr_uturnright.bmp");
    arr_uturnright_dis = storage_loadBmp("/app/gfx/arr_uturnright_dis.bmp");
}