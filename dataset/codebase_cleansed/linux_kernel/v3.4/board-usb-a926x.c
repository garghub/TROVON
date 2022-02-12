static void __init ek_init_early(void)
{
at91_initialize(12000000);
at91_register_uart(0, 0, 0);
at91_set_serial_console(0);
}
static void __init ek_add_device_udc(void)
{
if (machine_is_usb_a9260() || machine_is_usb_a9g20())
ek_udc_data.vbus_pin = AT91_PIN_PC5;
at91_add_device_udc(&ek_udc_data);
}
static int at91_mmc_spi_init(struct device *dev,
irqreturn_t (*detect_int)(int, void *), void *data)
{
at91_set_gpio_input(MMC_SPI_CARD_DETECT_INT, 0);
return request_irq(gpio_to_irq(MMC_SPI_CARD_DETECT_INT), detect_int,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
"mmc-spi-detect", data);
}
static void at91_mmc_spi_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(MMC_SPI_CARD_DETECT_INT), data);
}
static void __init ek_add_device_spi(void)
{
if (machine_is_usb_a9263())
at91_add_device_spi(usb_a9263_spi_devices, ARRAY_SIZE(usb_a9263_spi_devices));
else if (machine_is_usb_a9g20())
at91_add_device_spi(usb_a9g20_spi_devices, ARRAY_SIZE(usb_a9g20_spi_devices));
}
static void __init ek_add_device_eth(void)
{
if (machine_is_usb_a9260() || machine_is_usb_a9g20())
ek_macb_data.phy_irq_pin = AT91_PIN_PA31;
at91_add_device_eth(&ek_macb_data);
}
static void __init ek_add_device_nand(void)
{
if (machine_is_usb_a9260() || machine_is_usb_a9g20()) {
ek_nand_data.rdy_pin = AT91_PIN_PC13;
ek_nand_data.enable_pin = AT91_PIN_PC14;
}
if (machine_is_usb_a9g20())
sam9_smc_configure(0, 3, &usb_a9g20_nand_smc_config);
else
sam9_smc_configure(0, 3, &usb_a9260_nand_smc_config);
at91_add_device_nand(&ek_nand_data);
}
static void __init ek_add_device_buttons(void)
{
at91_set_GPIO_periph(AT91_PIN_PB10, 1);
at91_set_deglitch(AT91_PIN_PB10, 1);
platform_device_register(&ek_button_device);
}
static void __init ek_add_device_buttons(void) {}
static void __init ek_add_device_leds(void)
{
if (machine_is_usb_a9260() || machine_is_usb_a9g20())
ek_leds[0].active_low = 0;
at91_gpio_leds(ek_leds, ARRAY_SIZE(ek_leds));
}
static void __init ek_board_init(void)
{
at91_add_device_serial();
at91_add_device_usbh(&ek_usbh_data);
ek_add_device_udc();
ek_add_device_spi();
ek_add_device_eth();
ek_add_device_nand();
ek_add_device_buttons();
ek_add_device_leds();
if (machine_is_usb_a9g20()) {
at91_add_device_i2c(ek_i2c_devices, ARRAY_SIZE(ek_i2c_devices));
} else {
at91_add_device_i2c(NULL, 0);
at91_shdwc_write(AT91_SHDW_MR, AT91_SHDW_CPTWK0_(10)
| AT91_SHDW_WKMODE0_LOW
| AT91_SHDW_RTTWKEN);
}
}
