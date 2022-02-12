static void __init csb637_init_early(void)
{
at91_initialize(3686400);
}
static void __init csb637_board_init(void)
{
at91_gpio_leds(csb_leds, ARRAY_SIZE(csb_leds));
at91_register_uart(0, 0, 0);
at91_add_device_serial();
at91_add_device_eth(&csb637_eth_data);
at91_add_device_usbh(&csb637_usbh_data);
at91_add_device_udc(&csb637_udc_data);
at91_add_device_i2c(NULL, 0);
at91_add_device_spi(NULL, 0);
platform_device_register(&csb_flash);
}
