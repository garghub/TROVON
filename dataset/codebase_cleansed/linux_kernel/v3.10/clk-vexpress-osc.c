static unsigned long vexpress_osc_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct vexpress_osc *osc = to_vexpress_osc(hw);
u32 rate;
vexpress_config_read(osc->func, 0, &rate);
return rate;
}
static long vexpress_osc_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct vexpress_osc *osc = to_vexpress_osc(hw);
if (WARN_ON(osc->rate_min && rate < osc->rate_min))
rate = osc->rate_min;
if (WARN_ON(osc->rate_max && rate > osc->rate_max))
rate = osc->rate_max;
return rate;
}
static int vexpress_osc_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct vexpress_osc *osc = to_vexpress_osc(hw);
return vexpress_config_write(osc->func, 0, rate);
}
struct clk * __init vexpress_osc_setup(struct device *dev)
{
struct clk_init_data init;
struct vexpress_osc *osc = kzalloc(sizeof(*osc), GFP_KERNEL);
if (!osc)
return NULL;
osc->func = vexpress_config_func_get_by_dev(dev);
if (!osc->func) {
kfree(osc);
return NULL;
}
init.name = dev_name(dev);
init.ops = &vexpress_osc_ops;
init.flags = CLK_IS_ROOT;
init.num_parents = 0;
osc->hw.init = &init;
return clk_register(NULL, &osc->hw);
}
void __init vexpress_osc_of_setup(struct device_node *node)
{
struct clk_init_data init;
struct vexpress_osc *osc;
struct clk *clk;
u32 range[2];
osc = kzalloc(sizeof(*osc), GFP_KERNEL);
if (!osc)
goto error;
osc->func = vexpress_config_func_get_by_node(node);
if (!osc->func) {
pr_err("Failed to obtain config func for node '%s'!\n",
node->name);
goto error;
}
if (of_property_read_u32_array(node, "freq-range", range,
ARRAY_SIZE(range)) == 0) {
osc->rate_min = range[0];
osc->rate_max = range[1];
}
of_property_read_string(node, "clock-output-names", &init.name);
if (!init.name)
init.name = node->name;
init.ops = &vexpress_osc_ops;
init.flags = CLK_IS_ROOT;
init.num_parents = 0;
osc->hw.init = &init;
clk = clk_register(NULL, &osc->hw);
if (IS_ERR(clk)) {
pr_err("Failed to register clock '%s'!\n", init.name);
goto error;
}
of_clk_add_provider(node, of_clk_src_simple_get, clk);
pr_debug("Registered clock '%s'\n", init.name);
return;
error:
if (osc->func)
vexpress_config_func_put(osc->func);
kfree(osc);
}
