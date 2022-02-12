static void __init smdk4x12_map_io(void)
{
clk_xusbxti.rate = 24000000;
exynos_init_io(NULL, 0);
s3c24xx_init_clocks(clk_xusbxti.rate);
s3c24xx_init_uarts(smdk4x12_uartcfgs, ARRAY_SIZE(smdk4x12_uartcfgs));
}
static void __init smdk4x12_reserve(void)
{
s5p_mfc_reserve_mem(0x43000000, 8 << 20, 0x51000000, 8 << 20);
}
static void __init smdk4x12_machine_init(void)
{
s3c_i2c0_set_platdata(NULL);
i2c_register_board_info(0, smdk4x12_i2c_devs0,
ARRAY_SIZE(smdk4x12_i2c_devs0));
s3c_i2c1_set_platdata(NULL);
i2c_register_board_info(1, smdk4x12_i2c_devs1,
ARRAY_SIZE(smdk4x12_i2c_devs1));
s3c_i2c3_set_platdata(NULL);
i2c_register_board_info(3, smdk4x12_i2c_devs3,
ARRAY_SIZE(smdk4x12_i2c_devs3));
s3c_i2c7_set_platdata(NULL);
i2c_register_board_info(7, smdk4x12_i2c_devs7,
ARRAY_SIZE(smdk4x12_i2c_devs7));
samsung_bl_set(&smdk4x12_bl_gpio_info, &smdk4x12_bl_data);
samsung_keypad_set_platdata(&smdk4x12_keypad_data);
s3c_sdhci2_set_platdata(&smdk4x12_hsmmc2_pdata);
s3c_sdhci3_set_platdata(&smdk4x12_hsmmc3_pdata);
platform_add_devices(smdk4x12_devices, ARRAY_SIZE(smdk4x12_devices));
}
