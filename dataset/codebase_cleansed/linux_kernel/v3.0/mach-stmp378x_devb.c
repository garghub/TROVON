static void __init stmp378x_dvb_init(void)
{
int ret;
mxs_iomux_setup_multiple_pads(stmp378x_dvb_pads,
ARRAY_SIZE(stmp378x_dvb_pads));
mx23_add_duart();
mx23_add_auart0();
ret = gpio_request_one(STMP378X_DEVB_MMC0_SLOT_POWER,
GPIOF_OUT_INIT_LOW, "mmc0-slot-power");
if (ret)
pr_warn("could not power mmc (%d)\n", ret);
mx23_add_mxs_mmc(0, &stmp378x_dvb_mmc_pdata);
spi_register_board_info(spi_board_info, ARRAY_SIZE(spi_board_info));
}
static void __init stmp378x_dvb_timer_init(void)
{
mx23_clocks_init();
}
