#include "messagepack.hpp"
#include "file.hpp"

/// @brief method reading string from MessagePack file
/// @param file pointer to file or sth
/// @param buffer buffer to which store data (must fit maxLength)
/// @param maxLength number of bytes you're expecting, including leading NULL
/// @return number of bytes read
uint32_t msgpack_readString(fs::File &file, uint8_t* buffer, uint32_t maxLength)
{
    int type = file.read();
    log_d("Got entry of type %i", type);
    uint32_t length = 0;
    if ((type & 0b11100000) == 0b10100000)
        length = type & 0b00011111;
    else if (type == 0xd9)
        length = file.read();
    else if (type == 0xda)
        length = file_read16_be(file);
    else if (type == 0xdb)
        length = file_read32_be(file);
    log_d("Got string of length %i", length);
    if (length > maxLength - 1 || length == 0)
    {
        log_e("fuuuu, it's too long or 0. Wanted max %i, got %i", maxLength, length);
        buffer[0] = NULL;
        for (uint32_t i = 0; i < length; i++)
            file.read();
        return 0;
    }

    for (uint32_t i = 0; i < length; i++)
    {
        buffer[i] = file.read();
    }

    buffer[length] = NULL;

    return length;
}

uint8_t msgpack_readUint8(fs::File &file)
{
    int type = file.read();
    if (type < 0x80)
        return type & 0x7F;
    if (type == 0xcc)
        return file.read() & 0xFF;
    return 0x00;
}

uint16_t msgPack_readUint16(fs::File &file)
{
    int type = file.read();
    if (type == 0xcd)
        return file_read16_be(file);
    if (type == 0xcc)
        return file.read() & 0xFF;
    if (type < 0x80)
        return type & 0x7F;

    return 0x00;
}

uint32_t msgPack_readUint32(fs::File &file)
{
    int type = file.read();
    if (type == 0xce)
        return file_read32_be(file);
    if (type == 0xcd)
        return file_read16_be(file);
    if (type == 0xcc)
        return file.read() & 0xFF;
    if (type < 0x80)
        return type & 0x7F;

    return 0x0;
}

uint64_t msgPack_readUint64(fs::File &file)
{
    int type = file.read();
    if (type == 0xcf)
        return file_read64_be(file);
    if (type == 0xce)
        return file_read32_be(file);
    if (type == 0xcd)
        return file_read16_be(file);
    if (type == 0xcc)
        return file.read() & 0xFF;
    if (type < 0x80)
        return type & 0x7F;

    return 0x0;
}

int8_t msgPack_readInt(fs::File &file)
{
    int type = file.read();
    if (type < 0x80)
        return type & 0x7F;
    if (type & 0b11100000 == 0b1110000)
        return type & 0x1F;
    if (type == 0xcc)
        return file.read() & 0xFF;
    return 0x00;
}

int16_t msgPack_readInt16(fs::File &file)
{
    int type = file.read();
    if (type == 0xcd || type == 0xd1)
        return file_read16_be(file);
    if (type == 0xcc || type == 0xd0)
        return file.read() & 0xFF;
    if (type < 0x80)
        return type & 0x7F;
    if (type & 0b11100000 == 0b1110000)
        return type & 0x1F;

    return 0x00;
}

int32_t msgPack_readInt32(fs::File &file)
{
    int type = file.read();
    if (type == 0xce || type == 0xd2)
        return file_read32_be(file);
    if (type == 0xcd || type == 0xd1)
        return file_read16_be(file);
    if (type == 0xcc || type == 0xd0)
        return file.read() & 0xFF;
    if (type < 0x80)
        return type & 0x7F;
    if (type & 0b11100000 == 0b1110000)
        return type & 0x1F;

    return 0x0;
}

int64_t msgPack_readInt64(fs::File &file)
{
    int type = file.read();
    if (type == 0xcf || type == 0xd3)
        return (int64_t)file_read64_be(file);
    if (type == 0xce || type == 0xd2)
        return (int64_t)(int32_t)file_read32_be(file);
    if (type == 0xcd || type == 0xd1)
        return (int64_t)(int16_t)file_read16_be(file);
    if (type == 0xcc || type == 0xd0)
        return (int64_t)(int8_t)(file.read() & 0xFF);
    if (type < 0x80)
        return (int64_t)(int8_t)(type & 0x7F);
    if (type & 0b11100000 == 0b1110000)
        return (int64_t)(int8_t)(type & 0x1F);

    return 0x0;
}