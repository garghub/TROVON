void s3c_i2c0_cfg_gpio(struct platform_device *dev)
{
s3c_gpio_cfgpin(S3C2410_GPE(15), S3C2410_GPE15_IICSDA);
s3c_gpio_cfgpin(S3C2410_GPE(14), S3C2410_GPE14_IICSCL);
}
