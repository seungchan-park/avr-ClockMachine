#include "LCD.h"

uint8_t lcdControlData; // E RW RS x x x x x

void Gpio_init()
{
	LCD_CONTROL_DDR |= ((1<<LCD_RS)|(1<<LCD_RW)|(1<<LCD_E));
	LCD_DATA_DDR = 0xff;
}
void LCD_init()
{
	Gpio_init();
	_delay_ms(15);
	LCD_writeCmdData(LCD_FUNCTION_SET); // LCD_FUNCTION_SET D7~D0  00111000 -> 0x38
	_delay_ms(5);
	LCD_writeCmdData(LCD_FUNCTION_SET); // LCD_FUNCTION_SET
	_delay_ms(1);
	LCD_writeCmdData(LCD_FUNCTION_SET); // LCD_FUNCTION_SET
	LCD_writeCmdData(LCD_FUNCTION_SET); // LCD_FUNCTION_SET
	LCD_writeCmdData(LCD_DISPLAY_OFF); // LCD_DISPLAY_OFF
	LCD_writeCmdData(LCD_DISPLAY_CLEAR); // LCD_DISPLAY_CLEAR
	LCD_writeCmdData(LCD_ENTRY_MODE_SET); // LCD_ENTRY_MODE_SET
	LCD_writeCmdData(LCD_DISPLAY_ON); // LCD_DISPLAY_ON
}

void Gpio_writeControlData(uint8_t data)
{
	LCD_CONTROL_PORT = data;
}
void LCD_cmdMode()
{
	lcdControlData &= ~(1<<LCD_RS);
	Gpio_writeControlData(lcdControlData);
}
void LCD_charMode()
{
	lcdControlData |= (1<<LCD_RS);
	Gpio_writeControlData(lcdControlData);
}
void LCD_writeMode()
{
	lcdControlData &= ~(1<<LCD_RW);
	Gpio_writeControlData(lcdControlData);
}
void LCD_enableHigh()
{
	lcdControlData |= (1<<LCD_E);
	Gpio_writeControlData(lcdControlData);
	_delay_ms(1); // 정상적으로 enable이 H에서 L로 되는것을 기다려준다.
}
void LCD_enableLow()
{
	lcdControlData &= ~(1<<LCD_E);
	Gpio_writeControlData(lcdControlData);
	_delay_ms(1); // 정상적으로 enable이 H에서 L로 되는것을 기다려준다.
}
void LCD_writeByte(uint8_t data)
{
	Gpio_writeData(data);
}
void Gpio_writeData(uint8_t data)
{
	LCD_DATA_PORT = data;
}

void LCD_writeCmdData(uint8_t data) // LCD instruction 쓰기
{   // datasheet의 timing diagram을 setting
	LCD_cmdMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data); // 1byte data를 레지스터에 저장
	LCD_enableLow(); // data를 LCD에 출력
}
void LCD_writeCharData(uint8_t data) // LCD character 쓰기
{
	LCD_charMode();
	LCD_writeMode();
	LCD_enableHigh();
	LCD_writeByte(data);
	LCD_enableLow();
}

void LCD_writeString(char *str) // 문자열은 주소다
{
	for (int i = 0; str[i]; i++) // 조건식 str[i]가 NULL이 나오면 거짓
	{
		LCD_writeCharData(str[i]);
	}
}

void LCD_gotoXY(uint8_t row, uint8_t col)
{
	col %= 16;
	row %= 2;
	
	uint8_t lcdregisterAddress = (0x40 * row) + col;
	uint8_t command = 0x80 + lcdregisterAddress;
	LCD_writeCmdData(command);
}

void LCD_displayClear()
{
	LCD_writeCmdData(LCD_DISPLAY_CLEAR);
}
void LCD_writeStringXY(uint8_t row, uint8_t col, char *str)
{
	LCD_gotoXY(row, col);
	LCD_writeString(str);
}