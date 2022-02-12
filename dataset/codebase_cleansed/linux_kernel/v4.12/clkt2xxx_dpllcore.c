unsigned long omap2xxx_clk_get_core_rate(void)
{
long long core_clk;
u32 v;
WARN_ON(!dpll_core_ck);
core_clk = omap2_get_dpll_rate(dpll_core_ck);
v = omap2xxx_cm_get_core_clk_src();
if (v == CORE_CLK_SRC_32K)
core_clk = 32768;
else
core_clk *= v;
return core_clk;
}
static long omap2_dpllcore_round_rate(unsigned long target_rate)
{
u32 high, low, core_clk_src;
core_clk_src = omap2xxx_cm_get_core_clk_src();
if (core_clk_src == CORE_CLK_SRC_DPLL) {
high = curr_prcm_set->dpll_speed * 2;
low = curr_prcm_set->dpll_speed;
} else {
high = curr_prcm_set->dpll_speed;
low = curr_prcm_set->dpll_speed / 2;
}
#ifdef DOWN_VARIABLE_DPLL
if (target_rate > high)
return high;
else
return target_rate;
#else
if (target_rate > low)
return high;
else
return low;
#endif
}
unsigned long omap2_dpllcore_recalc(struct clk_hw *hw,
unsigned long parent_rate)
{
return omap2xxx_clk_get_core_rate();
}
int omap2_reprogram_dpllcore(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 cur_rate, low, mult, div, valid_rate, done_rate;
u32 bypass = 0;
struct prcm_config tmpset;
const struct dpll_data *dd;
cur_rate = omap2xxx_clk_get_core_rate();
mult = omap2xxx_cm_get_core_clk_src();
if ((rate == (cur_rate / 2)) && (mult == 2)) {
omap2xxx_sdrc_reprogram(CORE_CLK_SRC_DPLL, 1);
} else if ((rate == (cur_rate * 2)) && (mult == 1)) {
omap2xxx_sdrc_reprogram(CORE_CLK_SRC_DPLL_X2, 1);
} else if (rate != cur_rate) {
valid_rate = omap2_dpllcore_round_rate(rate);
if (valid_rate != rate)
return -EINVAL;
if (mult == 1)
low = curr_prcm_set->dpll_speed;
else
low = curr_prcm_set->dpll_speed / 2;
dd = clk->dpll_data;
if (!dd)
return -EINVAL;
tmpset.cm_clksel1_pll =
omap_clk_ll_ops.clk_readl(&dd->mult_div1_reg);
tmpset.cm_clksel1_pll &= ~(dd->mult_mask |
dd->div1_mask);
div = ((curr_prcm_set->xtal_speed / 1000000) - 1);
tmpset.cm_clksel2_pll = omap2xxx_cm_get_core_pll_config();
tmpset.cm_clksel2_pll &= ~OMAP24XX_CORE_CLK_SRC_MASK;
if (rate > low) {
tmpset.cm_clksel2_pll |= CORE_CLK_SRC_DPLL_X2;
mult = ((rate / 2) / 1000000);
done_rate = CORE_CLK_SRC_DPLL_X2;
} else {
tmpset.cm_clksel2_pll |= CORE_CLK_SRC_DPLL;
mult = (rate / 1000000);
done_rate = CORE_CLK_SRC_DPLL;
}
tmpset.cm_clksel1_pll |= (div << __ffs(dd->mult_mask));
tmpset.cm_clksel1_pll |= (mult << __ffs(dd->div1_mask));
tmpset.base_sdrc_rfr = SDRC_RFR_CTRL_BYPASS;
if (rate == curr_prcm_set->xtal_speed)
bypass = 1;
omap2xxx_sdrc_reprogram(CORE_CLK_SRC_DPLL_X2, 1);
omap2_set_prcm(tmpset.cm_clksel1_pll, tmpset.base_sdrc_rfr,
bypass);
omap2xxx_sdrc_init_params(omap2xxx_sdrc_dll_is_unlocked());
omap2xxx_sdrc_reprogram(done_rate, 0);
}
return 0;
}
void omap2xxx_clkt_dpllcore_init(struct clk_hw *hw)
{
WARN(dpll_core_ck, "dpll_core_ck already set - should never happen");
dpll_core_ck = to_clk_hw_omap(hw);
}
