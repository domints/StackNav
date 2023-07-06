#ifndef __MESSAGEPACK_HPP__
#define __MESSAGEPACK_HPP__

#include <Arduino.h>
#include <M5Core2.h>

uint32_t msgpack_readString(fs::File &file, uint8_t* buffer, uint32_t maxLength);
uint8_t msgpack_readUint8(fs::File &file);
uint16_t msgPack_readUint16(fs::File &file);
uint32_t msgPack_readUint32(fs::File &file);
uint64_t msgPack_readUint64(fs::File &file);
int8_t msgPack_readInt(fs::File &file);
int16_t msgPack_readInt16(fs::File &file);
int32_t msgPack_readInt32(fs::File &file);

#endif