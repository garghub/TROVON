static void __init universal_sdhci_init(void)
{
s3c_sdhci0_set_platdata(&universal_hsmmc0_data);
s3c_sdhci2_set_platdata(&universal_hsmmc2_data);
s3c_sdhci3_set_platdata(&universal_hsmmc3_data);
}
static void __init universal_map_io(void)
{
s5p_init_io(NULL, 0, S5P_VA_CHIPID);
s3c24xx_init_clocks(24000000);
s3c24xx_init_uarts(universal_uartcfgs, ARRAY_SIZE(universal_uartcfgs));
}
static void __init universal_machine_init(void)
{
universal_sdhci_init();
i2c_register_board_info(0, i2c0_devs, ARRAY_SIZE(i2c0_devs));
i2c_register_board_info(1, i2c1_devs, ARRAY_SIZE(i2c1_devs));
s3c_i2c5_set_platdata(NULL);
i2c_register_board_info(5, i2c5_devs, ARRAY_SIZE(i2c5_devs));
platform_add_devices(universal_devices, ARRAY_SIZE(universal_devices));
}
