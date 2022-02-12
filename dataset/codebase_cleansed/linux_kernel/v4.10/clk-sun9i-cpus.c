static unsigned long sun9i_a80_cpus_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct sun9i_a80_cpus_clk *cpus = to_sun9i_a80_cpus_clk(hw);
unsigned long rate;
u32 reg;
reg = readl(cpus->reg);
if (SUN9I_CPUS_MUX_GET_PARENT(reg) == SUN9I_CPUS_MUX_PARENT_PLL4)
parent_rate /= SUN9I_CPUS_PLL4_DIV_GET(reg) + 1;
rate = parent_rate / (SUN9I_CPUS_DIV_GET(reg) + 1);
return rate;
}
static long sun9i_a80_cpus_clk_round(unsigned long rate, u8 *divp, u8 *pre_divp,
u8 parent, unsigned long parent_rate)
{
u8 div, pre_div = 1;
if (parent_rate && rate > parent_rate)
rate = parent_rate;
div = DIV_ROUND_UP(parent_rate, rate);
if (parent == SUN9I_CPUS_MUX_PARENT_PLL4 && div > 4) {
if (div < 32) {
pre_div = div;
div = 1;
} else if (div < 64) {
pre_div = DIV_ROUND_UP(div, 2);
div = 2;
} else if (div < 96) {
pre_div = DIV_ROUND_UP(div, 3);
div = 3;
} else {
pre_div = DIV_ROUND_UP(div, 4);
div = 4;
}
}
if (divp) {
*divp = div - 1;
*pre_divp = pre_div - 1;
}
return parent_rate / pre_div / div;
}
static int sun9i_a80_cpus_clk_determine_rate(struct clk_hw *clk,
struct clk_rate_request *req)
{
struct clk_hw *parent, *best_parent = NULL;
int i, num_parents;
unsigned long parent_rate, best = 0, child_rate, best_child_rate = 0;
unsigned long rate = req->rate;
num_parents = clk_hw_get_num_parents(clk);
for (i = 0; i < num_parents; i++) {
parent = clk_hw_get_parent_by_index(clk, i);
if (!parent)
continue;
if (clk_hw_get_flags(clk) & CLK_SET_RATE_PARENT)
parent_rate = clk_hw_round_rate(parent, rate);
else
parent_rate = clk_hw_get_rate(parent);
child_rate = sun9i_a80_cpus_clk_round(rate, NULL, NULL, i,
parent_rate);
if (child_rate <= rate && child_rate > best_child_rate) {
best_parent = parent;
best = parent_rate;
best_child_rate = child_rate;
}
}
if (!best_parent)
return -EINVAL;
req->best_parent_hw = best_parent;
req->best_parent_rate = best;
req->rate = best_child_rate;
return 0;
}
static int sun9i_a80_cpus_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct sun9i_a80_cpus_clk *cpus = to_sun9i_a80_cpus_clk(hw);
unsigned long flags;
u8 div, pre_div, parent;
u32 reg;
spin_lock_irqsave(&sun9i_a80_cpus_lock, flags);
reg = readl(cpus->reg);
parent = SUN9I_CPUS_MUX_GET_PARENT(reg);
sun9i_a80_cpus_clk_round(rate, &div, &pre_div, parent, parent_rate);
reg = SUN9I_CPUS_DIV_SET(reg, div);
reg = SUN9I_CPUS_PLL4_DIV_SET(reg, pre_div);
writel(reg, cpus->reg);
spin_unlock_irqrestore(&sun9i_a80_cpus_lock, flags);
return 0;
}
static void sun9i_a80_cpus_setup(struct device_node *node)
{
const char *clk_name = node->name;
const char *parents[SUN9I_CPUS_MAX_PARENTS];
struct resource res;
struct sun9i_a80_cpus_clk *cpus;
struct clk_mux *mux;
struct clk *clk;
int ret;
cpus = kzalloc(sizeof(*cpus), GFP_KERNEL);
if (!cpus)
return;
cpus->reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(cpus->reg))
goto err_free_cpus;
of_property_read_string(node, "clock-output-names", &clk_name);
ret = of_clk_parent_fill(node, parents, SUN9I_CPUS_MAX_PARENTS);
mux = kzalloc(sizeof(*mux), GFP_KERNEL);
if (!mux)
goto err_unmap;
mux->reg = cpus->reg;
mux->shift = SUN9I_CPUS_MUX_SHIFT;
mux->mask = SUN9I_CPUS_MUX_MASK >> SUN9I_CPUS_MUX_SHIFT;
mux->lock = &sun9i_a80_cpus_lock;
clk = clk_register_composite(NULL, clk_name, parents, ret,
&mux->hw, &clk_mux_ops,
&cpus->hw, &sun9i_a80_cpus_clk_ops,
NULL, NULL, 0);
if (IS_ERR(clk))
goto err_free_mux;
ret = of_clk_add_provider(node, of_clk_src_simple_get, clk);
if (ret)
goto err_unregister;
return;
err_unregister:
clk_unregister(clk);
err_free_mux:
kfree(mux);
err_unmap:
iounmap(cpus->reg);
of_address_to_resource(node, 0, &res);
release_mem_region(res.start, resource_size(&res));
err_free_cpus:
kfree(cpus);
}
