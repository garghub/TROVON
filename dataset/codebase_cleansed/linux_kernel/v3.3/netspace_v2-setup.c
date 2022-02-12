static void netspace_v2_power_off(void)
{
gpio_set_value(NETSPACE_V2_GPIO_POWER_OFF, 1);
}
static void __init netspace_v2_init(void)
{
kirkwood_init();
kirkwood_mpp_conf(netspace_v2_mpp_config);
if (machine_is_netspace_max_v2())
lacie_v2_hdd_power_init(2);
else
lacie_v2_hdd_power_init(1);
kirkwood_ehci_init();
kirkwood_ge00_init(&netspace_v2_ge00_data);
kirkwood_sata_init(&netspace_v2_sata_data);
kirkwood_uart0_init();
lacie_v2_register_flash();
lacie_v2_register_i2c_devices();
platform_device_register(&netspace_v2_leds);
platform_device_register(&netspace_v2_gpio_leds);
platform_device_register(&netspace_v2_gpio_buttons);
if (machine_is_netspace_max_v2())
platform_device_register(&netspace_max_v2_gpio_fan);
if (gpio_request(NETSPACE_V2_GPIO_POWER_OFF, "power-off") == 0 &&
gpio_direction_output(NETSPACE_V2_GPIO_POWER_OFF, 0) == 0)
pm_power_off = netspace_v2_power_off;
else
pr_err("netspace_v2: failed to configure power-off GPIO\n");
}
