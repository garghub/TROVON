static int mx21ads_fb_init(struct platform_device *pdev)
{
u16 tmp;
tmp = __raw_readw(MX21ADS_IO_REG);
tmp |= MX21ADS_IO_LCDON;
__raw_writew(tmp, MX21ADS_IO_REG);
return 0;
}
static void mx21ads_fb_exit(struct platform_device *pdev)
{
u16 tmp;
tmp = __raw_readw(MX21ADS_IO_REG);
tmp &= ~MX21ADS_IO_LCDON;
__raw_writew(tmp, MX21ADS_IO_REG);
}
static int mx21ads_sdhc_get_ro(struct device *dev)
{
return (__raw_readw(MX21ADS_IO_REG) & MX21ADS_IO_SD_WP) ? 1 : 0;
}
static int mx21ads_sdhc_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
return request_irq(IRQ_GPIOD(25), detect_irq,
IRQF_TRIGGER_FALLING, "mmc-detect", data);
}
static void mx21ads_sdhc_exit(struct device *dev, void *data)
{
free_irq(IRQ_GPIOD(25), data);
}
static void __init mx21ads_map_io(void)
{
mx21_map_io();
iotable_init(mx21ads_io_desc, ARRAY_SIZE(mx21ads_io_desc));
}
static void __init mx21ads_board_init(void)
{
mxc_gpio_setup_multiple_pins(mx21ads_pins, ARRAY_SIZE(mx21ads_pins),
"mx21ads");
imx21_add_imx_uart0(&uart_pdata_rts);
imx21_add_imx_uart2(&uart_pdata_norts);
imx21_add_imx_uart3(&uart_pdata_rts);
imx21_add_imx_fb(&mx21ads_fb_data);
imx21_add_mxc_mmc(0, &mx21ads_sdhc_pdata);
imx21_add_mxc_nand(&mx21ads_nand_board_info);
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
}
static void __init mx21ads_timer_init(void)
{
mx21_clocks_init(32768, 26000000);
}
