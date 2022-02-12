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
char **parent_names = NULL;
u8 len;
fixed = kzalloc(sizeof(struct clk_fixed_rate), GFP_KERNEL);
if (!fixed) {
pr_err("%s: could not allocate fixed clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
fixed->fixed_rate = fixed_rate;
if (parent_name) {
parent_names = kmalloc(sizeof(char *), GFP_KERNEL);
if (! parent_names)
goto out;
len = sizeof(char) * strlen(parent_name);
parent_names[0] = kmalloc(len, GFP_KERNEL);
if (!parent_names[0])
goto out;
strncpy(parent_names[0], parent_name, len);
}
out:
return clk_register(dev, name,
&clk_fixed_rate_ops, &fixed->hw,
parent_names,
(parent_name ? 1 : 0),
flags);
}
