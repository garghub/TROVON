void s3c_i2c2_cfg_gpio(struct platform_device *dev)
{
s3c_gpio_cfgall_range(S5PV210_GPD1(4), 2,
S3C_GPIO_SFN(2), S3C_GPIO_PULL_UP);
}
