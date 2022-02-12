void __init s3c244x_init_uarts(struct s3c2410_uartcfg *cfg, int no)
{
s3c24xx_init_uartdevs("s3c2440-uart", s3c2410_uart_resources, cfg, no);
}
void __init s3c244x_map_io(void)
{
iotable_init(s3c244x_iodesc, ARRAY_SIZE(s3c244x_iodesc));
s3c_device_sdi.name = "s3c2440-sdi";
s3c_device_i2c0.name = "s3c2440-i2c";
s3c_nand_setname("s3c2440-nand");
s3c_device_ts.name = "s3c2440-ts";
s3c_device_usbgadget.name = "s3c2440-usbgadget";
s3c2410_device_dclk.name = "s3c2440-dclk";
}
void __init_or_cpufreq s3c244x_setup_clocks(void)
{
}
static int __init s3c2440_core_init(void)
{
return subsys_system_register(&s3c2440_subsys, NULL);
}
static int __init s3c2442_core_init(void)
{
return subsys_system_register(&s3c2442_subsys, NULL);
}
static int s3c244x_suspend(void)
{
s3c_pm_do_save(s3c244x_sleep, ARRAY_SIZE(s3c244x_sleep));
return 0;
}
static void s3c244x_resume(void)
{
s3c_pm_do_restore(s3c244x_sleep, ARRAY_SIZE(s3c244x_sleep));
}
void s3c244x_restart(enum reboot_mode mode, const char *cmd)
{
if (mode == REBOOT_SOFT)
soft_restart(0);
samsung_wdt_reset();
soft_restart(0);
}
