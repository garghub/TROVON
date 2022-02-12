int omap2_clk_deny_idle(struct clk *clk)
{
struct clk_hw_omap *c;
c = to_clk_hw_omap(__clk_get_hw(clk));
if (c->ops && c->ops->deny_idle)
c->ops->deny_idle(c);
return 0;
}
int omap2_clk_allow_idle(struct clk *clk)
{
struct clk_hw_omap *c;
c = to_clk_hw_omap(__clk_get_hw(clk));
if (c->ops && c->ops->allow_idle)
c->ops->allow_idle(c);
return 0;
}
static void _allow_autoidle(struct clk_ti_autoidle *clk)
{
u32 val;
val = ti_clk_ll_ops->clk_readl(&clk->reg);
if (clk->flags & AUTOIDLE_LOW)
val &= ~(1 << clk->shift);
else
val |= (1 << clk->shift);
ti_clk_ll_ops->clk_writel(val, &clk->reg);
}
static void _deny_autoidle(struct clk_ti_autoidle *clk)
{
u32 val;
val = ti_clk_ll_ops->clk_readl(&clk->reg);
if (clk->flags & AUTOIDLE_LOW)
val |= (1 << clk->shift);
else
val &= ~(1 << clk->shift);
ti_clk_ll_ops->clk_writel(val, &clk->reg);
}
static void _clk_generic_allow_autoidle_all(void)
{
struct clk_ti_autoidle *c;
list_for_each_entry(c, &autoidle_clks, node)
_allow_autoidle(c);
}
static void _clk_generic_deny_autoidle_all(void)
{
struct clk_ti_autoidle *c;
list_for_each_entry(c, &autoidle_clks, node)
_deny_autoidle(c);
}
int __init of_ti_clk_autoidle_setup(struct device_node *node)
{
u32 shift;
struct clk_ti_autoidle *clk;
int ret;
if (of_property_read_u32(node, "ti,autoidle-shift", &shift))
return 0;
clk = kzalloc(sizeof(*clk), GFP_KERNEL);
if (!clk)
return -ENOMEM;
clk->shift = shift;
clk->name = node->name;
ret = ti_clk_get_reg_addr(node, 0, &clk->reg);
if (ret) {
kfree(clk);
return ret;
}
if (of_property_read_bool(node, "ti,invert-autoidle-bit"))
clk->flags |= AUTOIDLE_LOW;
list_add(&clk->node, &autoidle_clks);
return 0;
}
void omap2_init_clk_hw_omap_clocks(struct clk_hw *hw)
{
struct clk_hw_omap *c;
if (clk_hw_get_flags(hw) & CLK_IS_BASIC)
return;
c = to_clk_hw_omap(hw);
list_add(&c->node, &clk_hw_omap_clocks);
}
int omap2_clk_enable_autoidle_all(void)
{
struct clk_hw_omap *c;
list_for_each_entry(c, &clk_hw_omap_clocks, node)
if (c->ops && c->ops->allow_idle)
c->ops->allow_idle(c);
_clk_generic_allow_autoidle_all();
return 0;
}
int omap2_clk_disable_autoidle_all(void)
{
struct clk_hw_omap *c;
list_for_each_entry(c, &clk_hw_omap_clocks, node)
if (c->ops && c->ops->deny_idle)
c->ops->deny_idle(c);
_clk_generic_deny_autoidle_all();
return 0;
}
