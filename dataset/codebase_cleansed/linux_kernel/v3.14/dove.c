static u32 __init dove_get_tclk_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_DOVE_TCLK_FREQ) &
SAR_DOVE_TCLK_FREQ_MASK;
return dove_tclk_freqs[opt];
}
static u32 __init dove_get_cpu_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_DOVE_CPU_FREQ) &
SAR_DOVE_CPU_FREQ_MASK;
return dove_cpu_freqs[opt];
}
static void __init dove_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
switch (id) {
case DOVE_CPU_TO_L2:
{
u32 opt = (readl(sar) >> SAR_DOVE_L2_RATIO) &
SAR_DOVE_L2_RATIO_MASK;
*mult = dove_cpu_l2_ratios[opt][0];
*div = dove_cpu_l2_ratios[opt][1];
break;
}
case DOVE_CPU_TO_DDR:
{
u32 opt = (readl(sar) >> SAR_DOVE_DDR_RATIO) &
SAR_DOVE_DDR_RATIO_MASK;
*mult = dove_cpu_ddr_ratios[opt][0];
*div = dove_cpu_ddr_ratios[opt][1];
break;
}
}
}
static void __init dove_clk_init(struct device_node *np)
{
struct device_node *cgnp =
of_find_compatible_node(NULL, NULL, "marvell,dove-gating-clock");
mvebu_coreclk_setup(np, &dove_coreclks);
if (cgnp)
mvebu_clk_gating_setup(cgnp, dove_gating_desc);
}
