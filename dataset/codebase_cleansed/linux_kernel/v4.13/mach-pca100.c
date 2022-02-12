static void pca100_ac97_warm_reset(struct snd_ac97 *ac97)
{
mxc_gpio_mode(GPIO_PORTC | 20 | GPIO_GPIO | GPIO_OUT);
gpio_set_value(GPIO_PORTC + 20, 1);
udelay(2);
gpio_set_value(GPIO_PORTC + 20, 0);
mxc_gpio_mode(PC20_PF_SSI1_FS);
msleep(2);
}
static void pca100_ac97_cold_reset(struct snd_ac97 *ac97)
{
mxc_gpio_mode(GPIO_PORTC | 20 | GPIO_GPIO | GPIO_OUT);
gpio_set_value(GPIO_PORTC + 20, 0);
mxc_gpio_mode(GPIO_PORTC | 22 | GPIO_GPIO | GPIO_OUT);
gpio_set_value(GPIO_PORTC + 22, 0);
mxc_gpio_mode(GPIO_PORTC | 28 | GPIO_GPIO | GPIO_OUT);
gpio_set_value(GPIO_PORTC + 28, 0);
udelay(10);
gpio_set_value(GPIO_PORTC + 28, 1);
mxc_gpio_mode(PC20_PF_SSI1_FS);
mxc_gpio_mode(PC22_PF_SSI1_TXD);
msleep(2);
}
static int pca100_sdhc2_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
int ret;
ret = request_irq(gpio_to_irq(IMX_GPIO_NR(3, 29)), detect_irq,
IRQF_TRIGGER_FALLING, "imx-mmc-detect", data);
if (ret)
printk(KERN_ERR
"pca100: Failed to request irq for sd/mmc detection\n");
return ret;
}
static void pca100_sdhc2_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(IMX_GPIO_NR(3, 29)), data);
}
static int otg_phy_init(struct platform_device *pdev)
{
gpio_set_value(OTG_PHY_CS_GPIO, 0);
mdelay(10);
return mx27_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int usbh2_phy_init(struct platform_device *pdev)
{
gpio_set_value(USBH2_PHY_CS_GPIO, 0);
mdelay(10);
return mx27_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int __init pca100_otg_mode(char *options)
{
if (!strcmp(options, "host"))
otg_mode_host = true;
else if (!strcmp(options, "device"))
otg_mode_host = false;
else
pr_info("otg_mode neither \"host\" nor \"device\". "
"Defaulting to device\n");
return 1;
}
static void __init pca100_init(void)
{
int ret;
imx27_soc_init();
ret = mxc_gpio_setup_multiple_pins(pca100_pins,
ARRAY_SIZE(pca100_pins), "PCA100");
if (ret)
printk(KERN_ERR "pca100: Failed to setup pins (%d)\n", ret);
imx27_add_imx_uart0(&uart_pdata);
imx27_add_mxc_nand(&pca100_nand_board_info);
i2c_register_board_info(1, pca100_i2c_devices,
ARRAY_SIZE(pca100_i2c_devices));
imx27_add_imx_i2c(1, &pca100_i2c1_data);
mxc_gpio_mode(GPIO_PORTD | 28 | GPIO_GPIO | GPIO_IN);
mxc_gpio_mode(GPIO_PORTD | 27 | GPIO_GPIO | GPIO_IN);
spi_register_board_info(pca100_spi_board_info,
ARRAY_SIZE(pca100_spi_board_info));
imx27_add_spi_imx0(&pca100_spi0_data);
imx27_add_imx_fb(&pca100_fb_data);
imx27_add_fec(NULL);
imx27_add_imx2_wdt();
imx27_add_mxc_w1();
}
static void __init pca100_late_init(void)
{
imx27_add_imx_ssi(0, &pca100_ssi_pdata);
imx27_add_mxc_mmc(1, &sdhc_pdata);
gpio_request(OTG_PHY_CS_GPIO, "usb-otg-cs");
gpio_direction_output(OTG_PHY_CS_GPIO, 1);
gpio_request(USBH2_PHY_CS_GPIO, "usb-host2-cs");
gpio_direction_output(USBH2_PHY_CS_GPIO, 1);
if (otg_mode_host) {
otg_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (otg_pdata.otg)
imx27_add_mxc_ehci_otg(&otg_pdata);
} else {
gpio_set_value(OTG_PHY_CS_GPIO, 0);
imx27_add_fsl_usb2_udc(&otg_device_pdata);
}
usbh2_pdata.otg = imx_otg_ulpi_create(
ULPI_OTG_DRVVBUS | ULPI_OTG_DRVVBUS_EXT);
if (usbh2_pdata.otg)
imx27_add_mxc_ehci_hs(2, &usbh2_pdata);
}
static void __init pca100_timer_init(void)
{
mx27_clocks_init(26000000);
}
