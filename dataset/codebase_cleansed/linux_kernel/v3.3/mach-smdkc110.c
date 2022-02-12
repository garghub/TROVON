static void __init smdkc110_map_io(void)
{
s5pv210_init_io(NULL, 0);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(smdkv210_uartcfgs, ARRAY_SIZE(smdkv210_uartcfgs));
s5p_set_timer_source(S5P_PWM3, S5P_PWM4);
}
static void __init smdkc110_machine_init(void)
{
s3c_pm_init();
s3c_i2c0_set_platdata(NULL);
s3c_i2c1_set_platdata(NULL);
s3c_i2c2_set_platdata(NULL);
i2c_register_board_info(0, smdkc110_i2c_devs0,
ARRAY_SIZE(smdkc110_i2c_devs0));
i2c_register_board_info(1, smdkc110_i2c_devs1,
ARRAY_SIZE(smdkc110_i2c_devs1));
i2c_register_board_info(2, smdkc110_i2c_devs2,
ARRAY_SIZE(smdkc110_i2c_devs2));
s3c_ide_set_platdata(&smdkc110_ide_pdata);
platform_add_devices(smdkc110_devices, ARRAY_SIZE(smdkc110_devices));
}
