static void __init marzen_init(void)
{
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
r8a7779_pinmux_init();
gpio_request(GPIO_FN_TX2_C, NULL);
gpio_request(GPIO_FN_RX2_C, NULL);
gpio_request(GPIO_FN_TX4, NULL);
gpio_request(GPIO_FN_RX4, NULL);
gpio_request(GPIO_FN_EX_CS0, NULL);
gpio_request(GPIO_FN_IRQ1_B, NULL);
r8a7779_add_standard_devices();
platform_add_devices(marzen_devices, ARRAY_SIZE(marzen_devices));
}
