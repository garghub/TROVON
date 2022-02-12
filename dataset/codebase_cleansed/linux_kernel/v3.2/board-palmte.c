static void __init palmte_misc_gpio_setup(void)
{
if (gpio_request(PALMTE_PINTDAV_GPIO, "TSC2102 PINTDAV") < 0) {
printk(KERN_ERR "Could not reserve PINTDAV GPIO!\n");
return;
}
gpio_direction_input(PALMTE_PINTDAV_GPIO);
if (gpio_request(PALMTE_USB_OR_DC_GPIO, "USB/DC-IN") < 0) {
printk(KERN_ERR "Could not reserve cable signal GPIO!\n");
return;
}
gpio_direction_input(PALMTE_USB_OR_DC_GPIO);
}
static void __init omap_palmte_init(void)
{
omap_cfg_reg(UART1_TX);
omap_cfg_reg(UART1_RTS);
omap_cfg_reg(UART2_TX);
omap_cfg_reg(UART2_RTS);
omap_cfg_reg(UART3_TX);
omap_cfg_reg(UART3_RX);
omap_board_config = palmte_config;
omap_board_config_size = ARRAY_SIZE(palmte_config);
platform_add_devices(palmte_devices, ARRAY_SIZE(palmte_devices));
spi_register_board_info(palmte_spi_info, ARRAY_SIZE(palmte_spi_info));
palmte_misc_gpio_setup();
omap_serial_init();
omap1_usb_init(&palmte_usb_config);
omap_register_i2c_bus(1, 100, NULL, 0);
}
