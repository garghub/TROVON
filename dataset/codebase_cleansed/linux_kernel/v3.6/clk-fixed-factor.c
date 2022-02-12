static unsigned long clk_factor_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_fixed_factor *fix = to_clk_fixed_factor(hw);
return parent_rate * fix->mult / fix->div;
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
