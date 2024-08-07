#include <M5Core2.h>
#include "gps.hpp"
#include "ui/gpsdetails.hpp"
#include "ui.hpp"

void drawLocation();
void drawSatellites();
void drawDateTime();

UiScreen ui_gpsdetails_render(bool forceRender)
{
    if (forceRender)
    {
        M5.Lcd.clear();
        drawLocation();
        drawSatellites();

        return UiScreen::GPSDetails;
    }
    if (gps_getLocation().isUpdated())
    {
        drawLocation();
    }
    if (gps_getDate().isUpdated() || gps_getTime().isUpdated()) {
        drawDateTime();
    }
    if (gps_getSatellites().isUpdated())
    {
        log_d("satUpdated");
        drawSatellites();
    }

    return UiScreen::GPSDetails;
}

void drawLocation()
{
    M5.Lcd.fillRect(0, 0, 159, 68, TFT_BLACK);
    M5.Lcd.drawRect(0, 0, 159, 68, TFT_LIGHTGREY);
    M5.Lcd.setCursor(3, 3);
    M5.Lcd.println(gps_getLocation().isValid() ? "Loc valid" : "Loc INvalid");
    M5.Lcd.cursor_x = 3;
    M5.Lcd.println(gps_getLocation().age());
    M5.Lcd.cursor_x = 3;
    M5.Lcd.printf("%02.7f\n", gps_getLocation().lat());
    M5.Lcd.cursor_x = 3;
    M5.Lcd.printf("%02.7f\n", gps_getLocation().lng());
}

void drawSatellites() {
    M5.Lcd.fillRect(0, 70, 159, 36, TFT_BLACK);
    M5.Lcd.drawRect(0, 70, 159, 36, TFT_LIGHTGREY);
    M5.Lcd.setCursor(3, 73);
    M5.Lcd.println(gps_getLocation().isValid() ? "Sat valid" : "Sat INvalid");
    M5.Lcd.cursor_x = 3;
    M5.Lcd.println(gps_getSatellites().value());
}

void drawDateTime() {
    M5.Lcd.fillRect(162, 0, 159, 68, TFT_BLACK);
    M5.Lcd.drawRect(161, 0, 159, 68, TFT_LIGHTGREY);
    M5.Lcd.setCursor(163, 3);
    M5.Lcd.println(gps_getDate().isValid() ? "Date valid" : "Date INvalid");
    M5.Lcd.cursor_x = 163;
    M5.Lcd.printf("%02d-%02d-%04d\n", gps_getDate().day(), gps_getDate().month(), gps_getDate().year());
    M5.Lcd.cursor_x = 163;
    M5.Lcd.println(gps_getTime().isValid() ? "Time valid" : "Time INvalid");
    M5.Lcd.cursor_x = 163;
    M5.Lcd.printf("%02d:%02d:%02d", gps_getTime().hour(), gps_getTime().minute(), gps_getTime().second());
}