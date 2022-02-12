static int smdk6440_backlight_init(struct device *dev)
{
int ret;
ret = gpio_request(S5P6440_GPF(15), "Backlight");
if (ret) {
printk(KERN_ERR "failed to request GPF for PWM-OUT1\n");
return ret;
}
s3c_gpio_cfgpin(S5P6440_GPF(15), S3C_GPIO_SFN(2));
return 0;
}
static void smdk6440_backlight_exit(struct device *dev)
{
s3c_gpio_cfgpin(S5P6440_GPF(15), S3C_GPIO_OUTPUT);
gpio_free(S5P6440_GPF(15));
}
static void __init smdk6440_map_io(void)
{
s5p_init_io(NULL, 0, S5P64X0_SYS_ID);
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(smdk6440_uartcfgs, ARRAY_SIZE(smdk6440_uartcfgs));
s5p_set_timer_source(S5P_PWM3, S5P_PWM4);
}
static void __init smdk6440_machine_init(void)
{
s3c24xx_ts_set_platdata(&s3c_ts_platform);
s3c_i2c0_set_platdata(&s5p6440_i2c0_data);
s3c_i2c1_set_platdata(&s5p6440_i2c1_data);
i2c_register_board_info(0, smdk6440_i2c_devs0,
ARRAY_SIZE(smdk6440_i2c_devs0));
i2c_register_board_info(1, smdk6440_i2c_devs1,
ARRAY_SIZE(smdk6440_i2c_devs1));
platform_add_devices(smdk6440_devices, ARRAY_SIZE(smdk6440_devices));
}
