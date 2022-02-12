static u32 __init axp_get_tclk_freq(void __iomem *sar)
{
return 250000000;
}
static u32 __init axp_get_cpu_freq(void __iomem *sar)
{
u32 cpu_freq;
u8 cpu_freq_select = 0;
cpu_freq_select = ((readl(sar + SARL) >> SARL_AXP_PCLK_FREQ_OPT) &
SARL_AXP_PCLK_FREQ_OPT_MASK);
cpu_freq_select |= (((readl(sar + SARH) >> SARH_AXP_PCLK_FREQ_OPT) &
SARH_AXP_PCLK_FREQ_OPT_MASK) << SARH_AXP_PCLK_FREQ_OPT_SHIFT);
if (cpu_freq_select >= ARRAY_SIZE(axp_cpu_freqs)) {
pr_err("CPU freq select unsupported: %d\n", cpu_freq_select);
cpu_freq = 0;
} else
cpu_freq = axp_cpu_freqs[cpu_freq_select];
return cpu_freq;
}
static void __init axp_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
u32 opt = ((readl(sar + SARL) >> SARL_AXP_FAB_FREQ_OPT) &
SARL_AXP_FAB_FREQ_OPT_MASK);
opt |= (((readl(sar + SARH) >> SARH_AXP_FAB_FREQ_OPT) &
SARH_AXP_FAB_FREQ_OPT_MASK) << SARH_AXP_FAB_FREQ_OPT_SHIFT);
switch (id) {
case AXP_CPU_TO_NBCLK:
*mult = axp_nbclk_ratios[opt][0];
*div = axp_nbclk_ratios[opt][1];
break;
case AXP_CPU_TO_HCLK:
*mult = axp_hclk_ratios[opt][0];
*div = axp_hclk_ratios[opt][1];
break;
case AXP_CPU_TO_DRAMCLK:
*mult = axp_dramclk_ratios[opt][0];
*div = axp_dramclk_ratios[opt][1];
break;
}
}
static void __init axp_clk_init(struct device_node *np)
{
struct device_node *cgnp =
of_find_compatible_node(NULL, NULL, "marvell,armada-xp-gating-clock");
mvebu_coreclk_setup(np, &axp_coreclks);
if (cgnp)
mvebu_clk_gating_setup(cgnp, axp_gating_desc);
}
