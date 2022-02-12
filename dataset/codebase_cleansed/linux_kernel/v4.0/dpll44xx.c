void omap4_dpllmx_allow_gatectrl(struct clk_hw_omap *clk)
{
u32 v;
u32 mask;
if (!clk || !clk->clksel_reg)
return;
mask = clk->flags & CLOCK_CLKOUTX2 ?
OMAP4430_DPLL_CLKOUTX2_GATE_CTRL_MASK :
OMAP4430_DPLL_CLKOUT_GATE_CTRL_MASK;
v = omap2_clk_readl(clk, clk->clksel_reg);
v &= ~mask;
omap2_clk_writel(v, clk, clk->clksel_reg);
}
void omap4_dpllmx_deny_gatectrl(struct clk_hw_omap *clk)
{
u32 v;
u32 mask;
if (!clk || !clk->clksel_reg)
return;
mask = clk->flags & CLOCK_CLKOUTX2 ?
OMAP4430_DPLL_CLKOUTX2_GATE_CTRL_MASK :
OMAP4430_DPLL_CLKOUT_GATE_CTRL_MASK;
v = omap2_clk_readl(clk, clk->clksel_reg);
v |= mask;
omap2_clk_writel(v, clk, clk->clksel_reg);
}
static void omap4_dpll_lpmode_recalc(struct dpll_data *dd)
{
long fint, fout;
fint = __clk_get_rate(dd->clk_ref) / (dd->last_rounded_n + 1);
fout = fint * dd->last_rounded_m;
if ((fint < OMAP4_DPLL_LP_FINT_MAX) && (fout < OMAP4_DPLL_LP_FOUT_MAX))
dd->last_rounded_lpmode = 1;
else
dd->last_rounded_lpmode = 0;
}
unsigned long omap4_dpll_regm4xen_recalc(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 v;
unsigned long rate;
struct dpll_data *dd;
if (!clk || !clk->dpll_data)
return 0;
dd = clk->dpll_data;
rate = omap2_get_dpll_rate(clk);
v = omap2_clk_readl(clk, dd->control_reg);
if (v & OMAP4430_DPLL_REGM4XEN_MASK)
rate *= OMAP4430_REGM4XEN_MULT;
return rate;
}
long omap4_dpll_regm4xen_round_rate(struct clk_hw *hw,
unsigned long target_rate,
unsigned long *parent_rate)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
struct dpll_data *dd;
long r;
if (!clk || !clk->dpll_data)
return -EINVAL;
dd = clk->dpll_data;
dd->last_rounded_m4xen = 0;
r = omap2_dpll_round_rate(hw, target_rate, NULL);
if (r != ~0)
goto out;
r = omap2_dpll_round_rate(hw, target_rate / OMAP4430_REGM4XEN_MULT,
NULL);
if (r == ~0)
return r;
dd->last_rounded_rate *= OMAP4430_REGM4XEN_MULT;
dd->last_rounded_m4xen = 1;
out:
omap4_dpll_lpmode_recalc(dd);
return dd->last_rounded_rate;
}
long omap4_dpll_regm4xen_determine_rate(struct clk_hw *hw, unsigned long rate,
unsigned long min_rate,
unsigned long max_rate,
unsigned long *best_parent_rate,
struct clk_hw **best_parent_clk)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
struct dpll_data *dd;
if (!hw || !rate)
return -EINVAL;
dd = clk->dpll_data;
if (!dd)
return -EINVAL;
if (__clk_get_rate(dd->clk_bypass) == rate &&
(dd->modes & (1 << DPLL_LOW_POWER_BYPASS))) {
*best_parent_clk = __clk_get_hw(dd->clk_bypass);
} else {
rate = omap4_dpll_regm4xen_round_rate(hw, rate,
best_parent_rate);
*best_parent_clk = __clk_get_hw(dd->clk_ref);
}
*best_parent_rate = rate;
return rate;
}
