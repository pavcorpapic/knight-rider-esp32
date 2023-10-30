#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

#define BLINK_DELAY_MS 200

static const char *TAG = "KnightRider";

void app_main() {
    // Configure the GPIO pins for the LEDs
    for (int i = 2; i <= 5; i++) {
        gpio_pad_select_gpio(i);
        gpio_set_direction(i, GPIO_MODE_OUTPUT);
    }

    int i = 2;
    int direction = 1;

    while (1) {
        // Turn on the current LED
        gpio_set_level(i, 1);

        vTaskDelay(BLINK_DELAY_MS / portTICK_PERIOD_MS);

        // Turn off the current LED
        gpio_set_level(i, 0);

        // Move to the next LED
        i += direction;

        // Change direction at the end or beginning of the LED row
        if (i == 2 || i == 5) {
            direction *= -1;
        }
    }
}
