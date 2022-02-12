void s3c_i2c0_cfg_gpio(struct platform_device *dev)
{
s3c_gpio_cfgall_range(S3C64XX_GPB(5), 2,
S3C_GPIO_SFN(2), S3C_GPIO_PULL_UP);
}
