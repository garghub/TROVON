static void __init ecb_at91init_early(void)
{
at91rm9200_set_type(ARCH_REVISON_9200_PQFP);
at91_initialize(18432000);
}
static void __init ecb_at91board_init(void)
{
at91_init_leds(AT91_PIN_PC7, AT91_PIN_PC7);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91RM9200_ID_US0, 1, 0);
at91_add_device_serial();
at91_add_device_eth(&ecb_at91eth_data);
at91_add_device_usbh(&ecb_at91usbh_data);
at91_add_device_i2c(NULL, 0);
at91_add_device_mmc(0, &ecb_at91mmc_data);
at91_add_device_spi(ecb_at91spi_devices, ARRAY_SIZE(ecb_at91spi_devices));
}
