#include <Arduino.h>
#include <M5Core2.h>
#include "ui.hpp"
#include "ui/lineselect.hpp"
#include "data.hpp"
#include "storage.hpp"

uint16_t lines_count;
LineDesc *linesList;
uint16_t top_index;

void ui_lineselect_init()
{
    std::tie(lines_count, linesList) = storage_loadLines();
    top_index = 0;
}

UiScreen ui_lineselect_render(bool forceRender)
{
    M5.update();
    if (forceRender)
    {
        _ui_redraw_lines();
    }

    if (M5.BtnA.wasPressed())
    {
        if (lines_count > 4 && top_index < lines_count - 1)
        {
            top_index++;
            _ui_redraw_lines();
        }
    }

    if (M5.BtnC.wasPressed())
    {
        if (top_index > 0)
        {
            top_index--;
            _ui_redraw_lines();
        }
    }

    return UiScreen::LineSelect;
}

void _ui_redraw_lines()
{
    M5.Lcd.clear();
    log_d("Redrawing lines");
    if (lines_count == 0)
    {
        M5.Lcd.loadFont("app/font/Helvetica-32", SD);
        M5.Lcd.println("No lines available!");
        M5.Lcd.unloadFont();
    }
    M5.Lcd.setTextWrap(false);

    uint16_t last_item = min((uint16_t)(top_index + 4), lines_count);
    for (uint8_t ix = top_index; ix < last_item; ix++)
    {
        uint8_t position = ix - top_index;
        _ui_draw_line(position, linesList[ix]);
    }
    M5.Lcd.setTextWrap(true);
    ui_drawButtons();
}

void _ui_draw_line(uint8_t index, LineDesc line)
{
    uint8_t top = index * UI_LINESELECT_LINE_HEIGHT;
    M5.Lcd.drawLine(10, top, 309, top, TFT_LIGHTGREY);
    M5.Lcd.drawLine(10, top + UI_LINESELECT_LINE_HEIGHT - 1, 309, top + UI_LINESELECT_LINE_HEIGHT - 1, TFT_DARKGREY);
    M5.Lcd.setCursor(4, top + 7);
    M5.Lcd.loadFont("app/font/Helvetica-48", SD);
    M5.Lcd.print((char *)line.name);
    M5.Lcd.unloadFont();
    M5.Lcd.loadFont("app/font/Helvetica-16", SD);
    M5.Lcd.setCursor(120, top + 9);
    M5.Lcd.print((char *)line.from);
    M5.Lcd.setCursor(120, top + 28);
    M5.Lcd.print((char *)line.to);
    M5.Lcd.unloadFont();
}