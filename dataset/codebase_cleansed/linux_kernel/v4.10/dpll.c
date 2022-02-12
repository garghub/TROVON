static void __init _register_dpll(struct clk_hw *hw,
struct device_node *node)
{
struct clk_hw_omap *clk_hw = to_clk_hw_omap(hw);
struct dpll_data *dd = clk_hw->dpll_data;
struct clk *clk;
clk = of_clk_get(node, 0);
if (IS_ERR(clk)) {
pr_debug("clk-ref missing for %s, retry later\n",
node->name);
if (!ti_clk_retry_init(node, hw, _register_dpll))
return;
goto cleanup;
}
dd->clk_ref = __clk_get_hw(clk);
clk = of_clk_get(node, 1);
if (IS_ERR(clk)) {
pr_debug("clk-bypass missing for %s, retry later\n",
node->name);
if (!ti_clk_retry_init(node, hw, _register_dpll))
return;
goto cleanup;
}
dd->clk_bypass = __clk_get_hw(clk);
clk = clk_register(NULL, &clk_hw->hw);
if (!IS_ERR(clk)) {
omap2_init_clk_hw_omap_clocks(&clk_hw->hw);
of_clk_add_provider(node, of_clk_src_simple_get, clk);
kfree(clk_hw->hw.init->parent_names);
kfree(clk_hw->hw.init);
return;
}
cleanup:
kfree(clk_hw->dpll_data);
kfree(clk_hw->hw.init->parent_names);
kfree(clk_hw->hw.init);
kfree(clk_hw);
}
static void __iomem *_get_reg(u8 module, u16 offset)
{
u32 reg;
struct clk_omap_reg *reg_setup;
reg_setup = (struct clk_omap_reg *)&reg;
reg_setup->index = module;
reg_setup->offset = offset;
return (void __iomem *)reg;
}
struct clk *ti_clk_register_dpll(struct ti_clk *setup)
{
struct clk_hw_omap *clk_hw;
struct clk_init_data init = { NULL };
struct dpll_data *dd;
struct clk *clk;
struct ti_clk_dpll *dpll;
const struct clk_ops *ops = &omap3_dpll_ck_ops;
struct clk *clk_ref;
struct clk *clk_bypass;
dpll = setup->data;
if (dpll->num_parents < 2)
return ERR_PTR(-EINVAL);
clk_ref = clk_get_sys(NULL, dpll->parents[0]);
clk_bypass = clk_get_sys(NULL, dpll->parents[1]);
if (IS_ERR_OR_NULL(clk_ref) || IS_ERR_OR_NULL(clk_bypass))
return ERR_PTR(-EAGAIN);
dd = kzalloc(sizeof(*dd), GFP_KERNEL);
clk_hw = kzalloc(sizeof(*clk_hw), GFP_KERNEL);
if (!dd || !clk_hw) {
clk = ERR_PTR(-ENOMEM);
goto cleanup;
}
clk_hw->dpll_data = dd;
clk_hw->ops = &clkhwops_omap3_dpll;
clk_hw->hw.init = &init;
clk_hw->flags = MEMMAP_ADDRESSING;
init.name = setup->name;
init.ops = ops;
init.num_parents = dpll->num_parents;
init.parent_names = dpll->parents;
dd->control_reg = _get_reg(dpll->module, dpll->control_reg);
dd->idlest_reg = _get_reg(dpll->module, dpll->idlest_reg);
dd->mult_div1_reg = _get_reg(dpll->module, dpll->mult_div1_reg);
dd->autoidle_reg = _get_reg(dpll->module, dpll->autoidle_reg);
dd->modes = dpll->modes;
dd->div1_mask = dpll->div1_mask;
dd->idlest_mask = dpll->idlest_mask;
dd->mult_mask = dpll->mult_mask;
dd->autoidle_mask = dpll->autoidle_mask;
dd->enable_mask = dpll->enable_mask;
dd->sddiv_mask = dpll->sddiv_mask;
dd->dco_mask = dpll->dco_mask;
dd->max_divider = dpll->max_divider;
dd->min_divider = dpll->min_divider;
dd->max_multiplier = dpll->max_multiplier;
dd->auto_recal_bit = dpll->auto_recal_bit;
dd->recal_en_bit = dpll->recal_en_bit;
dd->recal_st_bit = dpll->recal_st_bit;
dd->clk_ref = __clk_get_hw(clk_ref);
dd->clk_bypass = __clk_get_hw(clk_bypass);
if (dpll->flags & CLKF_CORE)
ops = &omap3_dpll_core_ck_ops;
if (dpll->flags & CLKF_PER)
ops = &omap3_dpll_per_ck_ops;
if (dpll->flags & CLKF_J_TYPE)
dd->flags |= DPLL_J_TYPE;
clk = clk_register(NULL, &clk_hw->hw);
if (!IS_ERR(clk))
return clk;
cleanup:
kfree(dd);
kfree(clk_hw);
return clk;
}
static void _register_dpll_x2(struct device_node *node,
const struct clk_ops *ops,
const struct clk_hw_omap_ops *hw_ops)
{
struct clk *clk;
struct clk_init_data init = { NULL };
struct clk_hw_omap *clk_hw;
const char *name = node->name;
const char *parent_name;
parent_name = of_clk_get_parent_name(node, 0);
if (!parent_name) {
pr_err("%s must have parent\n", node->name);
return;
}
clk_hw = kzalloc(sizeof(*clk_hw), GFP_KERNEL);
if (!clk_hw)
return;
clk_hw->ops = hw_ops;
clk_hw->hw.init = &init;
init.name = name;
init.ops = ops;
init.parent_names = &parent_name;
init.num_parents = 1;
clk = clk_register(NULL, &clk_hw->hw);
if (IS_ERR(clk)) {
kfree(clk_hw);
} else {
omap2_init_clk_hw_omap_clocks(&clk_hw->hw);
of_clk_add_provider(node, of_clk_src_simple_get, clk);
}
}
static void __init of_ti_dpll_setup(struct device_node *node,
const struct clk_ops *ops,
const struct dpll_data *ddt)
{
struct clk_hw_omap *clk_hw = NULL;
struct clk_init_data *init = NULL;
const char **parent_names = NULL;
struct dpll_data *dd = NULL;
u8 dpll_mode = 0;
dd = kzalloc(sizeof(*dd), GFP_KERNEL);
clk_hw = kzalloc(sizeof(*clk_hw), GFP_KERNEL);
init = kzalloc(sizeof(*init), GFP_KERNEL);
if (!dd || !clk_hw || !init)
goto cleanup;
memcpy(dd, ddt, sizeof(*dd));
clk_hw->dpll_data = dd;
clk_hw->ops = &clkhwops_omap3_dpll;
clk_hw->hw.init = init;
clk_hw->flags = MEMMAP_ADDRESSING;
init->name = node->name;
init->ops = ops;
init->num_parents = of_clk_get_parent_count(node);
if (!init->num_parents) {
pr_err("%s must have parent(s)\n", node->name);
goto cleanup;
}
parent_names = kzalloc(sizeof(char *) * init->num_parents, GFP_KERNEL);
if (!parent_names)
goto cleanup;
of_clk_parent_fill(node, parent_names, init->num_parents);
init->parent_names = parent_names;
dd->control_reg = ti_clk_get_reg_addr(node, 0);
if (!dd->idlest_mask) {
dd->mult_div1_reg = ti_clk_get_reg_addr(node, 1);
#ifdef CONFIG_ARCH_OMAP2
clk_hw->ops = &clkhwops_omap2xxx_dpll;
omap2xxx_clkt_dpllcore_init(&clk_hw->hw);
#endif
} else {
dd->idlest_reg = ti_clk_get_reg_addr(node, 1);
if (IS_ERR(dd->idlest_reg))
goto cleanup;
dd->mult_div1_reg = ti_clk_get_reg_addr(node, 2);
}
if (IS_ERR(dd->control_reg) || IS_ERR(dd->mult_div1_reg))
goto cleanup;
if (dd->autoidle_mask) {
dd->autoidle_reg = ti_clk_get_reg_addr(node, 3);
if (IS_ERR(dd->autoidle_reg))
goto cleanup;
}
if (of_property_read_bool(node, "ti,low-power-stop"))
dpll_mode |= 1 << DPLL_LOW_POWER_STOP;
if (of_property_read_bool(node, "ti,low-power-bypass"))
dpll_mode |= 1 << DPLL_LOW_POWER_BYPASS;
if (of_property_read_bool(node, "ti,lock"))
dpll_mode |= 1 << DPLL_LOCKED;
if (dpll_mode)
dd->modes = dpll_mode;
_register_dpll(&clk_hw->hw, node);
return;
cleanup:
kfree(dd);
kfree(parent_names);
kfree(init);
kfree(clk_hw);
}
static void __init of_ti_omap4_dpll_x2_setup(struct device_node *node)
{
_register_dpll_x2(node, &dpll_x2_ck_ops, &clkhwops_omap4_dpllmx);
}
static void __init of_ti_am3_dpll_x2_setup(struct device_node *node)
{
_register_dpll_x2(node, &dpll_x2_ck_ops, NULL);
}
static void __init of_ti_omap3_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.autoidle_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.freqsel_mask = 0xf0,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
if ((of_machine_is_compatible("ti,omap3630") ||
of_machine_is_compatible("ti,omap36xx")) &&
!strcmp(node->name, "dpll5_ck"))
of_ti_dpll_setup(node, &omap3_dpll5_ck_ops, &dd);
else
of_ti_dpll_setup(node, &omap3_dpll_ck_ops, &dd);
}
static void __init of_ti_omap3_core_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.autoidle_mask = 0x7,
.mult_mask = 0x7ff << 16,
.div1_mask = 0x7f << 8,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.freqsel_mask = 0xf0,
};
of_ti_dpll_setup(node, &omap3_dpll_core_ck_ops, &dd);
}
static void __init of_ti_omap3_per_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1 << 1,
.enable_mask = 0x7 << 16,
.autoidle_mask = 0x7 << 3,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.freqsel_mask = 0xf00000,
.modes = (1 << DPLL_LOW_POWER_STOP) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &omap3_dpll_per_ck_ops, &dd);
}
static void __init of_ti_omap3_per_jtype_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1 << 1,
.enable_mask = 0x7 << 16,
.autoidle_mask = 0x7 << 3,
.mult_mask = 0xfff << 8,
.div1_mask = 0x7f,
.max_multiplier = 4095,
.max_divider = 128,
.min_divider = 1,
.sddiv_mask = 0xff << 24,
.dco_mask = 0xe << 20,
.flags = DPLL_J_TYPE,
.modes = (1 << DPLL_LOW_POWER_STOP) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &omap3_dpll_per_ck_ops, &dd);
}
static void __init of_ti_omap4_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.autoidle_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_ck_ops, &dd);
}
static void __init of_ti_omap5_mpu_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.autoidle_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.dcc_mask = BIT(22),
.dcc_rate = 1400000000,
.min_divider = 1,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_ck_ops, &dd);
}
static void __init of_ti_omap4_core_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.autoidle_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_core_ck_ops, &dd);
}
static void __init of_ti_omap4_m4xen_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.autoidle_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.m4xen_mask = 0x800,
.lpmode_mask = 1 << 10,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_m4xen_ck_ops, &dd);
}
static void __init of_ti_omap4_jtype_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.autoidle_mask = 0x7,
.mult_mask = 0xfff << 8,
.div1_mask = 0xff,
.max_multiplier = 4095,
.max_divider = 256,
.min_divider = 1,
.sddiv_mask = 0xff << 24,
.flags = DPLL_J_TYPE,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_m4xen_ck_ops, &dd);
}
static void __init of_ti_am3_no_gate_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.max_rate = 1000000000,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_no_gate_ck_ops, &dd);
}
static void __init of_ti_am3_jtype_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 4095,
.max_divider = 256,
.min_divider = 2,
.flags = DPLL_J_TYPE,
.max_rate = 2000000000,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_ck_ops, &dd);
}
static void __init of_ti_am3_no_gate_jtype_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.max_rate = 2000000000,
.flags = DPLL_J_TYPE,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_no_gate_ck_ops, &dd);
}
static void __init of_ti_am3_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.max_rate = 1000000000,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_ck_ops, &dd);
}
static void __init of_ti_am3_core_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.idlest_mask = 0x1,
.enable_mask = 0x7,
.mult_mask = 0x7ff << 8,
.div1_mask = 0x7f,
.max_multiplier = 2047,
.max_divider = 128,
.min_divider = 1,
.max_rate = 1000000000,
.modes = (1 << DPLL_LOW_POWER_BYPASS) | (1 << DPLL_LOCKED),
};
of_ti_dpll_setup(node, &dpll_core_ck_ops, &dd);
}
static void __init of_ti_omap2_core_dpll_setup(struct device_node *node)
{
const struct dpll_data dd = {
.enable_mask = 0x3,
.mult_mask = 0x3ff << 12,
.div1_mask = 0xf << 8,
.max_divider = 16,
.min_divider = 1,
};
of_ti_dpll_setup(node, &omap2_dpll_core_ck_ops, &dd);
}
