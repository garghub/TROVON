static void __init smdk2443_map_io(void)
{
s3c24xx_init_io(smdk2443_iodesc, ARRAY_SIZE(smdk2443_iodesc));
s3c24xx_init_clocks(12000000);
s3c24xx_init_uarts(smdk2443_uartcfgs, ARRAY_SIZE(smdk2443_uartcfgs));
}
static void __init smdk2443_machine_init(void)
{
s3c_i2c0_set_platdata(NULL);
#ifdef CONFIG_SND_SOC_SMDK2443_WM9710
s3c24xx_ac97_setup_gpio(S3C24XX_AC97_GPE0);
#endif
platform_add_devices(smdk2443_devices, ARRAY_SIZE(smdk2443_devices));
smdk_machine_init();
}
