static int initialize_otg_port(struct platform_device *pdev)
{
u32 v;
void __iomem *usb_base;
void __iomem *usbother_base;
usb_base = ioremap(MX51_USB_OTG_BASE_ADDR, SZ_4K);
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
usb_base = ioremap(MX51_USB_OTG_BASE_ADDR, SZ_4K);
if (!usb_base)
return -ENOMEM;
usbother_base = usb_base + MX5_USBOTHER_REGS_OFFSET;
v = __raw_readl(usbother_base + MX51_USB_CTRL_1_OFFSET);
__raw_writel(v | MX51_USB_CTRL_UH1_EXT_CLK_EN, usbother_base + MX51_USB_CTRL_1_OFFSET);
iounmap(usb_base);
mdelay(10);
return mx51_initialize_usb_hw(1, MXC_EHCI_POWER_PINS_ENABLED |
MXC_EHCI_ITC_NO_THRESHOLD);
}
static int __init eukrea_cpuimx51_otg_mode(char *options)
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
static void __init eukrea_cpuimx51_init(void)
{
imx51_soc_init();
mxc_iomux_v3_setup_multiple_pads(eukrea_cpuimx51_pads,
ARRAY_SIZE(eukrea_cpuimx51_pads));
imx51_add_imx_uart(0, &uart_pdata);
imx51_add_mxc_nand(&eukrea_cpuimx51_nand_board_info);
gpio_request(CPUIMX51_QUARTA_GPIO, "quarta_irq");
gpio_direction_input(CPUIMX51_QUARTA_GPIO);
gpio_free(CPUIMX51_QUARTA_GPIO);
gpio_request(CPUIMX51_QUARTB_GPIO, "quartb_irq");
gpio_direction_input(CPUIMX51_QUARTB_GPIO);
gpio_free(CPUIMX51_QUARTB_GPIO);
gpio_request(CPUIMX51_QUARTC_GPIO, "quartc_irq");
gpio_direction_input(CPUIMX51_QUARTC_GPIO);
gpio_free(CPUIMX51_QUARTC_GPIO);
gpio_request(CPUIMX51_QUARTD_GPIO, "quartd_irq");
gpio_direction_input(CPUIMX51_QUARTD_GPIO);
gpio_free(CPUIMX51_QUARTD_GPIO);
imx51_add_fec(NULL);
platform_add_devices(devices, ARRAY_SIZE(devices));
imx51_add_imx_i2c(1, &eukrea_cpuimx51_i2c_data);
i2c_register_board_info(1, eukrea_cpuimx51_i2c_devices,
ARRAY_SIZE(eukrea_cpuimx51_i2c_devices));
if (otg_mode_host)
imx51_add_mxc_ehci_otg(&dr_utmi_config);
else {
initialize_otg_port(NULL);
imx51_add_fsl_usb2_udc(&usb_pdata);
}
imx51_add_mxc_ehci_hs(1, &usbh1_config);
#ifdef CONFIG_MACH_EUKREA_MBIMX51_BASEBOARD
eukrea_mbimx51_baseboard_init();
#endif
}
static void __init eukrea_cpuimx51_timer_init(void)
{
mx51_clocks_init(32768, 24000000, 22579200, 0);
}
