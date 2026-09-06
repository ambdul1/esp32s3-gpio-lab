#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <esp_err.h>
#include <esp_log.h>

namespace 
{
	constexpr char TAG[] = "GPIO_CONFIG_LAB";
	constexpr gpio_num_t LED_GPIO = GPIO_NUM_7;
}

extern "C" void app_main()
{
	// Configuration du GPIO_7
	gpio_config_t led_config{};

	led_config.pin_bit_mask = 1ULL << LED_GPIO;
	led_config.mode = GPIO_MODE_OUTPUT;
	led_config.pull_up_en = GPIO_PULLUP_DISABLE;
	led_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
	led_config.intr_type = GPIO_INTR_DISABLE;

	// Initialisation du GPIO (I/O)
	const esp_err_t result = gpio_config(&led_config);

	if (result != ESP_OK)
	{
		ESP_LOGE(
				TAG,
				"Echec de la configuration du GPIO 7 %s", 
				esp_err_to_name(result)
			);
		return;
	}

	// Placer la sortie dans un etat initial a LOW
	const esp_err_t level = gpio_set_level(LED_GPIO, 0);

	if (level != ESP_OK)
	{
		ESP_LOGE(
				TAG,
			       	"Echec de l utilisation du GPIO 7 %s",
			       	esp_err_to_name(level)
			);
		return;
	}

	// La boucle d allumage du LED
	
	for (;;)
	{
		gpio_set_level(LED_GPIO, 1);
		vTaskDelay(pdMS_TO_TICKS(1000));

		gpio_set_level(LED_GPIO, 0);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}


}
