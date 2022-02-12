int __init omap3xxx_clk_init(void)
{
struct omap_clk *c;
u32 cpu_clkflg = 0;
if (soc_is_am35xx()) {
cpu_mask = RATE_IN_34XX;
cpu_clkflg = CK_AM35XX;
} else if (cpu_is_omap3630()) {
cpu_mask = (RATE_IN_34XX | RATE_IN_36XX);
cpu_clkflg = CK_36XX;
} else if (cpu_is_ti816x()) {
cpu_mask = RATE_IN_TI816X;
cpu_clkflg = CK_TI816X;
} else if (soc_is_am33xx()) {
cpu_mask = RATE_IN_AM33XX;
} else if (cpu_is_ti814x()) {
cpu_mask = RATE_IN_TI814X;
} else if (cpu_is_omap34xx()) {
if (omap_rev() == OMAP3430_REV_ES1_0) {
cpu_mask = RATE_IN_3430ES1;
cpu_clkflg = CK_3430ES1;
} else {
cpu_mask = RATE_IN_3430ES2PLUS;
cpu_clkflg = CK_3430ES2PLUS;
}
} else {
WARN(1, "clock: could not identify OMAP3 variant\n");
}
if (omap3_has_192mhz_clk())
omap_96m_alwon_fck = omap_96m_alwon_fck_3630;
if (cpu_is_omap3630()) {
dpll3_m3x2_ck.ops =
&clkops_omap36xx_pwrdn_with_hsdiv_wait_restore;
dpll4_m2x2_ck.ops =
&clkops_omap36xx_pwrdn_with_hsdiv_wait_restore;
dpll4_m3x2_ck.ops =
&clkops_omap36xx_pwrdn_with_hsdiv_wait_restore;
dpll4_m4x2_ck.ops =
&clkops_omap36xx_pwrdn_with_hsdiv_wait_restore;
dpll4_m5x2_ck.ops =
&clkops_omap36xx_pwrdn_with_hsdiv_wait_restore;
dpll4_m6x2_ck.ops =
&clkops_omap36xx_pwrdn_with_hsdiv_wait_restore;
}
if (cpu_is_omap3630())
dpll4_dd = dpll4_dd_3630;
else
dpll4_dd = dpll4_dd_34xx;
clk_init(&omap2_clk_functions);
for (c = omap3xxx_clks; c < omap3xxx_clks + ARRAY_SIZE(omap3xxx_clks);
c++)
clk_preinit(c->lk.clk);
for (c = omap3xxx_clks; c < omap3xxx_clks + ARRAY_SIZE(omap3xxx_clks);
c++)
if (c->cpu & cpu_clkflg) {
clkdev_add(&c->lk);
clk_register(c->lk.clk);
omap2_init_clk_clkdm(c->lk.clk);
}
omap_clk_disable_autoidle_all();
recalculate_root_clocks();
pr_info("Clocking rate (Crystal/Core/MPU): %ld.%01ld/%ld/%ld MHz\n",
(osc_sys_ck.rate / 1000000), (osc_sys_ck.rate / 100000) % 10,
(core_ck.rate / 1000000), (arm_fck.rate / 1000000));
clk_enable_init_clocks();
if (!cpu_is_ti81xx() && (omap_rev() >= OMAP3430_REV_ES2_0))
omap3_clk_lock_dpll5();
sdrc_ick_p = clk_get(NULL, "sdrc_ick");
arm_fck_p = clk_get(NULL, "arm_fck");
return 0;
}
