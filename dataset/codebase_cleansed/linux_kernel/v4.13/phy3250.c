static int lpc32xx_clcd_setup(struct clcd_fb *fb)
{
dma_addr_t dma;
fb->fb.screen_base = dma_alloc_wc(&fb->dev->dev, PANEL_SIZE, &dma,
GFP_KERNEL);
if (!fb->fb.screen_base) {
printk(KERN_ERR "CLCD: unable to map framebuffer\n");
return -ENOMEM;
}
fb->fb.fix.smem_start = dma;
fb->fb.fix.smem_len = PANEL_SIZE;
fb->panel = &conn_lcd_panel;
return 0;
}
static int lpc32xx_clcd_mmap(struct clcd_fb *fb, struct vm_area_struct *vma)
{
return dma_mmap_wc(&fb->dev->dev, vma, fb->fb.screen_base,
fb->fb.fix.smem_start, fb->fb.fix.smem_len);
}
static void lpc32xx_clcd_remove(struct clcd_fb *fb)
{
dma_free_wc(&fb->dev->dev, fb->fb.fix.smem_len, fb->fb.screen_base,
fb->fb.fix.smem_start);
}
static int pl08x_get_signal(const struct pl08x_channel_data *cd)
{
return cd->min_signal;
}
static void pl08x_put_signal(const struct pl08x_channel_data *cd, int ch)
{
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
of_platform_default_populate(NULL, lpc32xx_auxdata_lookup, NULL);
}
