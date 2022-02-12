void s3c_i2c6_cfg_gpio(struct platform_device *dev)
{
s3c_gpio_cfgall_range(EXYNOS4_GPC1(3), 2,
S3C_GPIO_SFN(4), S3C_GPIO_PULL_UP);
}
