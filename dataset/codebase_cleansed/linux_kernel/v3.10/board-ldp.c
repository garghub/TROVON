static inline void __init ldp_init_smsc911x(void)
{
gpmc_smsc911x_init(&smsc911x_cfg);
}
static void __init ldp_display_init(void)
{
ldp_panel_data.gpios[2] = LCD_PANEL_RESET_GPIO;
ldp_panel_data.gpios[3] = LCD_PANEL_QVGA_GPIO;
omap_display_init(&ldp_dss_data);
}
static int ldp_twl_gpio_setup(struct device *dev, unsigned gpio, unsigned ngpio)
{
ldp_panel_data.gpios[0] = gpio + 7;
ldp_panel_data.gpio_invert[0] = true;
ldp_panel_data.gpios[1] = gpio + 15;
ldp_panel_data.gpio_invert[1] = true;
return 0;
}
static int __init omap_i2c_init(void)
{
omap3_pmic_get_config(&ldp_twldata,
TWL_COMMON_PDATA_USB | TWL_COMMON_PDATA_MADC, 0);
omap3_pmic_init("twl4030", &ldp_twldata);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 400, NULL, 0);
return 0;
}
static void __init omap_ldp_init(void)
{
regulator_register_fixed(0, dummy_supplies, ARRAY_SIZE(dummy_supplies));
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
ldp_init_smsc911x();
omap_i2c_init();
platform_add_devices(ldp_devices, ARRAY_SIZE(ldp_devices));
omap_ads7846_init(1, 54, 310, NULL);
omap_serial_init();
omap_sdrc_init(NULL, NULL);
usb_bind_phy("musb-hdrc.0.auto", 0, "twl4030_usb");
usb_musb_init(NULL);
board_nand_init(ldp_nand_partitions, ARRAY_SIZE(ldp_nand_partitions),
ZOOM_NAND_CS, 0, nand_default_timings);
omap_hsmmc_init(mmc);
ldp_display_init();
}
