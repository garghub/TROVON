static int lpc32xx_clcd_setup(struct clcd_fb *fb)
{
dma_addr_t dma;
fb->fb.screen_base = dma_alloc_writecombine(&fb->dev->dev,
PANEL_SIZE, &dma, GFP_KERNEL);
if (!fb->fb.screen_base) {
printk(KERN_ERR "CLCD: unable to map framebuffer\n");
return -ENOMEM;
}
fb->fb.fix.smem_start = dma;
fb->fb.fix.smem_len = PANEL_SIZE;
fb->panel = &conn_lcd_panel;
if (gpio_request(LCD_POWER_GPIO, "LCD power"))
printk(KERN_ERR "Error requesting gpio %u",
LCD_POWER_GPIO);
else if (gpio_direction_output(LCD_POWER_GPIO, 1))
printk(KERN_ERR "Error setting gpio %u to output",
LCD_POWER_GPIO);
if (gpio_request(BKL_POWER_GPIO, "LCD backlight power"))
printk(KERN_ERR "Error requesting gpio %u",
BKL_POWER_GPIO);
else if (gpio_direction_output(BKL_POWER_GPIO, 1))
printk(KERN_ERR "Error setting gpio %u to output",
BKL_POWER_GPIO);
return 0;
}
static int lpc32xx_clcd_mmap(struct clcd_fb *fb, struct vm_area_struct *vma)
{
return dma_mmap_writecombine(&fb->dev->dev, vma,
fb->fb.screen_base, fb->fb.fix.smem_start,
fb->fb.fix.smem_len);
}
static void lpc32xx_clcd_remove(struct clcd_fb *fb)
{
dma_free_writecombine(&fb->dev->dev, fb->fb.fix.smem_len,
fb->fb.screen_base, fb->fb.fix.smem_start);
}
static void clcd_disable(struct clcd_fb *fb)
{
gpio_set_value(BKL_POWER_GPIO, 0);
gpio_set_value(LCD_POWER_GPIO, 0);
}
static void clcd_enable(struct clcd_fb *fb)
{
gpio_set_value(BKL_POWER_GPIO, 1);
gpio_set_value(LCD_POWER_GPIO, 1);
}
static int pl08x_get_signal(const struct pl08x_channel_data *cd)
{
return cd->min_signal;
}
static void pl08x_put_signal(const struct pl08x_channel_data *cd, int ch)
{
}
static int mmc_handle_ios(struct device *dev, struct mmc_ios *ios)
{
if (ios->power_mode == MMC_POWER_OFF)
gpio_set_value(MMC_PWR_ENABLE_GPIO, 0);
else
gpio_set_value(MMC_PWR_ENABLE_GPIO, 1);
return 0;
}
static void __init lpc3250_machine_init(void)
{
u32 tmp;
tmp = __raw_readl(LPC32XX_CLKPWR_LCDCLK_CTRL) &
~(LPC32XX_CLKPWR_LCDCTRL_LCDTYPE_MSK |
LPC32XX_CLKPWR_LCDCTRL_PSCALE_MSK);
tmp |= LPC32XX_CLKPWR_LCDCTRL_LCDTYPE_TFT16;
__raw_writel(tmp, LPC32XX_CLKPWR_LCDCLK_CTRL);
lpc32xx_serial_init();
__raw_writel(LPC32XX_CLKPWR_TESTCLK2_SEL_MOSC |
LPC32XX_CLKPWR_TESTCLK_TESTCLK2_EN,
LPC32XX_CLKPWR_TEST_CLK_SEL);
of_platform_populate(NULL, of_default_bus_match_table,
lpc32xx_auxdata_lookup, NULL);
}
