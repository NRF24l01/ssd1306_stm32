#ifndef FONTS_H
#define FONTS_H

#include <stdint.h>

// Font width and height (for 5x8 font)
#define FONT_WIDTH  5
#define FONT_HEIGHT 8

// Font data (ASCII 32 to 127, 96 characters)
extern const uint8_t font[96][FONT_WIDTH];

#endif // FONTS_H
