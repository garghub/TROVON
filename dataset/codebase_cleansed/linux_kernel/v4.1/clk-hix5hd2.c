static int clk_ether_prepare(struct clk_hw *hw)
{
struct hix5hd2_clk_complex *clk = to_complex_clk(hw);
u32 val;
val = readl_relaxed(clk->ctrl_reg);
val |= clk->ctrl_clk_mask | clk->ctrl_rst_mask;
writel_relaxed(val, clk->ctrl_reg);
val &= ~(clk->ctrl_rst_mask);
writel_relaxed(val, clk->ctrl_reg);
val = readl_relaxed(clk->phy_reg);
val |= clk->phy_clk_mask;
val &= ~(clk->phy_rst_mask);
writel_relaxed(val, clk->phy_reg);
mdelay(10);
val &= ~(clk->phy_clk_mask);
val |= clk->phy_rst_mask;
writel_relaxed(val, clk->phy_reg);
mdelay(10);
val |= clk->phy_clk_mask;
val &= ~(clk->phy_rst_mask);
writel_relaxed(val, clk->phy_reg);
mdelay(30);
return 0;
}
static void clk_ether_unprepare(struct clk_hw *hw)
{
struct hix5hd2_clk_complex *clk = to_complex_clk(hw);
u32 val;
val = readl_relaxed(clk->ctrl_reg);
val &= ~(clk->ctrl_clk_mask);
writel_relaxed(val, clk->ctrl_reg);
}
static int clk_complex_enable(struct clk_hw *hw)
{
struct hix5hd2_clk_complex *clk = to_complex_clk(hw);
u32 val;
val = readl_relaxed(clk->ctrl_reg);
val |= clk->ctrl_clk_mask;
val &= ~(clk->ctrl_rst_mask);
writel_relaxed(val, clk->ctrl_reg);
val = readl_relaxed(clk->phy_reg);
val |= clk->phy_clk_mask;
val &= ~(clk->phy_rst_mask);
writel_relaxed(val, clk->phy_reg);
return 0;
}
static void clk_complex_disable(struct clk_hw *hw)
{
struct hix5hd2_clk_complex *clk = to_complex_clk(hw);
u32 val;
val = readl_relaxed(clk->ctrl_reg);
val |= clk->ctrl_rst_mask;
val &= ~(clk->ctrl_clk_mask);
writel_relaxed(val, clk->ctrl_reg);
val = readl_relaxed(clk->phy_reg);
val |= clk->phy_rst_mask;
val &= ~(clk->phy_clk_mask);
writel_relaxed(val, clk->phy_reg);
}
void __init hix5hd2_clk_register_complex(struct hix5hd2_complex_clock *clks,
int nums, struct hisi_clock_data *data)
{
void __iomem *base = data->base;
int i;
for (i = 0; i < nums; i++) {
struct hix5hd2_clk_complex *p_clk;
struct clk *clk;
struct clk_init_data init;
p_clk = kzalloc(sizeof(*p_clk), GFP_KERNEL);
if (!p_clk)
return;
init.name = clks[i].name;
if (clks[i].type == TYPE_ETHER)
init.ops = &clk_ether_ops;
else
init.ops = &clk_complex_ops;
init.flags = CLK_IS_BASIC;
init.parent_names =
(clks[i].parent_name ? &clks[i].parent_name : NULL);
init.num_parents = (clks[i].parent_name ? 1 : 0);
p_clk->ctrl_reg = base + clks[i].ctrl_reg;
p_clk->ctrl_clk_mask = clks[i].ctrl_clk_mask;
p_clk->ctrl_rst_mask = clks[i].ctrl_rst_mask;
p_clk->phy_reg = base + clks[i].phy_reg;
p_clk->phy_clk_mask = clks[i].phy_clk_mask;
p_clk->phy_rst_mask = clks[i].phy_rst_mask;
p_clk->hw.init = &init;
clk = clk_register(NULL, &p_clk->hw);
if (IS_ERR(clk)) {
kfree(p_clk);
pr_err("%s: failed to register clock %s\n",
__func__, clks[i].name);
continue;
}
data->clk_data.clks[clks[i].id] = clk;
}
}
static void __init hix5hd2_clk_init(struct device_node *np)
{
struct hisi_clock_data *clk_data;
clk_data = hisi_clk_init(np, HIX5HD2_NR_CLKS);
if (!clk_data)
return;
hisi_clk_register_fixed_rate(hix5hd2_fixed_rate_clks,
ARRAY_SIZE(hix5hd2_fixed_rate_clks),
clk_data);
hisi_clk_register_mux(hix5hd2_mux_clks, ARRAY_SIZE(hix5hd2_mux_clks),
clk_data);
hisi_clk_register_gate(hix5hd2_gate_clks,
ARRAY_SIZE(hix5hd2_gate_clks), clk_data);
hix5hd2_clk_register_complex(hix5hd2_complex_clks,
ARRAY_SIZE(hix5hd2_complex_clks),
clk_data);
}
