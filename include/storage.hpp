#ifndef __STORAGE_HPP__
#define __STORAGE_HPP__

#include <M5Core2.h>

void storage_verify();
void storage_list(fs::FS &fs, const char *dirname, uint8_t levels, bool skipHidden);
uint8_t *storage_loadBmp(const char *path);

#endif