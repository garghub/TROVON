void s3c64xx_ide_setup_gpio(void)
{
u32 reg;
reg = readl(S3C_MEM_SYS_CFG) & (~0x3f);
writel(reg | MEM_SYS_CFG_INDEP_CF |
MEM_SYS_CFG_EBI_FIX_PRI_CFCON, S3C_MEM_SYS_CFG);
s3c_gpio_cfgpin(S3C64XX_GPB(4), S3C_GPIO_SFN(4));
s3c_gpio_cfgpin_range(S3C64XX_GPK(0), 16, S3C_GPIO_SFN(5));
s3c_gpio_cfgpin_range(S3C64XX_GPL(0), 3, S3C_GPIO_SFN(6));
s3c_gpio_cfgpin(S3C64XX_GPM(5), S3C_GPIO_SFN(1));
s3c_gpio_cfgpin_range(S3C64XX_GPM(0), 5, S3C_GPIO_SFN(6));
}
