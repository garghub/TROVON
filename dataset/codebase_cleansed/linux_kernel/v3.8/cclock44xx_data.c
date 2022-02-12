int __init omap4xxx_clk_init(void)
{
u32 cpu_clkflg;
struct omap_clk *c;
int rc;
if (cpu_is_omap443x()) {
cpu_mask = RATE_IN_4430;
cpu_clkflg = CK_443X;
} else if (cpu_is_omap446x() || cpu_is_omap447x()) {
cpu_mask = RATE_IN_4460 | RATE_IN_4430;
cpu_clkflg = CK_446X | CK_443X;
if (cpu_is_omap447x())
pr_warn("WARNING: OMAP4470 clock data incomplete!\n");
} else {
return 0;
}
for (c = omap44xx_clks; c < omap44xx_clks + ARRAY_SIZE(omap44xx_clks);
c++) {
if (c->cpu & cpu_clkflg) {
clkdev_add(&c->lk);
if (!__clk_init(NULL, c->lk.clk))
omap2_init_clk_hw_omap_clocks(c->lk.clk);
}
}
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
rc = clk_set_parent(&abe_dpll_refclk_mux_ck, &sys_32k_ck);
if (!rc)
rc = clk_set_rate(&dpll_abe_ck, OMAP4_DPLL_ABE_DEFFREQ);
if (rc)
pr_err("%s: failed to configure ABE DPLL!\n", __func__);
return 0;
}
