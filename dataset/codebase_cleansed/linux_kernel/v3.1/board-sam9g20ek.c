static int inline ek_have_2mmc(void)
{
return machine_is_at91sam9g20ek_2mmc() || (system_rev & HAVE_2MMC);
}
static void __init ek_init_early(void)
{
at91_initialize(18432000);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9260_ID_US0, 1, ATMEL_UART_CTS | ATMEL_UART_RTS
| ATMEL_UART_DTR | ATMEL_UART_DSR | ATMEL_UART_DCD
| ATMEL_UART_RI);
at91_register_uart(AT91SAM9260_ID_US1, 2, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_set_serial_console(0);
}
static void __init ek_add_device_macb(void)
{
if (ek_have_2mmc())
ek_macb_data.phy_irq_pin = AT91_PIN_PB0;
at91_add_device_eth(&ek_macb_data);
}
static struct mtd_partition * __init nand_partitions(int size, int *num_partitions)
{
*num_partitions = ARRAY_SIZE(ek_nand_partition);
return ek_nand_partition;
}
static void __init ek_add_device_nand(void)
{
ek_nand_data.bus_width_16 = board_have_nand_16bit();
if (ek_nand_data.bus_width_16)
ek_nand_smc_config.mode |= AT91_SMC_DBW_16;
else
ek_nand_smc_config.mode |= AT91_SMC_DBW_8;
sam9_smc_configure(3, &ek_nand_smc_config);
at91_add_device_nand(&ek_nand_data);
}
static void __init ek_add_device_mmc(void)
{
#if defined(CONFIG_MMC_ATMELMCI) || defined(CONFIG_MMC_ATMELMCI_MODULE)
if (ek_have_2mmc()) {
ek_mmc_data.slot[0].bus_width = 4;
ek_mmc_data.slot[0].detect_pin = AT91_PIN_PC2;
}
at91_add_device_mci(0, &ek_mmc_data);
#else
at91_add_device_mmc(0, &ek_mmc_data);
#endif
}
static void __init ek_add_device_gpio_leds(void)
{
if (ek_have_2mmc()) {
ek_leds[0].gpio = AT91_PIN_PB8;
ek_leds[1].gpio = AT91_PIN_PB9;
}
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
}
static void __init ek_add_device_buttons(void)
{
at91_set_gpio_input(AT91_PIN_PA30, 1);
at91_set_deglitch(AT91_PIN_PA30, 1);
at91_set_gpio_input(AT91_PIN_PA31, 1);
at91_set_deglitch(AT91_PIN_PA31, 1);
platform_device_register(&ek_button_device);
}
static void __init ek_add_device_buttons(void) {}
static void __init ek_add_regulators(void)
{
platform_device_register(&ek_voltage_regulator);
}
static void __init ek_add_regulators(void) {}
static void __init ek_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh(&ek_usbh_data);
at91_add_device_udc(&ek_udc_data);
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
ek_add_device_nand();
ek_add_device_macb();
ek_add_regulators();
ek_add_device_mmc();
at91_add_device_i2c(ek_i2c_devices, ARRAY_SIZE(ek_i2c_devices));
ek_add_device_gpio_leds();
ek_add_device_buttons();
at91_set_B_periph(AT91_PIN_PC1, 0);
at91_add_device_ssc(AT91SAM9260_ID_SSC, ATMEL_SSC_TX);
}
