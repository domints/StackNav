#include "Arduino.h"
#include <TinyGPSPlus.h>
#include "gps.hpp"

TinyGPSPlus gps;

static const uint32_t GPSBaud = 9600;
static const int MAX_SATELLITES = 40;
static const int PAGE_LENGTH = 40;

TinyGPSCustom totalGPGSVMessages(gps, "GPGSV", 1); // $GPGSV sentence, first element
TinyGPSCustom messageNumber(gps, "GPGSV", 2);      // $GPGSV sentence, second element
TinyGPSCustom satNumber[4];                        // to be initialized later
TinyGPSCustom elevation[4];
bool anyChanges = false;
unsigned long linecount = 0;

struct
{
    int elevation;
    bool active;
} sats[MAX_SATELLITES];

void gps_init()
{
    Serial2.begin(GPSBaud);
    //  Initialize all the uninitialized TinyGPSCustom objects
    for (int i = 0; i < 4; ++i)
    {
        satNumber[i].begin(gps, "GPGSV", 4 + 4 * i); // offsets 4, 8, 12, 16
        elevation[i].begin(gps, "GPGSV", 5 + 4 * i); // offsets 5, 9, 13, 17
    }
}

void gps_update()
{
    bool newData = false;
    while (Serial2.available() > 0)
    {
        uint8_t c = Serial2.read();
        Serial.write(c);
        if (gps.encode(c))
        {
            newData = true;
            anyChanges = true;
        }
    }
}

TinyGPSLocation gps_getLocation()
{
    return gps.location;
}

TinyGPSInteger gps_getSatellites()
{
    return gps.satellites;
}

TinyGPSAltitude gps_getAltitude()
{
    return gps.altitude;
}

TinyGPSCourse gps_getCourse()
{
    return gps.course;
}

TinyGPSDate gps_getDate()
{
    return gps.date;
}

TinyGPSTime gps_getTime()
{
    return gps.time;
}
