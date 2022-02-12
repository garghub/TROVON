static void __init ek_init_early(void)
{
at91_initialize(12000000);
at91_register_uart(0, 0, 0);
at91_set_serial_console(0);
}
static struct mtd_partition * __init nand_partitions(int size, int *num_partitions)
{
*num_partitions = ARRAY_SIZE(ek_nand_partition);
return ek_nand_partition;
}
static void __init ek_add_device_nand(void)
{
sam9_smc_configure(3, &ek_nand_smc_config);
at91_add_device_nand(&ek_nand_data);
}
static void __init ek_add_device_buttons(void)
{
at91_set_GPIO_periph(AT91_PIN_PB10, 1);
at91_set_deglitch(AT91_PIN_PB10, 1);
platform_device_register(&ek_button_device);
}
static void __init ek_add_device_buttons(void) {}
static void __init ek_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh(&ek_usbh_data);
at91_add_device_udc(&ek_udc_data);
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
at91_add_device_eth(&ek_macb_data);
ek_add_device_nand();
at91_add_device_i2c(NULL, 0);
ek_add_device_buttons();
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
at91_sys_write(AT91_SHDW_MR, AT91_SHDW_CPTWK0_(10) | AT91_SHDW_WKMODE0_LOW
| AT91_SHDW_RTTWKEN);
}
