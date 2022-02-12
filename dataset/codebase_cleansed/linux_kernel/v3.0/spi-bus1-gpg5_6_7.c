void s3c24xx_spi_gpiocfg_bus1_gpg5_6_7(struct s3c2410_spi_info *spi,
int enable)
{
if (enable) {
s3c_gpio_cfgpin(S3C2410_GPG(7), S3C2410_GPG7_SPICLK1);
s3c_gpio_cfgpin(S3C2410_GPG(6), S3C2410_GPG6_SPIMOSI1);
s3c_gpio_cfgpin(S3C2410_GPG(5), S3C2410_GPG5_SPIMISO1);
s3c2410_gpio_pullup(S3C2410_GPG(5), 0);
s3c2410_gpio_pullup(S3C2410_GPG(6), 0);
} else {
s3c_gpio_cfgpin(S3C2410_GPG(7), S3C2410_GPIO_INPUT);
s3c_gpio_cfgpin(S3C2410_GPG(5), S3C2410_GPIO_INPUT);
s3c_gpio_setpull(S3C2410_GPG(5), S3C_GPIO_PULL_NONE);
s3c_gpio_setpull(S3C2410_GPG(6), S3C_GPIO_PULL_NONE);
s3c_gpio_setpull(S3C2410_GPG(7), S3C_GPIO_PULL_NONE);
}
}
