static void __init sun4i_pll2_setup(struct device_node *node,
int post_div_offset)
{
const char *clk_name = node->name, *parent;
struct clk **clks, *base_clk, *prediv_clk;
struct clk_onecell_data *clk_data;
struct clk_multiplier *mult;
struct clk_gate *gate;
void __iomem *reg;
u32 val;
reg = of_io_request_and_map(node, 0, of_node_full_name(node));
if (IS_ERR(reg))
return;
clk_data = kzalloc(sizeof(*clk_data), GFP_KERNEL);
if (!clk_data)
goto err_unmap;
clks = kcalloc(SUN4I_PLL2_OUTPUTS, sizeof(struct clk *), GFP_KERNEL);
if (!clks)
goto err_free_data;
parent = of_clk_get_parent_name(node, 0);
prediv_clk = clk_register_divider(NULL, "pll2-prediv",
parent, 0, reg,
SUN4I_PLL2_PRE_DIV_SHIFT,
SUN4I_PLL2_PRE_DIV_WIDTH,
CLK_DIVIDER_ONE_BASED | CLK_DIVIDER_ALLOW_ZERO,
&sun4i_a10_pll2_lock);
if (!prediv_clk) {
pr_err("Couldn't register the prediv clock\n");
goto err_free_array;
}
gate = kzalloc(sizeof(struct clk_gate), GFP_KERNEL);
if (!gate)
goto err_unregister_prediv;
gate->reg = reg;
gate->bit_idx = SUN4I_PLL2_ENABLE;
gate->lock = &sun4i_a10_pll2_lock;
mult = kzalloc(sizeof(struct clk_multiplier), GFP_KERNEL);
if (!mult)
goto err_free_gate;
mult->reg = reg;
mult->shift = SUN4I_PLL2_N_SHIFT;
mult->width = 7;
mult->flags = CLK_MULTIPLIER_ZERO_BYPASS |
CLK_MULTIPLIER_ROUND_CLOSEST;
mult->lock = &sun4i_a10_pll2_lock;
parent = __clk_get_name(prediv_clk);
base_clk = clk_register_composite(NULL, "pll2-base",
&parent, 1,
NULL, NULL,
&mult->hw, &clk_multiplier_ops,
&gate->hw, &clk_gate_ops,
CLK_SET_RATE_PARENT);
if (!base_clk) {
pr_err("Couldn't register the base multiplier clock\n");
goto err_free_multiplier;
}
parent = __clk_get_name(base_clk);
val = readl(reg);
val &= ~(SUN4I_PLL2_POST_DIV_MASK << SUN4I_PLL2_POST_DIV_SHIFT);
val |= (SUN4I_PLL2_POST_DIV_VALUE - post_div_offset) << SUN4I_PLL2_POST_DIV_SHIFT;
writel(val, reg);
of_property_read_string_index(node, "clock-output-names",
SUN4I_A10_PLL2_1X, &clk_name);
clks[SUN4I_A10_PLL2_1X] = clk_register_fixed_factor(NULL, clk_name,
parent,
CLK_SET_RATE_PARENT,
1,
SUN4I_PLL2_POST_DIV_VALUE);
WARN_ON(IS_ERR(clks[SUN4I_A10_PLL2_1X]));
of_property_read_string_index(node, "clock-output-names",
SUN4I_A10_PLL2_2X, &clk_name);
clks[SUN4I_A10_PLL2_2X] = clk_register_fixed_factor(NULL, clk_name,
parent,
CLK_SET_RATE_PARENT,
1, 2);
WARN_ON(IS_ERR(clks[SUN4I_A10_PLL2_2X]));
of_property_read_string_index(node, "clock-output-names",
SUN4I_A10_PLL2_4X, &clk_name);
clks[SUN4I_A10_PLL2_4X] = clk_register_fixed_factor(NULL, clk_name,
parent,
CLK_SET_RATE_PARENT,
1, 1);
WARN_ON(IS_ERR(clks[SUN4I_A10_PLL2_4X]));
of_property_read_string_index(node, "clock-output-names",
SUN4I_A10_PLL2_8X, &clk_name);
clks[SUN4I_A10_PLL2_8X] = clk_register_fixed_factor(NULL, clk_name,
parent,
CLK_SET_RATE_PARENT,
2, 1);
WARN_ON(IS_ERR(clks[SUN4I_A10_PLL2_8X]));
clk_data->clks = clks;
clk_data->clk_num = SUN4I_PLL2_OUTPUTS;
of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
return;
err_free_multiplier:
kfree(mult);
err_free_gate:
kfree(gate);
err_unregister_prediv:
clk_unregister_divider(prediv_clk);
err_free_array:
kfree(clks);
err_free_data:
kfree(clk_data);
err_unmap:
iounmap(reg);
}
static void __init sun4i_a10_pll2_setup(struct device_node *node)
{
sun4i_pll2_setup(node, 0);
}
static void __init sun5i_a13_pll2_setup(struct device_node *node)
{
sun4i_pll2_setup(node, 1);
}
