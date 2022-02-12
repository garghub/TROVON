static void __init marzen_init(void)
{
regulator_register_always_on(0, "fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
regulator_register_fixed(1, dummy_supplies,
ARRAY_SIZE(dummy_supplies));
r8a7779_pinmux_init();
gpio_request(GPIO_FN_TX2_C, NULL);
gpio_request(GPIO_FN_RX2_C, NULL);
gpio_request(GPIO_FN_TX4, NULL);
gpio_request(GPIO_FN_RX4, NULL);
gpio_request(GPIO_FN_EX_CS0, NULL);
gpio_request(GPIO_FN_IRQ1_B, NULL);
gpio_request(GPIO_FN_SD0_CLK, NULL);
gpio_request(GPIO_FN_SD0_CMD, NULL);
gpio_request(GPIO_FN_SD0_DAT0, NULL);
gpio_request(GPIO_FN_SD0_DAT1, NULL);
gpio_request(GPIO_FN_SD0_DAT2, NULL);
gpio_request(GPIO_FN_SD0_DAT3, NULL);
gpio_request(GPIO_FN_SD0_CD, NULL);
gpio_request(GPIO_FN_SD0_WP, NULL);
r8a7779_add_standard_devices();
platform_add_devices(marzen_devices, ARRAY_SIZE(marzen_devices));
}
