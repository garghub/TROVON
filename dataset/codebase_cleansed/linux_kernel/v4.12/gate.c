static int omap36xx_gate_clk_enable_with_hsdiv_restore(struct clk_hw *hw)
{
struct clk_omap_divider *parent;
struct clk_hw *parent_hw;
u32 dummy_v, orig_v;
int ret;
ret = omap2_dflt_clk_enable(hw);
parent_hw = clk_hw_get_parent(clk_hw_get_parent(hw));
parent = to_clk_omap_divider(parent_hw);
if (!ret) {
orig_v = ti_clk_ll_ops->clk_readl(&parent->reg);
dummy_v = orig_v;
dummy_v ^= (1 << parent->shift);
ti_clk_ll_ops->clk_writel(dummy_v, &parent->reg);
ti_clk_ll_ops->clk_writel(orig_v, &parent->reg);
}
return ret;
}
static struct clk *_register_gate(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
struct clk_omap_reg *reg, u8 bit_idx,
u8 clk_gate_flags, const struct clk_ops *ops,
const struct clk_hw_omap_ops *hw_ops)
{
struct clk_init_data init = { NULL };
struct clk_hw_omap *clk_hw;
struct clk *clk;
clk_hw = kzalloc(sizeof(*clk_hw), GFP_KERNEL);
if (!clk_hw)
return ERR_PTR(-ENOMEM);
clk_hw->hw.init = &init;
init.name = name;
init.ops = ops;
memcpy(&clk_hw->enable_reg, reg, sizeof(*reg));
clk_hw->enable_bit = bit_idx;
clk_hw->ops = hw_ops;
clk_hw->flags = clk_gate_flags;
init.parent_names = &parent_name;
init.num_parents = 1;
init.flags = flags;
clk = ti_clk_register(NULL, &clk_hw->hw, name);
if (IS_ERR(clk))
kfree(clk_hw);
return clk;
}
struct clk *ti_clk_register_gate(struct ti_clk *setup)
{
const struct clk_ops *ops = &omap_gate_clk_ops;
const struct clk_hw_omap_ops *hw_ops = NULL;
struct clk_omap_reg reg;
u32 flags = 0;
u8 clk_gate_flags = 0;
struct ti_clk_gate *gate;
gate = setup->data;
if (gate->flags & CLKF_INTERFACE)
return ti_clk_register_interface(setup);
if (gate->flags & CLKF_SET_RATE_PARENT)
flags |= CLK_SET_RATE_PARENT;
if (gate->flags & CLKF_SET_BIT_TO_DISABLE)
clk_gate_flags |= INVERT_ENABLE;
if (gate->flags & CLKF_HSDIV) {
ops = &omap_gate_clk_hsdiv_restore_ops;
hw_ops = &clkhwops_wait;
}
if (gate->flags & CLKF_DSS)
hw_ops = &clkhwops_omap3430es2_dss_usbhost_wait;
if (gate->flags & CLKF_WAIT)
hw_ops = &clkhwops_wait;
if (gate->flags & CLKF_CLKDM)
ops = &omap_gate_clkdm_clk_ops;
if (gate->flags & CLKF_AM35XX)
hw_ops = &clkhwops_am35xx_ipss_module_wait;
reg.index = gate->module;
reg.offset = gate->reg;
reg.ptr = NULL;
return _register_gate(NULL, setup->name, gate->parent, flags,
&reg, gate->bit_shift,
clk_gate_flags, ops, hw_ops);
}
struct clk_hw *ti_clk_build_component_gate(struct ti_clk_gate *setup)
{
struct clk_hw_omap *gate;
struct clk_omap_reg *reg;
const struct clk_hw_omap_ops *ops = &clkhwops_wait;
if (!setup)
return NULL;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate)
return ERR_PTR(-ENOMEM);
reg = (struct clk_omap_reg *)&gate->enable_reg;
reg->index = setup->module;
reg->offset = setup->reg;
gate->enable_bit = setup->bit_shift;
if (setup->flags & CLKF_NO_WAIT)
ops = NULL;
if (setup->flags & CLKF_INTERFACE)
ops = &clkhwops_iclk_wait;
gate->ops = ops;
return &gate->hw;
}
static void __init _of_ti_gate_clk_setup(struct device_node *node,
const struct clk_ops *ops,
const struct clk_hw_omap_ops *hw_ops)
{
struct clk *clk;
const char *parent_name;
struct clk_omap_reg reg;
u8 enable_bit = 0;
u32 val;
u32 flags = 0;
u8 clk_gate_flags = 0;
if (ops != &omap_gate_clkdm_clk_ops) {
if (ti_clk_get_reg_addr(node, 0, &reg))
return;
if (!of_property_read_u32(node, "ti,bit-shift", &val))
enable_bit = val;
}
if (of_clk_get_parent_count(node) != 1) {
pr_err("%s must have 1 parent\n", node->name);
return;
}
parent_name = of_clk_get_parent_name(node, 0);
if (of_property_read_bool(node, "ti,set-rate-parent"))
flags |= CLK_SET_RATE_PARENT;
if (of_property_read_bool(node, "ti,set-bit-to-disable"))
clk_gate_flags |= INVERT_ENABLE;
clk = _register_gate(NULL, node->name, parent_name, flags, &reg,
enable_bit, clk_gate_flags, ops, hw_ops);
if (!IS_ERR(clk))
of_clk_add_provider(node, of_clk_src_simple_get, clk);
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
if (ti_clk_get_reg_addr(node, 0, &gate->enable_reg))
goto cleanup;
of_property_read_u32(node, "ti,bit-shift", &val);
gate->enable_bit = val;
gate->ops = hw_ops;
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
