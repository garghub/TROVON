static int gpio_usbh1_active(void)
{
iomux_v3_cfg_t usbh1stp_gpio = MX51_PAD_USBH1_STP__GPIO1_27;
int ret;
mxc_iomux_v3_setup_pad(usbh1stp_gpio);
ret = gpio_request_array(mx51_babbage_usbh1_gpios,
ARRAY_SIZE(mx51_babbage_usbh1_gpios));
if (ret) {
pr_debug("failed to get USBH1 pins: %d\n", ret);
return ret;
}
msleep(100);
gpio_set_value(BABBAGE_USBH1_STP, 1);
gpio_set_value(BABBAGE_USB_PHY_RESET, 1);
gpio_free_array(mx51_babbage_usbh1_gpios,
ARRAY_SIZE(mx51_babbage_usbh1_gpios));
return 0;
}
static inline void babbage_usbhub_reset(void)
{
int ret;
ret = gpio_request_one(BABBAGE_USB_HUB_RESET,
GPIOF_OUT_INIT_LOW, "GPIO1_7");
if (ret) {
printk(KERN_ERR"failed to get GPIO_USB_HUB_RESET: %d\n", ret);
return;
}
msleep(2);
gpio_set_value(BABBAGE_USB_HUB_RESET, 1);
}
static inline void babbage_fec_reset(void)
{
int ret;
ret = gpio_request_one(BABBAGE_FEC_PHY_RESET,
GPIOF_OUT_INIT_LOW, "fec-phy-reset");
if (ret) {
printk(KERN_ERR"failed to get GPIO_FEC_PHY_RESET: %d\n", ret);
return;
}
msleep(1);
gpio_set_value(BABBAGE_FEC_PHY_RESET, 1);
}
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
static int __init babbage_otg_mode(char *options)
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
void __init imx51_babbage_common_init(void)
{
mxc_iomux_v3_setup_multiple_pads(mx51babbage_pads,
ARRAY_SIZE(mx51babbage_pads));
}
static void __init mx51_babbage_init(void)
{
iomux_v3_cfg_t usbh1stp = MX51_PAD_USBH1_STP__USBH1_STP;
iomux_v3_cfg_t power_key = NEW_PAD_CTRL(MX51_PAD_EIM_A27__GPIO2_21,
PAD_CTL_SRE_FAST | PAD_CTL_DSE_HIGH);
imx51_soc_init();
#if defined(CONFIG_CPU_FREQ_IMX)
get_cpu_op = mx51_get_cpu_op;
#endif
imx51_babbage_common_init();
imx51_add_imx_uart(0, &uart_pdata);
imx51_add_imx_uart(1, NULL);
imx51_add_imx_uart(2, &uart_pdata);
babbage_fec_reset();
imx51_add_fec(NULL);
mxc_iomux_v3_setup_pad(power_key);
imx_add_gpio_keys(&imx_button_data);
imx51_add_imx_i2c(0, &babbage_i2c_data);
imx51_add_imx_i2c(1, &babbage_i2c_data);
imx51_add_hsi2c(&babbage_hsi2c_data);
if (otg_mode_host)
imx51_add_mxc_ehci_otg(&dr_utmi_config);
else {
initialize_otg_port(NULL);
imx51_add_fsl_usb2_udc(&usb_pdata);
}
gpio_usbh1_active();
imx51_add_mxc_ehci_hs(1, &usbh1_config);
mxc_iomux_v3_setup_pad(usbh1stp);
babbage_usbhub_reset();
imx51_add_sdhci_esdhc_imx(0, &mx51_babbage_sd1_data);
imx51_add_sdhci_esdhc_imx(1, &mx51_babbage_sd2_data);
spi_register_board_info(mx51_babbage_spi_board_info,
ARRAY_SIZE(mx51_babbage_spi_board_info));
imx51_add_ecspi(0, &mx51_babbage_spi_pdata);
imx51_add_imx2_wdt(0, NULL);
}
static void __init mx51_babbage_timer_init(void)
{
mx51_clocks_init(32768, 24000000, 22579200, 0);
}
