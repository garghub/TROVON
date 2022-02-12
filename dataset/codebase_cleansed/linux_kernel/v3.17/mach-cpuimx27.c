static int eukrea_cpuimx27_otg_init(struct platform_device *pdev)
{
return mx27_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int eukrea_cpuimx27_usbh2_init(struct platform_device *pdev)
{
return mx27_initialize_usb_hw(pdev->id, MXC_EHCI_INTERFACE_DIFF_UNI);
}
static int __init eukrea_cpuimx27_otg_mode(char *options)
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
static void __init eukrea_cpuimx27_init(void)
{
imx27_soc_init();
mxc_gpio_setup_multiple_pins(eukrea_cpuimx27_pins,
ARRAY_SIZE(eukrea_cpuimx27_pins), "CPUIMX27");
imx27_add_imx_uart0(&uart_pdata);
imx27_add_mxc_nand(&cpuimx27_nand_board_info);
i2c_register_board_info(0, eukrea_cpuimx27_i2c_devices,
ARRAY_SIZE(eukrea_cpuimx27_i2c_devices));
imx27_add_imx_i2c(0, &cpuimx27_i2c1_data);
imx27_add_fec(NULL);
platform_add_devices(platform_devices, ARRAY_SIZE(platform_devices));
imx27_add_imx2_wdt();
imx27_add_mxc_w1();
#if defined(CONFIG_MACH_EUKREA_CPUIMX27_USESDHC2)
imx27_add_mxc_mmc(1, NULL);
#endif
#if defined(CONFIG_MACH_EUKREA_CPUIMX27_USEUART4)
imx27_add_imx_uart3(&uart_pdata);
#endif
#if defined(CONFIG_SERIAL_8250) || defined(CONFIG_SERIAL_8250_MODULE)
serial_platform_data[0].irq = IMX_GPIO_NR(2, 23);
serial_platform_data[1].irq = IMX_GPIO_NR(2, 22);
serial_platform_data[2].irq = IMX_GPIO_NR(2, 27);
serial_platform_data[3].irq = IMX_GPIO_NR(2, 30);
platform_device_register(&serial_device);
#endif
if (otg_mode_host) {
otg_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (otg_pdata.otg)
imx27_add_mxc_ehci_otg(&otg_pdata);
} else {
imx27_add_fsl_usb2_udc(&otg_device_pdata);
}
usbh2_pdata.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT);
if (usbh2_pdata.otg)
imx27_add_mxc_ehci_hs(2, &usbh2_pdata);
#ifdef CONFIG_MACH_EUKREA_MBIMX27_BASEBOARD
eukrea_mbimx27_baseboard_init();
#endif
}
static void __init eukrea_cpuimx27_timer_init(void)
{
mx27_clocks_init(26000000);
}
