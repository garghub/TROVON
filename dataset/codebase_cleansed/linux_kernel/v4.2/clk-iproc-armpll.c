static unsigned int __get_fid(struct iproc_arm_pll *pll)
{
u32 val;
unsigned int policy, fid, active_fid;
val = readl(pll->base + IPROC_CLK_ARM_DIV_OFFSET);
if (val & (1 << IPROC_CLK_ARM_DIV_PLL_SELECT_OVERRIDE_SHIFT))
policy = val & IPROC_CLK_ARM_DIV_ARM_PLL_SELECT_MASK;
else
policy = 0;
BUG_ON(policy > IPROC_CLK_MAX_FREQ_POLICY);
val = readl(pll->base + IPROC_CLK_POLICY_FREQ_OFFSET);
fid = (val >> (IPROC_CLK_POLICY_FREQ_POLICY_FREQ_SHIFT * policy)) &
IPROC_CLK_POLICY_FREQ_POLICY_FREQ_MASK;
val = readl(pll->base + IPROC_CLK_POLICY_DBG_OFFSET);
active_fid = IPROC_CLK_POLICY_DBG_ACT_FREQ_MASK &
(val >> IPROC_CLK_POLICY_DBG_ACT_FREQ_SHIFT);
if (fid != active_fid) {
pr_debug("%s: fid override %u->%u\n", __func__, fid,
active_fid);
fid = active_fid;
}
pr_debug("%s: active fid: %u\n", __func__, fid);
return fid;
}
static int __get_mdiv(struct iproc_arm_pll *pll)
{
unsigned int fid;
int mdiv;
u32 val;
fid = __get_fid(pll);
switch (fid) {
case ARM_PLL_FID_CRYSTAL_CLK:
case ARM_PLL_FID_SYS_CLK:
mdiv = 1;
break;
case ARM_PLL_FID_CH0_SLOW_CLK:
val = readl(pll->base + IPROC_CLK_PLLARMC_OFFSET);
mdiv = val & IPROC_CLK_PLLARMC_MDIV_MASK;
if (mdiv == 0)
mdiv = 256;
break;
case ARM_PLL_FID_CH1_FAST_CLK:
val = readl(pll->base + IPROC_CLK_PLLARMCTL5_OFFSET);
mdiv = val & IPROC_CLK_PLLARMCTL5_H_MDIV_MASK;
if (mdiv == 0)
mdiv = 256;
break;
default:
mdiv = -EFAULT;
}
return mdiv;
}
static unsigned int __get_ndiv(struct iproc_arm_pll *pll)
{
u32 val;
unsigned int ndiv_int, ndiv_frac, ndiv;
val = readl(pll->base + IPROC_CLK_PLLARM_OFFSET_OFFSET);
if (val & (1 << IPROC_CLK_PLLARM_SW_CTL_SHIFT)) {
ndiv_int = (val >> IPROC_CLK_PLLARM_NDIV_INT_OFFSET_SHIFT) &
IPROC_CLK_PLLARM_NDIV_INT_OFFSET_MASK;
if (ndiv_int == 0)
ndiv_int = 256;
ndiv_frac = val & IPROC_CLK_PLLARM_NDIV_FRAC_OFFSET_MASK;
} else {
val = readl(pll->base + IPROC_CLK_PLLARMA_OFFSET);
ndiv_int = (val >> IPROC_CLK_PLLARMA_NDIV_INT_SHIFT) &
IPROC_CLK_PLLARMA_NDIV_INT_MASK;
if (ndiv_int == 0)
ndiv_int = 1024;
val = readl(pll->base + IPROC_CLK_PLLARMB_OFFSET);
ndiv_frac = val & IPROC_CLK_PLLARMB_NDIV_FRAC_MASK;
}
ndiv = (ndiv_int << 20) | ndiv_frac;
return ndiv;
}
static unsigned long iproc_arm_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct iproc_arm_pll *pll = to_iproc_arm_pll(hw);
u32 val;
int mdiv;
u64 ndiv;
unsigned int pdiv;
val = readl(pll->base + IPROC_CLK_PLLARMC_OFFSET);
if (val & (1 << IPROC_CLK_PLLARMC_BYPCLK_EN_SHIFT)) {
pll->rate = parent_rate;
return pll->rate;
}
val = readl(pll->base + IPROC_CLK_PLLARMA_OFFSET);
if (!(val & (1 << IPROC_CLK_PLLARMA_LOCK_SHIFT))) {
pll->rate = 0;
return 0;
}
pdiv = (val >> IPROC_CLK_PLLARMA_PDIV_SHIFT) &
IPROC_CLK_PLLARMA_PDIV_MASK;
if (pdiv == 0)
pdiv = 16;
ndiv = __get_ndiv(pll);
mdiv = __get_mdiv(pll);
if (mdiv <= 0) {
pll->rate = 0;
return 0;
}
pll->rate = (ndiv * parent_rate) >> 20;
pll->rate = (pll->rate / pdiv) / mdiv;
pr_debug("%s: ARM PLL rate: %lu. parent rate: %lu\n", __func__,
pll->rate, parent_rate);
pr_debug("%s: ndiv_int: %u, pdiv: %u, mdiv: %d\n", __func__,
(unsigned int)(ndiv >> 20), pdiv, mdiv);
return pll->rate;
}
void __init iproc_armpll_setup(struct device_node *node)
{
int ret;
struct clk *clk;
struct iproc_arm_pll *pll;
struct clk_init_data init;
const char *parent_name;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (WARN_ON(!pll))
return;
pll->base = of_iomap(node, 0);
if (WARN_ON(!pll->base))
goto err_free_pll;
init.name = node->name;
init.ops = &iproc_arm_pll_ops;
init.flags = 0;
parent_name = of_clk_get_parent_name(node, 0);
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
pll->hw.init = &init;
clk = clk_register(NULL, &pll->hw);
if (WARN_ON(IS_ERR(clk)))
goto err_iounmap;
ret = of_clk_add_provider(node, of_clk_src_simple_get, clk);
if (WARN_ON(ret))
goto err_clk_unregister;
return;
err_clk_unregister:
clk_unregister(clk);
err_iounmap:
iounmap(pll->base);
err_free_pll:
kfree(pll);
}
