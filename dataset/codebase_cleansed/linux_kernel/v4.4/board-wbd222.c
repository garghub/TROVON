static void __init wbd222_init(void)
{
gemini_gpio_init();
platform_register_uart();
platform_register_pflash(SZ_8M, wbd222_partitions,
wbd222_num_partitions);
platform_device_register(&wbd222_leds_device);
platform_device_register(&wbd222_keys_device);
platform_register_rtc();
}
