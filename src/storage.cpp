#include <M5Core2.h>
#include "storage.hpp"
#include "messagepack.hpp"
#include "file.hpp"

void storage_verify()
{
    if (!SD.begin())
    {
        M5.Lcd.setTextSize(4);
        M5.Lcd.println(F("Please insert\nSD Card\nand reboot!"));
        while (1)
            ;
    }
}

void storage_list(fs::FS &fs, const char *dirname, uint8_t levels, bool skipHidden)
{

    // Print blank line on screen
    M5.Lcd.printf(" \n  ");
    M5.Lcd.printf(" \n  ");

    log_d("Listing directory: %s\n", dirname);
    M5.Lcd.printf("Listing directory: %s\n", dirname);

    File root = fs.open(dirname);
    if (!root)
    {
        log_e("Failed to open directory");
        M5.Lcd.println("Failed to open directory");
        return;
    }
    if (!root.isDirectory())
    {
        log_e("Not a directory");
        M5.Lcd.println("Not a directory");
        return;
    }

    File file = root.openNextFile();
    while (file)
    {
        if (skipHidden && file.name()[0] == '.')
        {
            file = root.openNextFile();
            continue;
        }

        if (file.isDirectory())
        {
            Serial.print("  DIR : ");
            M5.Lcd.print("  DIR : ");
            Serial.println(file.name());
            M5.Lcd.println(file.name());
            if (levels)
            {
                char result[255];
                strcpy(result, dirname);
                if (dirname[strlen(dirname) - 1] != '/')
                    strcat(result, "/");
                strcat(result, file.name());
                storage_list(fs, result, levels - 1, skipHidden);
            }
        }
        else
        {
            Serial.print("  FILE: ");
            M5.Lcd.print("  FILE: ");
            Serial.print(file.name());
            M5.Lcd.print(file.name());
            Serial.print("  SIZE: ");
            M5.Lcd.print("  SIZE: ");
            Serial.println(file.size());
            M5.Lcd.println(file.size());
        }
        file = root.openNextFile();
    }
}

uint8_t *storage_loadBmp(const char *path)
{
    File bmpFS = SD.open(path, "r");
    if (!bmpFS)
    {
        log_e("File not found: %s", path);
        return (uint8_t *)NULL;
    }

    uint32_t seekOffset;
    uint16_t w, row, col;
    int32_t h;
    uint16_t planes, depth, format;
    uint8_t r, g, b;

    uint32_t startTime = millis();

    uint8_t *image_data;

    if (file_read16(bmpFS) == 0x4D42)
    {
        file_read32(bmpFS); // file size
        file_read32(bmpFS); // creator bytes (ignore)
        seekOffset = file_read32(bmpFS);
        file_read32(bmpFS);     // header size
        w = file_read32(bmpFS); // width
        h = (int32_t)file_read32(bmpFS); // height
        uint32_t habs = abs(h);

        planes = file_read16(bmpFS);
        depth = file_read16(bmpFS);
        format = file_read16(bmpFS);

        image_data = (uint8_t *)ps_malloc(sizeof(uint16_t) * w * habs);

        if (image_data == NULL)
        {
            log_e("Failed to allocate memory for file %s", path);
            return (uint8_t *)NULL;
        }

        if ((planes == 1) && (depth == 16 || depth == 24 || depth == 32) && (format == 0 || format == 3))
        {
            bmpFS.seek(seekOffset);

            uint16_t padding = 0;
            if (depth == 24)
                padding = (4 - ((w * 3) & 3)) & 3;
            uint8_t lineBuffer[w * (depth / 8) + padding];

            uint16_t *pixels = (uint16_t *)image_data;
            
            for (row = 0; row < habs; row++)
            {
                bmpFS.read(lineBuffer, sizeof(lineBuffer));
                uint8_t *bptr = lineBuffer;
                
                for (col = 0; col < w; col++)
                {
                    uint16_t color;
                    if (depth == 32)
                    {
                        // Convert 32 to 16 bit colours
                        b = *bptr++;
                        g = *bptr++;
                        r = *bptr++;
                        *bptr++; //alpha
                        color = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
                    }
                    else if (depth == 24)
                    {
                        // Convert 24 to 16 bit colours
                        b = *bptr++;
                        g = *bptr++;
                        r = *bptr++;
                        color = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
                    }
                    else if (depth == 16)
                    {
                        color = (*bptr++ << 8) | (*bptr++);
                    }
                    uint16_t rowIx = row;
                    if (h > 0)
                        rowIx = (h - row - 1);
                    pixels[(rowIx * w) + col] = color;
                }
            }
            log_d("Loaded in %i ms", millis() - startTime);
        }
        else
            log_e("BMP format not recognized.");
    }
    bmpFS.close();

    return image_data;
}

std::tuple<int16_t, LineDesc*> storage_loadLines()
{
    File root = SD.open("/lines");
    if (!root)
    {
        log_e("Lines folder does not exist!");
        return {-1, NULL};
    }
    if (!root.isDirectory())
    {
        log_e("Lines folder is not a folder!");
        return {-1, NULL};
    }

    File file = root.openNextFile();
    if (!file)
    {
        return {0, NULL};
    }

    uint8_t lineCount = 0;

    do
    {
        int init = file.read();
        if(init != 0x96)
            continue;
        lineCount++;
    } while (file = root.openNextFile());

    M5.Lcd.clear();
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(80, 90);
    M5.Lcd.print("Laduje linie");
    M5.Lcd.progressBar(5, 120, 310, 20, 0);

    LineDesc *lines = (LineDesc*)ps_malloc(sizeof(LineDesc) * lineCount);

    root.rewindDirectory();
    file = root.openNextFile();
    uint8_t ix = 0;
    do
    {
        int init = file.read();
        if(init != 0x96)
            continue;
        msgpack_readString(file, lines[ix].name, 5);
        msgpack_readString(file, lines[ix].from, 26);
        msgpack_readString(file, lines[ix].to, 26);
        lines[ix].stopCount = msgPack_readUint16(file);
        strcpy((char *)lines[ix].fileName, file.name());
        ix++;

        M5.Lcd.fillRect(5, 120, 310, 20, 0);
        M5.Lcd.progressBar(5, 120, 310, 20, (ix + 1) * 100 / lineCount);
    } while (file = root.openNextFile());
    log_d("%i", lines[0].stopCount);
    return {lineCount, lines};
}