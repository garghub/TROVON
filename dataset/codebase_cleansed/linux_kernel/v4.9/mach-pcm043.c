static void pcm043_ac97_warm_reset(struct snd_ac97 *ac97)
{
iomux_v3_cfg_t txfs_gpio = MX35_PAD_STXFS4__GPIO2_31;
iomux_v3_cfg_t txfs = MX35_PAD_STXFS4__AUDMUX_AUD4_TXFS;
int ret;
ret = gpio_request(AC97_GPIO_TXFS, "SSI");
if (ret) {
printk("failed to get GPIO_TXFS: %d\n", ret);
return;
}
mxc_iomux_v3_setup_pad(txfs_gpio);
gpio_direction_output(AC97_GPIO_TXFS, 1);
udelay(2);
gpio_set_value(AC97_GPIO_TXFS, 0);
gpio_free(AC97_GPIO_TXFS);
mxc_iomux_v3_setup_pad(txfs);
}
static void pcm043_ac97_cold_reset(struct snd_ac97 *ac97)
{
iomux_v3_cfg_t txfs_gpio = MX35_PAD_STXFS4__GPIO2_31;
iomux_v3_cfg_t txfs = MX35_PAD_STXFS4__AUDMUX_AUD4_TXFS;
iomux_v3_cfg_t txd_gpio = MX35_PAD_STXD4__GPIO2_28;
iomux_v3_cfg_t txd = MX35_PAD_STXD4__AUDMUX_AUD4_TXD;
iomux_v3_cfg_t reset_gpio = MX35_PAD_SD2_CMD__GPIO2_0;
int ret;
ret = gpio_request(AC97_GPIO_TXFS, "SSI");
if (ret)
goto err1;
ret = gpio_request(AC97_GPIO_TXD, "SSI");
if (ret)
goto err2;
ret = gpio_request(AC97_GPIO_RESET, "SSI");
if (ret)
goto err3;
mxc_iomux_v3_setup_pad(txfs_gpio);
mxc_iomux_v3_setup_pad(txd_gpio);
mxc_iomux_v3_setup_pad(reset_gpio);
gpio_direction_output(AC97_GPIO_TXFS, 0);
gpio_direction_output(AC97_GPIO_TXD, 0);
gpio_direction_output(AC97_GPIO_RESET, 0);
udelay(10);
gpio_direction_output(AC97_GPIO_RESET, 1);
mxc_iomux_v3_setup_pad(txd);
mxc_iomux_v3_setup_pad(txfs);
gpio_free(AC97_GPIO_RESET);
err3:
gpio_free(AC97_GPIO_TXD);
err2:
gpio_free(AC97_GPIO_TXFS);
err1:
if (ret)
printk("%s failed with %d\n", __func__, ret);
mdelay(1);
}
static int pcm043_otg_init(struct platform_device *pdev)
{
return mx35_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int pcm043_usbh1_init(struct platform_device *pdev)
{
return mx35_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_SINGLE_UNI |
MXC_EHCI_INTERNAL_PHY | MXC_EHCI_IPPUE_DOWN);
}
static int __init pcm043_otg_mode(char *options)
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
static void __init pcm043_init(void)
{
imx35_soc_init();
mxc_iomux_v3_setup_multiple_pads(pcm043_pads, ARRAY_SIZE(pcm043_pads));
imx35_add_fec(NULL);
platform_add_devices(devices, ARRAY_SIZE(devices));
imx35_add_imx2_wdt();
imx35_add_imx_uart0(&uart_pdata);
imx35_add_mxc_nand(&pcm037_nand_board_info);
imx35_add_imx_uart1(&uart_pdata);
i2c_register_board_info(0, pcm043_i2c_devices,
ARRAY_SIZE(pcm043_i2c_devices));
imx35_add_imx_i2c0(&pcm043_i2c0_data);
imx35_add_ipu_core();
imx35_add_mx3_sdc_fb(&mx3fb_pdata);
if (otg_mode_host) {
otg_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (otg_pdata.otg)
imx35_add_mxc_ehci_otg(&otg_pdata);
}
imx35_add_mxc_ehci_hs(&usbh1_pdata);
if (!otg_mode_host)
imx35_add_fsl_usb2_udc(&otg_device_pdata);
imx35_add_flexcan1();
}
static void __init pcm043_late_init(void)
{
imx35_add_imx_ssi(0, &pcm043_ssi_pdata);
imx35_add_sdhci_esdhc_imx(0, &sd1_pdata);
}
static void __init pcm043_timer_init(void)
{
mx35_clocks_init();
}
