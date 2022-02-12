int __init s3c2440_init(void)
{
printk("S3C2440: Initialising architecture\n");
s3c_device_wdt.resource[1].start = IRQ_S3C2440_WDT;
s3c_device_wdt.resource[1].end = IRQ_S3C2440_WDT;
#ifdef CONFIG_PM
register_syscore_ops(&s3c2410_pm_syscore_ops);
#endif
register_syscore_ops(&s3c244x_pm_syscore_ops);
register_syscore_ops(&s3c24xx_irq_syscore_ops);
return sysdev_register(&s3c2440_sysdev);
}
void __init s3c2440_map_io(void)
{
s3c244x_map_io();
s3c24xx_gpiocfg_default.set_pull = s3c24xx_gpio_setpull_1up;
s3c24xx_gpiocfg_default.get_pull = s3c24xx_gpio_getpull_1up;
}
