static void __init d2net_sata_power_init(void)
{
int err;
err = gpio_request(D2NET_GPIO_SATA0_POWER, "SATA0 power");
if (err == 0) {
err = gpio_direction_output(D2NET_GPIO_SATA0_POWER, 1);
if (err)
gpio_free(D2NET_GPIO_SATA0_POWER);
}
if (err)
pr_err("d2net: failed to configure SATA0 power GPIO\n");
err = gpio_request(D2NET_GPIO_SATA1_POWER, "SATA1 power");
if (err == 0) {
err = gpio_direction_output(D2NET_GPIO_SATA1_POWER, 1);
if (err)
gpio_free(D2NET_GPIO_SATA1_POWER);
}
if (err)
pr_err("d2net: failed to configure SATA1 power GPIO\n");
}
static void __init d2net_gpio_leds_init(void)
{
int err;
orion_gpio_set_valid(D2NET_GPIO_BLUE_LED_OFF, 1);
err = gpio_request(D2NET_GPIO_BLUE_LED_BLINK_CTRL, "blue LED blink");
if (err == 0) {
err = gpio_direction_output(D2NET_GPIO_BLUE_LED_BLINK_CTRL, 1);
if (err)
gpio_free(D2NET_GPIO_BLUE_LED_BLINK_CTRL);
}
if (err)
pr_err("d2net: failed to configure blue LED blink GPIO\n");
platform_device_register(&d2net_gpio_leds);
}
static void __init d2net_init(void)
{
orion5x_init();
orion5x_mpp_conf(d2net_mpp_modes);
orion5x_ehci0_init();
orion5x_eth_init(&d2net_eth_data);
orion5x_i2c_init();
orion5x_uart0_init();
d2net_sata_power_init();
orion5x_sata_init(&d2net_sata_data);
orion5x_setup_dev_boot_win(D2NET_NOR_BOOT_BASE,
D2NET_NOR_BOOT_SIZE);
platform_device_register(&d2net_nor_flash);
platform_device_register(&d2net_gpio_buttons);
d2net_gpio_leds_init();
pr_notice("d2net: Flash write are not yet supported.\n");
i2c_register_board_info(0, d2net_i2c_devices,
ARRAY_SIZE(d2net_i2c_devices));
orion_gpio_set_valid(D2NET_GPIO_INHIBIT_POWER_OFF, 1);
}
