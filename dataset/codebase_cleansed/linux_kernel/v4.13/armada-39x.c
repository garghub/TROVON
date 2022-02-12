static u32 __init armada_39x_get_tclk_freq(void __iomem *sar)
{
u8 tclk_freq_select;
tclk_freq_select = ((readl(sar + SARL) >> SARL_A390_TCLK_FREQ_OPT) &
SARL_A390_TCLK_FREQ_OPT_MASK);
return armada_39x_tclk_frequencies[tclk_freq_select];
}
static u32 __init armada_39x_get_cpu_freq(void __iomem *sar)
{
u8 cpu_freq_select;
cpu_freq_select = ((readl(sar + SARL) >> SARL_A390_CPU_DDR_L2_FREQ_OPT) &
SARL_A390_CPU_DDR_L2_FREQ_OPT_MASK);
if (cpu_freq_select >= ARRAY_SIZE(armada_39x_cpu_frequencies)) {
pr_err("Selected CPU frequency (%d) unsupported\n",
cpu_freq_select);
return 0;
}
return armada_39x_cpu_frequencies[cpu_freq_select];
}
static void __init armada_39x_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
switch (id) {
case A390_CPU_TO_NBCLK:
*mult = 1;
*div = 2;
break;
case A390_CPU_TO_HCLK:
*mult = 1;
*div = 4;
break;
case A390_CPU_TO_DCLK:
*mult = 1;
*div = 2;
break;
}
}
static u32 __init armada_39x_refclk_ratio(void __iomem *sar)
{
if (readl(sar + SARH) & SARH_A390_REFCLK_FREQ)
return 40 * 1000 * 1000;
else
return 25 * 1000 * 1000;
}
static void __init armada_39x_coreclk_init(struct device_node *np)
{
mvebu_coreclk_setup(np, &armada_39x_coreclks);
}
static void __init armada_39x_clk_gating_init(struct device_node *np)
{
mvebu_clk_gating_setup(np, armada_39x_gating_desc);
}
