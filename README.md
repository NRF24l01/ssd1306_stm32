# Library for connect i2c screen with ssd1306 to stm32f103c8t6
*Tested only for oled screen with ssd1306, 128x64 sizes, with blue pill(stm32f103c8t6)*
## Usage example
```cpp
extern I2C_HandleTypeDef hi2c1;

int main(void)
{
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
  MX_I2C1_Init();

  SSD1306_Init(&hi2c1);

  SSD1306_Clear();
  SSD1306_UpdateScreen(&hi2c1);

  SSD1306_Clear();
  SSD1306_DrawString(5, 5, "abcd&*?", 1);
  SSD1306_UpdateScreen(&hi2c1);
}
```