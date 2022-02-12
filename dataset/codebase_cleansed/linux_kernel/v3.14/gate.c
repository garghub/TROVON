static int omap36xx_gate_clk_enable_with_hsdiv_restore(struct clk_hw *clk)
{
struct clk_divider *parent;
struct clk_hw *parent_hw;
u32 dummy_v, orig_v;
int ret;
ret = omap2_dflt_clk_enable(clk);
parent_hw = __clk_get_hw(__clk_get_parent(__clk_get_parent(clk->clk)));
parent = to_clk_divider(parent_hw);
if (!ret) {
orig_v = ti_clk_ll_ops->clk_readl(parent->reg);
dummy_v = orig_v;
dummy_v ^= (1 << parent->shift);
ti_clk_ll_ops->clk_writel(dummy_v, parent->reg);
ti_clk_ll_ops->clk_writel(orig_v, parent->reg);
}
return ret;
}
static void __init _of_ti_gate_clk_setup(struct device_node *node,
const struct clk_ops *ops,
const struct clk_hw_omap_ops *hw_ops)
{
struct clk *clk;
struct clk_init_data init = { NULL };
struct clk_hw_omap *clk_hw;
const char *clk_name = node->name;
const char *parent_name;
u32 val;
clk_hw = kzalloc(sizeof(*clk_hw), GFP_KERNEL);
if (!clk_hw)
return;
clk_hw->hw.init = &init;
init.name = clk_name;
init.ops = ops;
if (ops != &omap_gate_clkdm_clk_ops) {
clk_hw->enable_reg = ti_clk_get_reg_addr(node, 0);
if (!clk_hw->enable_reg)
goto cleanup;
if (!of_property_read_u32(node, "ti,bit-shift", &val))
clk_hw->enable_bit = val;
}
clk_hw->ops = hw_ops;
clk_hw->flags = MEMMAP_ADDRESSING;
if (of_clk_get_parent_count(node) != 1) {
pr_err("%s must have 1 parent\n", clk_name);
goto cleanup;
}
parent_name = of_clk_get_parent_name(node, 0);
init.parent_names = &parent_name;
init.num_parents = 1;
if (of_property_read_bool(node, "ti,set-rate-parent"))
init.flags |= CLK_SET_RATE_PARENT;
if (of_property_read_bool(node, "ti,set-bit-to-disable"))
clk_hw->flags |= INVERT_ENABLE;
clk = clk_register(NULL, &clk_hw->hw);
if (!IS_ERR(clk)) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
return;
}
cleanup:
kfree(clk_hw);
}
static void __init
_of_ti_composite_gate_clk_setup(struct device_node *node,
const struct clk_hw_omap_ops *hw_ops)
{
struct clk_hw_omap *gate;
u32 val = 0;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate)
return;
gate->enable_reg = ti_clk_get_reg_addr(node, 0);
if (!gate->enable_reg)
goto cleanup;
of_property_read_u32(node, "ti,bit-shift", &val);
gate->enable_bit = val;
gate->ops = hw_ops;
gate->flags = MEMMAP_ADDRESSING;
if (!ti_clk_add_component(node, &gate->hw, CLK_COMPONENT_TYPE_GATE))
return;
cleanup:
kfree(gate);
}
static void __init
of_ti_composite_no_wait_gate_clk_setup(struct device_node *node)
{
_of_ti_composite_gate_clk_setup(node, NULL);
}
static void __init of_ti_composite_interface_clk_setup(struct device_node *node)
{
_of_ti_composite_gate_clk_setup(node, &clkhwops_iclk_wait);
}
static void __init of_ti_composite_gate_clk_setup(struct device_node *node)
{
_of_ti_composite_gate_clk_setup(node, &clkhwops_wait);
}
static void __init of_ti_clkdm_gate_clk_setup(struct device_node *node)
{
_of_ti_gate_clk_setup(node, &omap_gate_clkdm_clk_ops, NULL);
}
static void __init of_ti_hsdiv_gate_clk_setup(struct device_node *node)
{
_of_ti_gate_clk_setup(node, &omap_gate_clk_hsdiv_restore_ops,
&clkhwops_wait);
}
static void __init of_ti_gate_clk_setup(struct device_node *node)
{
_of_ti_gate_clk_setup(node, &omap_gate_clk_ops, NULL);
}
static void __init of_ti_wait_gate_clk_setup(struct device_node *node)
{
_of_ti_gate_clk_setup(node, &omap_gate_clk_ops, &clkhwops_wait);
}
static void __init of_ti_am35xx_gate_clk_setup(struct device_node *node)
{
_of_ti_gate_clk_setup(node, &omap_gate_clk_ops,
&clkhwops_am35xx_ipss_module_wait);
}
static void __init of_ti_dss_gate_clk_setup(struct device_node *node)
{
_of_ti_gate_clk_setup(node, &omap_gate_clk_ops,
&clkhwops_omap3430es2_dss_usbhost_wait);
}
