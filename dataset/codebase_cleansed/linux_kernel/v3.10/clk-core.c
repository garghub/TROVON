static void __init mvebu_clk_core_setup(struct device_node *np,
struct core_clocks *coreclk)
{
const char *tclk_name = "tclk";
const char *cpuclk_name = "cpuclk";
void __iomem *base;
unsigned long rate;
int n;
base = of_iomap(np, 0);
if (WARN_ON(!base))
return;
clk_data.clk_num = 2 + coreclk->num_ratios;
clk_data.clks = kzalloc(clk_data.clk_num * sizeof(struct clk *),
GFP_KERNEL);
if (WARN_ON(!clk_data.clks))
return;
of_property_read_string_index(np, "clock-output-names", 0,
&tclk_name);
rate = coreclk->get_tclk_freq(base);
clk_data.clks[0] = clk_register_fixed_rate(NULL, tclk_name, NULL,
CLK_IS_ROOT, rate);
WARN_ON(IS_ERR(clk_data.clks[0]));
of_property_read_string_index(np, "clock-output-names", 1,
&cpuclk_name);
rate = coreclk->get_cpu_freq(base);
clk_data.clks[1] = clk_register_fixed_rate(NULL, cpuclk_name, NULL,
CLK_IS_ROOT, rate);
WARN_ON(IS_ERR(clk_data.clks[1]));
for (n = 0; n < coreclk->num_ratios; n++) {
const char *rclk_name = coreclk->ratios[n].name;
int mult, div;
of_property_read_string_index(np, "clock-output-names",
2+n, &rclk_name);
coreclk->get_clk_ratio(base, coreclk->ratios[n].id,
&mult, &div);
clk_data.clks[2+n] = clk_register_fixed_factor(NULL, rclk_name,
cpuclk_name, 0, mult, div);
WARN_ON(IS_ERR(clk_data.clks[2+n]));
};
iounmap(base);
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
}
static u32 __init armada_370_get_tclk_freq(void __iomem *sar)
{
u8 tclk_freq_select = 0;
tclk_freq_select = ((readl(sar) >> SARL_A370_TCLK_FREQ_OPT) &
SARL_A370_TCLK_FREQ_OPT_MASK);
return armada_370_tclk_frequencies[tclk_freq_select];
}
static u32 __init armada_370_get_cpu_freq(void __iomem *sar)
{
u32 cpu_freq;
u8 cpu_freq_select = 0;
cpu_freq_select = ((readl(sar) >> SARL_A370_PCLK_FREQ_OPT) &
SARL_A370_PCLK_FREQ_OPT_MASK);
if (cpu_freq_select >= ARRAY_SIZE(armada_370_cpu_frequencies)) {
pr_err("CPU freq select unsupported %d\n", cpu_freq_select);
cpu_freq = 0;
} else
cpu_freq = armada_370_cpu_frequencies[cpu_freq_select];
return cpu_freq;
}
static void __init armada_370_xp_get_clk_ratio(u32 opt,
void __iomem *sar, int id, int *mult, int *div)
{
switch (id) {
case A370_XP_NBCLK:
*mult = armada_370_xp_nbclk_ratios[opt][0];
*div = armada_370_xp_nbclk_ratios[opt][1];
break;
case A370_XP_HCLK:
*mult = armada_370_xp_hclk_ratios[opt][0];
*div = armada_370_xp_hclk_ratios[opt][1];
break;
case A370_XP_DRAMCLK:
*mult = armada_370_xp_dramclk_ratios[opt][0];
*div = armada_370_xp_dramclk_ratios[opt][1];
break;
}
}
static void __init armada_370_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
u32 opt = ((readl(sar) >> SARL_A370_FAB_FREQ_OPT) &
SARL_A370_FAB_FREQ_OPT_MASK);
armada_370_xp_get_clk_ratio(opt, sar, id, mult, div);
}
static u32 __init armada_xp_get_tclk_freq(void __iomem *sar)
{
return 250 * 1000 * 1000;
}
static u32 __init armada_xp_get_cpu_freq(void __iomem *sar)
{
u32 cpu_freq;
u8 cpu_freq_select = 0;
cpu_freq_select = ((readl(sar) >> SARL_AXP_PCLK_FREQ_OPT) &
SARL_AXP_PCLK_FREQ_OPT_MASK);
cpu_freq_select |= (((readl(sar+4) >> SARH_AXP_PCLK_FREQ_OPT) &
SARH_AXP_PCLK_FREQ_OPT_MASK)
<< SARH_AXP_PCLK_FREQ_OPT_SHIFT);
if (cpu_freq_select >= ARRAY_SIZE(armada_xp_cpu_frequencies)) {
pr_err("CPU freq select unsupported: %d\n", cpu_freq_select);
cpu_freq = 0;
} else
cpu_freq = armada_xp_cpu_frequencies[cpu_freq_select];
return cpu_freq;
}
static void __init armada_xp_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
u32 opt = ((readl(sar) >> SARL_AXP_FAB_FREQ_OPT) &
SARL_AXP_FAB_FREQ_OPT_MASK);
opt |= (((readl(sar+4) >> SARH_AXP_FAB_FREQ_OPT) &
SARH_AXP_FAB_FREQ_OPT_MASK)
<< SARH_AXP_FAB_FREQ_OPT_SHIFT);
armada_370_xp_get_clk_ratio(opt, sar, id, mult, div);
}
static u32 __init dove_get_tclk_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_DOVE_TCLK_FREQ) &
SAR_DOVE_TCLK_FREQ_MASK;
return dove_tclk_frequencies[opt];
}
static u32 __init dove_get_cpu_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_DOVE_CPU_FREQ) &
SAR_DOVE_CPU_FREQ_MASK;
return dove_cpu_frequencies[opt];
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
static u32 __init kirkwood_get_tclk_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_KIRKWOOD_TCLK_FREQ) &
SAR_KIRKWOOD_TCLK_FREQ_MASK;
return (opt) ? 166666667 : 200000000;
}
static u32 __init kirkwood_get_cpu_freq(void __iomem *sar)
{
u32 opt = SAR_KIRKWOOD_CPU_FREQ(readl(sar));
return kirkwood_cpu_frequencies[opt];
}
static void __init kirkwood_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
switch (id) {
case KIRKWOOD_CPU_TO_L2:
{
u32 opt = SAR_KIRKWOOD_L2_RATIO(readl(sar));
*mult = kirkwood_cpu_l2_ratios[opt][0];
*div = kirkwood_cpu_l2_ratios[opt][1];
break;
}
case KIRKWOOD_CPU_TO_DDR:
{
u32 opt = (readl(sar) >> SAR_KIRKWOOD_DDR_RATIO) &
SAR_KIRKWOOD_DDR_RATIO_MASK;
*mult = kirkwood_cpu_ddr_ratios[opt][0];
*div = kirkwood_cpu_ddr_ratios[opt][1];
break;
}
}
}
static u32 __init mv88f6180_get_cpu_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_MV88F6180_CLK) & SAR_MV88F6180_CLK_MASK;
return mv88f6180_cpu_frequencies[opt];
}
static void __init mv88f6180_get_clk_ratio(
void __iomem *sar, int id, int *mult, int *div)
{
switch (id) {
case KIRKWOOD_CPU_TO_L2:
{
*mult = 1;
*div = 2;
break;
}
case KIRKWOOD_CPU_TO_DDR:
{
u32 opt = (readl(sar) >> SAR_MV88F6180_CLK) &
SAR_MV88F6180_CLK_MASK;
*mult = mv88f6180_cpu_ddr_ratios[opt][0];
*div = mv88f6180_cpu_ddr_ratios[opt][1];
break;
}
}
}
void __init mvebu_core_clk_init(void)
{
struct device_node *np;
for_each_matching_node(np, clk_core_match) {
const struct of_device_id *match =
of_match_node(clk_core_match, np);
mvebu_clk_core_setup(np, (struct core_clocks *)match->data);
}
}
