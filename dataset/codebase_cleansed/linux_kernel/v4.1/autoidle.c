static void ti_allow_autoidle(struct clk_ti_autoidle *clk)
{
u32 val;
val = ti_clk_ll_ops->clk_readl(clk->reg);
if (clk->flags & AUTOIDLE_LOW)
val &= ~(1 << clk->shift);
else
val |= (1 << clk->shift);
ti_clk_ll_ops->clk_writel(val, clk->reg);
}
static void ti_deny_autoidle(struct clk_ti_autoidle *clk)
{
u32 val;
val = ti_clk_ll_ops->clk_readl(clk->reg);
if (clk->flags & AUTOIDLE_LOW)
val |= (1 << clk->shift);
else
val &= ~(1 << clk->shift);
ti_clk_ll_ops->clk_writel(val, clk->reg);
}
void of_ti_clk_allow_autoidle_all(void)
{
struct clk_ti_autoidle *c;
list_for_each_entry(c, &autoidle_clks, node)
ti_allow_autoidle(c);
}
void of_ti_clk_deny_autoidle_all(void)
{
struct clk_ti_autoidle *c;
list_for_each_entry(c, &autoidle_clks, node)
ti_deny_autoidle(c);
}
int __init of_ti_clk_autoidle_setup(struct device_node *node)
{
u32 shift;
struct clk_ti_autoidle *clk;
if (of_property_read_u32(node, "ti,autoidle-shift", &shift))
return 0;
clk = kzalloc(sizeof(*clk), GFP_KERNEL);
if (!clk)
return -ENOMEM;
clk->shift = shift;
clk->name = node->name;
clk->reg = ti_clk_get_reg_addr(node, 0);
if (IS_ERR(clk->reg)) {
kfree(clk);
return -EINVAL;
}
if (of_property_read_bool(node, "ti,invert-autoidle-bit"))
clk->flags |= AUTOIDLE_LOW;
list_add(&clk->node, &autoidle_clks);
return 0;
}
