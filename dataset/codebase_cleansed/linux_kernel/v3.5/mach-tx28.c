static void __init tx28_stk5v3_init(void)
{
mx28_soc_init();
mxs_iomux_setup_multiple_pads(tx28_stk5v3_pads,
ARRAY_SIZE(tx28_stk5v3_pads));
mx28_add_duart();
mx28_add_auart(1);
tx28_add_fec0();
spi_register_board_info(tx28_spi_board_info,
ARRAY_SIZE(tx28_spi_board_info));
gpio_led_register_device(0, &tx28_stk5v3_led_data);
mx28_add_mxs_i2c(0);
i2c_register_board_info(0, tx28_stk5v3_i2c_boardinfo,
ARRAY_SIZE(tx28_stk5v3_i2c_boardinfo));
mx28_add_mxs_mmc(0, &tx28_mmc0_pdata);
mx28_add_rtc_stmp3xxx();
}
static void __init tx28_timer_init(void)
{
mx28_clocks_init();
}
