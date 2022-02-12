static int _wait_idlest_generic(struct clk_hw_omap *clk, void __iomem *reg,
u32 mask, u8 idlest, const char *name)
{
int i = 0, ena = 0;
ena = (idlest) ? 0 : mask;
for (i = 0; i < MAX_MODULE_ENABLE_WAIT; i++) {
if ((ti_clk_ll_ops->clk_readl(reg) & mask) == ena)
break;
udelay(1);
}
if (i < MAX_MODULE_ENABLE_WAIT)
pr_debug("omap clock: module associated with clock %s ready after %d loops\n",
name, i);
else
pr_err("omap clock: module associated with clock %s didn't enable in %d tries\n",
name, MAX_MODULE_ENABLE_WAIT);
return (i < MAX_MODULE_ENABLE_WAIT) ? 1 : 0;
}
static void _omap2_module_wait_ready(struct clk_hw_omap *clk)
{
void __iomem *companion_reg, *idlest_reg;
u8 other_bit, idlest_bit, idlest_val, idlest_reg_id;
s16 prcm_mod;
int r;
if (clk->ops->find_companion) {
clk->ops->find_companion(clk, &companion_reg, &other_bit);
if (!(ti_clk_ll_ops->clk_readl(companion_reg) &
(1 << other_bit)))
return;
}
clk->ops->find_idlest(clk, &idlest_reg, &idlest_bit, &idlest_val);
r = ti_clk_ll_ops->cm_split_idlest_reg(idlest_reg, &prcm_mod,
&idlest_reg_id);
if (r) {
_wait_idlest_generic(clk, idlest_reg, (1 << idlest_bit),
idlest_val, clk_hw_get_name(&clk->hw));
} else {
ti_clk_ll_ops->cm_wait_module_ready(0, prcm_mod, idlest_reg_id,
idlest_bit);
}
}
void omap2_clk_dflt_find_companion(struct clk_hw_omap *clk,
void __iomem **other_reg, u8 *other_bit)
{
u32 r;
r = ((__force u32)clk->enable_reg ^ (CM_FCLKEN ^ CM_ICLKEN));
*other_reg = (__force void __iomem *)r;
*other_bit = clk->enable_bit;
}
void omap2_clk_dflt_find_idlest(struct clk_hw_omap *clk,
void __iomem **idlest_reg, u8 *idlest_bit,
u8 *idlest_val)
{
u32 r;
r = (((__force u32)clk->enable_reg & ~0xf0) | 0x20);
*idlest_reg = (__force void __iomem *)r;
*idlest_bit = clk->enable_bit;
*idlest_val = ti_clk_get_features()->cm_idlest_val;
}
int omap2_dflt_clk_enable(struct clk_hw *hw)
{
struct clk_hw_omap *clk;
u32 v;
int ret = 0;
bool clkdm_control;
if (ti_clk_get_features()->flags & TI_CLK_DISABLE_CLKDM_CONTROL)
clkdm_control = false;
else
clkdm_control = true;
clk = to_clk_hw_omap(hw);
if (clkdm_control && clk->clkdm) {
ret = ti_clk_ll_ops->clkdm_clk_enable(clk->clkdm, hw->clk);
if (ret) {
WARN(1,
"%s: could not enable %s's clockdomain %s: %d\n",
__func__, clk_hw_get_name(hw),
clk->clkdm_name, ret);
return ret;
}
}
if (IS_ERR(clk->enable_reg)) {
pr_err("%s: %s missing enable_reg\n", __func__,
clk_hw_get_name(hw));
ret = -EINVAL;
goto err;
}
v = ti_clk_ll_ops->clk_readl(clk->enable_reg);
if (clk->flags & INVERT_ENABLE)
v &= ~(1 << clk->enable_bit);
else
v |= (1 << clk->enable_bit);
ti_clk_ll_ops->clk_writel(v, clk->enable_reg);
v = ti_clk_ll_ops->clk_readl(clk->enable_reg);
if (clk->ops && clk->ops->find_idlest)
_omap2_module_wait_ready(clk);
return 0;
err:
if (clkdm_control && clk->clkdm)
ti_clk_ll_ops->clkdm_clk_disable(clk->clkdm, hw->clk);
return ret;
}
void omap2_dflt_clk_disable(struct clk_hw *hw)
{
struct clk_hw_omap *clk;
u32 v;
clk = to_clk_hw_omap(hw);
if (IS_ERR(clk->enable_reg)) {
pr_err("%s: independent clock %s has no enable_reg\n",
__func__, clk_hw_get_name(hw));
return;
}
v = ti_clk_ll_ops->clk_readl(clk->enable_reg);
if (clk->flags & INVERT_ENABLE)
v |= (1 << clk->enable_bit);
else
v &= ~(1 << clk->enable_bit);
ti_clk_ll_ops->clk_writel(v, clk->enable_reg);
if (!(ti_clk_get_features()->flags & TI_CLK_DISABLE_CLKDM_CONTROL) &&
clk->clkdm)
ti_clk_ll_ops->clkdm_clk_disable(clk->clkdm, hw->clk);
}
int omap2_dflt_clk_is_enabled(struct clk_hw *hw)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 v;
v = ti_clk_ll_ops->clk_readl(clk->enable_reg);
if (clk->flags & INVERT_ENABLE)
v ^= BIT(clk->enable_bit);
v &= BIT(clk->enable_bit);
return v ? 1 : 0;
}
