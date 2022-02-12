void s3c_i2c1_cfg_gpio(struct platform_device *dev)
{
s3c_gpio_cfgall_range(EXYNOS4_GPD1(2), 2,
S3C_GPIO_SFN(2), S3C_GPIO_PULL_UP);
}
