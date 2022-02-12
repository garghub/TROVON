static void omap4_dpllmx_allow_gatectrl(struct clk_hw_omap *clk)
{
u32 v;
u32 mask;
if (!clk || !clk->clksel_reg)
return;
mask = clk->flags & CLOCK_CLKOUTX2 ?
OMAP4430_DPLL_CLKOUTX2_GATE_CTRL_MASK :
OMAP4430_DPLL_CLKOUT_GATE_CTRL_MASK;
v = ti_clk_ll_ops->clk_readl(clk->clksel_reg);
v &= ~mask;
ti_clk_ll_ops->clk_writel(v, clk->clksel_reg);
}
static void omap4_dpllmx_deny_gatectrl(struct clk_hw_omap *clk)
{
u32 v;
u32 mask;
if (!clk || !clk->clksel_reg)
return;
mask = clk->flags & CLOCK_CLKOUTX2 ?
OMAP4430_DPLL_CLKOUTX2_GATE_CTRL_MASK :
OMAP4430_DPLL_CLKOUT_GATE_CTRL_MASK;
v = ti_clk_ll_ops->clk_readl(clk->clksel_reg);
v |= mask;
ti_clk_ll_ops->clk_writel(v, clk->clksel_reg);
}
static void omap4_dpll_lpmode_recalc(struct dpll_data *dd)
{
long fint, fout;
fint = clk_hw_get_rate(dd->clk_ref) / (dd->last_rounded_n + 1);
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
v = ti_clk_ll_ops->clk_readl(dd->control_reg);
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
int omap4_dpll_regm4xen_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
struct dpll_data *dd;
if (!req->rate)
return -EINVAL;
dd = clk->dpll_data;
if (!dd)
return -EINVAL;
if (clk_hw_get_rate(dd->clk_bypass) == req->rate &&
(dd->modes & (1 << DPLL_LOW_POWER_BYPASS))) {
req->best_parent_hw = dd->clk_bypass;
} else {
req->rate = omap4_dpll_regm4xen_round_rate(hw, req->rate,
&req->best_parent_rate);
req->best_parent_hw = dd->clk_ref;
}
req->best_parent_rate = req->rate;
return 0;
}
