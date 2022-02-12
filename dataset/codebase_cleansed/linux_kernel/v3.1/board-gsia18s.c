static void __init gsia18s_init_early(void)
{
stamp9g20_init_early();
at91_register_uart(AT91SAM9260_ID_US0, 1,
ATMEL_UART_CTS | ATMEL_UART_RTS |
ATMEL_UART_DTR | ATMEL_UART_DSR |
ATMEL_UART_DCD | ATMEL_UART_RI);
at91_register_uart(AT91SAM9260_ID_US1, 2,
ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US2, 3,
ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US3, 4, ATMEL_UART_RTS);
at91_register_uart(AT91SAM9260_ID_US4, 5, 0);
}
static void __init gsia18s_leds_init(void)
{
platform_device_register(&leds);
}
static void __init gsia18s_pcf_leds_init(void)
{
platform_device_register(&pcf_leds1);
platform_device_register(&pcf_leds2);
platform_device_register(&pcf_leds3);
}
static void __init gsia18s_add_device_buttons(void)
{
at91_set_gpio_input(GPIO_TRIG_NET_IN, 1);
at91_set_deglitch(GPIO_TRIG_NET_IN, 1);
at91_set_gpio_input(GPIO_CARD_UNMOUNT_0, 1);
at91_set_deglitch(GPIO_CARD_UNMOUNT_0, 1);
at91_set_gpio_input(GPIO_CARD_UNMOUNT_1, 1);
at91_set_deglitch(GPIO_CARD_UNMOUNT_1, 1);
at91_set_gpio_input(GPIO_KEY_POWER, 0);
at91_set_deglitch(GPIO_KEY_POWER, 1);
platform_device_register(&button_device);
}
static int pcf8574x_0x20_setup(struct i2c_client *client, int gpio,
unsigned int ngpio, void *context)
{
int status;
status = gpio_request(gpio + PCF_GPIO_ETH_DETECT, "eth_det");
if (status < 0) {
pr_err("error: can't request GPIO%d\n",
gpio + PCF_GPIO_ETH_DETECT);
return status;
}
status = gpio_direction_input(gpio + PCF_GPIO_ETH_DETECT);
if (status < 0) {
pr_err("error: can't setup GPIO%d as input\n",
gpio + PCF_GPIO_ETH_DETECT);
return status;
}
status = gpio_export(gpio + PCF_GPIO_ETH_DETECT, false);
if (status < 0) {
pr_err("error: can't export GPIO%d\n",
gpio + PCF_GPIO_ETH_DETECT);
return status;
}
status = gpio_sysfs_set_active_low(gpio + PCF_GPIO_ETH_DETECT, 1);
if (status < 0) {
pr_err("error: gpio_sysfs_set active_low(GPIO%d, 1)\n",
gpio + PCF_GPIO_ETH_DETECT);
return status;
}
return 0;
}
static int pcf8574x_0x20_teardown(struct i2c_client *client, int gpio,
unsigned ngpio, void *context)
{
gpio_free(gpio + PCF_GPIO_ETH_DETECT);
return 0;
}
static void gsia18s_power_off(void)
{
pr_notice("Power supply will be switched off automatically now or after 60 seconds without ArmDAS.\n");
at91_set_gpio_output(AT91_PIN_PA25, 1);
while (1)
;
}
static int __init gsia18s_power_off_init(void)
{
pm_power_off = gsia18s_power_off;
return 0;
}
static void __init gsia18s_board_init(void)
{
stamp9g20_board_init();
at91_add_device_usbh(&usbh_data);
at91_add_device_udc(&udc_data);
at91_add_device_eth(&macb_data);
gsia18s_leds_init();
gsia18s_pcf_leds_init();
gsia18s_add_device_buttons();
at91_add_device_i2c(gsia18s_i2c_devices,
ARRAY_SIZE(gsia18s_i2c_devices));
at91_add_device_cf(&gsia18s_cf1_data);
at91_add_device_spi(gsia18s_spi_devices,
ARRAY_SIZE(gsia18s_spi_devices));
gsia18s_power_off_init();
}
