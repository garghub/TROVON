static void dnskw_power_off(void)
{
gpio_set_value(36, 1);
}
static void __init dnskw_gpio_register(unsigned gpio, char *name, int def)
{
if (gpio_request(gpio, name) == 0 &&
gpio_direction_output(gpio, 0) == 0) {
gpio_set_value(gpio, def);
if (gpio_export(gpio, 0) != 0)
pr_err("dnskw: Failed to export GPIO %s\n", name);
} else
pr_err("dnskw: Failed to register %s\n", name);
}
void __init dnskw_init(void)
{
kirkwood_mpp_conf(dnskw_mpp_config);
kirkwood_ehci_init();
kirkwood_ge00_init(&dnskw_ge00_data);
kirkwood_sata_init(&dnskw_sata_data);
kirkwood_i2c_init();
platform_device_register(&dnskw_button_device);
platform_device_register(&dnskw_fan_device);
if (of_machine_is_compatible("dlink,dns-325")) {
i2c_register_board_info(0, dns325_i2c_board_info,
ARRAY_SIZE(dns325_i2c_board_info));
platform_device_register(&dns325_led_device);
} else if (of_machine_is_compatible("dlink,dns-320"))
platform_device_register(&dns320_led_device);
if (gpio_request(36, "dnskw:power:off") == 0
&& gpio_direction_output(36, 0) == 0)
pm_power_off = dnskw_power_off;
else
pr_err("dnskw: failed to configure power-off GPIO\n");
dnskw_gpio_register(39, "dnskw:power:sata0", 1);
dnskw_gpio_register(40, "dnskw:power:sata1", 1);
dnskw_gpio_register(37, "dnskw:power:recover", 1);
}
