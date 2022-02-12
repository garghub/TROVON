static void __init net2big_sata_power_init(void)
{
int err;
orion_gpio_set_valid(NET2BIG_GPIO_SATA0_POWER, 1);
orion_gpio_set_valid(NET2BIG_GPIO_SATA1_POWER, 1);
err = gpio_request(NET2BIG_GPIO_SATA0_POWER, "SATA0 power status");
if (err == 0) {
err = gpio_direction_input(NET2BIG_GPIO_SATA0_POWER);
if (err)
gpio_free(NET2BIG_GPIO_SATA0_POWER);
}
if (err) {
pr_err("net2big: failed to setup SATA0 power GPIO\n");
return;
}
err = gpio_request(NET2BIG_GPIO_SATA1_POWER, "SATA1 power status");
if (err == 0) {
err = gpio_direction_input(NET2BIG_GPIO_SATA1_POWER);
if (err)
gpio_free(NET2BIG_GPIO_SATA1_POWER);
}
if (err) {
pr_err("net2big: failed to setup SATA1 power GPIO\n");
goto err_free_1;
}
err = gpio_request(NET2BIG_GPIO_SATA_POWER_REQ, "SATA power request");
if (err == 0) {
err = gpio_direction_output(NET2BIG_GPIO_SATA_POWER_REQ, 0);
if (err)
gpio_free(NET2BIG_GPIO_SATA_POWER_REQ);
}
if (err) {
pr_err("net2big: failed to setup SATA power request GPIO\n");
goto err_free_2;
}
if (gpio_get_value(NET2BIG_GPIO_SATA0_POWER) &&
gpio_get_value(NET2BIG_GPIO_SATA1_POWER)) {
return;
}
msleep(300);
gpio_set_value(NET2BIG_GPIO_SATA_POWER_REQ, 1);
pr_info("net2big: power up SATA hard disks\n");
return;
err_free_2:
gpio_free(NET2BIG_GPIO_SATA1_POWER);
err_free_1:
gpio_free(NET2BIG_GPIO_SATA0_POWER);
return;
}
static void __init net2big_gpio_leds_init(void)
{
int err;
err = gpio_request(NET2BIG_GPIO_PWR_LED_BLINK_STOP,
"Power LED blink stop");
if (err == 0) {
err = gpio_direction_output(NET2BIG_GPIO_PWR_LED_BLINK_STOP, 1);
if (err)
gpio_free(NET2BIG_GPIO_PWR_LED_BLINK_STOP);
}
if (err)
pr_err("net2big: failed to setup power LED blink GPIO\n");
err = gpio_request(NET2BIG_GPIO_SATA0_BLUE_LED,
"SATA0 blue LED control");
if (err == 0) {
err = gpio_direction_output(NET2BIG_GPIO_SATA0_BLUE_LED, 1);
if (err)
gpio_free(NET2BIG_GPIO_SATA0_BLUE_LED);
}
if (err)
pr_err("net2big: failed to setup SATA0 blue LED GPIO\n");
err = gpio_request(NET2BIG_GPIO_SATA1_BLUE_LED,
"SATA1 blue LED control");
if (err == 0) {
err = gpio_direction_output(NET2BIG_GPIO_SATA1_BLUE_LED, 1);
if (err)
gpio_free(NET2BIG_GPIO_SATA1_BLUE_LED);
}
if (err)
pr_err("net2big: failed to setup SATA1 blue LED GPIO\n");
platform_device_register(&net2big_gpio_leds);
}
static void net2big_power_off(void)
{
gpio_set_value(NET2BIG_GPIO_POWER_OFF, 1);
}
static void __init net2big_init(void)
{
orion5x_init();
orion5x_mpp_conf(net2big_mpp_modes);
orion5x_ehci0_init();
orion5x_ehci1_init();
orion5x_eth_init(&net2big_eth_data);
orion5x_i2c_init();
orion5x_uart0_init();
orion5x_xor_init();
net2big_sata_power_init();
orion5x_sata_init(&net2big_sata_data);
orion5x_setup_dev_boot_win(NET2BIG_NOR_BOOT_BASE,
NET2BIG_NOR_BOOT_SIZE);
platform_device_register(&net2big_nor_flash);
platform_device_register(&net2big_gpio_buttons);
net2big_gpio_leds_init();
i2c_register_board_info(0, net2big_i2c_devices,
ARRAY_SIZE(net2big_i2c_devices));
orion_gpio_set_valid(NET2BIG_GPIO_POWER_OFF, 1);
if (gpio_request(NET2BIG_GPIO_POWER_OFF, "power-off") == 0 &&
gpio_direction_output(NET2BIG_GPIO_POWER_OFF, 0) == 0)
pm_power_off = net2big_power_off;
else
pr_err("net2big: failed to configure power-off GPIO\n");
pr_notice("net2big: Flash writing is not yet supported.\n");
}
