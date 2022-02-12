static u32 __init mv98dx3236_get_tclk_freq(void __iomem *sar)
{
return 200000000;
}
static u32 __init mv98dx3236_get_cpu_freq(void __iomem *sar)
{
u32 cpu_freq = 0;
u8 cpu_freq_select = 0;
cpu_freq_select = ((readl(sar) >> SAR1_MV98DX3236_CPU_DDR_MPLL_FREQ_OPT) &
SAR1_MV98DX3236_CPU_DDR_MPLL_FREQ_OPT_MASK);
if (of_machine_is_compatible("marvell,armadaxp-98dx4251"))
cpu_freq = mv98dx4251_cpu_frequencies[cpu_freq_select];
else if (of_machine_is_compatible("marvell,armadaxp-98dx3236"))
cpu_freq = mv98dx3236_cpu_frequencies[cpu_freq_select];
if (!cpu_freq)
pr_err("CPU freq select unsupported %d\n", cpu_freq_select);
return cpu_freq;
}
static void __init mv98dx3236_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
u32 opt = ((readl(sar) >> SAR1_MV98DX3236_CPU_DDR_MPLL_FREQ_OPT) &
SAR1_MV98DX3236_CPU_DDR_MPLL_FREQ_OPT_MASK);
switch (id) {
case MV98DX3236_CPU_TO_DDR:
if (of_machine_is_compatible("marvell,armadaxp-98dx4251")) {
*mult = mv98dx4251_cpu_ddr_ratios[opt][0];
*div = mv98dx4251_cpu_ddr_ratios[opt][1];
} else if (of_machine_is_compatible("marvell,armadaxp-98dx3236")) {
*mult = mv98dx3236_cpu_ddr_ratios[opt][0];
*div = mv98dx3236_cpu_ddr_ratios[opt][1];
}
break;
case MV98DX3236_CPU_TO_MPLL:
if (of_machine_is_compatible("marvell,armadaxp-98dx4251")) {
*mult = mv98dx4251_cpu_mpll_ratios[opt][0];
*div = mv98dx4251_cpu_mpll_ratios[opt][1];
} else if (of_machine_is_compatible("marvell,armadaxp-98dx3236")) {
*mult = mv98dx3236_cpu_mpll_ratios[opt][0];
*div = mv98dx3236_cpu_mpll_ratios[opt][1];
}
break;
}
}
static void __init mv98dx3236_clk_init(struct device_node *np)
{
struct device_node *cgnp =
of_find_compatible_node(NULL, NULL, "marvell,mv98dx3236-gating-clock");
mvebu_coreclk_setup(np, &mv98dx3236_core_clocks);
if (cgnp)
mvebu_clk_gating_setup(cgnp, mv98dx3236_gating_desc);
}
