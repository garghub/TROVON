static void d2net_v2_power_off(void)
{
gpio_set_value(D2NET_V2_GPIO_POWER_OFF, 1);
}
static void __init d2net_v2_init(void)
{
kirkwood_init();
kirkwood_mpp_conf(d2net_v2_mpp_config);
lacie_v2_hdd_power_init(1);
kirkwood_ehci_init();
kirkwood_ge00_init(&d2net_v2_ge00_data);
kirkwood_sata_init(&d2net_v2_sata_data);
kirkwood_uart0_init();
lacie_v2_register_flash();
lacie_v2_register_i2c_devices();
platform_device_register(&d2net_v2_leds);
platform_device_register(&d2net_v2_gpio_leds);
platform_device_register(&d2net_v2_gpio_buttons);
if (gpio_request(D2NET_V2_GPIO_POWER_OFF, "power-off") == 0 &&
gpio_direction_output(D2NET_V2_GPIO_POWER_OFF, 0) == 0)
pm_power_off = d2net_v2_power_off;
else
pr_err("d2net_v2: failed to configure power-off GPIO\n");
}
