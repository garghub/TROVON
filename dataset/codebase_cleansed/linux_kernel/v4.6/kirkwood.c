static u32 __init kirkwood_get_tclk_freq(void __iomem *sar)
{
u32 opt = (readl(sar) >> SAR_KIRKWOOD_TCLK_FREQ) &
SAR_KIRKWOOD_TCLK_FREQ_MASK;
return (opt) ? 166666667 : 200000000;
}
static u32 __init kirkwood_get_cpu_freq(void __iomem *sar)
{
u32 opt = SAR_KIRKWOOD_CPU_FREQ(readl(sar));
return kirkwood_cpu_freqs[opt];
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
return mv88f6180_cpu_freqs[opt];
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
static struct clk *clk_muxing_get_src(
struct of_phandle_args *clkspec, void *data)
{
struct clk_muxing_ctrl *ctrl = (struct clk_muxing_ctrl *)data;
int n;
if (clkspec->args_count < 1)
return ERR_PTR(-EINVAL);
for (n = 0; n < ctrl->num_muxes; n++) {
struct clk_mux *mux =
to_clk_mux(__clk_get_hw(ctrl->muxes[n]));
if (clkspec->args[0] == mux->shift)
return ctrl->muxes[n];
}
return ERR_PTR(-ENODEV);
}
static void __init kirkwood_clk_muxing_setup(struct device_node *np,
const struct clk_muxing_soc_desc *desc)
{
struct clk_muxing_ctrl *ctrl;
void __iomem *base;
int n;
base = of_iomap(np, 0);
if (WARN_ON(!base))
return;
ctrl = kzalloc(sizeof(*ctrl), GFP_KERNEL);
if (WARN_ON(!ctrl))
goto ctrl_out;
ctrl->lock = &ctrl_gating_lock;
for (n = 0; desc[n].name;)
n++;
ctrl->num_muxes = n;
ctrl->muxes = kcalloc(ctrl->num_muxes, sizeof(struct clk *),
GFP_KERNEL);
if (WARN_ON(!ctrl->muxes))
goto muxes_out;
for (n = 0; n < ctrl->num_muxes; n++) {
ctrl->muxes[n] = clk_register_mux(NULL, desc[n].name,
desc[n].parents, desc[n].num_parents,
desc[n].flags, base, desc[n].shift,
desc[n].width, desc[n].flags, ctrl->lock);
WARN_ON(IS_ERR(ctrl->muxes[n]));
}
of_clk_add_provider(np, clk_muxing_get_src, ctrl);
return;
muxes_out:
kfree(ctrl);
ctrl_out:
iounmap(base);
}
static void __init kirkwood_clk_init(struct device_node *np)
{
struct device_node *cgnp =
of_find_compatible_node(NULL, NULL, "marvell,kirkwood-gating-clock");
if (of_device_is_compatible(np, "marvell,mv88f6180-core-clock"))
mvebu_coreclk_setup(np, &mv88f6180_coreclks);
else
mvebu_coreclk_setup(np, &kirkwood_coreclks);
if (cgnp) {
mvebu_clk_gating_setup(cgnp, kirkwood_gating_desc);
kirkwood_clk_muxing_setup(cgnp, kirkwood_mux_desc);
}
}
