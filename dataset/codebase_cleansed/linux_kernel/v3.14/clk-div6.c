static int cpg_div6_clock_enable(struct clk_hw *hw)
{
struct div6_clock *clock = to_div6_clock(hw);
clk_writel(CPG_DIV6_DIV(clock->div - 1), clock->reg);
return 0;
}
static void cpg_div6_clock_disable(struct clk_hw *hw)
{
struct div6_clock *clock = to_div6_clock(hw);
clk_writel(CPG_DIV6_CKSTP | CPG_DIV6_DIV(CPG_DIV6_DIV_MASK),
clock->reg);
}
static int cpg_div6_clock_is_enabled(struct clk_hw *hw)
{
struct div6_clock *clock = to_div6_clock(hw);
return !(clk_readl(clock->reg) & CPG_DIV6_CKSTP);
}
static unsigned long cpg_div6_clock_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct div6_clock *clock = to_div6_clock(hw);
unsigned int div = (clk_readl(clock->reg) & CPG_DIV6_DIV_MASK) + 1;
return parent_rate / div;
}
static unsigned int cpg_div6_clock_calc_div(unsigned long rate,
unsigned long parent_rate)
{
unsigned int div;
div = DIV_ROUND_CLOSEST(parent_rate, rate);
return clamp_t(unsigned int, div, 1, 64);
}
static long cpg_div6_clock_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned int div = cpg_div6_clock_calc_div(rate, *parent_rate);
return *parent_rate / div;
}
static int cpg_div6_clock_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct div6_clock *clock = to_div6_clock(hw);
unsigned int div = cpg_div6_clock_calc_div(rate, parent_rate);
clock->div = div;
if (!(clk_readl(clock->reg) & CPG_DIV6_CKSTP))
clk_writel(CPG_DIV6_DIV(clock->div - 1), clock->reg);
return 0;
}
static void __init cpg_div6_clock_init(struct device_node *np)
{
struct clk_init_data init;
struct div6_clock *clock;
const char *parent_name;
const char *name;
struct clk *clk;
int ret;
clock = kzalloc(sizeof(*clock), GFP_KERNEL);
if (!clock) {
pr_err("%s: failed to allocate %s DIV6 clock\n",
__func__, np->name);
return;
}
clock->reg = of_iomap(np, 0);
if (clock->reg == NULL) {
pr_err("%s: failed to map %s DIV6 clock register\n",
__func__, np->name);
goto error;
}
clock->div = (clk_readl(clock->reg) & CPG_DIV6_DIV_MASK) + 1;
ret = of_property_read_string(np, "clock-output-names", &name);
if (ret < 0) {
pr_err("%s: failed to get %s DIV6 clock output name\n",
__func__, np->name);
goto error;
}
parent_name = of_clk_get_parent_name(np, 0);
if (parent_name == NULL) {
pr_err("%s: failed to get %s DIV6 clock parent name\n",
__func__, np->name);
goto error;
}
init.name = name;
init.ops = &cpg_div6_clock_ops;
init.flags = CLK_IS_BASIC;
init.parent_names = &parent_name;
init.num_parents = 1;
clock->hw.init = &init;
clk = clk_register(NULL, &clock->hw);
if (IS_ERR(clk)) {
pr_err("%s: failed to register %s DIV6 clock (%ld)\n",
__func__, np->name, PTR_ERR(clk));
goto error;
}
of_clk_add_provider(np, of_clk_src_simple_get, clk);
return;
error:
if (clock->reg)
iounmap(clock->reg);
kfree(clock);
}
