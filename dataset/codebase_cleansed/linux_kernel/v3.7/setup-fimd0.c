void exynos4_fimd0_gpio_setup_24bpp(void)
{
unsigned int reg;
s3c_gpio_cfgrange_nopull(EXYNOS4_GPF0(0), 8, S3C_GPIO_SFN(2));
s3c_gpio_cfgrange_nopull(EXYNOS4_GPF1(0), 8, S3C_GPIO_SFN(2));
s3c_gpio_cfgrange_nopull(EXYNOS4_GPF2(0), 8, S3C_GPIO_SFN(2));
s3c_gpio_cfgrange_nopull(EXYNOS4_GPF3(0), 4, S3C_GPIO_SFN(2));
reg = __raw_readl(S3C_VA_SYS + 0x0210);
reg |= (1 << 1);
__raw_writel(reg, S3C_VA_SYS + 0x0210);
}
