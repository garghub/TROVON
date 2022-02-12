void s3c_i2c4_cfg_gpio(struct platform_device *dev)
{
s3c_gpio_cfgall_range(EXYNOS4_GPB(2), 2,
S3C_GPIO_SFN(3), S3C_GPIO_PULL_UP);
}
