static void __init dk_init_early(void)
{
at91rm9200_initialize(18432000);
at91_init_leds(AT91_PIN_PB2, AT91_PIN_PB2);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US1, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_set_serial_console(0);
}
static void __init dk_init_irq(void)
{
at91rm9200_init_interrupts(NULL);
}
static struct mtd_partition * __init nand_partitions(int size, int *num_partitions)
{
*num_partitions = ARRAY_SIZE(dk_nand_partition);
return dk_nand_partition;
}
static void __init dk_board_init(void)
{
at91_add_device_serial();
at91_add_device_eth(&dk_eth_data);
at91_add_device_usbh(&dk_usbh_data);
at91_add_device_udc(&dk_udc_data);
at91_set_multi_drive(dk_udc_data.pullup_pin, 1);
at91_add_device_cf(&dk_cf_data);
at91_add_device_i2c(dk_i2c_devices, ARRAY_SIZE(dk_i2c_devices));
at91_add_device_spi(dk_spi_devices, ARRAY_SIZE(dk_spi_devices));
#ifdef CONFIG_MTD_AT91_DATAFLASH_CARD
at91_set_gpio_output(AT91_PIN_PB7, 0);
#else
at91_set_gpio_output(AT91_PIN_PB7, 1);
at91_add_device_mmc(0, &dk_mmc_data);
#endif
at91_add_device_nand(&dk_nand_data);
platform_device_register(&dk_flash);
at91_gpio_leds(dk_leds, ARRAY_SIZE(dk_leds));
}
