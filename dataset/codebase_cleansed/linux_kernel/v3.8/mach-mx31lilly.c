static int usbh1_init(struct platform_device *pdev)
{
int pins[] = {
MX31_PIN_CSPI1_MOSI__USBH1_RXDM,
MX31_PIN_CSPI1_MISO__USBH1_RXDP,
MX31_PIN_CSPI1_SS0__USBH1_TXDM,
MX31_PIN_CSPI1_SS1__USBH1_TXDP,
MX31_PIN_CSPI1_SS2__USBH1_RCV,
MX31_PIN_CSPI1_SCLK__USBH1_OEB,
MX31_PIN_CSPI1_SPI_RDY__USBH1_FS,
};
mxc_iomux_setup_multiple_pins(pins, ARRAY_SIZE(pins), "USB H1");
mxc_iomux_set_pad(MX31_PIN_CSPI1_MOSI, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_MISO, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SS0, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SS1, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SS2, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SCLK, USB_PAD_CFG);
mxc_iomux_set_pad(MX31_PIN_CSPI1_SPI_RDY, USB_PAD_CFG);
mxc_iomux_set_gpr(MUX_PGP_USB_SUSPEND, true);
mdelay(10);
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED |
MXC_EHCI_INTERFACE_SINGLE_UNI);
}
static int usbh2_init(struct platform_device *pdev)
{
int pins[] = {
MX31_PIN_USBH2_DATA0__USBH2_DATA0,
MX31_PIN_USBH2_DATA1__USBH2_DATA1,
MX31_PIN_USBH2_CLK__USBH2_CLK,
MX31_PIN_USBH2_DIR__USBH2_DIR,
MX31_PIN_USBH2_NXT__USBH2_NXT,
MX31_PIN_USBH2_STP__USBH2_STP,
};
mxc_iomux_setup_multiple_pins(pins, ARRAY_SIZE(pins), "USB H2");
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
mxc_iomux_alloc_pin(IOMUX_MODE(MX31_PIN_DTR_DCE1, IOMUX_CONFIG_GPIO),
"USBH2_CS");
gpio_request(IOMUX_TO_GPIO(MX31_PIN_DTR_DCE1), "USBH2 CS");
gpio_direction_output(IOMUX_TO_GPIO(MX31_PIN_DTR_DCE1), 0);
mdelay(10);
return mx31_initialize_usb_hw(pdev->id, MXC_EHCI_POWER_PINS_ENABLED);
}
static void __init lilly1131_usb_init(void)
{
imx31_add_mxc_ehci_hs(1, &usbh1_pdata);
usbh2_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (usbh2_pdata.otg)
imx31_add_mxc_ehci_hs(2, &usbh2_pdata);
}
static void __init mx31lilly_board_init(void)
{
imx31_soc_init();
switch (mx31lilly_baseboard) {
case MX31LILLY_NOBOARD:
break;
case MX31LILLY_DB:
mx31lilly_db_init();
break;
default:
printk(KERN_ERR "Illegal mx31lilly_baseboard type %d\n",
mx31lilly_baseboard);
}
mxc_iomux_alloc_pin(MX31_PIN_CS4__CS4, "Ethernet CS");
mxc_iomux_alloc_pin(MX31_PIN_CSPI1_SCLK__SCLK, "SPI1_CLK");
mxc_iomux_alloc_pin(MX31_PIN_CSPI1_MOSI__MOSI, "SPI1_TX");
mxc_iomux_alloc_pin(MX31_PIN_CSPI1_MISO__MISO, "SPI1_RX");
mxc_iomux_alloc_pin(MX31_PIN_CSPI1_SPI_RDY__SPI_RDY, "SPI1_RDY");
mxc_iomux_alloc_pin(MX31_PIN_CSPI1_SS0__SS0, "SPI1_SS0");
mxc_iomux_alloc_pin(MX31_PIN_CSPI1_SS1__SS1, "SPI1_SS1");
mxc_iomux_alloc_pin(MX31_PIN_CSPI1_SS2__SS2, "SPI1_SS2");
mxc_iomux_alloc_pin(MX31_PIN_CSPI2_SCLK__SCLK, "SPI2_CLK");
mxc_iomux_alloc_pin(MX31_PIN_CSPI2_MOSI__MOSI, "SPI2_TX");
mxc_iomux_alloc_pin(MX31_PIN_CSPI2_MISO__MISO, "SPI2_RX");
mxc_iomux_alloc_pin(MX31_PIN_CSPI2_SPI_RDY__SPI_RDY, "SPI2_RDY");
mxc_iomux_alloc_pin(MX31_PIN_CSPI2_SS0__SS0, "SPI2_SS0");
mxc_iomux_alloc_pin(MX31_PIN_CSPI2_SS1__SS1, "SPI2_SS1");
mxc_iomux_alloc_pin(MX31_PIN_CSPI2_SS2__SS2, "SPI2_SS2");
imx31_add_spi_imx0(&spi0_pdata);
imx31_add_spi_imx1(&spi1_pdata);
mc13783_dev.irq = gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO1_3));
spi_register_board_info(&mc13783_dev, 1);
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
smsc91x_resources[1].start =
gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO1_0));
smsc91x_resources[1].end =
gpio_to_irq(IOMUX_TO_GPIO(MX31_PIN_GPIO1_0));
platform_add_devices(devices, ARRAY_SIZE(devices));
lilly1131_usb_init();
}
static void __init mx31lilly_timer_init(void)
{
mx31_clocks_init(26000000);
}
