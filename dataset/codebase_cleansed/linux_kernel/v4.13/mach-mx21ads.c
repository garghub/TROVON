static int mx21ads_sdhc_get_ro(struct device *dev)
{
return gpio_get_value(MX21ADS_IO_SD_WP);
}
static int mx21ads_sdhc_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
int ret;
ret = gpio_request(MX21ADS_IO_SD_WP, "mmc-ro");
if (ret)
return ret;
return request_irq(gpio_to_irq(MX21ADS_MMC_CD), detect_irq,
IRQF_TRIGGER_FALLING, "mmc-detect", data);
}
static void mx21ads_sdhc_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(MX21ADS_MMC_CD), data);
gpio_free(MX21ADS_IO_SD_WP);
}
static void __init mx21ads_board_init(void)
{
imx21_soc_init();
mxc_gpio_setup_multiple_pins(mx21ads_pins, ARRAY_SIZE(mx21ads_pins),
"mx21ads");
imx21_add_imx_uart0(&uart_pdata_rts);
imx21_add_imx_uart2(&uart_pdata_norts);
imx21_add_imx_uart3(&uart_pdata_rts);
imx21_add_mxc_nand(&mx21ads_nand_board_info);
imx21_add_imx_fb(&mx21ads_fb_data);
}
static void __init mx21ads_late_init(void)
{
imx21_add_mxc_mmc(0, &mx21ads_sdhc_pdata);
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
mx21ads_cs8900_resources[1].start =
gpio_to_irq(MX21ADS_CS8900A_IRQ_GPIO);
mx21ads_cs8900_resources[1].end =
gpio_to_irq(MX21ADS_CS8900A_IRQ_GPIO);
platform_device_register_full(&mx21ads_cs8900_devinfo);
}
static void __init mx21ads_timer_init(void)
{
mx21_clocks_init(32768, 26000000);
}
