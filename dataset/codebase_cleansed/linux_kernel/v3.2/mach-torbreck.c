static void __init torbreck_map_io(void)
{
s5p_init_io(NULL, 0, S5P_VA_CHIPID);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(torbreck_uartcfgs, ARRAY_SIZE(torbreck_uartcfgs));
s5p_set_timer_source(S5P_PWM3, S5P_PWM4);
}
static void __init torbreck_machine_init(void)
{
s3c_i2c0_set_platdata(NULL);
s3c_i2c1_set_platdata(NULL);
s3c_i2c2_set_platdata(NULL);
i2c_register_board_info(0, torbreck_i2c_devs0,
ARRAY_SIZE(torbreck_i2c_devs0));
i2c_register_board_info(1, torbreck_i2c_devs1,
ARRAY_SIZE(torbreck_i2c_devs1));
i2c_register_board_info(2, torbreck_i2c_devs2,
ARRAY_SIZE(torbreck_i2c_devs2));
platform_add_devices(torbreck_devices, ARRAY_SIZE(torbreck_devices));
}
