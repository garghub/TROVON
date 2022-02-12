void __init s3c6410_map_io(void)
{
s3c6410_default_sdhci0();
s3c6410_default_sdhci1();
s3c6410_default_sdhci2();
s3c_i2c0_setname("s3c2440-i2c");
s3c_i2c1_setname("s3c2440-i2c");
s3c_adc_setname("s3c64xx-adc");
s3c_device_nand.name = "s3c6400-nand";
s3c_onenand_setname("s3c6410-onenand");
s3c64xx_onenand1_setname("s3c6410-onenand");
s3c_cfcon_setname("s3c64xx-pata");
}
void __init s3c6410_init_irq(void)
{
s3c64xx_init_irq(~0 & ~(1 << 7), ~0);
}
static int __init s3c6410_core_init(void)
{
if (of_have_populated_dt())
return 0;
return subsys_system_register(&s3c6410_subsys, NULL);
}
int __init s3c6410_init(void)
{
printk("S3C6410: Initialising architecture\n");
return device_register(&s3c6410_dev);
}
