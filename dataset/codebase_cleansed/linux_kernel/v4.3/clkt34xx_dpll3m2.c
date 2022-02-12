int omap3_core_dpll_m2_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 new_div = 0;
u32 unlock_dll = 0;
u32 c;
unsigned long validrate, sdrcrate, _mpurate;
struct omap_sdrc_params *sdrc_cs0;
struct omap_sdrc_params *sdrc_cs1;
int ret;
unsigned long clkrate;
if (!clk || !rate)
return -EINVAL;
new_div = DIV_ROUND_UP(parent_rate, rate);
validrate = parent_rate / new_div;
if (validrate != rate)
return -EINVAL;
sdrcrate = clk_get_rate(sdrc_ick_p);
clkrate = clk_hw_get_rate(hw);
if (rate > clkrate)
sdrcrate <<= ((rate / clkrate) >> 1);
else
sdrcrate >>= ((clkrate / rate) >> 1);
ret = omap2_sdrc_get_params(sdrcrate, &sdrc_cs0, &sdrc_cs1);
if (ret)
return -EINVAL;
if (sdrcrate < MIN_SDRC_DLL_LOCK_FREQ) {
pr_debug("clock: will unlock SDRC DLL\n");
unlock_dll = 1;
}
_mpurate = clk_get_rate(arm_fck_p) / CYCLES_PER_MHZ;
c = (_mpurate << SDRC_MPURATE_SCALE) >> SDRC_MPURATE_BASE_SHIFT;
c += 1;
c *= SDRC_MPURATE_LOOPS;
c >>= SDRC_MPURATE_SCALE;
if (c == 0)
c = 1;
pr_debug("clock: changing CORE DPLL rate from %lu to %lu\n",
clkrate, validrate);
pr_debug("clock: SDRC CS0 timing params used: RFR %08x CTRLA %08x CTRLB %08x MR %08x\n",
sdrc_cs0->rfr_ctrl, sdrc_cs0->actim_ctrla,
sdrc_cs0->actim_ctrlb, sdrc_cs0->mr);
if (sdrc_cs1)
pr_debug("clock: SDRC CS1 timing params used: RFR %08x CTRLA %08x CTRLB %08x MR %08x\n",
sdrc_cs1->rfr_ctrl, sdrc_cs1->actim_ctrla,
sdrc_cs1->actim_ctrlb, sdrc_cs1->mr);
if (sdrc_cs1)
omap3_configure_core_dpll(
new_div, unlock_dll, c, rate > clkrate,
sdrc_cs0->rfr_ctrl, sdrc_cs0->actim_ctrla,
sdrc_cs0->actim_ctrlb, sdrc_cs0->mr,
sdrc_cs1->rfr_ctrl, sdrc_cs1->actim_ctrla,
sdrc_cs1->actim_ctrlb, sdrc_cs1->mr);
else
omap3_configure_core_dpll(
new_div, unlock_dll, c, rate > clkrate,
sdrc_cs0->rfr_ctrl, sdrc_cs0->actim_ctrla,
sdrc_cs0->actim_ctrlb, sdrc_cs0->mr,
0, 0, 0, 0);
return 0;
}
