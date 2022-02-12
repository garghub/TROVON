static void __init wbd111_init(void)
{
gemini_gpio_init();
platform_register_uart();
platform_register_pflash(SZ_8M, wbd111_partitions,
wbd111_num_partitions);
platform_device_register(&wbd111_leds_device);
platform_device_register(&wbd111_keys_device);
platform_register_rtc();
}
