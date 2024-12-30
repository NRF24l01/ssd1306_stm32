#include "../Inc/ssd1306.h"
#include "../Inc/fonts.h"
#include <string.h>
#include <stdlib.h>

// Internal framebuffer
static uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

static void SSD1306_WriteCommand(I2C_HandleTypeDef *hi2c, uint8_t command) {
    uint8_t buffer[2] = {0x00, command};
    HAL_I2C_Master_Transmit(hi2c, SSD1306_I2C_ADDR, buffer, 2, HAL_MAX_DELAY);
}

void SSD1306_Init(I2C_HandleTypeDef *hi2c) {
    HAL_Delay(100); // Startup delay

    // Initialization sequence
    SSD1306_WriteCommand(hi2c, 0xAE); // Display OFF
    SSD1306_WriteCommand(hi2c, 0x20); // Set Memory Addressing Mode
    SSD1306_WriteCommand(hi2c, 0x00); // Horizontal addressing mode
    SSD1306_WriteCommand(hi2c, 0xB0); // Set Page Start Address for Page Addressing Mode
    SSD1306_WriteCommand(hi2c, 0xC8); // Set COM Output Scan Direction
    SSD1306_WriteCommand(hi2c, 0x00); // Set low column address
    SSD1306_WriteCommand(hi2c, 0x10); // Set high column address
    SSD1306_WriteCommand(hi2c, 0x40); // Set start line address
    SSD1306_WriteCommand(hi2c, 0x81); // Set contrast control
    SSD1306_WriteCommand(hi2c, 0xFF); // Max contrast
    SSD1306_WriteCommand(hi2c, 0xA1); // Set segment re-map
    SSD1306_WriteCommand(hi2c, 0xA6); // Set normal display
    SSD1306_WriteCommand(hi2c, 0xA8); // Set multiplex ratio
    SSD1306_WriteCommand(hi2c, 0x3F); // 1/64 duty
    SSD1306_WriteCommand(hi2c, 0xA4); // Disable entire display ON
    SSD1306_WriteCommand(hi2c, 0xD3); // Set display offset
    SSD1306_WriteCommand(hi2c, 0x00); // No offset
    SSD1306_WriteCommand(hi2c, 0xD5); // Set display clock divide ratio/oscillator frequency
    SSD1306_WriteCommand(hi2c, 0xF0); // Max frequency
    SSD1306_WriteCommand(hi2c, 0xD9); // Set pre-charge period
    SSD1306_WriteCommand(hi2c, 0x22);
    SSD1306_WriteCommand(hi2c, 0xDA); // Set COM pins hardware configuration
    SSD1306_WriteCommand(hi2c, 0x12);
    SSD1306_WriteCommand(hi2c, 0xDB); // Set VCOMH deselect level
    SSD1306_WriteCommand(hi2c, 0x20);
    SSD1306_WriteCommand(hi2c, 0x8D); // Enable charge pump regulator
    SSD1306_WriteCommand(hi2c, 0x14);
    SSD1306_WriteCommand(hi2c, 0xAF); // Display ON

    // Clear screen
    SSD1306_Fill(0);
    SSD1306_UpdateScreen(hi2c);
}

void SSD1306_Fill(uint8_t color) {
    memset(SSD1306_Buffer, (color ? 0xFF : 0x00), sizeof(SSD1306_Buffer));
}

void SSD1306_Clear(void) {
    SSD1306_Fill(0);
}

void SSD1306_UpdateScreen(I2C_HandleTypeDef *hi2c) {
    for (uint8_t page = 0; page < 8; page++) {
        SSD1306_WriteCommand(hi2c, 0xB0 + page); // Set page address
        SSD1306_WriteCommand(hi2c, 0x00);        // Set low column address
        SSD1306_WriteCommand(hi2c, 0x10);        // Set high column address

        HAL_I2C_Mem_Write(hi2c, SSD1306_I2C_ADDR, 0x40, 1, &SSD1306_Buffer[SSD1306_WIDTH * page], SSD1306_WIDTH, HAL_MAX_DELAY);
    }
}

void SSD1306_DrawPixel(uint8_t x, uint8_t y, uint8_t color) {
    if (x >= SSD1306_WIDTH || y >= SSD1306_HEIGHT) return;

    if (color) {
        SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] |= (1 << (y % 8));
    } else {
        SSD1306_Buffer[x + (y / 8) * SSD1306_WIDTH] &= ~(1 << (y % 8));
    }
}

void SSD1306_DrawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;

    while (1) {
        SSD1306_DrawPixel(x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

// Draw a single character on the SSD1306 display
void SSD1306_DrawChar(uint8_t x, uint8_t y, char c, uint8_t color) {
    if (c < 32 || c > 127) return; // Skip unsupported characters
    uint8_t fontIndex = c - 32;

    for (uint8_t i = 0; i < FONT_WIDTH; i++) {
        uint8_t column = font[fontIndex][i];
        for (uint8_t j = 0; j < 8; j++) {
            if (column & (1 << j)) {
                SSD1306_DrawPixel(x + i, y + j, color);
            } else {
                SSD1306_DrawPixel(x + i, y + j, !color); // Optional: Draw background
            }
        }
    }
}


// Print a string on the SSD1306 display
void SSD1306_DrawString(uint8_t x, uint8_t y, const char *str, uint8_t color) {
    uint8_t cursorX = x;
    while (*str) {
        if (cursorX + FONT_WIDTH + 1 > SSD1306_WIDTH) break; // Stop if out of bounds
        SSD1306_DrawChar(cursorX, y, *str, color);
        cursorX += FONT_WIDTH + 1; // Move to the next character with a space
        str++;
    }
}