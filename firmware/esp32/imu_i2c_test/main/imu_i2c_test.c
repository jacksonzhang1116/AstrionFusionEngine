#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"
#include "esp_err.h"

#define IMU_I2C_PORT I2C_NUM_0

#define IMU_I2C_SDA GPIO_NUM_19
#define IMU_I2C_SCL GPIO_NUM_20

#define IMU_I2C_FREQ_HZ 100000
#define IMU_I2C_ADDR 0x50

#define BUF_SIZE 32

// JY901B 常用寄存器地址
#define REG_ACC_X_L 0x34

void app_main(void)
{
    printf("I2C IMU test start\r\n");
    printf("I2C SDA = GPIO19, SCL = GPIO20, addr = 0x%02X\r\n",
       IMU_I2C_ADDR);

    i2c_config_t i2c_config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = IMU_I2C_SDA,
        .scl_io_num = IMU_I2C_SCL,
        .sda_pullup_en = GPIO_PULLUP_DISABLE,
        .scl_pullup_en = GPIO_PULLUP_DISABLE,
        .master.clk_speed = IMU_I2C_FREQ_HZ,
    };

    ESP_ERROR_CHECK(i2c_param_config(IMU_I2C_PORT, &i2c_config));
    ESP_ERROR_CHECK(i2c_driver_install(IMU_I2C_PORT, I2C_MODE_MASTER, 0, 0, 0));

    uint8_t data[BUF_SIZE];

    while (1) {
        esp_err_t ret = i2c_master_write_read_device(
            IMU_I2C_PORT,
            IMU_I2C_ADDR,
            (uint8_t[]){REG_ACC_X_L},
            1,
            data,
            BUF_SIZE,
            pdMS_TO_TICKS(500)
        );

        if (ret == ESP_OK) {
            printf("len = %d\r\n", BUF_SIZE);
            printf("Data: ");

            for (int i = 0; i < BUF_SIZE; i++) {
                printf("%02X ", data[i]);
            }

            printf("\r\n");
        } else {
            printf("I2C read failed: %s\r\n", esp_err_to_name(ret));
        }

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}