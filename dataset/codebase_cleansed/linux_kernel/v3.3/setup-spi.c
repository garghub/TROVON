int s3c64xx_spi0_cfg_gpio(struct platform_device *dev)
{
s3c_gpio_cfgall_range(S3C64XX_GPC(0), 3,
S3C_GPIO_SFN(2), S3C_GPIO_PULL_UP);
return 0;
}
int s3c64xx_spi1_cfg_gpio(struct platform_device *dev)
{
s3c_gpio_cfgall_range(S3C64XX_GPC(4), 3,
S3C_GPIO_SFN(2), S3C_GPIO_PULL_UP);
return 0;
}
