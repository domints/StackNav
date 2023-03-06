#include "Arduino.h"
#include <M5Core2.h>
#include "ui.hpp"
#include "storage.hpp"
#include "arrows.hpp"

uint8_t *bottom_btn;

void ui_init()
{
    bottom_btn = storage_loadBmp("/app/gfx/bottom_btn.bmp");
    ui_load_arrows();
    M5.Lcd.drawBitmap(0, 240 - 32, 106, 32, bottom_btn);
    M5.Lcd.drawBitmap(107, 240 - 32, 106, 32, bottom_btn);
    M5.Lcd.drawBitmap(214, 240 - 32, 106, 32, bottom_btn);
    M5.Lcd.fillRect(0, 0, 320, 40, ARROWS_BG);
    M5.Lcd.drawBitmap(0, 4, 32, 32, arr_left_uturnleft_dis);
    M5.Lcd.drawBitmap(32, 4, 32, 32, arr_left_dis);
    M5.Lcd.drawBitmap(64, 4, 32, 32, arr_through_slightleft);
    M5.Lcd.drawBitmap(96, 4, 32, 32, arr_through);
    M5.Lcd.drawBitmap(128, 4, 32, 32, arr_through_right);
    M5.Lcd.drawBitmap(160, 4, 32, 32, arr_mergeright_dis);
}
