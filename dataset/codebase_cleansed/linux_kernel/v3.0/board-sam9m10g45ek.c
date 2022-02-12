static void __init ek_init_early(void)
{
at91sam9g45_initialize(12000000);
at91_register_uart(0, 0, 0);
at91_register_uart(AT91SAM9G45_ID_US1, 2, ATMEL_UART_CTS | ATMEL_UART_RTS);
at91_set_serial_console(0);
}
static void __init ek_init_irq(void)
{
at91sam9g45_init_interrupts(NULL);
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
static void __init ek_add_device_buttons(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(ek_buttons); i++) {
at91_set_GPIO_periph(ek_buttons[i].gpio, 1);
at91_set_deglitch(ek_buttons[i].gpio, 1);
}
platform_device_register(&ek_button_device);
}
static void __init ek_add_device_buttons(void) {}
static void __init ek_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh_ohci(&ek_usbh_hs_data);
at91_add_device_usbh_ehci(&ek_usbh_hs_data);
at91_add_device_usba(&ek_usba_udc_data);
at91_add_device_spi(ek_spi_devices, ARRAY_SIZE(ek_spi_devices));
at91_add_device_mci(0, &mci0_data);
at91_add_device_mci(1, &mci1_data);
at91_add_device_eth(&ek_macb_data);
ek_add_device_nand();
at91_add_device_i2c(0, NULL, 0);
at91_add_device_lcdc(&ek_lcdc_data);
at91_add_device_tsadcc(&ek_tsadcc_data);
ek_add_device_buttons();
at91_add_device_ac97(&ek_ac97_data);
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
at91_pwm_leds(ek_pwm_led, ARRAY_SIZE(ek_pwm_led));
}
