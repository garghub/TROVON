static int initialize_otg_port(struct platform_device *pdev)
{
u32 v;
void __iomem *usb_base;
void __iomem *usbother_base;
usb_base = ioremap(MX51_OTG_BASE_ADDR, SZ_4K);
if (!usb_base)
return -ENOMEM;
usbother_base = usb_base + MX5_USBOTHER_REGS_OFFSET;
v = __raw_readl(usbother_base + MXC_USB_PHY_CTR_FUNC2_OFFSET);
v &= ~MX5_USB_UTMI_PHYCTRL1_PLLDIV_MASK;
v |= MX51_USB_PLL_DIV_19_2_MHZ;
__raw_writel(v, usbother_base + MXC_USB_PHY_CTR_FUNC2_OFFSET);
iounmap(usb_base);
mdelay(10);
return mx51_initialize_usb_hw(0, MXC_EHCI_INTERNAL_PHY);
}
static int initialize_usbh1_port(struct platform_device *pdev)
{
u32 v;
void __iomem *usb_base;
void __iomem *usbother_base;
usb_base = ioremap(MX51_OTG_BASE_ADDR, SZ_4K);
if (!usb_base)
return -ENOMEM;
usbother_base = usb_base + MX5_USBOTHER_REGS_OFFSET;
v = __raw_readl(usbother_base + MX51_USB_CTRL_1_OFFSET);
__raw_writel(v | MX51_USB_CTRL_UH1_EXT_CLK_EN,
usbother_base + MX51_USB_CTRL_1_OFFSET);
iounmap(usb_base);
mdelay(10);
return mx51_initialize_usb_hw(1, MXC_EHCI_POWER_PINS_ENABLED |
MXC_EHCI_ITC_NO_THRESHOLD);
}
static int __init eukrea_cpuimx51sd_otg_mode(char *options)
{
if (!strcmp(options, "host"))
otg_mode_host = 1;
else if (!strcmp(options, "device"))
otg_mode_host = 0;
else
pr_info("otg_mode neither \"host\" nor \"device\". "
"Defaulting to device\n");
return 0;
}
static void __init eukrea_cpuimx51sd_init(void)
{
mxc_iomux_v3_setup_multiple_pads(eukrea_cpuimx51sd_pads,
ARRAY_SIZE(eukrea_cpuimx51sd_pads));
#if defined(CONFIG_CPU_FREQ_IMX)
get_cpu_op = mx51_get_cpu_op;
#endif
imx51_add_imx_uart(0, &uart_pdata);
imx51_add_mxc_nand(&eukrea_cpuimx51sd_nand_board_info);
gpio_request(ETH_RST, "eth_rst");
gpio_set_value(ETH_RST, 1);
imx51_add_fec(NULL);
gpio_request(CAN_IRQGPIO, "can_irq");
gpio_direction_input(CAN_IRQGPIO);
gpio_free(CAN_IRQGPIO);
gpio_request(CAN_NCS, "can_ncs");
gpio_direction_output(CAN_NCS, 1);
gpio_free(CAN_NCS);
gpio_request(CAN_RST, "can_rst");
gpio_direction_output(CAN_RST, 0);
msleep(20);
gpio_set_value(CAN_RST, 1);
imx51_add_ecspi(0, &cpuimx51sd_ecspi1_pdata);
spi_register_board_info(cpuimx51sd_spi_device,
ARRAY_SIZE(cpuimx51sd_spi_device));
gpio_request(TSC2007_IRQGPIO, "tsc2007_irq");
gpio_direction_input(TSC2007_IRQGPIO);
gpio_free(TSC2007_IRQGPIO);
i2c_register_board_info(0, eukrea_cpuimx51sd_i2c_devices,
ARRAY_SIZE(eukrea_cpuimx51sd_i2c_devices));
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
if (otg_mode_host)
mxc_register_device(&mxc_usbdr_host_device, &dr_utmi_config);
else {
initialize_otg_port(NULL);
mxc_register_device(&mxc_usbdr_udc_device, &usb_pdata);
}
gpio_request(USBH1_RST, "usb_rst");
gpio_direction_output(USBH1_RST, 0);
msleep(20);
gpio_set_value(USBH1_RST, 1);
mxc_register_device(&mxc_usbh1_device, &usbh1_config);
#ifdef CONFIG_MACH_EUKREA_MBIMXSD51_BASEBOARD
eukrea_mbimxsd51_baseboard_init();
#endif
}
static void __init eukrea_cpuimx51sd_timer_init(void)
{
mx51_clocks_init(32768, 24000000, 22579200, 0);
}
