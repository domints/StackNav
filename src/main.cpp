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
  uint32_t heapBefore = ESP.getFreeHeap();
  uint32_t psramBefore = ESP.getPsramSize();
  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Free heap: %d", ESP.getFreeHeap());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
  ui_init();
  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Free heap: %d", ESP.getFreeHeap());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
  uint32_t heapAfter = ESP.getFreeHeap();
  uint32_t psramAfter = ESP.getFreePsram();
  log_d("Heap memory used: %i bytes", heapBefore - heapAfter);
  log_d("PSRAM used: %i bytes", psramBefore - psramAfter);
  // listDir(SD, "/", 3, true);
  /*uint32_t heapBefore = ESP.getFreeHeap();
  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Free heap: %d", ESP.getFreeHeap());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
  M5.Lcd.loadFont("app/font/Helvetica-24", SD);
  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Free heap: %d", ESP.getFreeHeap());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
  uint32_t heapAfter = ESP.getFreeHeap();
  M5.Lcd.print("Font memory used: ");
  M5.Lcd.println(heapBefore - heapAfter);
  M5.Lcd.println("Text size 1");
  M5.Lcd.loadFont("app/font/Helvetica-32", SD);
  heapAfter = ESP.getFreeHeap();
  M5.Lcd.print("Text size 2, ");
  M5.Lcd.println(heapBefore - heapAfter);
  M5.Lcd.loadFont("app/font/Helvetica-48", SD);
  heapAfter = ESP.getFreeHeap();
  M5.Lcd.print("Text size 3, ");
  M5.Lcd.println(heapBefore - heapAfter);*/
  // M5.Lcd.print(M5.Lcd.fontsLoaded());
}

void loop()
{
  M5.update();
  gps_update();
}