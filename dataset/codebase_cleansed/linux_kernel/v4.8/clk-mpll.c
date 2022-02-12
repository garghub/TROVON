static unsigned long mpll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct meson_clk_mpll *mpll = to_meson_clk_mpll(hw);
struct parm *p;
unsigned long rate = 0;
unsigned long reg, sdm, n2;
p = &mpll->sdm;
reg = readl(mpll->base + p->reg_off);
sdm = PARM_GET(p->width, p->shift, reg);
p = &mpll->n2;
reg = readl(mpll->base + p->reg_off);
n2 = PARM_GET(p->width, p->shift, reg);
rate = (parent_rate * SDM_MAX) / ((SDM_MAX * n2) + sdm);
return rate;
}
