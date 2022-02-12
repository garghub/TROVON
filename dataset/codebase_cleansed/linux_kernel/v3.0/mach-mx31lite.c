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
void __init mx31lite_map_io(void)
{
mx31_map_io();
iotable_init(mx31lite_io_desc, ARRAY_SIZE(mx31lite_io_desc));
}
static void __init mx31lite_init(void)
{
int ret;
switch (mx31lite_baseboard) {
case MX31LITE_NOBOARD:
break;
case MX31LITE_DB:
mx31lite_db_init();
break;
default:
printk(KERN_ERR "Illegal mx31lite_baseboard type %d\n",
mx31lite_baseboard);
}
mxc_iomux_setup_multiple_pins(mx31lite_pins, ARRAY_SIZE(mx31lite_pins),
"mx31lite");
platform_device_register(&physmap_flash_device);
imx31_add_mxc_nand(&mx31lite_nand_board_info);
imx31_add_spi_imx1(&spi1_pdata);
spi_register_board_info(&mc13783_spi_dev, 1);
usbh2_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (usbh2_pdata.otg)
imx31_add_mxc_ehci_hs(2, &usbh2_pdata);
ret = gpio_request(IOMUX_TO_GPIO(MX31_PIN_SFS6), "sms9117-irq");
if (ret)
pr_warning("could not get LAN irq gpio\n");
else {
gpio_direction_input(IOMUX_TO_GPIO(MX31_PIN_SFS6));
platform_device_register(&smsc911x_device);
}
}
static void __init mx31lite_timer_init(void)
{
mx31_clocks_init(26000000);
}
