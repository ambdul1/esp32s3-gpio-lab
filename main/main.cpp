#include "hal/gpio_types.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <soc/gpio_num.h>
#include <esp_log.h>

namespace
{
    constexpr char TAG[] = "GPIO_PIN_LAB";
}

extern "C" void app_main()
{
    gpio_config_t led_config{};

    led_config.pin_bit_mask = 1ULL << GPIO_NUM_7;
    led_config.mode = GPIO_MODE_OUTPUT;
    led_config.pull_up_en = GPIO_PULLUP_DISABLE;
    led_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
}
