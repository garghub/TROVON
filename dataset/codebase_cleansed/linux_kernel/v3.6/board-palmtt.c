static int palmtt_get_pendown_state(void)
{
return !gpio_get_value(6);
}
static void __init omap_mpu_wdt_mode(int mode) {
if (mode)
omap_writew(0x8000, OMAP_WDT_TIMER_MODE);
else {
omap_writew(0x00f5, OMAP_WDT_TIMER_MODE);
omap_writew(0x00a0, OMAP_WDT_TIMER_MODE);
}
}
static void __init omap_palmtt_init(void)
{
omap_cfg_reg(UART1_TX);
omap_cfg_reg(UART1_RTS);
omap_cfg_reg(UART2_TX);
omap_cfg_reg(UART2_RTS);
omap_cfg_reg(UART3_TX);
omap_cfg_reg(UART3_RX);
omap_mpu_wdt_mode(0);
platform_add_devices(palmtt_devices, ARRAY_SIZE(palmtt_devices));
palmtt_boardinfo[0].irq = gpio_to_irq(6);
spi_register_board_info(palmtt_boardinfo,ARRAY_SIZE(palmtt_boardinfo));
omap_serial_init();
omap1_usb_init(&palmtt_usb_config);
omap_register_i2c_bus(1, 100, NULL, 0);
omapfb_set_lcd_config(&palmtt_lcd_config);
}
