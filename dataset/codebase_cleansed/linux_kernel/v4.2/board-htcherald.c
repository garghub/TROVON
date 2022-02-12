static void __init htcherald_lcd_init(void)
{
u32 reg;
unsigned int tries = 200;
reg = omap_readl(OMAP_LCDC_CONTROL);
if (reg & OMAP_LCDC_CTRL_LCD_EN) {
reg &= ~OMAP_LCDC_CTRL_LCD_EN;
omap_writel(reg, OMAP_LCDC_CONTROL);
while (!(omap_readl(OMAP_LCDC_STATUS) & OMAP_LCDC_STAT_DONE)) {
tries--;
if (!tries)
break;
}
if (!tries)
pr_err("Timeout waiting for end of frame -- LCD may not be available\n");
reg = omap_readw(OMAP_DMA_LCD_CCR);
reg &= ~(1 << 7);
omap_writew(reg, OMAP_DMA_LCD_CCR);
reg = omap_readw(OMAP_DMA_LCD_CTRL);
reg &= ~(1 << 8);
omap_writew(reg, OMAP_DMA_LCD_CTRL);
}
}
static void __init htcherald_map_io(void)
{
omap7xx_map_io();
htcherald_lcd_init();
printk(KERN_INFO "htcherald_map_io done.\n");
}
static void __init htcherald_disable_watchdog(void)
{
if (omap_readl(OMAP_WDT_TIMER_MODE) & 0x8000) {
printk(KERN_WARNING "OMAP850 Watchdog seems to be activated, disabling it for now.\n");
omap_writel(0xF5, OMAP_WDT_TIMER_MODE);
omap_writel(0xA0, OMAP_WDT_TIMER_MODE);
}
}
static void __init htcherald_usb_enable(void)
{
unsigned int tries = 20;
unsigned int value = 0;
if (gpio_request(HTCHERALD_GPIO_USB_EN1, "herald_usb") < 0)
goto err1;
if (gpio_request(HTCHERALD_GPIO_USB_EN2, "herald_usb") < 0)
goto err2;
if (gpio_request(HTCHERALD_GPIO_USB_DM, "herald_usb") < 0)
goto err3;
if (gpio_request(HTCHERALD_GPIO_USB_DP, "herald_usb") < 0)
goto err4;
do {
gpio_direction_output(HTCHERALD_GPIO_USB_EN1, 0);
} while ((value = gpio_get_value(HTCHERALD_GPIO_USB_EN1)) == 1 &&
--tries);
if (value == 1)
printk(KERN_WARNING "Unable to reset USB, trying to continue\n");
gpio_direction_output(HTCHERALD_GPIO_USB_EN2, 0);
gpio_direction_input(HTCHERALD_GPIO_USB_DM);
gpio_direction_input(HTCHERALD_GPIO_USB_DP);
goto done;
err4:
gpio_free(HTCHERALD_GPIO_USB_DM);
err3:
gpio_free(HTCHERALD_GPIO_USB_EN2);
err2:
gpio_free(HTCHERALD_GPIO_USB_EN1);
err1:
printk(KERN_ERR "Unabled to request GPIO for USB\n");
done:
printk(KERN_INFO "USB setup complete.\n");
}
static void __init htcherald_init(void)
{
printk(KERN_INFO "HTC Herald init.\n");
htcpld_resources[0].start = gpio_to_irq(HTCHERALD_GIRQ_BTNS);
htcpld_resources[0].end = gpio_to_irq(HTCHERALD_GIRQ_BTNS);
platform_add_devices(devices, ARRAY_SIZE(devices));
htcherald_disable_watchdog();
htcherald_usb_enable();
omap1_usb_init(&htcherald_usb_config);
htcherald_spi_board_info[0].irq = gpio_to_irq(HTCHERALD_GPIO_TS);
spi_register_board_info(htcherald_spi_board_info,
ARRAY_SIZE(htcherald_spi_board_info));
omap_register_i2c_bus(1, 100, NULL, 0);
#if defined(CONFIG_MMC_OMAP) || defined(CONFIG_MMC_OMAP_MODULE)
htc_mmc_data[0] = &htc_mmc1_data;
omap1_init_mmc(htc_mmc_data, 1);
#endif
omapfb_set_lcd_config(&htcherald_lcd_config);
}
