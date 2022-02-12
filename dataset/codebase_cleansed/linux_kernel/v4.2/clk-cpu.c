static void wait_until_divider_stable(void __iomem *div_reg, unsigned long mask)
{
unsigned long timeout = jiffies + msecs_to_jiffies(10);
do {
if (!(readl(div_reg) & mask))
return;
} while (time_before(jiffies, timeout));
if (!(readl(div_reg) & mask))
return;
pr_err("%s: timeout in divider stablization\n", __func__);
}
static void wait_until_mux_stable(void __iomem *mux_reg, u32 mux_pos,
unsigned long mux_value)
{
unsigned long timeout = jiffies + msecs_to_jiffies(10);
do {
if (((readl(mux_reg) >> mux_pos) & MUX_MASK) == mux_value)
return;
} while (time_before(jiffies, timeout));
if (((readl(mux_reg) >> mux_pos) & MUX_MASK) == mux_value)
return;
pr_err("%s: re-parenting mux timed-out\n", __func__);
}
static long exynos_cpuclk_round_rate(struct clk_hw *hw,
unsigned long drate, unsigned long *prate)
{
struct clk *parent = __clk_get_parent(hw->clk);
*prate = __clk_round_rate(parent, drate);
return *prate;
}
static unsigned long exynos_cpuclk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return parent_rate;
}
static void exynos_set_safe_div(void __iomem *base, unsigned long div,
unsigned long mask)
{
unsigned long div0;
div0 = readl(base + E4210_DIV_CPU0);
div0 = (div0 & ~mask) | (div & mask);
writel(div0, base + E4210_DIV_CPU0);
wait_until_divider_stable(base + E4210_DIV_STAT_CPU0, mask);
}
static int exynos_cpuclk_pre_rate_change(struct clk_notifier_data *ndata,
struct exynos_cpuclk *cpuclk, void __iomem *base)
{
const struct exynos_cpuclk_cfg_data *cfg_data = cpuclk->cfg;
unsigned long alt_prate = clk_get_rate(cpuclk->alt_parent);
unsigned long alt_div = 0, alt_div_mask = DIV_MASK;
unsigned long div0, div1 = 0, mux_reg;
while ((cfg_data->prate * 1000) != ndata->new_rate) {
if (cfg_data->prate == 0)
return -EINVAL;
cfg_data++;
}
spin_lock(cpuclk->lock);
div0 = cfg_data->div0;
if (test_bit(CLK_CPU_HAS_DIV1, &cpuclk->flags)) {
div1 = cfg_data->div1;
if (readl(base + E4210_SRC_CPU) & E4210_MUX_HPM_MASK)
div1 = readl(base + E4210_DIV_CPU1) &
(E4210_DIV1_HPM_MASK | E4210_DIV1_COPY_MASK);
}
if (alt_prate > ndata->old_rate || ndata->old_rate > ndata->new_rate) {
unsigned long tmp_rate = min(ndata->old_rate, ndata->new_rate);
alt_div = DIV_ROUND_UP(alt_prate, tmp_rate) - 1;
WARN_ON(alt_div >= MAX_DIV);
if (test_bit(CLK_CPU_NEEDS_DEBUG_ALT_DIV, &cpuclk->flags)) {
alt_div |= E4210_DIV0_ATB_MASK;
alt_div_mask |= E4210_DIV0_ATB_MASK;
}
exynos_set_safe_div(base, alt_div, alt_div_mask);
div0 |= alt_div;
}
mux_reg = readl(base + E4210_SRC_CPU);
writel(mux_reg | (1 << 16), base + E4210_SRC_CPU);
wait_until_mux_stable(base + E4210_STAT_CPU, 16, 2);
writel(div0, base + E4210_DIV_CPU0);
wait_until_divider_stable(base + E4210_DIV_STAT_CPU0, DIV_MASK_ALL);
if (test_bit(CLK_CPU_HAS_DIV1, &cpuclk->flags)) {
writel(div1, base + E4210_DIV_CPU1);
wait_until_divider_stable(base + E4210_DIV_STAT_CPU1,
DIV_MASK_ALL);
}
spin_unlock(cpuclk->lock);
return 0;
}
static int exynos_cpuclk_post_rate_change(struct clk_notifier_data *ndata,
struct exynos_cpuclk *cpuclk, void __iomem *base)
{
const struct exynos_cpuclk_cfg_data *cfg_data = cpuclk->cfg;
unsigned long div = 0, div_mask = DIV_MASK;
unsigned long mux_reg;
if (test_bit(CLK_CPU_NEEDS_DEBUG_ALT_DIV, &cpuclk->flags)) {
while ((cfg_data->prate * 1000) != ndata->new_rate) {
if (cfg_data->prate == 0)
return -EINVAL;
cfg_data++;
}
}
spin_lock(cpuclk->lock);
mux_reg = readl(base + E4210_SRC_CPU);
writel(mux_reg & ~(1 << 16), base + E4210_SRC_CPU);
wait_until_mux_stable(base + E4210_STAT_CPU, 16, 1);
if (test_bit(CLK_CPU_NEEDS_DEBUG_ALT_DIV, &cpuclk->flags)) {
div |= (cfg_data->div0 & E4210_DIV0_ATB_MASK);
div_mask |= E4210_DIV0_ATB_MASK;
}
exynos_set_safe_div(base, div, div_mask);
spin_unlock(cpuclk->lock);
return 0;
}
static int exynos_cpuclk_notifier_cb(struct notifier_block *nb,
unsigned long event, void *data)
{
struct clk_notifier_data *ndata = data;
struct exynos_cpuclk *cpuclk;
void __iomem *base;
int err = 0;
cpuclk = container_of(nb, struct exynos_cpuclk, clk_nb);
base = cpuclk->ctrl_base;
if (event == PRE_RATE_CHANGE)
err = exynos_cpuclk_pre_rate_change(ndata, cpuclk, base);
else if (event == POST_RATE_CHANGE)
err = exynos_cpuclk_post_rate_change(ndata, cpuclk, base);
return notifier_from_errno(err);
}
int __init exynos_register_cpu_clock(struct samsung_clk_provider *ctx,
unsigned int lookup_id, const char *name, const char *parent,
const char *alt_parent, unsigned long offset,
const struct exynos_cpuclk_cfg_data *cfg,
unsigned long num_cfgs, unsigned long flags)
{
struct exynos_cpuclk *cpuclk;
struct clk_init_data init;
struct clk *clk;
int ret = 0;
cpuclk = kzalloc(sizeof(*cpuclk), GFP_KERNEL);
if (!cpuclk)
return -ENOMEM;
init.name = name;
init.flags = CLK_SET_RATE_PARENT;
init.parent_names = &parent;
init.num_parents = 1;
init.ops = &exynos_cpuclk_clk_ops;
cpuclk->hw.init = &init;
cpuclk->ctrl_base = ctx->reg_base + offset;
cpuclk->lock = &ctx->lock;
cpuclk->flags = flags;
cpuclk->clk_nb.notifier_call = exynos_cpuclk_notifier_cb;
cpuclk->alt_parent = __clk_lookup(alt_parent);
if (!cpuclk->alt_parent) {
pr_err("%s: could not lookup alternate parent %s\n",
__func__, alt_parent);
ret = -EINVAL;
goto free_cpuclk;
}
clk = __clk_lookup(parent);
if (!clk) {
pr_err("%s: could not lookup parent clock %s\n",
__func__, parent);
ret = -EINVAL;
goto free_cpuclk;
}
ret = clk_notifier_register(clk, &cpuclk->clk_nb);
if (ret) {
pr_err("%s: failed to register clock notifier for %s\n",
__func__, name);
goto free_cpuclk;
}
cpuclk->cfg = kmemdup(cfg, sizeof(*cfg) * num_cfgs, GFP_KERNEL);
if (!cpuclk->cfg) {
pr_err("%s: could not allocate memory for cpuclk data\n",
__func__);
ret = -ENOMEM;
goto unregister_clk_nb;
}
clk = clk_register(NULL, &cpuclk->hw);
if (IS_ERR(clk)) {
pr_err("%s: could not register cpuclk %s\n", __func__, name);
ret = PTR_ERR(clk);
goto free_cpuclk_data;
}
samsung_clk_add_lookup(ctx, clk, lookup_id);
return 0;
free_cpuclk_data:
kfree(cpuclk->cfg);
unregister_clk_nb:
clk_notifier_unregister(__clk_lookup(parent), &cpuclk->clk_nb);
free_cpuclk:
kfree(cpuclk);
return ret;
}
