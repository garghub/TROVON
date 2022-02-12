static void vr1000_power_off(void)
{
gpio_direction_output(S3C2410_GPB(9), 1);
}
static void __init vr1000_map_io(void)
{
s3c24xx_dclk0.parent = &clk_upll;
s3c24xx_dclk0.rate = 12*1000*1000;
s3c24xx_dclk1.parent = NULL;
s3c24xx_dclk1.rate = 3692307;
s3c24xx_clkout0.parent = &s3c24xx_dclk0;
s3c24xx_clkout1.parent = &s3c24xx_dclk1;
s3c24xx_uclk.parent = &s3c24xx_clkout1;
s3c24xx_register_clocks(vr1000_clocks, ARRAY_SIZE(vr1000_clocks));
pm_power_off = vr1000_power_off;
s3c24xx_init_io(vr1000_iodesc, ARRAY_SIZE(vr1000_iodesc));
s3c24xx_init_clocks(0);
s3c24xx_init_uarts(vr1000_uartcfgs, ARRAY_SIZE(vr1000_uartcfgs));
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
