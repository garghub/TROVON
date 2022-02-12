void __init s3c6400_map_io(void)
{
s3c6400_default_sdhci0();
s3c6400_default_sdhci1();
s3c6400_default_sdhci2();
s3c_i2c0_setname("s3c2440-i2c");
s3c_device_nand.name = "s3c6400-nand";
s3c_onenand_setname("s3c6400-onenand");
s3c64xx_onenand1_setname("s3c6400-onenand");
}
void __init s3c6400_init_irq(void)
{
s3c64xx_init_irq(~0 & ~(0xf << 5), ~0);
}
static int __init s3c6400_core_init(void)
{
if (of_have_populated_dt())
return 0;
return subsys_system_register(&s3c6400_subsys, NULL);
}
int __init s3c6400_init(void)
{
printk("S3C6400: Initialising architecture\n");
return device_register(&s3c6400_dev);
}
