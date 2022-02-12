static int eukrea_cpuimx25_otg_init(struct platform_device *pdev)
{
return mx25_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int eukrea_cpuimx25_usbh2_init(struct platform_device *pdev)
{
return mx25_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_SINGLE_UNI |
MXC_EHCI_INTERNAL_PHY | MXC_EHCI_IPPUE_DOWN);
}
static int __init eukrea_cpuimx25_otg_mode(char *options)
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
static void __init eukrea_cpuimx25_init(void)
{
if (mxc_iomux_v3_setup_multiple_pads(eukrea_cpuimx25_pads,
ARRAY_SIZE(eukrea_cpuimx25_pads)))
printk(KERN_ERR "error setting cpuimx25 pads !\n");
imx25_add_imx_uart0(&uart_pdata);
imx25_add_mxc_nand(&eukrea_cpuimx25_nand_board_info);
imx25_add_imxdi_rtc(NULL);
imx25_add_fec(&mx25_fec_pdata);
i2c_register_board_info(0, eukrea_cpuimx25_i2c_devices,
ARRAY_SIZE(eukrea_cpuimx25_i2c_devices));
imx25_add_imx_i2c0(&eukrea_cpuimx25_i2c0_data);
if (otg_mode_host)
imx25_add_mxc_ehci_otg(&otg_pdata);
else
imx25_add_fsl_usb2_udc(&otg_device_pdata);
imx25_add_mxc_ehci_hs(&usbh2_pdata);
#ifdef CONFIG_MACH_EUKREA_MBIMXSD25_BASEBOARD
eukrea_mbimxsd25_baseboard_init();
#endif
}
static void __init eukrea_cpuimx25_timer_init(void)
{
mx25_clocks_init();
}
