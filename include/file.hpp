#ifndef __FILE_HPP__
#define __FILE_HPP__

#include <Arduino.h>
#include <M5Core2.h>

uint16_t file_read16(fs::File &f);
uint32_t file_read32(fs::File &f);
uint16_t file_read16_be(fs::File &f);
uint32_t file_read32_be(fs::File &f);
uint64_t file_read64_be(fs::File &f);

#endif