static void vr1000_power_off(void)
{
gpio_direction_output(S3C2410_GPB(9), 1);
}
static void __init vr1000_map_io(void)
{
pm_power_off = vr1000_power_off;
s3c24xx_init_io(vr1000_iodesc, ARRAY_SIZE(vr1000_iodesc));
s3c24xx_init_uarts(vr1000_uartcfgs, ARRAY_SIZE(vr1000_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init vr1000_init_time(void)
{
s3c2410_init_clocks(12000000);
samsung_timer_init();
}
static void __init vr1000_init(void)
{
s3c_i2c0_set_platdata(NULL);
platform_add_devices(vr1000_devices, ARRAY_SIZE(vr1000_devices));
i2c_register_board_info(0, vr1000_i2c_devs,
ARRAY_SIZE(vr1000_i2c_devs));
nor_simtec_init();
simtec_audio_add(NULL, true, NULL);
WARN_ON(gpio_request(S3C2410_GPB(9), "power off"));
}
