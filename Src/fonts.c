#include "fonts.h"

// 5x8 font (each character is 5 bytes wide and 8 pixels high)
const uint8_t font[96][FONT_WIDTH] = {
    // 32 ' ' (space)
    {0x00, 0x00, 0x00, 0x00, 0x00},
    // 33 '!'
    {0x00, 0x00, 0x5F, 0x00, 0x00},
    // 34 '"'
    {0x00, 0x07, 0x00, 0x07, 0x00},
    // 35 '#'
    {0x14, 0x7F, 0x14, 0x7F, 0x14},
    // 36 '$'
    {0x24, 0x2A, 0x7F, 0x2A, 0x12},
    // 37 '%'
    {0x23, 0x13, 0x08, 0x64, 0x62},
    // 38 '&'
    {0x36, 0x49, 0x55, 0x22, 0x50},
    // 39 '''
    {0x00, 0x05, 0x03, 0x00, 0x00},
    // 40 '('
    {0x00, 0x1C, 0x22, 0x41, 0x00},
    // 41 ')'
    {0x00, 0x41, 0x22, 0x1C, 0x00},
    // 42 '*'
    {0x14, 0x08, 0x3E, 0x08, 0x14},
    // 43 '+'
    {0x08, 0x08, 0x3E, 0x08, 0x08},
    // 44 ','
    {0x00, 0x50, 0x30, 0x00, 0x00},
    // 45 '-'
    {0x08, 0x08, 0x08, 0x08, 0x08},
    // 46 '.'
    {0x00, 0x60, 0x60, 0x00, 0x00},
    // 47 '/'
    {0x20, 0x10, 0x08, 0x04, 0x02},
    // 48 '0'
    {0x3E, 0x51, 0x49, 0x45, 0x3E},
    // 49 '1'
    {0x00, 0x42, 0x7F, 0x40, 0x00},
    // 50 '2'
    {0x42, 0x61, 0x51, 0x49, 0x46},
    // 51 '3'
    {0x21, 0x41, 0x49, 0x4D, 0x33},
    // 52 '4'
    {0x18, 0x14, 0x12, 0x7F, 0x10},
    // 53 '5'
    {0x27, 0x45, 0x45, 0x45, 0x39},
    // 54 '6'
    {0x3C, 0x4A, 0x49, 0x49, 0x30},
    // 55 '7'
    {0x01, 0x01, 0x7F, 0x01, 0x01},
    // 56 '8'
    {0x36, 0x49, 0x49, 0x49, 0x36},
    // 57 '9'
    {0x26, 0x49, 0x49, 0x49, 0x3E},
    // 58 ':'
    {0x00, 0x36, 0x36, 0x00, 0x00},
    // 59 ';'
    {0x00, 0x56, 0x36, 0x00, 0x00},
    // 60 '<'
    {0x10, 0x28, 0x44, 0x28, 0x10},
    // 61 '='
    {0x28, 0x28, 0x28, 0x28, 0x28},
    // 62 '>'
    {0x10, 0x28, 0x44, 0x28, 0x10},
    // 63 '?'
    {0x20, 0x10, 0x08, 0x04, 0x02},
    // 64 '@'
    {0x3E, 0x41, 0x5D, 0x59, 0x4E},
    // 65 'A'
    {0x7F, 0x09, 0x09, 0x09, 0x7F},
    // 66 'B'
    {0x7F, 0x49, 0x49, 0x49, 0x36},
    // 67 'C'
    {0x3E, 0x41, 0x41, 0x41, 0x22},
    // 68 'D'
    {0x7F, 0x41, 0x41, 0x41, 0x3E},
    // 69 'E'
    {0x7F, 0x49, 0x49, 0x49, 0x41},
    // 70 'F'
    {0x7F, 0x09, 0x09, 0x09, 0x01},
    // 71 'G'
    {0x3E, 0x41, 0x41, 0x49, 0x2E},
    // 72 'H'
    {0x7F, 0x08, 0x08, 0x08, 0x7F},
    // 73 'I'
    {0x00, 0x41, 0x7F, 0x41, 0x00},
    // 74 'J'
    {0x20, 0x40, 0x40, 0x40, 0x3F},
    // 75 'K'
    {0x7F, 0x08, 0x14, 0x22, 0x41},
    // 76 'L'
    {0x7F, 0x40, 0x40, 0x40, 0x40},
    // 77 'M'
    {0x7F, 0x02, 0x04, 0x02, 0x7F},
    // 78 'N'
    {0x7F, 0x02, 0x04, 0x08, 0x7F},
    // 79 'O'
    {0x3E, 0x41, 0x41, 0x41, 0x3E},
    // 80 'P'
    {0x7F, 0x09, 0x09, 0x09, 0x06},
    // 81 'Q'
    {0x3E, 0x41, 0x41, 0x51, 0x3E},
    // 82 'R'
    {0x7F, 0x09, 0x19, 0x29, 0x46},
    // 83 'S'
    {0x26, 0x49, 0x49, 0x49, 0x32},
    // 84 'T'
    {0x01, 0x01, 0x7F, 0x01, 0x01},
    // 85 'U'
    {0x3F, 0x40, 0x40, 0x40, 0x3F},
    // 86 'V'
    {0x1F, 0x20, 0x40, 0x20, 0x1F},
    // 87 'W'
    {0x3F, 0x40, 0x38, 0x40, 0x3F},
    // 88 'X'
    {0x63, 0x14, 0x08, 0x14, 0x63},
    // 89 'Y'
    {0x07, 0x08, 0x70, 0x08, 0x07},
    // 90 'Z'
    {0x61, 0x51, 0x49, 0x45, 0x43},
    // 91 '['
    {0x00, 0x7F, 0x41, 0x41, 0x00},
    // 92 '\'
    {0x02, 0x04, 0x08, 0x10, 0x20},
    // 93 ']'
    {0x00, 0x41, 0x41, 0x7F, 0x00},
    // 94 '^'
    {0x04, 0x02, 0x02, 0x04, 0x00},
    // 95 '_'
    {0x40, 0x40, 0x40, 0x40, 0x40},
    // 96 '`'
    {0x00, 0x01, 0x02, 0x00, 0x00},
    // 97 'a'
    {0x20, 0x54, 0x54, 0x54, 0x78},
    // 98 'b'
    {0x7F, 0x54, 0x54, 0x54, 0x20},
    // 99 'c'
    {0x78, 0x44, 0x44, 0x44, 0x44},
    // 100 'd'
    {0x20, 0x54, 0x54, 0x54, 0x7F},
    // 101 'e'
    {0x78, 0x54, 0x54, 0x54, 0x50},
    // 102 'f'
    {0x00, 0x7E, 0x09, 0x09, 0x00},
    // 103 'g'
    {0x4C, 0x54, 0x54, 0x54, 0x3C},
    // 104 'h'
    {0x7F, 0x08, 0x08, 0x08, 0x70},
    // 105 'i'
    {0x00, 0x50, 0x7F, 0x40, 0x00},
    // 106 'j'
    {0x20, 0x40, 0x40, 0x20, 0x7F},
    // 107 'k'
    {0x7F, 0x08, 0x14, 0x22, 0x41},
    // 108 'l'
    {0x00, 0x41, 0x7F, 0x40, 0x00},
    // 109 'm'
    {0x7C, 0x04, 0x18, 0x04, 0x78},
    // 110 'n'
    {0x7C, 0x08, 0x08, 0x08, 0x70},
    // 111 'o'
    {0x78, 0x44, 0x44, 0x44, 0x78},
    // 112 'p'
    {0x7C, 0x14, 0x14, 0x14, 0x08},
    // 113 'q'
    {0x08, 0x14, 0x14, 0x14, 0x7C},
    // 114 'r'
    {0x7C, 0x08, 0x08, 0x08, 0x10},
    // 115 's'
    {0x50, 0x54, 0x54, 0x54, 0x20},
    // 116 't'
    {0x08, 0x08, 0x7F, 0x08, 0x08},
    // 117 'u'
    {0x3C, 0x40, 0x40, 0x40, 0x3C},
    // 118 'v'
    {0x1C, 0x20, 0x40, 0x20, 0x1C},
    // 119 'w'
    {0x3C, 0x40, 0x30, 0x40, 0x3C},
    // 120 'x'
    {0x63, 0x14, 0x08, 0x14, 0x63},
    // 121 'y'
    {0x4C, 0x54, 0x54, 0x54, 0x3C},
    // 122 'z'
    {0x44, 0x64, 0x54, 0x4C, 0x44},
    // 123 '{'
    {0x00, 0x1C, 0x22, 0x41, 0x00},
    // 124 '|'
    {0x00, 0x00, 0x7F, 0x00, 0x00},
    // 125 '}'
    {0x00, 0x41, 0x22, 0x1C, 0x00},
    // 126 '~'
    {0x08, 0x14, 0x08, 0x14, 0x08}
};
