void s3c_i2c7_cfg_gpio(struct platform_device *dev)
{
s3c_gpio_cfgall_range(EXYNOS4_GPD0(2), 2,
S3C_GPIO_SFN(3), S3C_GPIO_PULL_UP);
}
