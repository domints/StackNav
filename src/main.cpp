#include <Arduino.h>
#include <M5Core2.h>
#include "main.hpp"
#include "ui.hpp"
#include "gps.hpp"
#include "storage.hpp"

void setup()
{
  M5.begin();
  storage_verify();

  gps_init();
  ui_init();
}

void loop()
{
  M5.update();
  gps_update();
  ui_update();
}