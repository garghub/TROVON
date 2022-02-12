static void __init sffsdr_init_i2c(void)
{
davinci_init_i2c(&i2c_pdata);
i2c_register_board_info(1, i2c_info, ARRAY_SIZE(i2c_info));
}
static void __init davinci_sffsdr_map_io(void)
{
dm644x_init();
}
static __init void davinci_sffsdr_init(void)
{
struct davinci_soc_info *soc_info = &davinci_soc_info;
platform_add_devices(davinci_sffsdr_devices,
ARRAY_SIZE(davinci_sffsdr_devices));
sffsdr_init_i2c();
davinci_serial_init(&uart_config);
soc_info->emac_pdata->phy_id = SFFSDR_PHY_ID;
davinci_setup_usb(0, 0);
davinci_cfg_reg(DM644X_VLYNQEN);
davinci_cfg_reg(DM644X_VLYNQWD);
}
