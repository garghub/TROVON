static void __init tx28_stk5v3_init(void)
{
mxs_iomux_setup_multiple_pads(tx28_stk5v3_pads,
ARRAY_SIZE(tx28_stk5v3_pads));
mx28_add_duart();
mx28_add_auart(1);
tx28_add_fec0();
spi_register_board_info(tx28_spi_board_info,
ARRAY_SIZE(tx28_spi_board_info));
mxs_add_platform_device("leds-gpio", 0, NULL, 0,
&tx28_stk5v3_led_data, sizeof(tx28_stk5v3_led_data));
mx28_add_mxs_i2c(0);
i2c_register_board_info(0, tx28_stk5v3_i2c_boardinfo,
ARRAY_SIZE(tx28_stk5v3_i2c_boardinfo));
}
static void __init tx28_timer_init(void)
{
mx28_clocks_init();
}
