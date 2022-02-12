int __init omap2420_clk_init(void)
{
const struct prcm_config *prcm;
struct omap_clk *c;
u32 clkrate;
prcm_clksrc_ctrl = OMAP2420_PRCM_CLKSRC_CTRL;
cm_idlest_pll = OMAP_CM_REGADDR(PLL_MOD, CM_IDLEST);
cpu_mask = RATE_IN_242X;
rate_table = omap2420_rate_table;
clk_init(&omap2_clk_functions);
for (c = omap2420_clks; c < omap2420_clks + ARRAY_SIZE(omap2420_clks);
c++)
clk_preinit(c->lk.clk);
osc_ck.rate = omap2_osc_clk_recalc(&osc_ck);
propagate_rate(&osc_ck);
sys_ck.rate = omap2xxx_sys_clk_recalc(&sys_ck);
propagate_rate(&sys_ck);
for (c = omap2420_clks; c < omap2420_clks + ARRAY_SIZE(omap2420_clks);
c++) {
clkdev_add(&c->lk);
clk_register(c->lk.clk);
omap2_init_clk_clkdm(c->lk.clk);
}
omap_clk_disable_autoidle_all();
clkrate = omap2xxx_clk_get_core_rate(&dpll_ck);
for (prcm = rate_table; prcm->mpu_speed; prcm++) {
if (!(prcm->flags & cpu_mask))
continue;
if (prcm->xtal_speed != sys_ck.rate)
continue;
if (prcm->dpll_speed <= clkrate)
break;
}
curr_prcm_set = prcm;
recalculate_root_clocks();
pr_info("Clocking rate (Crystal/DPLL/MPU): %ld.%01ld/%ld/%ld MHz\n",
(sys_ck.rate / 1000000), (sys_ck.rate / 100000) % 10,
(dpll_ck.rate / 1000000), (mpu_ck.rate / 1000000)) ;
clk_enable_init_clocks();
vclk = clk_get(NULL, "virt_prcm_set");
sclk = clk_get(NULL, "sys_ck");
dclk = clk_get(NULL, "dpll_ck");
return 0;
}
