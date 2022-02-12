static int initialize_otg_port(struct platform_device *pdev)
{
u32 v;
void __iomem *usb_base;
void __iomem *usbother_base;
usb_base = ioremap(MX51_OTG_BASE_ADDR, SZ_4K);
if (!usb_base)
return -ENOMEM;
usbother_base = (void __iomem *)(usb_base + MX5_USBOTHER_REGS_OFFSET);
v = __raw_readl(usbother_base + MXC_USB_PHY_CTR_FUNC2_OFFSET);
v &= ~MX5_USB_UTMI_PHYCTRL1_PLLDIV_MASK;
v |= MX51_USB_PLL_DIV_19_2_MHZ;
__raw_writel(v, usbother_base + MXC_USB_PHY_CTR_FUNC2_OFFSET);
iounmap(usb_base);
mdelay(10);
return mx51_initialize_usb_hw(pdev->id, MXC_EHCI_INTERNAL_PHY);
}
static int initialize_usbh1_port(struct platform_device *pdev)
{
iomux_v3_cfg_t usbh1stp = MX51_PAD_USBH1_STP__USBH1_STP;
iomux_v3_cfg_t usbh1gpio = MX51_PAD_USBH1_STP__GPIO1_27;
u32 v;
void __iomem *usb_base;
void __iomem *socregs_base;
mxc_iomux_v3_setup_pad(usbh1gpio);
gpio_request(EFIKAMX_USBH1_STP, "usbh1_stp");
gpio_direction_output(EFIKAMX_USBH1_STP, 0);
msleep(1);
gpio_set_value(EFIKAMX_USBH1_STP, 1);
msleep(1);
usb_base = ioremap(MX51_OTG_BASE_ADDR, SZ_4K);
socregs_base = (void __iomem *)(usb_base + MX5_USBOTHER_REGS_OFFSET);
v = __raw_readl(socregs_base + MX51_USB_CTRL_1_OFFSET);
__raw_writel(v | MX51_USB_CTRL_UH1_EXT_CLK_EN,
socregs_base + MX51_USB_CTRL_1_OFFSET);
iounmap(usb_base);
gpio_free(EFIKAMX_USBH1_STP);
mxc_iomux_v3_setup_pad(usbh1stp);
mdelay(10);
return mx51_initialize_usb_hw(pdev->id, MXC_EHCI_ITC_NO_THRESHOLD);
}
static void mx51_efika_hubreset(void)
{
gpio_request(EFIKAMX_USB_HUB_RESET, "usb_hub_rst");
gpio_direction_output(EFIKAMX_USB_HUB_RESET, 1);
msleep(1);
gpio_set_value(EFIKAMX_USB_HUB_RESET, 0);
msleep(1);
gpio_set_value(EFIKAMX_USB_HUB_RESET, 1);
}
static void __init mx51_efika_usb(void)
{
mx51_efika_hubreset();
gpio_request(EFIKA_USB_PHY_RESET, "usb_phy_reset");
gpio_direction_output(EFIKA_USB_PHY_RESET, 0);
msleep(1);
gpio_set_value(EFIKA_USB_PHY_RESET, 1);
usbh1_config.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT | ULPI_OTG_EXTVBUSIND);
mxc_register_device(&mxc_usbdr_host_device, &dr_utmi_config);
if (usbh1_config.otg)
mxc_register_device(&mxc_usbh1_device, &usbh1_config);
}
void __init efika_board_common_init(void)
{
mxc_iomux_v3_setup_multiple_pads(mx51efika_pads,
ARRAY_SIZE(mx51efika_pads));
imx51_add_imx_uart(0, &uart_pdata);
mx51_efika_usb();
imx51_add_sdhci_esdhc_imx(0, NULL);
if (mx51_revision() < IMX_CHIP_REVISION_2_0)
sw2_init.constraints.state_mem.uV = 1100000;
else if (mx51_revision() == IMX_CHIP_REVISION_2_0) {
sw2_init.constraints.state_mem.uV = 1250000;
sw1_init.constraints.state_mem.uV = 1000000;
}
if (machine_is_mx51_efikasb())
vgen1_init.constraints.max_uV = 1200000;
gpio_request(EFIKAMX_PMIC, "pmic irq");
gpio_direction_input(EFIKAMX_PMIC);
spi_register_board_info(mx51_efika_spi_board_info,
ARRAY_SIZE(mx51_efika_spi_board_info));
imx51_add_ecspi(0, &mx51_efika_spi_pdata);
#if defined(CONFIG_CPU_FREQ_IMX)
get_cpu_op = mx51_get_cpu_op;
#endif
}
