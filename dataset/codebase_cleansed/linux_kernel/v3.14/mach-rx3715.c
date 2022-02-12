static void __init rx3715_map_io(void)
{
s3c24xx_init_io(rx3715_iodesc, ARRAY_SIZE(rx3715_iodesc));
s3c24xx_init_clocks(16934000);
s3c24xx_init_uarts(rx3715_uartcfgs, ARRAY_SIZE(rx3715_uartcfgs));
samsung_set_timer_source(SAMSUNG_PWM3, SAMSUNG_PWM4);
}
static void __init rx3715_reserve(void)
{
memblock_reserve(0x30003000, 0x1000);
memblock_reserve(0x30081000, 0x1000);
}
static void __init rx3715_init_machine(void)
{
#ifdef CONFIG_PM_H1940
memcpy(phys_to_virt(H1940_SUSPEND_RESUMEAT), h1940_pm_return, 1024);
#endif
s3c_pm_init();
s3c_nand_set_platdata(&rx3715_nand_info);
s3c24xx_fb_set_platdata(&rx3715_fb_info);
platform_add_devices(rx3715_devices, ARRAY_SIZE(rx3715_devices));
}
