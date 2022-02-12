static void __init mx25pdk_fec_reset(void)
{
gpio_request(FEC_ENABLE_GPIO, "FEC PHY enable");
gpio_request(FEC_RESET_B_GPIO, "FEC PHY reset");
gpio_direction_output(FEC_ENABLE_GPIO, 0);
gpio_direction_output(FEC_RESET_B_GPIO, 0);
udelay(2);
gpio_set_value(FEC_ENABLE_GPIO, 1);
gpio_set_value(FEC_RESET_B_GPIO, 1);
}
static int mx25pdk_usbh2_init(struct platform_device *pdev)
{
return mx25_initialize_usb_hw(pdev->id, MXC_EHCI_INTERNAL_PHY);
}
static void __init mx25pdk_init(void)
{
imx25_soc_init();
mxc_iomux_v3_setup_multiple_pads(mx25pdk_pads,
ARRAY_SIZE(mx25pdk_pads));
imx25_add_imx_uart0(&uart_pdata);
imx25_add_fsl_usb2_udc(&otg_device_pdata);
imx25_add_mxc_ehci_hs(&usbh2_pdata);
imx25_add_mxc_nand(&mx25pdk_nand_board_info);
imx25_add_imxdi_rtc(NULL);
imx25_add_imx_fb(&mx25pdk_fb_pdata);
imx25_add_imx2_wdt(NULL);
mx25pdk_fec_reset();
imx25_add_fec(&mx25_fec_pdata);
imx25_add_imx_keypad(&mx25pdk_keymap_data);
imx25_add_sdhci_esdhc_imx(0, &mx25pdk_esdhc_pdata);
imx25_add_imx_i2c0(&mx25_3ds_i2c0_data);
gpio_request_one(MX25PDK_CAN_PWDN, GPIOF_OUT_INIT_LOW, "can-pwdn");
imx25_add_flexcan0(NULL);
}
static void __init mx25pdk_timer_init(void)
{
mx25_clocks_init();
}
