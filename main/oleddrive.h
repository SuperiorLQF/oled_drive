#ifndef __OLEDDRIVE_H
#define __OLEDDRIVE_H
#define SIZE        16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64

#define OLED_CMD    0
#define OLED_DATA   1

#define SCLK        19
#define SDIN        23
#define RST         18
#define DC          21

#define OLED_DC_Set()   gpio_set_level(DC,1)
#define OLED_DC_Clr()   gpio_set_level(DC,0)
#define OLED_SCLK_Set() gpio_set_level(SCLK,1)
#define OLED_SCLK_Clr() gpio_set_level(SCLK,0)
#define OLED_SDIN_Set() gpio_set_level(SDIN,1)
#define OLED_SDIN_Clr() gpio_set_level(SDIN,0)
#define OLED_RST_Set()  gpio_set_level(RST,1)
#define OLED_RST_Clr()  gpio_set_level(RST,0)
#define GPIO_OUTPUT_PIN_SEL ((1ULL<<SCLK)|(1ULL<<SDIN)|(1ULL<<RST)|(1ULL<<DC))
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define delay_ms(x)     vTaskDelay(x / portTICK_PERIOD_MS);    
void OLED_Init(void);
void OLED_WR_Byte(int dat,int cmd);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowChar(int x,int y,char chr); 
void OLED_Clear(void);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,const unsigned char BMP[]);
#endif