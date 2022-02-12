static void __init smdk6450_map_io(void)
{
s5p_init_io(NULL, 0, S5P64X0_SYS_ID);
s3c24xx_init_clocks(19200000);
s3c24xx_init_uarts(smdk6450_uartcfgs, ARRAY_SIZE(smdk6450_uartcfgs));
s5p_set_timer_source(S5P_PWM3, S5P_PWM4);
}
static void __init smdk6450_machine_init(void)
{
s3c24xx_ts_set_platdata(&s3c_ts_platform);
s3c_i2c0_set_platdata(&s5p6450_i2c0_data);
s3c_i2c1_set_platdata(&s5p6450_i2c1_data);
i2c_register_board_info(0, smdk6450_i2c_devs0,
ARRAY_SIZE(smdk6450_i2c_devs0));
i2c_register_board_info(1, smdk6450_i2c_devs1,
ARRAY_SIZE(smdk6450_i2c_devs1));
samsung_bl_set(&smdk6450_bl_gpio_info, &smdk6450_bl_data);
platform_add_devices(smdk6450_devices, ARRAY_SIZE(smdk6450_devices));
}
