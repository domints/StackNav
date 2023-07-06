#ifndef __UI_HPP__
#define __UI_HPP__

#include "ui/screen.hpp"

#define ARROWS_BG 0x4640

void ui_init();
void ui_update();
void ui_drawButtons();

// priv
UiScreen _ui_render(bool forceRender);

#endif