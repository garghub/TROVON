static long rate_from_params(unsigned long parent_rate,
unsigned long sdm,
unsigned long n2)
{
unsigned long divisor = (SDM_DEN * n2) + sdm;
if (n2 < N2_MIN)
return -EINVAL;
return DIV_ROUND_UP_ULL((u64)parent_rate * SDM_DEN, divisor);
}
static void params_from_rate(unsigned long requested_rate,
unsigned long parent_rate,
unsigned long *sdm,
unsigned long *n2)
{
uint64_t div = parent_rate;
unsigned long rem = do_div(div, requested_rate);
if (div < N2_MIN) {
*n2 = N2_MIN;
*sdm = 0;
} else if (div > N2_MAX) {
*n2 = N2_MAX;
*sdm = SDM_DEN - 1;
} else {
*n2 = div;
*sdm = DIV_ROUND_UP(rem * SDM_DEN, requested_rate);
}
}
static unsigned long mpll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct meson_clk_mpll *mpll = to_meson_clk_mpll(hw);
struct parm *p;
unsigned long reg, sdm, n2;
long rate;
p = &mpll->sdm;
reg = readl(mpll->base + p->reg_off);
sdm = PARM_GET(p->width, p->shift, reg);
p = &mpll->n2;
reg = readl(mpll->base + p->reg_off);
n2 = PARM_GET(p->width, p->shift, reg);
rate = rate_from_params(parent_rate, sdm, n2);
if (rate < 0)
return 0;
return rate;
}
static long mpll_round_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long *parent_rate)
{
unsigned long sdm, n2;
params_from_rate(rate, *parent_rate, &sdm, &n2);
return rate_from_params(*parent_rate, sdm, n2);
}
static int mpll_set_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long parent_rate)
{
struct meson_clk_mpll *mpll = to_meson_clk_mpll(hw);
struct parm *p;
unsigned long reg, sdm, n2;
unsigned long flags = 0;
params_from_rate(rate, parent_rate, &sdm, &n2);
if (mpll->lock)
spin_lock_irqsave(mpll->lock, flags);
else
__acquire(mpll->lock);
p = &mpll->sdm;
reg = readl(mpll->base + p->reg_off);
reg = PARM_SET(p->width, p->shift, reg, sdm);
writel(reg, mpll->base + p->reg_off);
p = &mpll->sdm_en;
reg = readl(mpll->base + p->reg_off);
reg = PARM_SET(p->width, p->shift, reg, 1);
writel(reg, mpll->base + p->reg_off);
p = &mpll->ssen;
if (p->width != 0) {
reg = readl(mpll->base + p->reg_off);
reg = PARM_SET(p->width, p->shift, reg, 1);
writel(reg, mpll->base + p->reg_off);
}
p = &mpll->n2;
reg = readl(mpll->base + p->reg_off);
reg = PARM_SET(p->width, p->shift, reg, n2);
writel(reg, mpll->base + p->reg_off);
if (mpll->lock)
spin_unlock_irqrestore(mpll->lock, flags);
else
__release(mpll->lock);
return 0;
}
static void mpll_enable_core(struct clk_hw *hw, int enable)
{
struct meson_clk_mpll *mpll = to_meson_clk_mpll(hw);
struct parm *p;
unsigned long reg;
unsigned long flags = 0;
if (mpll->lock)
spin_lock_irqsave(mpll->lock, flags);
else
__acquire(mpll->lock);
p = &mpll->en;
reg = readl(mpll->base + p->reg_off);
reg = PARM_SET(p->width, p->shift, reg, enable ? 1 : 0);
writel(reg, mpll->base + p->reg_off);
if (mpll->lock)
spin_unlock_irqrestore(mpll->lock, flags);
else
__release(mpll->lock);
}
static int mpll_enable(struct clk_hw *hw)
{
mpll_enable_core(hw, 1);
return 0;
}
static void mpll_disable(struct clk_hw *hw)
{
mpll_enable_core(hw, 0);
}
static int mpll_is_enabled(struct clk_hw *hw)
{
struct meson_clk_mpll *mpll = to_meson_clk_mpll(hw);
struct parm *p;
unsigned long reg;
int en;
p = &mpll->en;
reg = readl(mpll->base + p->reg_off);
en = PARM_GET(p->width, p->shift, reg);
return en;
}
