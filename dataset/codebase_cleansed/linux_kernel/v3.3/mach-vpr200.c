static int vpr200_usbh_init(struct platform_device *pdev)
{
return mx35_initialize_usb_hw(pdev->id,
MXC_EHCI_INTERFACE_SINGLE_UNI | MXC_EHCI_INTERNAL_PHY);
}
static void __init vpr200_board_init(void)
{
imx35_soc_init();
mxc_iomux_v3_setup_multiple_pads(vpr200_pads, ARRAY_SIZE(vpr200_pads));
imx35_add_fec(NULL);
imx35_add_imx2_wdt(NULL);
imx_add_gpio_keys(&vpr200_gpio_keys_data);
platform_add_devices(devices, ARRAY_SIZE(devices));
if (0 != gpio_request(GPIO_LCDPWR, "LCDPWR"))
printk(KERN_WARNING "vpr200: Couldn't get LCDPWR gpio\n");
else
gpio_direction_output(GPIO_LCDPWR, 0);
if (0 != gpio_request(GPIO_PMIC_INT, "PMIC_INT"))
printk(KERN_WARNING "vpr200: Couldn't get PMIC_INT gpio\n");
else
gpio_direction_input(GPIO_PMIC_INT);
imx35_add_imx_uart0(NULL);
imx35_add_imx_uart2(NULL);
imx35_add_ipu_core(&mx3_ipu_data);
imx35_add_mx3_sdc_fb(&mx3fb_pdata);
imx35_add_fsl_usb2_udc(&otg_device_pdata);
imx35_add_mxc_ehci_hs(&usb_host_pdata);
imx35_add_mxc_nand(&vpr200_nand_board_info);
imx35_add_sdhci_esdhc_imx(0, NULL);
i2c_register_board_info(0, vpr200_i2c_devices,
ARRAY_SIZE(vpr200_i2c_devices));
imx35_add_imx_i2c0(&vpr200_i2c0_data);
}
static void __init vpr200_timer_init(void)
{
mx35_clocks_init();
}
