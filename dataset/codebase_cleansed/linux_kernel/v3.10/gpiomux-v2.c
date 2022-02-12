void __msm_gpiomux_write(unsigned gpio, gpiomux_config_t val)
{
writel(val & ~GPIOMUX_CTL_MASK,
MSM_TLMM_BASE + 0x1000 + (0x10 * gpio));
}
