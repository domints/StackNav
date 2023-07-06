#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <Arduino.h>

struct LineDesc {
    uint8_t name[5];
    uint8_t from[26];
    uint8_t to[26];
    uint16_t stopCount;
    uint8_t fileName[33];
};

#endif