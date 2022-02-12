static void __init rm680_i2c_init(void)
{
omap3_pmic_get_config(&rm680_twl_data, TWL_COMMON_PDATA_USB, 0);
omap_pmic_init(1, 2900, "twl5031", INT_34XX_SYS_NIRQ, &rm680_twl_data);
omap_register_i2c_bus(2, 400, NULL, 0);
omap_register_i2c_bus(3, 400, NULL, 0);
}
static void __init rm680_peripherals_init(void)
{
platform_add_devices(rm680_peripherals_devices,
ARRAY_SIZE(rm680_peripherals_devices));
rm680_i2c_init();
gpmc_onenand_init(board_onenand_data);
omap2_hsmmc_init(mmc);
}
static void __init rm680_init_early(void)
{
struct omap_sdrc_params *sdrc_params;
omap2_init_common_infrastructure();
sdrc_params = nokia_get_sdram_timings();
omap2_init_common_devices(sdrc_params, sdrc_params);
}
static void __init rm680_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap_serial_init();
usb_musb_init(NULL);
rm680_peripherals_init();
}
static void __init rm680_map_io(void)
{
omap2_set_globals_3xxx();
omap34xx_map_common_io();
}
