static int eukrea_cpuimx35_otg_init(struct platform_device *pdev)
{
return mx35_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int eukrea_cpuimx35_usbh1_init(struct platform_device *pdev)
{
return mx35_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_SINGLE_UNI |
MXC_EHCI_INTERNAL_PHY | MXC_EHCI_IPPUE_DOWN);
}
static int __init eukrea_cpuimx35_otg_mode(char *options)
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
static void __init eukrea_cpuimx35_init(void)
{
imx35_soc_init();
mxc_iomux_v3_setup_multiple_pads(eukrea_cpuimx35_pads,
ARRAY_SIZE(eukrea_cpuimx35_pads));
imx35_add_fec(NULL);
imx35_add_imx2_wdt(NULL);
imx35_add_imx_uart0(&uart_pdata);
imx35_add_mxc_nand(&eukrea_cpuimx35_nand_board_info);
i2c_register_board_info(0, eukrea_cpuimx35_i2c_devices,
ARRAY_SIZE(eukrea_cpuimx35_i2c_devices));
imx35_add_imx_i2c0(&eukrea_cpuimx35_i2c0_data);
if (otg_mode_host)
imx35_add_mxc_ehci_otg(&otg_pdata);
else
imx35_add_fsl_usb2_udc(&otg_device_pdata);
imx35_add_mxc_ehci_hs(&usbh1_pdata);
#ifdef CONFIG_MACH_EUKREA_MBIMXSD35_BASEBOARD
eukrea_mbimxsd35_baseboard_init();
#endif
}
static void __init eukrea_cpuimx35_timer_init(void)
{
mx35_clocks_init();
}
