static void __init kota2_init(void)
{
regulator_register_always_on(0, "fixed-1.8V", fixed1v8_power_consumers,
ARRAY_SIZE(fixed1v8_power_consumers), 1800000);
regulator_register_always_on(1, "fixed-3.3V", fixed3v3_power_consumers,
ARRAY_SIZE(fixed3v3_power_consumers), 3300000);
regulator_register_fixed(2, dummy_supplies, ARRAY_SIZE(dummy_supplies));
pinctrl_register_mappings(kota2_pinctrl_map,
ARRAY_SIZE(kota2_pinctrl_map));
sh73a0_pinmux_init();
gpio_request_one(144, GPIOF_IN, NULL);
gpio_request_one(145, GPIOF_OUT_INIT_HIGH, NULL);
gpio_request_one(208, GPIOF_OUT_INIT_HIGH, NULL);
#ifdef CONFIG_CACHE_L2X0
l2x0_init(IOMEM(0xf0100000), 0x40460000, 0x82000fff);
#endif
sh73a0_add_standard_devices();
platform_add_devices(kota2_devices, ARRAY_SIZE(kota2_devices));
}
