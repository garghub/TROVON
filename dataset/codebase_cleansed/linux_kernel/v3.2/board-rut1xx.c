static void __init rut1xx_init(void)
{
gemini_gpio_init();
platform_register_uart();
platform_register_pflash(SZ_8M, NULL, 0);
platform_device_register(&rut1xx_leds);
platform_device_register(&rut1xx_keys_device);
platform_register_rtc();
}
