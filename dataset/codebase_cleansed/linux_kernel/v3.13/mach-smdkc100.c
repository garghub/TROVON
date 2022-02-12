static void smdkc100_lcd_power_set(struct plat_lcd_data *pd,
unsigned int power)
{
if (power) {
gpio_direction_output(S5PC100_GPH0(6), 1);
mdelay(100);
gpio_direction_output(S5PC100_GPH0(6), 0);
mdelay(10);
gpio_direction_output(S5PC100_GPH0(6), 1);
mdelay(10);
}
}
static void __init smdkc100_map_io(void)
{
s5pc100_init_io(NULL, 0);
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(smdkc100_uartcfgs, ARRAY_SIZE(smdkc100_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init smdkc100_machine_init(void)
{
s3c24xx_ts_set_platdata(NULL);
s3c_i2c0_set_platdata(NULL);
s3c_i2c1_set_platdata(NULL);
i2c_register_board_info(0, i2c_devs0, ARRAY_SIZE(i2c_devs0));
i2c_register_board_info(1, i2c_devs1, ARRAY_SIZE(i2c_devs1));
s3c_fb_set_platdata(&smdkc100_lcd_pdata);
s3c_ide_set_platdata(&smdkc100_ide_pdata);
samsung_keypad_set_platdata(&smdkc100_keypad_data);
s5pc100_spdif_setup_gpio(S5PC100_SPDIF_GPD);
gpio_request(S5PC100_GPH0(6), "GPH0");
smdkc100_lcd_power_set(&smdkc100_lcd_power_data, 0);
platform_add_devices(smdkc100_devices, ARRAY_SIZE(smdkc100_devices));
samsung_bl_set(&smdkc100_bl_gpio_info, &smdkc100_bl_data);
}
