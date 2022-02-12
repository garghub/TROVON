void s3c64xx_setup_sdhci0_cfg_gpio(struct platform_device *dev, int width)
{
struct s3c_sdhci_platdata *pdata = dev->dev.platform_data;
s3c_gpio_cfgrange_nopull(S3C64XX_GPG(0), 2 + width, S3C_GPIO_SFN(2));
if (pdata->cd_type == S3C_SDHCI_CD_INTERNAL) {
s3c_gpio_setpull(S3C64XX_GPG(6), S3C_GPIO_PULL_UP);
s3c_gpio_cfgpin(S3C64XX_GPG(6), S3C_GPIO_SFN(2));
}
}
void s3c64xx_setup_sdhci1_cfg_gpio(struct platform_device *dev, int width)
{
struct s3c_sdhci_platdata *pdata = dev->dev.platform_data;
s3c_gpio_cfgrange_nopull(S3C64XX_GPH(0), 2 + width, S3C_GPIO_SFN(2));
if (pdata->cd_type == S3C_SDHCI_CD_INTERNAL) {
s3c_gpio_setpull(S3C64XX_GPG(6), S3C_GPIO_PULL_UP);
s3c_gpio_cfgpin(S3C64XX_GPG(6), S3C_GPIO_SFN(3));
}
}
void s3c64xx_setup_sdhci2_cfg_gpio(struct platform_device *dev, int width)
{
s3c_gpio_cfgrange_nopull(S3C64XX_GPH(6), width, S3C_GPIO_SFN(3));
s3c_gpio_cfgrange_nopull(S3C64XX_GPC(4), 2, S3C_GPIO_SFN(3));
}
