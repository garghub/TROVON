static u32 __init armada_38x_get_tclk_freq(void __iomem *sar)
{
u8 tclk_freq_select;
tclk_freq_select = ((readl(sar) >> SAR_A380_TCLK_FREQ_OPT) &
SAR_A380_TCLK_FREQ_OPT_MASK);
return armada_38x_tclk_frequencies[tclk_freq_select];
}
static u32 __init armada_38x_get_cpu_freq(void __iomem *sar)
{
u8 cpu_freq_select;
cpu_freq_select = ((readl(sar) >> SAR_A380_CPU_DDR_L2_FREQ_OPT) &
SAR_A380_CPU_DDR_L2_FREQ_OPT_MASK);
if (cpu_freq_select >= ARRAY_SIZE(armada_38x_cpu_frequencies)) {
pr_err("Selected CPU frequency (%d) unsupported\n",
cpu_freq_select);
return 0;
}
return armada_38x_cpu_frequencies[cpu_freq_select];
}
static void __init armada_38x_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
u32 opt = ((readl(sar) >> SAR_A380_CPU_DDR_L2_FREQ_OPT) &
SAR_A380_CPU_DDR_L2_FREQ_OPT_MASK);
switch (id) {
case A380_CPU_TO_L2:
*mult = armada_38x_cpu_l2_ratios[opt][0];
*div = armada_38x_cpu_l2_ratios[opt][1];
break;
case A380_CPU_TO_DDR:
*mult = armada_38x_cpu_ddr_ratios[opt][0];
*div = armada_38x_cpu_ddr_ratios[opt][1];
break;
}
}
static void __init armada_38x_coreclk_init(struct device_node *np)
{
mvebu_coreclk_setup(np, &armada_38x_coreclks);
}
static void __init armada_38x_clk_gating_init(struct device_node *np)
{
mvebu_clk_gating_setup(np, armada_38x_gating_desc);
}
