static void __init lager_add_standard_devices(void)
{
r8a7790_clock_init();
pinctrl_register_mappings(lager_pinctrl_map,
ARRAY_SIZE(lager_pinctrl_map));
r8a7790_pinmux_init();
r8a7790_add_standard_devices();
platform_device_register_data(&platform_bus, "leds-gpio", -1,
&lager_leds_pdata,
sizeof(lager_leds_pdata));
platform_device_register_data(&platform_bus, "gpio-keys", -1,
&lager_keys_pdata,
sizeof(lager_keys_pdata));
}
