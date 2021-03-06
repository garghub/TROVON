void s3c24xx_spi_gpiocfg_bus1_gpd8_9_10(struct s3c2410_spi_info *spi,
int enable)
{
printk(KERN_INFO "%s(%d)\n", __func__, enable);
if (enable) {
s3c_gpio_cfgpin(S3C2410_GPD(10), S3C2440_GPD10_SPICLK1);
s3c_gpio_cfgpin(S3C2410_GPD(9), S3C2440_GPD9_SPIMOSI1);
s3c_gpio_cfgpin(S3C2410_GPD(8), S3C2440_GPD8_SPIMISO1);
s3c2410_gpio_pullup(S3C2410_GPD(10), 0);
s3c2410_gpio_pullup(S3C2410_GPD(9), 0);
} else {
s3c_gpio_cfgpin(S3C2410_GPD(8), S3C2410_GPIO_INPUT);
s3c_gpio_cfgpin(S3C2410_GPD(9), S3C2410_GPIO_INPUT);
s3c_gpio_setpull(S3C2410_GPD(10), S3C_GPIO_PULL_NONE);
s3c_gpio_setpull(S3C2410_GPD(9), S3C_GPIO_PULL_NONE);
s3c_gpio_setpull(S3C2410_GPD(8), S3C_GPIO_PULL_NONE);
}
}
