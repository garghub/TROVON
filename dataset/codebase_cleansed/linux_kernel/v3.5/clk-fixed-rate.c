static unsigned long clk_fixed_rate_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return to_clk_fixed_rate(hw)->fixed_rate;
}
struct clk *clk_register_fixed_rate(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
unsigned long fixed_rate)
{
struct clk_fixed_rate *fixed;
struct clk *clk;
struct clk_init_data init;
fixed = kzalloc(sizeof(struct clk_fixed_rate), GFP_KERNEL);
if (!fixed) {
pr_err("%s: could not allocate fixed clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &clk_fixed_rate_ops;
init.flags = flags;
init.parent_names = (parent_name ? &parent_name: NULL);
init.num_parents = (parent_name ? 1 : 0);
fixed->fixed_rate = fixed_rate;
fixed->hw.init = &init;
clk = clk_register(dev, &fixed->hw);
if (IS_ERR(clk))
kfree(fixed);
return clk;
}
