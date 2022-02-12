static void __init genmai_add_standard_devices(void)
{
r7s72100_clock_init();
r7s72100_add_dt_devices();
platform_device_register_full(&ether_info);
r7s72100_register_rspi(0);
r7s72100_register_rspi(1);
r7s72100_register_rspi(2);
r7s72100_register_rspi(3);
r7s72100_register_rspi(4);
spi_register_board_info(spi_info, ARRAY_SIZE(spi_info));
}
