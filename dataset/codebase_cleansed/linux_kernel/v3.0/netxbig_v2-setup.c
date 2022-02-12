static void netxbig_v2_power_off(void)
{
gpio_set_value(NETXBIG_V2_GPIO_POWER_OFF, 1);
}
static void __init netxbig_v2_init(void)
{
kirkwood_init();
if (machine_is_net2big_v2())
kirkwood_mpp_conf(net2big_v2_mpp_config);
else
kirkwood_mpp_conf(net5big_v2_mpp_config);
if (machine_is_net2big_v2())
lacie_v2_hdd_power_init(2);
else
lacie_v2_hdd_power_init(5);
kirkwood_ehci_init();
kirkwood_ge00_init(&netxbig_v2_ge00_data);
if (machine_is_net5big_v2())
kirkwood_ge01_init(&netxbig_v2_ge01_data);
kirkwood_sata_init(&netxbig_v2_sata_data);
kirkwood_uart0_init();
lacie_v2_register_flash();
lacie_v2_register_i2c_devices();
if (machine_is_net5big_v2())
netxbig_v2_leds.dev.platform_data = &net5big_v2_leds_data;
platform_device_register(&netxbig_v2_leds);
platform_device_register(&netxbig_v2_gpio_buttons);
if (gpio_request(NETXBIG_V2_GPIO_POWER_OFF, "power-off") == 0 &&
gpio_direction_output(NETXBIG_V2_GPIO_POWER_OFF, 0) == 0)
pm_power_off = netxbig_v2_power_off;
else
pr_err("netxbig_v2: failed to configure power-off GPIO\n");
}
