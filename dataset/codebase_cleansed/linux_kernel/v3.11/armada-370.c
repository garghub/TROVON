static u32 __init a370_get_tclk_freq(void __iomem *sar)
{
u8 tclk_freq_select = 0;
tclk_freq_select = ((readl(sar) >> SARL_A370_TCLK_FREQ_OPT) &
SARL_A370_TCLK_FREQ_OPT_MASK);
return a370_tclk_freqs[tclk_freq_select];
}
static u32 __init a370_get_cpu_freq(void __iomem *sar)
{
u32 cpu_freq;
u8 cpu_freq_select = 0;
cpu_freq_select = ((readl(sar) >> SARL_A370_PCLK_FREQ_OPT) &
SARL_A370_PCLK_FREQ_OPT_MASK);
if (cpu_freq_select >= ARRAY_SIZE(a370_cpu_freqs)) {
pr_err("CPU freq select unsupported %d\n", cpu_freq_select);
cpu_freq = 0;
} else
cpu_freq = a370_cpu_freqs[cpu_freq_select];
return cpu_freq;
}
static void __init a370_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
u32 opt = ((readl(sar) >> SARL_A370_FAB_FREQ_OPT) &
SARL_A370_FAB_FREQ_OPT_MASK);
switch (id) {
case A370_CPU_TO_NBCLK:
*mult = a370_nbclk_ratios[opt][0];
*div = a370_nbclk_ratios[opt][1];
break;
case A370_CPU_TO_HCLK:
*mult = a370_hclk_ratios[opt][0];
*div = a370_hclk_ratios[opt][1];
break;
case A370_CPU_TO_DRAMCLK:
*mult = a370_dramclk_ratios[opt][0];
*div = a370_dramclk_ratios[opt][1];
break;
}
}
static void __init a370_coreclk_init(struct device_node *np)
{
mvebu_coreclk_setup(np, &a370_coreclks);
}
static void __init a370_clk_gating_init(struct device_node *np)
{
mvebu_clk_gating_setup(np, a370_gating_desc);
}
