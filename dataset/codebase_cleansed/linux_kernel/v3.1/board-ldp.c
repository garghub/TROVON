static inline void __init ldp_init_smsc911x(void)
{
gpmc_smsc911x_init(&smsc911x_cfg);
}
static void __init omap_ldp_init_early(void)
{
omap2_init_common_infrastructure();
omap2_init_common_devices(NULL, NULL);
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
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap_board_config = ldp_config;
omap_board_config_size = ARRAY_SIZE(ldp_config);
ldp_init_smsc911x();
omap_i2c_init();
platform_add_devices(ldp_devices, ARRAY_SIZE(ldp_devices));
omap_ads7846_init(1, 54, 310, NULL);
omap_serial_init();
usb_musb_init(NULL);
board_nand_init(ldp_nand_partitions,
ARRAY_SIZE(ldp_nand_partitions), ZOOM_NAND_CS, 0);
omap2_hsmmc_init(mmc);
}
