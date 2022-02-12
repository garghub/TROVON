static void __init cap9adk_init_early(void)
{
at91cap9_initialize(12000000);
at91_init_leds(AT91_PIN_PA10, AT91_PIN_PA11);
at91_set_gpio_output(AT91_PIN_PC29, 1);
at91_register_uart(0, 0, 0);
at91_set_serial_console(0);
}
static void __init cap9adk_init_irq(void)
{
at91cap9_init_interrupts(NULL);
}
static int ads7843_pendown_state(void)
{
return !at91_get_gpio_value(AT91_PIN_PC4);
}
static void __init cap9adk_add_device_ts(void)
{
at91_set_gpio_input(AT91_PIN_PC4, 1);
at91_set_gpio_input(AT91_PIN_PC5, 1);
}
static void __init cap9adk_add_device_ts(void) {}
static struct mtd_partition * __init nand_partitions(int size, int *num_partitions)
{
*num_partitions = ARRAY_SIZE(cap9adk_nand_partitions);
return cap9adk_nand_partitions;
}
static void __init cap9adk_add_device_nand(void)
{
unsigned long csa;
csa = at91_sys_read(AT91_MATRIX_EBICSA);
at91_sys_write(AT91_MATRIX_EBICSA, csa | AT91_MATRIX_EBI_VDDIOMSEL_3_3V);
cap9adk_nand_data.bus_width_16 = board_have_nand_16bit();
if (cap9adk_nand_data.bus_width_16)
cap9adk_nand_smc_config.mode |= AT91_SMC_DBW_16;
else
cap9adk_nand_smc_config.mode |= AT91_SMC_DBW_8;
sam9_smc_configure(3, &cap9adk_nand_smc_config);
at91_add_device_nand(&cap9adk_nand_data);
}
static __init void cap9adk_add_device_nor(void)
{
unsigned long csa;
csa = at91_sys_read(AT91_MATRIX_EBICSA);
at91_sys_write(AT91_MATRIX_EBICSA, csa | AT91_MATRIX_EBI_VDDIOMSEL_3_3V);
sam9_smc_configure(0, &cap9adk_nor_smc_config);
platform_device_register(&cap9adk_nor_flash);
}
static void at91_lcdc_power_control(int on)
{
if (on)
at91_set_gpio_value(AT91_PIN_PC0, 0);
else
at91_set_gpio_value(AT91_PIN_PC0, 1);
}
static void __init cap9adk_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh(&cap9adk_usbh_data);
at91_add_device_usba(&cap9adk_usba_udc_data);
at91_add_device_spi(cap9adk_spi_devices, ARRAY_SIZE(cap9adk_spi_devices));
cap9adk_add_device_ts();
at91_add_device_mmc(1, &cap9adk_mmc_data);
at91_add_device_eth(&cap9adk_macb_data);
cap9adk_add_device_nand();
cap9adk_add_device_nor();
at91_add_device_i2c(NULL, 0);
at91_add_device_lcdc(&cap9adk_lcdc_data);
at91_add_device_ac97(&cap9adk_ac97_data);
}
