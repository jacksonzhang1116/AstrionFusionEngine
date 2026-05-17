#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp_err.h"

#define IMU_UART_PORT UART_NUM_2
#define IMU_BAUD_RATE 9600

#define IMU_TX_PIN GPIO_NUM_19
#define IMU_RX_PIN GPIO_NUM_20

#define BUF_SIZE 1024

void app_main(void)
{
    printf("UART IMU test start\r\n");
    printf("UART2 RX = GPIO20, TX = GPIO19, baud = %d\r\n", IMU_BAUD_RATE);

    uart_config_t uart_config = {
        .baud_rate = IMU_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };

    ESP_ERROR_CHECK(uart_driver_install(IMU_UART_PORT, BUF_SIZE * 2, 0, 0, NULL, 0));
    ESP_ERROR_CHECK(uart_param_config(IMU_UART_PORT, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(
        IMU_UART_PORT,
        IMU_TX_PIN,
        IMU_RX_PIN,
        UART_PIN_NO_CHANGE,
        UART_PIN_NO_CHANGE
    ));

    uint8_t data[BUF_SIZE];

    while (1) {
        int len = uart_read_bytes(
            IMU_UART_PORT,
            data,
            BUF_SIZE,
            pdMS_TO_TICKS(500)
        );

        printf("len = %d\r\n", len);

        if (len > 0) {
            printf("Data: ");
            for (int i = 0; i < len; i++) {
                printf("%02X ", data[i]);
            }
            printf("\r\n");
        }

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}