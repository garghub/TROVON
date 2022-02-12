static void __init am3517_crane_i2c_init(void)
{
omap_register_i2c_bus(1, 2600, tps65910_board_info,
ARRAY_SIZE(tps65910_board_info));
}
static void __init am3517_crane_init(void)
{
int ret;
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap_serial_init();
omap_sdrc_init(NULL, NULL);
board_nand_init(crane_nand_partitions,
ARRAY_SIZE(crane_nand_partitions), 0,
NAND_BUSWIDTH_16, NULL);
am3517_crane_i2c_init();
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
usbhs_init_phys(phy_data, ARRAY_SIZE(phy_data));
usbhs_init(&usbhs_bdata);
am35xx_emac_init(AM35XX_DEFAULT_MDIO_FREQUENCY, 1);
}
