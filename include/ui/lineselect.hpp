#ifndef __UI_LINESELECT_HPP__
#define __UI_LINESELECT_HPP__ ;

#include "ui/screen.hpp"
#include "data.hpp"

#define UI_LINESELECT_LINE_HEIGHT 52

void ui_lineselect_init();
UiScreen ui_lineselect_render(bool forceRender);

// priv
void _ui_draw_line(uint8_t index, LineDesc line);
void _ui_redraw_lines();

#endif