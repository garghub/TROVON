static inline void s3c2412_init_gpio2(void)
{
s3c24xx_va_gpio2 = S3C24XX_VA_GPIO + 0x10;
}
void __init s3c2412_init_uarts(struct s3c2410_uartcfg *cfg, int no)
{
s3c24xx_init_uartdevs("s3c2412-uart", s3c2410_uart_resources, cfg, no);
s3c_device_sdi.name = "s3c2412-sdi";
s3c_device_lcd.name = "s3c2412-lcd";
s3c_nand_setname("s3c2412-nand");
s3c_device_sdi.resource[1].start = IRQ_S3C2412_SDI;
s3c_device_sdi.resource[1].end = IRQ_S3C2412_SDI;
s3c_device_spi0.name = "s3c2412-spi";
s3c_device_spi0.resource[0].end = S3C24XX_PA_SPI + 0x24;
s3c_device_spi1.name = "s3c2412-spi";
s3c_device_spi1.resource[0].start = S3C24XX_PA_SPI + S3C2412_SPI1;
s3c_device_spi1.resource[0].end = S3C24XX_PA_SPI + S3C2412_SPI1 + 0x24;
}
static void s3c2412_idle(void)
{
unsigned long tmp;
tmp = __raw_readl(S3C2412_PWRCFG);
tmp &= ~S3C2412_PWRCFG_STANDBYWFI_MASK;
tmp |= S3C2412_PWRCFG_STANDBYWFI_IDLE;
__raw_writel(tmp, S3C2412_PWRCFG);
cpu_do_idle();
}
void __init s3c2412_map_io(void)
{
s3c2412_init_gpio2();
arm_pm_idle = s3c2412_idle;
iotable_init(s3c2412_iodesc, ARRAY_SIZE(s3c2412_iodesc));
}
static int __init s3c2412_core_init(void)
{
return subsys_system_register(&s3c2412_subsys, NULL);
}
int __init s3c2412_init(void)
{
printk("S3C2412: Initialising architecture\n");
#ifdef CONFIG_PM_SLEEP
register_syscore_ops(&s3c2412_pm_syscore_ops);
register_syscore_ops(&s3c24xx_irq_syscore_ops);
#endif
return device_register(&s3c2412_dev);
}
