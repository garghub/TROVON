static void __init cam60_init_early(void)
{
at91_initialize(10000000);
}
static void __init cam60_add_device_nand(void)
{
sam9_smc_configure(0, 3, &cam60_nand_smc_config);
at91_add_device_nand(&cam60_nand_data);
}
static void __init cam60_board_init(void)
{
at91_register_devices();
at91_register_uart(0, 0, 0);
at91_add_device_serial();
at91_add_device_spi(cam60_spi_devices, ARRAY_SIZE(cam60_spi_devices));
at91_add_device_eth(&cam60_macb_data);
at91_set_gpio_output(AT91_PIN_PB18, 1);
at91_add_device_usbh(&cam60_usbh_data);
cam60_add_device_nand();
}
