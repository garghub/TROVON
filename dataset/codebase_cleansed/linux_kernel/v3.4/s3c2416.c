void s3c2416_restart(char mode, const char *cmd)
{
if (mode == 's')
soft_restart(0);
__raw_writel(S3C2443_SWRST_RESET, S3C2443_SWRST);
}
int __init s3c2416_init(void)
{
printk(KERN_INFO "S3C2416: Initializing architecture\n");
s3c_device_wdt.resource[1].start = IRQ_S3C2443_WDT;
s3c_device_wdt.resource[1].end = IRQ_S3C2443_WDT;
s3c_i2c0_setname("s3c2440-i2c");
s3c_i2c1_setname("s3c2440-i2c");
s3c_fb_setname("s3c2443-fb");
s3c_adc_setname("s3c2416-adc");
s3c_rtc_setname("s3c2416-rtc");
#ifdef CONFIG_PM
register_syscore_ops(&s3c2416_pm_syscore_ops);
#endif
register_syscore_ops(&s3c24xx_irq_syscore_ops);
return device_register(&s3c2416_dev);
}
void __init s3c2416_init_uarts(struct s3c2410_uartcfg *cfg, int no)
{
s3c24xx_init_uartdevs("s3c2440-uart", s3c2410_uart_resources, cfg, no);
s3c_nand_setname("s3c2412-nand");
}
void __init s3c2416_map_io(void)
{
s3c24xx_gpiocfg_default.set_pull = samsung_gpio_setpull_updown;
s3c24xx_gpiocfg_default.get_pull = samsung_gpio_getpull_updown;
s3c2416_default_sdhci0();
s3c2416_default_sdhci1();
iotable_init(s3c2416_iodesc, ARRAY_SIZE(s3c2416_iodesc));
}
static int __init s3c2416_core_init(void)
{
return subsys_system_register(&s3c2416_subsys, NULL);
}
