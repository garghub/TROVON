static void __init am3517_crane_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(NULL, NULL);
}
static void __init am3517_crane_init(void)
{
int ret;
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap_serial_init();
omap_board_config = am3517_crane_config;
omap_board_config_size = ARRAY_SIZE(am3517_crane_config);
if (omap_mux_init_gpio(GPIO_USB_NRESET, OMAP_PIN_OUTPUT)) {
pr_err("Can not configure mux for GPIO_USB_NRESET %d\n",
GPIO_USB_NRESET);
return;
}
if (omap_mux_init_gpio(GPIO_USB_POWER, OMAP_PIN_OUTPUT)) {
pr_err("Can not configure mux for GPIO_USB_POWER %d\n",
GPIO_USB_POWER);
return;
}
ret = gpio_request_one(GPIO_USB_POWER, GPIOF_OUT_INIT_HIGH,
"usb_ehci_enable");
if (ret < 0) {
pr_err("Can not request GPIO %d\n", GPIO_USB_POWER);
return;
}
usbhs_init(&usbhs_bdata);
}
