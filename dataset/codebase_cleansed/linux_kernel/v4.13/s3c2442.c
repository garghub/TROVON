int __init s3c2442_init(void)
{
printk("S3C2442: Initialising architecture\n");
#ifdef CONFIG_PM_SLEEP
register_syscore_ops(&s3c2410_pm_syscore_ops);
register_syscore_ops(&s3c24xx_irq_syscore_ops);
register_syscore_ops(&s3c244x_pm_syscore_ops);
#endif
return device_register(&s3c2442_dev);
}
void __init s3c2442_map_io(void)
{
s3c244x_map_io();
s3c24xx_gpiocfg_default.set_pull = s3c24xx_gpio_setpull_1down;
s3c24xx_gpiocfg_default.get_pull = s3c24xx_gpio_getpull_1down;
}
