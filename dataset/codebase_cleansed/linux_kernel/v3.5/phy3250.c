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
static void phy3250_spi_cs_set(u32 control)
{
gpio_set_value(SPI0_CS_GPIO, (int) control);
}
static int __init phy3250_spi_board_register(void)
{
#if defined(CONFIG_SPI_SPIDEV) || defined(CONFIG_SPI_SPIDEV_MODULE)
static struct spi_board_info info[] = {
{
.modalias = "spidev",
.max_speed_hz = 5000000,
.bus_num = 0,
.chip_select = 0,
.controller_data = &spi0_chip_info,
},
};
#else
static struct spi_eeprom eeprom = {
.name = "at25256a",
.byte_len = 0x8000,
.page_size = 64,
.flags = EE_ADDR2,
};
static struct spi_board_info info[] = {
{
.modalias = "at25",
.max_speed_hz = 5000000,
.bus_num = 0,
.chip_select = 0,
.mode = SPI_MODE_0,
.platform_data = &eeprom,
.controller_data = &spi0_chip_info,
},
};
#endif
return spi_register_board_info(info, ARRAY_SIZE(info));
}
static void __init lpc3250_machine_init(void)
{
u32 tmp;
__raw_writel(LPC32XX_CLKPWR_NANDCLK_SEL_SLC,
LPC32XX_CLKPWR_NAND_CLK_CTRL);
tmp = __raw_readl(LPC32XX_CLKPWR_LCDCLK_CTRL) &
~(LPC32XX_CLKPWR_LCDCTRL_LCDTYPE_MSK |
LPC32XX_CLKPWR_LCDCTRL_PSCALE_MSK);
tmp |= LPC32XX_CLKPWR_LCDCTRL_LCDTYPE_TFT16;
__raw_writel(tmp, LPC32XX_CLKPWR_LCDCLK_CTRL);
tmp = __raw_readl(LPC32XX_CLKPWR_USB_CTRL);
tmp |= LPC32XX_CLKPWR_USBCTRL_HCLK_EN |
LPC32XX_CLKPWR_USBCTRL_USBI2C_EN;
__raw_writel(tmp, LPC32XX_CLKPWR_USB_CTRL);
tmp = __raw_readl(LPC32XX_CLKPWR_I2C_CLK_CTRL);
tmp |= LPC32XX_CLKPWR_I2CCLK_USBI2CHI_DRIVE |
LPC32XX_CLKPWR_I2CCLK_I2C2HI_DRIVE;
__raw_writel(tmp, LPC32XX_CLKPWR_I2C_CLK_CTRL);
tmp = __raw_readl(LPC32XX_UARTCTL_CTRL);
tmp |= LPC32XX_UART_UART6_IRDAMOD_BYPASS;
__raw_writel(tmp, LPC32XX_UARTCTL_CTRL);
tmp = __raw_readl(LPC32XX_CLKPWR_I2S_CLK_CTRL);
tmp = LPC32XX_CLKPWR_I2SCTRL_I2S1_USE_DMA;
__raw_writel(tmp, LPC32XX_CLKPWR_I2S_CLK_CTRL);
lpc32xx_serial_init();
tmp = __raw_readl(LPC32XX_CLKPWR_LCDCLK_CTRL);
__raw_writel((tmp | LPC32XX_CLKPWR_LCDCTRL_CLK_EN),
LPC32XX_CLKPWR_LCDCLK_CTRL);
tmp = __raw_readl(LPC32XX_CLKPWR_SSP_CLK_CTRL);
__raw_writel((tmp | LPC32XX_CLKPWR_SSPCTRL_SSPCLK0_EN),
LPC32XX_CLKPWR_SSP_CLK_CTRL);
tmp = __raw_readl(LPC32XX_CLKPWR_DMA_CLK_CTRL);
__raw_writel((tmp | LPC32XX_CLKPWR_DMACLKCTRL_CLK_EN),
LPC32XX_CLKPWR_DMA_CLK_CTRL);
__raw_writel(LPC32XX_CLKPWR_TESTCLK2_SEL_MOSC |
LPC32XX_CLKPWR_TESTCLK_TESTCLK2_EN,
LPC32XX_CLKPWR_TEST_CLK_SEL);
of_platform_populate(NULL, of_default_bus_match_table,
lpc32xx_auxdata_lookup, NULL);
if (gpio_request(SPI0_CS_GPIO, "spi0 cs"))
printk(KERN_ERR "Error requesting gpio %u",
SPI0_CS_GPIO);
else if (gpio_direction_output(SPI0_CS_GPIO, 1))
printk(KERN_ERR "Error setting gpio %u to output",
SPI0_CS_GPIO);
}
