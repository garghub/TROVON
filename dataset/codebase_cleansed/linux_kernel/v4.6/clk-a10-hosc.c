static void __init sun4i_osc_clk_setup(struct device_node *node)
{
struct clk *clk;
struct clk_fixed_rate *fixed;
struct clk_gate *gate;
const char *clk_name = node->name;
u32 rate;
if (of_property_read_u32(node, "clock-frequency", &rate))
return;
fixed = kzalloc(sizeof(struct clk_fixed_rate), GFP_KERNEL);
if (!fixed)
return;
gate = kzalloc(sizeof(struct clk_gate), GFP_KERNEL);
if (!gate)
goto err_free_fixed;
of_property_read_string(node, "clock-output-names", &clk_name);
gate->reg = of_iomap(node, 0);
gate->bit_idx = SUNXI_OSC24M_GATE;
gate->lock = &hosc_lock;
fixed->fixed_rate = rate;
clk = clk_register_composite(NULL, clk_name,
NULL, 0,
NULL, NULL,
&fixed->hw, &clk_fixed_rate_ops,
&gate->hw, &clk_gate_ops,
CLK_IS_ROOT);
if (IS_ERR(clk))
goto err_free_gate;
of_clk_add_provider(node, of_clk_src_simple_get, clk);
return;
err_free_gate:
kfree(gate);
err_free_fixed:
kfree(fixed);
}
