static void __init d2net_gpio_leds_init(void)
{
int err;
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
void __init d2net_init(void)
{
d2net_gpio_leds_init();
pr_notice("d2net: Flash write are not yet supported.\n");
}
