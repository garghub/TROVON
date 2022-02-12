static int
palmz71_get_pendown_state(void)
{
return !gpio_get_value(PALMZ71_PENIRQ_GPIO);
}
static irqreturn_t
palmz71_powercable(int irq, void *dev_id)
{
if (gpio_get_value(PALMZ71_USBDETECT_GPIO)) {
printk(KERN_INFO "PM: Power cable connected\n");
irq_set_irq_type(gpio_to_irq(PALMZ71_USBDETECT_GPIO),
IRQ_TYPE_EDGE_FALLING);
} else {
printk(KERN_INFO "PM: Power cable disconnected\n");
irq_set_irq_type(gpio_to_irq(PALMZ71_USBDETECT_GPIO),
IRQ_TYPE_EDGE_RISING);
}
return IRQ_HANDLED;
}
static void __init
omap_mpu_wdt_mode(int mode)
{
if (mode)
omap_writew(0x8000, OMAP_WDT_TIMER_MODE);
else {
omap_writew(0x00f5, OMAP_WDT_TIMER_MODE);
omap_writew(0x00a0, OMAP_WDT_TIMER_MODE);
}
}
static void __init
palmz71_gpio_setup(int early)
{
if (early) {
gpio_direction_output(1, 1);
} else {
if (gpio_request(PALMZ71_MMC_WP_GPIO, "MMC WP") < 0) {
printk(KERN_ERR "Could not reserve WP GPIO!\n");
return;
}
gpio_direction_input(PALMZ71_MMC_WP_GPIO);
if (gpio_request(PALMZ71_USBDETECT_GPIO, "USB detect") < 0) {
printk(KERN_ERR
"Could not reserve cable signal GPIO!\n");
return;
}
gpio_direction_input(PALMZ71_USBDETECT_GPIO);
if (request_irq(gpio_to_irq(PALMZ71_USBDETECT_GPIO),
palmz71_powercable, 0, "palmz71-cable", NULL))
printk(KERN_ERR
"IRQ request for power cable failed!\n");
palmz71_powercable(gpio_to_irq(PALMZ71_USBDETECT_GPIO), NULL);
}
}
static void __init
omap_palmz71_init(void)
{
omap_cfg_reg(UART1_TX);
omap_cfg_reg(UART1_RTS);
omap_cfg_reg(UART2_TX);
omap_cfg_reg(UART2_RTS);
omap_cfg_reg(UART3_TX);
omap_cfg_reg(UART3_RX);
palmz71_gpio_setup(1);
omap_mpu_wdt_mode(0);
platform_add_devices(devices, ARRAY_SIZE(devices));
palmz71_boardinfo[0].irq = gpio_to_irq(PALMZ71_PENIRQ_GPIO);
spi_register_board_info(palmz71_boardinfo,
ARRAY_SIZE(palmz71_boardinfo));
omap1_usb_init(&palmz71_usb_config);
omap_serial_init();
omap_register_i2c_bus(1, 100, NULL, 0);
palmz71_gpio_setup(0);
omapfb_set_lcd_config(&palmz71_lcd_config);
}
