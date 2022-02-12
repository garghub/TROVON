static int initialize_usbh2_port(struct platform_device *pdev)
{
iomux_v3_cfg_t usbh2stp = MX51_PAD_EIM_A26__USBH2_STP;
iomux_v3_cfg_t usbh2gpio = MX51_PAD_EIM_A26__GPIO2_20;
mxc_iomux_v3_setup_pad(usbh2gpio);
gpio_request(EFIKASB_USBH2_STP, "usbh2_stp");
gpio_direction_output(EFIKASB_USBH2_STP, 0);
msleep(1);
gpio_set_value(EFIKASB_USBH2_STP, 1);
msleep(1);
gpio_free(EFIKASB_USBH2_STP);
mxc_iomux_v3_setup_pad(usbh2stp);
mdelay(10);
return mx51_initialize_usb_hw(pdev->id, MXC_EHCI_ITC_NO_THRESHOLD);
}
static void __init mx51_efikasb_usb(void)
{
usbh2_config.otg = imx_otg_ulpi_create(ULPI_OTG_DRVVBUS |
ULPI_OTG_DRVVBUS_EXT | ULPI_OTG_EXTVBUSIND);
if (usbh2_config.otg)
imx51_add_mxc_ehci_hs(2, &usbh2_config);
}
static void mx51_efikasb_power_off(void)
{
gpio_set_value(EFIKA_USB_PHY_RESET, 0);
if (!IS_ERR(pwgt1) && !IS_ERR(pwgt2)) {
regulator_disable(pwgt2);
regulator_disable(pwgt1);
}
gpio_direction_output(EFIKASB_POWEROFF, 1);
}
static int __init mx51_efikasb_power_init(void)
{
pwgt1 = regulator_get(NULL, "pwgt1");
pwgt2 = regulator_get(NULL, "pwgt2");
if (!IS_ERR(pwgt1) && !IS_ERR(pwgt2)) {
regulator_enable(pwgt1);
regulator_enable(pwgt2);
}
gpio_request(EFIKASB_POWEROFF, "poweroff");
pm_power_off = mx51_efikasb_power_off;
regulator_has_full_constraints();
return 0;
}
static void __init mx51_efikasb_init_late(void)
{
imx51_init_late();
mx51_efikasb_power_init();
}
static void __init mx51_efikasb_board_id(void)
{
int id;
gpio_request(EFIKASB_PCBID0, "pcb id0");
gpio_direction_input(EFIKASB_PCBID0);
gpio_request(EFIKASB_PCBID1, "pcb id1");
gpio_direction_input(EFIKASB_PCBID1);
id = gpio_get_value(EFIKASB_PCBID0) ? 1 : 0;
id |= (gpio_get_value(EFIKASB_PCBID1) ? 1 : 0) << 1;
switch (id) {
default:
break;
case 1:
system_rev = 0x13;
break;
case 2:
system_rev = 0x20;
break;
}
}
static void __init efikasb_board_init(void)
{
imx51_soc_init();
mxc_iomux_v3_setup_multiple_pads(mx51efikasb_pads,
ARRAY_SIZE(mx51efikasb_pads));
efika_board_common_init();
mx51_efikasb_board_id();
mx51_efikasb_usb();
imx51_add_sdhci_esdhc_imx(0, &sd0_pdata);
imx51_add_sdhci_esdhc_imx(1, &sd1_pdata);
gpio_led_register_device(-1, &mx51_efikasb_leds_data);
imx_add_gpio_keys(&mx51_efikasb_keys_data);
}
static void __init mx51_efikasb_timer_init(void)
{
mx51_clocks_init(32768, 24000000, 22579200, 24576000);
}
