static void __init of_ti_fixed_factor_clk_setup(struct device_node *node)
{
struct clk *clk;
const char *clk_name = node->name;
const char *parent_name;
u32 div, mult;
u32 flags = 0;
if (of_property_read_u32(node, "ti,clock-div", &div)) {
pr_err("%s must have a clock-div property\n", node->name);
return;
}
if (of_property_read_u32(node, "ti,clock-mult", &mult)) {
pr_err("%s must have a clock-mult property\n", node->name);
return;
}
if (of_property_read_bool(node, "ti,set-rate-parent"))
flags |= CLK_SET_RATE_PARENT;
parent_name = of_clk_get_parent_name(node, 0);
clk = clk_register_fixed_factor(NULL, clk_name, parent_name, flags,
mult, div);
if (!IS_ERR(clk)) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
of_ti_clk_autoidle_setup(node);
ti_clk_add_alias(NULL, clk, clk_name);
}
}
