static inline unsigned long pg_readl(unsigned long offset)
{
return readl(IO_TO_VIRT(TEGRA_APB_MISC_BASE + offset));
}
static inline void pg_writel(unsigned long value, unsigned long offset)
{
writel(value, IO_TO_VIRT(TEGRA_APB_MISC_BASE + offset));
}
void tegra_pinmux_suspend(void)
{
unsigned int i;
u32 *ctx = pinmux_reg;
for (i = 0; i < PIN_MUX_CTL_REG_NUM; i++)
*ctx++ = pg_readl(PIN_MUX_CTL_REG_A + i*4);
for (i = 0; i < PULLUPDOWN_REG_NUM; i++)
*ctx++ = pg_readl(PULLUPDOWN_REG_A + i*4);
for (i = 0; i < TRISTATE_REG_NUM; i++)
*ctx++ = pg_readl(TRISTATE_REG_A + i*4);
for (i = 0; i < ARRAY_SIZE(tegra_soc_drive_pingroups); i++)
*ctx++ = pg_readl(tegra_soc_drive_pingroups[i].reg);
}
void tegra_pinmux_resume(void)
{
unsigned int i;
u32 *ctx = pinmux_reg;
for (i = 0; i < PIN_MUX_CTL_REG_NUM; i++)
pg_writel(*ctx++, PIN_MUX_CTL_REG_A + i*4);
for (i = 0; i < PULLUPDOWN_REG_NUM; i++)
pg_writel(*ctx++, PULLUPDOWN_REG_A + i*4);
for (i = 0; i < TRISTATE_REG_NUM; i++)
pg_writel(*ctx++, TRISTATE_REG_A + i*4);
for (i = 0; i < ARRAY_SIZE(tegra_soc_drive_pingroups); i++)
pg_writel(*ctx++, tegra_soc_drive_pingroups[i].reg);
}
