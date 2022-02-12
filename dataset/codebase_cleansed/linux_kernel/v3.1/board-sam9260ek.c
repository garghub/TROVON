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
static void __init at73c213_set_clk(struct at73c213_board_info *info)
{
struct clk *pck0;
struct clk *plla;
pck0 = clk_get(NULL, "pck0");
plla = clk_get(NULL, "plla");
at91_set_B_periph(AT91_PIN_PC1, 0);
clk_set_parent(pck0, plla);
clk_put(plla);
info->dac_clk = pck0;
}
static void __init at73c213_set_clk(struct at73c213_board_info *info) {}
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
static void __init ek_add_device_buttons(void)
{
at91_set_gpio_input(AT91_PIN_PA30, 1);
at91_set_deglitch(AT91_PIN_PA30, 1);
at91_set_gpio_input(AT91_PIN_PA31, 1);
at91_set_deglitch(AT91_PIN_PA31, 1);
platform_device_register(&ek_button_device);
}
static void __init ek_add_device_buttons(void) {}
static void __init ek_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh(&ek_usbh_data);
at91_add_device_udc(&ek_udc_data);
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
ek_add_device_nand();
at91_add_device_eth(&ek_macb_data);
at91_add_device_mmc(0, &ek_mmc_data);
at91_add_device_i2c(ek_i2c_devices, ARRAY_SIZE(ek_i2c_devices));
at73c213_set_clk(&at73c213_data);
at91_add_device_ssc(AT91SAM9260_ID_SSC, ATMEL_SSC_TX);
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
ek_add_device_buttons();
}
