static int mx35_3ds_otg_init(struct platform_device *pdev)
{
return mx35_initialize_usb_hw(pdev->id, MXC_EHCI_INTERNAL_PHY);
}
static int mx35_3ds_usbh_init(struct platform_device *pdev)
{
return mx35_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_SINGLE_UNI |
MXC_EHCI_INTERNAL_PHY);
}
static int __init mx35_3ds_otg_mode(char *options)
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
static void __init mx35_3ds_init(void)
{
imx35_soc_init();
mxc_iomux_v3_setup_multiple_pads(mx35pdk_pads, ARRAY_SIZE(mx35pdk_pads));
imx35_add_fec(NULL);
imx35_add_imx2_wdt(NULL);
platform_add_devices(devices, ARRAY_SIZE(devices));
imx35_add_imx_uart0(&uart_pdata);
if (otg_mode_host)
imx35_add_mxc_ehci_otg(&otg_pdata);
imx35_add_mxc_ehci_hs(&usb_host_pdata);
if (!otg_mode_host)
imx35_add_fsl_usb2_udc(&usb_otg_pdata);
imx35_add_mxc_nand(&mx35pdk_nand_board_info);
imx35_add_sdhci_esdhc_imx(0, NULL);
if (mxc_expio_init(MX35_CS5_BASE_ADDR, EXPIO_PARENT_INT))
pr_warn("Init of the debugboard failed, all "
"devices on the debugboard are unusable.\n");
imx35_add_imx_i2c0(&mx35_3ds_i2c0_data);
}
static void __init mx35pdk_timer_init(void)
{
mx35_clocks_init();
}
