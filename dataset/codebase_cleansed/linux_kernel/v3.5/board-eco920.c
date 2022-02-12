static void __init eco920_init_early(void)
{
at91rm9200_set_type(ARCH_REVISON_9200_PQFP);
at91_initialize(18432000);
}
static void __init eco920_board_init(void)
{
at91_init_leds(AT91_PIN_PB0, AT91_PIN_PB1);
at91_register_uart(0, 0, 0);
at91_add_device_serial();
at91_add_device_eth(&eco920_eth_data);
at91_add_device_usbh(&eco920_usbh_data);
at91_add_device_udc(&eco920_udc_data);
at91_add_device_mmc(0, &eco920_mmc_data);
platform_device_register(&eco920_flash);
at91_ramc_write(0, AT91_SMC_CSR(7), AT91_SMC_RWHOLD_(1)
| AT91_SMC_RWSETUP_(1)
| AT91_SMC_DBW_8
| AT91_SMC_WSEN
| AT91_SMC_NWS_(15));
at91_set_A_periph(AT91_PIN_PC6, 1);
at91_set_gpio_input(AT91_PIN_PA23, 0);
at91_set_deglitch(AT91_PIN_PA23, 1);
at91_ramc_write(0, AT91_SMC_CSR(3),
AT91_SMC_DBW_16 |
AT91_SMC_WSEN |
AT91_SMC_NWS_(5) |
AT91_SMC_TDF_(1)
);
at91_add_device_spi(eco920_spi_devices, ARRAY_SIZE(eco920_spi_devices));
}
