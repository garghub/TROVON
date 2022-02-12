static int usbotg_init(struct platform_device *pdev)
{
int err;
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA0, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA1, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA2, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA3, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA4, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA5, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA6, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA7, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_CLK, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_DIR, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_NXT, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBOTG_STP, USB_PAD_CFG);
err = gpio_request(OTG_RESET, "USB-OTG-RESET");
if (err) {
pr_err("Failed to request the usb otg reset gpio\n");
return err;
}
err = gpio_direction_output(OTG_RESET, 1);
if (err) {
pr_err("Failed to reset the usb otg phy\n");
goto otg_free_reset;
}
gpio_set_value(OTG_RESET, 0);
mdelay(5);
gpio_set_value(OTG_RESET, 1);
mdelay(10);
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED |
MXC_EHCI_INTERFACE_DIFF_UNI);
otg_free_reset:
gpio_free(OTG_RESET);
return err;
}
static int usbh2_init(struct platform_device *pdev)
{
int err;
mxc_iomux_set_pad(MX31_PIN_USBH2_CLK, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_DIR, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_NXT, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_STP, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_DATA0, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_USBH2_DATA1, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SRXD6, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_STXD6, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SFS3, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SCK3, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SRXD3, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_STXD3, USB_PAD_CFG);
mxc_iomux_set_gpr(MUX_PGP_UH2, true);
err = gpio_request(USBH2_CS, "USB-H2-CS");
if (err) {
pr_err("Failed to request the usb host 2 CS gpio\n");
return err;
}
err = gpio_direction_output(USBH2_CS, 0);
if (err) {
pr_err("Failed to drive the usb host 2 CS gpio\n");
goto h2_free_cs;
}
err = gpio_request(USBH2_RESET, "USB-H2-RESET");
if (err) {
pr_err("Failed to request the usb host 2 reset gpio\n");
goto h2_free_cs;
}
err = gpio_direction_output(USBH2_RESET, 1);
if (err) {
pr_err("Failed to reset the usb host 2 phy\n");
goto h2_free_reset;
}
gpio_set_value(USBH2_RESET, 0);
mdelay(5);
gpio_set_value(USBH2_RESET, 1);
mdelay(10);
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED |
MXC_EHCI_INTERFACE_DIFF_UNI);
h2_free_reset:
gpio_free(USBH2_RESET);
h2_free_cs:
gpio_free(USBH2_CS);
return err;
}
static int armadillo5x0_sdhc1_get_ro(struct device *dev)
{
return gpio_get_value(IOMUX_TO_GPIO(MX31_PIN_ATA_RESET_B));
}
static int armadillo5x0_sdhc1_init(struct device *dev,
irq_handler_t detect_irq, void *data)
{
int ret;
int gpio_det, gpio_wp;
gpio_det = IOMUX_TO_GPIO(MX31_PIN_ATA_DMACK);
gpio_wp = IOMUX_TO_GPIO(MX31_PIN_ATA_RESET_B);
ret = gpio_request(gpio_det, "sdhc-card-detect");
if (ret)
return ret;
gpio_direction_input(gpio_det);
ret = gpio_request(gpio_wp, "sdhc-write-protect");
if (ret)
goto err_gpio_free;
gpio_direction_input(gpio_wp);
ret = request_irq(IOMUX_TO_IRQ(MX31_PIN_ATA_DMACK), detect_irq,
IRQF_DISABLED | IRQF_TRIGGER_FALLING,
"sdhc-detect", data);
if (ret)
goto err_gpio_free_2;
return 0;
err_gpio_free_2:
gpio_free(gpio_wp);
err_gpio_free:
gpio_free(gpio_det);
return ret;
}
static void armadillo5x0_sdhc1_exit(struct device *dev, void *data)
{
free_irq(IOMUX_TO_IRQ(MX31_PIN_ATA_DMACK), data);
gpio_free(IOMUX_TO_GPIO(MX31_PIN_ATA_DMACK));
gpio_free(IOMUX_TO_GPIO(MX31_PIN_ATA_RESET_B));
}
static void __init armadillo5x0_init(void)
{
imx31_soc_init();
mxc_iomux_setup_multiple_pins(armadillo5x0_pins,
ARRAY_SIZE(armadillo5x0_pins), "armadillo5x0");
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
platform_add_devices(devices, ARRAY_SIZE(devices));
imx_add_gpio_keys(&armadillo5x0_button_data);
imx31_add_imx_i2c1(NULL);
imx31_add_imx_uart0(&uart_pdata);
imx31_add_imx_uart1(&uart_pdata);
gpio_direction_input(MX31_PIN_GPIO1_0);
imx31_add_mxc_mmc(0, &sdhc_pdata);
imx31_add_ipu_core(&mx3_ipu_data);
imx31_add_mx3_sdc_fb(&mx3fb_pdata);
platform_device_register_resndata(NULL, "physmap-flash", -1,
&armadillo5x0_nor_flash_resource, 1,
&armadillo5x0_nor_flash_pdata,
sizeof(armadillo5x0_nor_flash_pdata));
imx31_add_mxc_nand(&armadillo5x0_nand_board_info);
__raw_writel(__raw_readl(MXC_CCM_RCSR) | (1 << 30), MXC_CCM_RCSR);
if (gpio_request(ARMADILLO5X0_RTC_GPIO, "rtc") == 0) {
if (gpio_direction_input(ARMADILLO5X0_RTC_GPIO) == 0)
armadillo5x0_i2c_rtc.irq = gpio_to_irq(ARMADILLO5X0_RTC_GPIO);
else
gpio_free(ARMADILLO5X0_RTC_GPIO);
}
if (armadillo5x0_i2c_rtc.irq == 0)
pr_warning("armadillo5x0_init: failed to get RTC IRQ\n");
i2c_register_board_info(1, &armadillo5x0_i2c_rtc, 1);
usbotg_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (usbotg_pdata.otg)
imx31_add_mxc_ehci_otg(&usbotg_pdata);
usbh2_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (usbh2_pdata.otg)
imx31_add_mxc_ehci_hs(2, &usbh2_pdata);
}
static void __init armadillo5x0_timer_init(void)
{
mx31_clocks_init(26000000);
}
