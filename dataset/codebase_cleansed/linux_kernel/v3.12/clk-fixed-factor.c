static unsigned long clk_factor_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_fixed_factor *fix = to_clk_fixed_factor(hw);
unsigned long long int rate;
rate = (unsigned long long int)parent_rate * fix->mult;
do_div(rate, fix->div);
return (unsigned long)rate;
}
static long clk_factor_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_fixed_factor *fix = to_clk_fixed_factor(hw);
if (__clk_get_flags(hw->clk) & CLK_SET_RATE_PARENT) {
unsigned long best_parent;
best_parent = (rate / fix->mult) * fix->div;
*prate = __clk_round_rate(__clk_get_parent(hw->clk),
best_parent);
}
return (*prate / fix->div) * fix->mult;
}
static int clk_factor_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
return 0;
}
struct clk *clk_register_fixed_factor(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
unsigned int mult, unsigned int div)
{
struct clk_fixed_factor *fix;
struct clk_init_data init;
struct clk *clk;
fix = kmalloc(sizeof(*fix), GFP_KERNEL);
if (!fix) {
pr_err("%s: could not allocate fixed factor clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
fix->mult = mult;
fix->div = div;
fix->hw.init = &init;
init.name = name;
init.ops = &clk_fixed_factor_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = &parent_name;
init.num_parents = 1;
clk = clk_register(dev, &fix->hw);
if (IS_ERR(clk))
kfree(fix);
return clk;
}
void __init of_fixed_factor_clk_setup(struct device_node *node)
{
struct clk *clk;
const char *clk_name = node->name;
const char *parent_name;
u32 div, mult;
if (of_property_read_u32(node, "clock-div", &div)) {
pr_err("%s Fixed factor clock <%s> must have a clock-div property\n",
__func__, node->name);
return;
}
if (of_property_read_u32(node, "clock-mult", &mult)) {
pr_err("%s Fixed factor clock <%s> must have a clokc-mult property\n",
__func__, node->name);
return;
}
of_property_read_string(node, "clock-output-names", &clk_name);
parent_name = of_clk_get_parent_name(node, 0);
clk = clk_register_fixed_factor(NULL, clk_name, parent_name, 0,
mult, div);
if (!IS_ERR(clk))
of_clk_add_provider(node, of_clk_src_simple_get, clk);
}
