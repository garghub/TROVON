int __init s3c2443_init(void)
{
printk("S3C2443: Initialising architecture\n");
s3c_nand_setname("s3c2412-nand");
s3c_fb_setname("s3c2443-fb");
s3c_adc_setname("s3c2443-adc");
s3c_rtc_setname("s3c2443-rtc");
s3c_device_wdt.resource[1].start = IRQ_S3C2443_WDT;
s3c_device_wdt.resource[1].end = IRQ_S3C2443_WDT;
return device_register(&s3c2443_dev);
}
void __init s3c2443_init_uarts(struct s3c2410_uartcfg *cfg, int no)
{
s3c24xx_init_uartdevs("s3c2440-uart", s3c2410_uart_resources, cfg, no);
}
void __init s3c2443_map_io(void)
{
s3c24xx_gpiocfg_default.set_pull = s3c2443_gpio_setpull;
s3c24xx_gpiocfg_default.get_pull = s3c2443_gpio_getpull;
s3c64xx_spi_setname("s3c2443-spi");
iotable_init(s3c2443_iodesc, ARRAY_SIZE(s3c2443_iodesc));
}
static int __init s3c2443_core_init(void)
{
return subsys_system_register(&s3c2443_subsys, NULL);
}
