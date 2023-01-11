/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "driver/gpio.h"

#include <time.h>
#include "cxk.h"
#include "oleddrive.h"
void cxk_dance();
void app_main(void)
{
    gpio_config_t io_conf={};
    io_conf.mode=GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask=GPIO_OUTPUT_PIN_SEL;
    io_conf.pull_down_en=0;
    io_conf.pull_up_en=0;
	gpio_config(&io_conf);
    OLED_Init();
	while(1){
		cxk_dance();
	}

}
void cxk_dance(){
	double ms_per_frame=60000/1781;
	for(int i=0;i<1765;i++){
		OLED_DrawBMP(0,0,127,7,gImage[i]);
		vTaskDelay(ms_per_frame / portTICK_PERIOD_MS);
	}
}
