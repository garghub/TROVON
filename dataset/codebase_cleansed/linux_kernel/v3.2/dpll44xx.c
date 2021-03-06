int omap4_dpllmx_gatectrl_read(struct clk *clk)
{
u32 v;
u32 mask;
if (!clk || !clk->clksel_reg || !cpu_is_omap44xx())
return -EINVAL;
mask = clk->flags & CLOCK_CLKOUTX2 ?
OMAP4430_DPLL_CLKOUTX2_GATE_CTRL_MASK :
OMAP4430_DPLL_CLKOUT_GATE_CTRL_MASK;
v = __raw_readl(clk->clksel_reg);
v &= mask;
v >>= __ffs(mask);
return v;
}
void omap4_dpllmx_allow_gatectrl(struct clk *clk)
{
u32 v;
u32 mask;
if (!clk || !clk->clksel_reg || !cpu_is_omap44xx())
return;
mask = clk->flags & CLOCK_CLKOUTX2 ?
OMAP4430_DPLL_CLKOUTX2_GATE_CTRL_MASK :
OMAP4430_DPLL_CLKOUT_GATE_CTRL_MASK;
v = __raw_readl(clk->clksel_reg);
v &= ~mask;
__raw_writel(v, clk->clksel_reg);
}
void omap4_dpllmx_deny_gatectrl(struct clk *clk)
{
u32 v;
u32 mask;
if (!clk || !clk->clksel_reg || !cpu_is_omap44xx())
return;
mask = clk->flags & CLOCK_CLKOUTX2 ?
OMAP4430_DPLL_CLKOUTX2_GATE_CTRL_MASK :
OMAP4430_DPLL_CLKOUT_GATE_CTRL_MASK;
v = __raw_readl(clk->clksel_reg);
v |= mask;
__raw_writel(v, clk->clksel_reg);
}
unsigned long omap4_dpll_regm4xen_recalc(struct clk *clk)
{
u32 v;
unsigned long rate;
struct dpll_data *dd;
if (!clk || !clk->dpll_data)
return 0;
dd = clk->dpll_data;
rate = omap2_get_dpll_rate(clk);
v = __raw_readl(dd->control_reg);
if (v & OMAP4430_DPLL_REGM4XEN_MASK)
rate *= OMAP4430_REGM4XEN_MULT;
return rate;
}
long omap4_dpll_regm4xen_round_rate(struct clk *clk, unsigned long target_rate)
{
u32 v;
struct dpll_data *dd;
long r;
if (!clk || !clk->dpll_data)
return -EINVAL;
dd = clk->dpll_data;
v = __raw_readl(dd->control_reg) & OMAP4430_DPLL_REGM4XEN_MASK;
if (v)
target_rate = target_rate / OMAP4430_REGM4XEN_MULT;
r = omap2_dpll_round_rate(clk, target_rate);
if (r == ~0)
return r;
if (v)
clk->dpll_data->last_rounded_rate *= OMAP4430_REGM4XEN_MULT;
return clk->dpll_data->last_rounded_rate;
}
