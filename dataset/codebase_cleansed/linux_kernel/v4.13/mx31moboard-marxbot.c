static int marxbot_sdhc2_get_ro(struct device *dev)
{
return !gpio_get_value(SDHC2_WP);
}
static int marxbot_sdhc2_init(struct device *dev, irq_handler_t detect_irq,
void *data)
{
int ret;
ret = gpio_request(SDHC2_CD, "sdhc-detect");
if (ret)
return ret;
gpio_direction_input(SDHC2_CD);
ret = gpio_request(SDHC2_WP, "sdhc-wp");
if (ret)
goto err_gpio_free;
gpio_direction_input(SDHC2_WP);
ret = request_irq(gpio_to_irq(SDHC2_CD), detect_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
"sdhc2-card-detect", data);
if (ret)
goto err_gpio_free_2;
return 0;
err_gpio_free_2:
gpio_free(SDHC2_WP);
err_gpio_free:
gpio_free(SDHC2_CD);
return ret;
}
static void marxbot_sdhc2_exit(struct device *dev, void *data)
{
free_irq(gpio_to_irq(SDHC2_CD), data);
gpio_free(SDHC2_WP);
gpio_free(SDHC2_CD);
}
static void dspics_resets_init(void)
{
if (!gpio_request(TRSLAT_RST_B, "translator-rst")) {
gpio_direction_output(TRSLAT_RST_B, 0);
gpio_export(TRSLAT_RST_B, false);
}
if (!gpio_request(DSPICS_RST_B, "dspics-rst")) {
gpio_direction_output(DSPICS_RST_B, 0);
gpio_export(DSPICS_RST_B, false);
}
}
static void marxbot_init_sel_gpios(void)
{
if (!gpio_request(SEL0, "sel0")) {
gpio_direction_input(SEL0);
gpio_export(SEL0, true);
}
if (!gpio_request(SEL1, "sel1")) {
gpio_direction_input(SEL1);
gpio_export(SEL1, true);
}
if (!gpio_request(SEL2, "sel2")) {
gpio_direction_input(SEL2);
gpio_export(SEL2, true);
}
if (!gpio_request(SEL3, "sel3")) {
gpio_direction_input(SEL3);
gpio_export(SEL3, true);
}
}
static int marxbot_usbh1_hw_init(struct platform_device *pdev)
{
mxc_iomux_set_gpr(MUX_PGP_USB_SUSPEND, true);
mxc_iomux_set_pad(MX31_PIN_CSPI1_MISO, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_MOSI, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SS0, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SS1, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SS2, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SCLK, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SPI_RDY, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_SFS6, USB_PAD_CFG);
mdelay(10);
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED |
MXC_EHCI_INTERFACE_SINGLE_UNI);
}
static int marxbot_isp1105_init(struct usb_phy *otg)
{
int ret = gpio_request(USBH1_MODE, "usbh1-mode");
if (ret)
return ret;
gpio_direction_output(USBH1_MODE, 0);
ret = gpio_request(USBH1_VBUSEN_B, "usbh1-vbusen");
if (ret) {
gpio_free(USBH1_MODE);
return ret;
}
gpio_direction_output(USBH1_VBUSEN_B, 1);
return 0;
}
static int marxbot_isp1105_set_vbus(struct usb_otg *otg, bool on)
{
if (on)
gpio_set_value(USBH1_VBUSEN_B, 0);
else
gpio_set_value(USBH1_VBUSEN_B, 1);
return 0;
}
static int __init marxbot_usbh1_init(void)
{
struct usb_phy *phy;
struct platform_device *pdev;
phy = kzalloc(sizeof(*phy), GFP_KERNEL);
if (!phy)
return -ENOMEM;
phy->otg = kzalloc(sizeof(struct usb_otg), GFP_KERNEL);
if (!phy->otg) {
kfree(phy);
return -ENOMEM;
}
phy->label = "ISP1105";
phy->init = marxbot_isp1105_init;
phy->otg->set_vbus = marxbot_isp1105_set_vbus;
usbh1_pdata.otg = phy;
pdev = imx31_add_mxc_ehci_hs(1, &usbh1_pdata);
return PTR_ERR_OR_ZERO(pdev);
}
void __init mx31moboard_marxbot_init(void)
{
printk(KERN_INFO "Initializing mx31marxbot peripherals\n");
mxc_iomux_setup_multiple_pins(marxbot_pins, ARRAY_SIZE(marxbot_pins),
"marxbot");
marxbot_init_sel_gpios();
dspics_resets_init();
imx31_add_mxc_mmc(1, &sdhc2_pdata);
spi_register_board_info(marxbot_spi_board_info,
ARRAY_SIZE(marxbot_spi_board_info));
gpio_request(IOMUX_TO_GPIO(MX31_PIN_LCS0), "bat-present");
gpio_direction_input(IOMUX_TO_GPIO(MX31_PIN_LCS0));
gpio_export(IOMUX_TO_GPIO(MX31_PIN_LCS0), false);
imx31_add_fsl_usb2_udc(&usb_pdata);
marxbot_usbh1_init();
}
