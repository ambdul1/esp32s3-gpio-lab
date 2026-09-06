#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <esp_log.h>

namespace
{
    constexpr char TAG[] = "GPIO_PIN_LAB";
}

extern "C" void app_main()
{
    ESP_LOGI(TAG, "Hello GPIO TAG");
}
