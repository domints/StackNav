#include "Arduino.h"
#include <M5Core2.h>
#include "ui.hpp"
#include "storage.hpp"
#include "arrows.hpp"
#include "data.hpp"

#include "ui/screen.hpp"
#include "ui/lineselect.hpp"

uint8_t *bottom_btn;
UiScreen currentScreen;

void ui_init()
{
    bottom_btn = storage_loadBmp("/app/gfx/bottom_btn.bmp");
    ui_load_arrows();
    ui_lineselect_init();
    currentScreen = UiScreen::Undefined;
}

void ui_update()
{
    UiScreen newScreen = _ui_render(false);
    while (newScreen != currentScreen)
    {
        currentScreen = newScreen;
        newScreen = _ui_render(true);
    }
}

void ui_drawButtons()
{
    M5.Lcd.drawBitmap(0, 240 - 32, 106, 32, bottom_btn);
    M5.Lcd.drawBitmap(107, 240 - 32, 106, 32, bottom_btn);
    M5.Lcd.drawBitmap(214, 240 - 32, 106, 32, bottom_btn);
}

UiScreen _ui_render(bool forceRender)
{
    switch (currentScreen)
    {
    case UiScreen::LineSelect:
        return ui_lineselect_render(forceRender);

    default:
        return UiScreen::LineSelect;
    }
}

void drawBitmap(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t* data)
{
    if (data == NULL)
        M5.Lcd.fillRect(x, y, w, h, TFT_MAGENTA);
    else
        M5.Lcd.drawBitmap(x, y, w, h, data);
}
