static int mx27_3ds_sdhc1_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
return request_irq(gpio_to_irq(SD1_CD), detect_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING, "sdhc1-card-detect", data);
}
static void mx27_3ds_sdhc1_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(SD1_CD), data);
}
static void mx27_3ds_sdhc1_enable_level_translator(void)
{
gpio_request(SD1_EN_GPIO, "sd1_enable");
gpio_direction_output(SD1_EN_GPIO, 1);
}
static int otg_phy_init(void)
{
gpio_request(OTG_PHY_RESET_GPIO, "usb-otg-reset");
gpio_direction_output(OTG_PHY_RESET_GPIO, 0);
mdelay(1);
gpio_set_value(OTG_PHY_RESET_GPIO, 1);
return 0;
}
static int mx27_3ds_otg_init(struct platform_device *pdev)
{
return mx27_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int __init mx27_3ds_otg_mode(char *options)
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
static int mx27_3ds_camera_power(struct device *dev, int on)
{
pr_debug("%s: %s the camera\n", __func__, on ? "ENABLE" : "DISABLE");
gpio_set_value(CSI_PWRDWN, on ? 0 : 1);
if (!on)
goto out;
gpio_set_value(CSI_RESET, 0);
msleep(20);
gpio_set_value(CSI_RESET, 1);
msleep(100);
out:
return 0;
}
static void __init mx27pdk_init(void)
{
int ret;
imx27_soc_init();
mxc_gpio_setup_multiple_pins(mx27pdk_pins, ARRAY_SIZE(mx27pdk_pins),
"mx27pdk");
mx27_3ds_sdhc1_enable_level_translator();
imx27_add_imx_uart0(&uart_pdata);
imx27_add_fec(NULL);
imx27_add_imx_keypad(&mx27_3ds_keymap_data);
imx27_add_mxc_mmc(0, &sdhc1_pdata);
imx27_add_imx2_wdt();
otg_phy_init();
if (otg_mode_host) {
otg_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (otg_pdata.otg)
imx27_add_mxc_ehci_otg(&otg_pdata);
}
if (!otg_mode_host)
imx27_add_fsl_usb2_udc(&otg_device_pdata);
imx27_add_spi_imx1(&spi2_pdata);
imx27_add_spi_imx0(&spi1_pdata);
mx27_3ds_spi_devs[0].irq = gpio_to_irq(PMIC_INT);
spi_register_board_info(mx27_3ds_spi_devs,
ARRAY_SIZE(mx27_3ds_spi_devs));
if (mxc_expio_init(MX27_CS5_BASE_ADDR, IMX_GPIO_NR(3, 28)))
pr_warn("Init of the debugboard failed, all devices on the debugboard are unusable.\n");
imx27_add_imx_i2c(0, &mx27_3ds_i2c0_data);
platform_add_devices(devices, ARRAY_SIZE(devices));
imx27_add_imx_fb(&mx27_3ds_fb_data);
ret = gpio_request_array(mx27_3ds_camera_gpios,
ARRAY_SIZE(mx27_3ds_camera_gpios));
if (ret) {
pr_err("Failed to request camera gpios");
iclink_ov2640.power = NULL;
}
imx27_add_mx2_camera(&mx27_3ds_cam_pdata);
imx27_add_imx_ssi(0, &mx27_3ds_ssi_pdata);
imx_add_platform_device("imx_mc13783", 0, NULL, 0, NULL, 0);
}
static void __init mx27pdk_timer_init(void)
{
mx27_clocks_init(26000000);
}
