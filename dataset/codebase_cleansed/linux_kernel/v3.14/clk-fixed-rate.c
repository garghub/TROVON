static unsigned long clk_fixed_rate_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return to_clk_fixed_rate(hw)->fixed_rate;
}
static unsigned long clk_fixed_rate_recalc_accuracy(struct clk_hw *hw,
unsigned long parent_accuracy)
{
return to_clk_fixed_rate(hw)->fixed_accuracy;
}
struct clk *clk_register_fixed_rate_with_accuracy(struct device *dev,
const char *name, const char *parent_name, unsigned long flags,
unsigned long fixed_rate, unsigned long fixed_accuracy)
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
init.flags = flags | CLK_IS_BASIC;
init.parent_names = (parent_name ? &parent_name: NULL);
init.num_parents = (parent_name ? 1 : 0);
fixed->fixed_rate = fixed_rate;
fixed->fixed_accuracy = fixed_accuracy;
fixed->hw.init = &init;
clk = clk_register(dev, &fixed->hw);
if (IS_ERR(clk))
kfree(fixed);
return clk;
}
struct clk *clk_register_fixed_rate(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
unsigned long fixed_rate)
{
return clk_register_fixed_rate_with_accuracy(dev, name, parent_name,
flags, fixed_rate, 0);
}
void of_fixed_clk_setup(struct device_node *node)
{
struct clk *clk;
const char *clk_name = node->name;
u32 rate;
u32 accuracy = 0;
if (of_property_read_u32(node, "clock-frequency", &rate))
return;
of_property_read_u32(node, "clock-accuracy", &accuracy);
of_property_read_string(node, "clock-output-names", &clk_name);
clk = clk_register_fixed_rate_with_accuracy(NULL, clk_name, NULL,
CLK_IS_ROOT, rate,
accuracy);
if (!IS_ERR(clk))
of_clk_add_provider(node, of_clk_src_simple_get, clk);
}
