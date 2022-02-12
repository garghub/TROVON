int s3c64xx_spi0_cfg_gpio(void)
{
s3c2410_modify_misccr(S3C2416_MISCCR_HSSPI_EN2, 1);
s3c_gpio_cfgall_range(S3C2410_GPE(11), 3,
S3C_GPIO_SFN(2), S3C_GPIO_PULL_UP);
return 0;
}
