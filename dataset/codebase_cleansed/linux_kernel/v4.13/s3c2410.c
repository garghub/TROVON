void __init s3c2410_init_uarts(struct s3c2410_uartcfg *cfg, int no)
{
s3c24xx_init_uartdevs("s3c2410-uart", s3c2410_uart_resources, cfg, no);
}
void __init s3c2410_map_io(void)
{
s3c24xx_gpiocfg_default.set_pull = s3c24xx_gpio_setpull_1up;
s3c24xx_gpiocfg_default.get_pull = s3c24xx_gpio_getpull_1up;
iotable_init(s3c2410_iodesc, ARRAY_SIZE(s3c2410_iodesc));
}
static int __init s3c2410_core_init(void)
{
return subsys_system_register(&s3c2410_subsys, NULL);
}
static int __init s3c2410a_core_init(void)
{
return subsys_system_register(&s3c2410a_subsys, NULL);
}
int __init s3c2410_init(void)
{
printk("S3C2410: Initialising architecture\n");
#ifdef CONFIG_PM_SLEEP
register_syscore_ops(&s3c2410_pm_syscore_ops);
register_syscore_ops(&s3c24xx_irq_syscore_ops);
#endif
return device_register(&s3c2410_dev);
}
int __init s3c2410a_init(void)
{
s3c2410_dev.bus = &s3c2410a_subsys;
return s3c2410_init();
}
