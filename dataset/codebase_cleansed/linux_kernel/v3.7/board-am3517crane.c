static void __init am3517_crane_init(void)
{
int ret;
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap_serial_init();
omap_sdrc_init(NULL, NULL);
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
am35xx_emac_init(AM35XX_DEFAULT_MDIO_FREQUENCY, 1);
}
