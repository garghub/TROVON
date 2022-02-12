void s3c24xx_ts_cfg_gpio(struct platform_device *dev)
{
s3c2410_gpio_cfgpin(S3C2410_GPG(12), S3C2410_GPG12_XMON);
s3c2410_gpio_cfgpin(S3C2410_GPG(13), S3C2410_GPG13_nXPON);
s3c2410_gpio_cfgpin(S3C2410_GPG(14), S3C2410_GPG14_YMON);
s3c2410_gpio_cfgpin(S3C2410_GPG(15), S3C2410_GPG15_nYPON);
}
