static unsigned long clk_factors_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
u8 n = 1, k = 0, p = 0, m = 0;
u32 reg;
unsigned long rate;
struct clk_factors *factors = to_clk_factors(hw);
struct clk_factors_config *config = factors->config;
reg = readl(factors->reg);
if (config->nwidth != SUNXI_FACTORS_NOT_APPLICABLE)
n = FACTOR_GET(config->nshift, config->nwidth, reg);
if (config->kwidth != SUNXI_FACTORS_NOT_APPLICABLE)
k = FACTOR_GET(config->kshift, config->kwidth, reg);
if (config->mwidth != SUNXI_FACTORS_NOT_APPLICABLE)
m = FACTOR_GET(config->mshift, config->mwidth, reg);
if (config->pwidth != SUNXI_FACTORS_NOT_APPLICABLE)
p = FACTOR_GET(config->pshift, config->pwidth, reg);
rate = (parent_rate * n * (k + 1) >> p) / (m + 1);
return rate;
}
static long clk_factors_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct clk_factors *factors = to_clk_factors(hw);
factors->get_factors((u32 *)&rate, (u32)*parent_rate,
NULL, NULL, NULL, NULL);
return rate;
}
static long clk_factors_determine_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *best_parent_rate,
struct clk **best_parent_p)
{
struct clk *clk = hw->clk, *parent, *best_parent = NULL;
int i, num_parents;
unsigned long parent_rate, best = 0, child_rate, best_child_rate = 0;
num_parents = __clk_get_num_parents(clk);
for (i = 0; i < num_parents; i++) {
parent = clk_get_parent_by_index(clk, i);
if (!parent)
continue;
if (__clk_get_flags(clk) & CLK_SET_RATE_PARENT)
parent_rate = __clk_round_rate(parent, rate);
else
parent_rate = __clk_get_rate(parent);
child_rate = clk_factors_round_rate(hw, rate, &parent_rate);
if (child_rate <= rate && child_rate > best_child_rate) {
best_parent = parent;
best = parent_rate;
best_child_rate = child_rate;
}
}
if (best_parent)
*best_parent_p = best_parent;
*best_parent_rate = best;
return best_child_rate;
}
static int clk_factors_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
u8 n = 0, k = 0, m = 0, p = 0;
u32 reg;
struct clk_factors *factors = to_clk_factors(hw);
struct clk_factors_config *config = factors->config;
unsigned long flags = 0;
factors->get_factors((u32 *)&rate, (u32)parent_rate, &n, &k, &m, &p);
if (factors->lock)
spin_lock_irqsave(factors->lock, flags);
reg = readl(factors->reg);
reg = FACTOR_SET(config->nshift, config->nwidth, reg, n);
reg = FACTOR_SET(config->kshift, config->kwidth, reg, k);
reg = FACTOR_SET(config->mshift, config->mwidth, reg, m);
reg = FACTOR_SET(config->pshift, config->pwidth, reg, p);
writel(reg, factors->reg);
__delay((rate >> 20) * 500 / 2);
if (factors->lock)
spin_unlock_irqrestore(factors->lock, flags);
return 0;
}
