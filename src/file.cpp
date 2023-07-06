#include "file.hpp"

uint16_t file_read16(fs::File &f)
{
    uint16_t result;
    ((uint8_t *)&result)[0] = f.read(); // LSB
    ((uint8_t *)&result)[1] = f.read(); // MSB
    return result;
}

uint32_t file_read32(fs::File &f)
{
    uint32_t result;
    ((uint8_t *)&result)[0] = f.read(); // LSB
    ((uint8_t *)&result)[1] = f.read();
    ((uint8_t *)&result)[2] = f.read();
    ((uint8_t *)&result)[3] = f.read(); // MSB
    return result;
}

uint16_t file_read16_be(fs::File &f)
{
    uint16_t result;
    ((uint8_t *)&result)[1] = f.read(); // LSB
    ((uint8_t *)&result)[0] = f.read(); // MSB
    return result;
}

uint32_t file_read32_be(fs::File &f)
{
    uint32_t result;
    ((uint8_t *)&result)[3] = f.read(); // LSB
    ((uint8_t *)&result)[2] = f.read();
    ((uint8_t *)&result)[1] = f.read();
    ((uint8_t *)&result)[0] = f.read(); // MSB
    return result;
}

uint64_t file_read64_be(fs::File &f)
{
    uint64_t result;
    ((uint8_t *)&result)[7] = f.read(); // LSB
    ((uint8_t *)&result)[6] = f.read();
    ((uint8_t *)&result)[5] = f.read();
    ((uint8_t *)&result)[4] = f.read();
    ((uint8_t *)&result)[3] = f.read();
    ((uint8_t *)&result)[2] = f.read();
    ((uint8_t *)&result)[1] = f.read();
    ((uint8_t *)&result)[0] = f.read(); // MSB
    return result;
}