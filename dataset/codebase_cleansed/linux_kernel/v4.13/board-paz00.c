void __init tegra_paz00_wifikill_init(void)
{
platform_device_add_properties(&wifi_rfkill_device, wifi_rfkill_prop);
gpiod_add_lookup_table(&wifi_gpio_lookup);
platform_device_register(&wifi_rfkill_device);
}
