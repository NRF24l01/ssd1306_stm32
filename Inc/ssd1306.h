#ifndef SSD1306_H
#define SSD1306_H

#include "../../STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

// I2C address of the SSD1306 display
#define SSD1306_I2C_ADDR        0x78

// Screen dimensions
#define SSD1306_WIDTH           128
#define SSD1306_HEIGHT          64

// Public function prototypes
void SSD1306_Init(I2C_HandleTypeDef *hi2c);
void SSD1306_Fill(uint8_t color);
void SSD1306_Clear(void);
void SSD1306_UpdateScreen(I2C_HandleTypeDef *hi2c);
void SSD1306_DrawPixel(uint8_t x, uint8_t y, uint8_t color);
void SSD1306_DrawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t color);

// Function to print a string on the screen
void SSD1306_DrawString(uint8_t x, uint8_t y, const char *str, uint8_t color);

#endif // SSD1306_H
