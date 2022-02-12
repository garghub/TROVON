static void __init smdk2413_fixup(struct tag *tags, char **cmdline)
{
if (tags != phys_to_virt(S3C2410_SDRAM_PA + 0x100)) {
memblock_add(0x30000000, SZ_64M);
}
}
static void __init smdk2413_map_io(void)
{
s3c24xx_init_io(smdk2413_iodesc, ARRAY_SIZE(smdk2413_iodesc));
s3c24xx_init_uarts(smdk2413_uartcfgs, ARRAY_SIZE(smdk2413_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init smdk2413_init_time(void)
{
s3c2412_init_clocks(12000000);
samsung_timer_init();
}
static void __init smdk2413_machine_init(void)
{
s3c2410_modify_misccr(S3C2410_MISCCR_USBHOST |
S3C2410_MISCCR_USBSUSPND0 |
S3C2410_MISCCR_USBSUSPND1, 0x0);
s3c24xx_udc_set_platdata(&smdk2413_udc_cfg);
s3c_i2c0_set_platdata(NULL);
platform_add_devices(smdk2413_devices, ARRAY_SIZE(smdk2413_devices));
smdk_machine_init();
}
