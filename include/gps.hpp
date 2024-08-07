#ifndef __GPS_HPP__
#define __GPS_HPP__ ;

#include <TinyGPSPlus.h>

void gps_init();
void gps_update();
TinyGPSLocation gps_getLocation();
TinyGPSInteger gps_getSatellites();
TinyGPSAltitude gps_getAltitude();
TinyGPSCourse gps_getCourse();
TinyGPSDate gps_getDate();
TinyGPSTime gps_getTime();

#endif