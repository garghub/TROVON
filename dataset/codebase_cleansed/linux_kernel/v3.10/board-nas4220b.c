static void __init ib4220b_init(void)
{
gemini_gpio_init();
platform_register_uart();
platform_register_pflash(SZ_16M, NULL, 0);
platform_device_register(&ib4220b_led_device);
platform_device_register(&ib4220b_key_device);
platform_register_rtc();
}
