static inline u32 tegra_pmc_readl(u32 reg)
{
return readl(IO_ADDRESS(TEGRA_PMC_BASE + reg));
}
static inline void tegra_pmc_writel(u32 val, u32 reg)
{
writel(val, IO_ADDRESS(TEGRA_PMC_BASE + reg));
}
void __init tegra_pmc_init(void)
{
bool invert_interrupt = true;
u32 val;
#ifdef CONFIG_OF
if (of_have_populated_dt()) {
struct device_node *np;
invert_interrupt = false;
np = of_find_matching_node(NULL, matches);
if (np) {
if (of_find_property(np, "nvidia,invert-interrupt",
NULL))
invert_interrupt = true;
}
}
#endif
val = tegra_pmc_readl(PMC_CTRL);
if (invert_interrupt)
val |= PMC_CTRL_INTR_LOW;
else
val &= ~PMC_CTRL_INTR_LOW;
tegra_pmc_writel(val, PMC_CTRL);
}
