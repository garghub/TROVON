int __init omap3xxx_clk_init(void)
{
if (omap3_has_192mhz_clk())
omap_96m_alwon_fck = omap_96m_alwon_fck_3630;
if (cpu_is_omap3630()) {
dpll3_m3x2_ck = dpll3_m3x2_ck_3630;
dpll4_m2x2_ck = dpll4_m2x2_ck_3630;
dpll4_m3x2_ck = dpll4_m3x2_ck_3630;
dpll4_m4x2_ck = dpll4_m4x2_ck_3630;
dpll4_m5x2_ck = dpll4_m5x2_ck_3630;
dpll4_m6x2_ck = dpll4_m6x2_ck_3630;
}
if (cpu_is_omap3630())
dpll4_dd = dpll4_dd_3630;
else
dpll4_dd = dpll4_dd_34xx;
if (soc_is_am35xx()) {
cpu_mask = RATE_IN_34XX;
omap_clocks_register(am35xx_clks, ARRAY_SIZE(am35xx_clks));
omap_clocks_register(omap36xx_am35xx_omap3430es2plus_clks,
ARRAY_SIZE(omap36xx_am35xx_omap3430es2plus_clks));
omap_clocks_register(omap3xxx_clks, ARRAY_SIZE(omap3xxx_clks));
} else if (cpu_is_omap3630()) {
cpu_mask = (RATE_IN_34XX | RATE_IN_36XX);
omap_clocks_register(omap36xx_clks, ARRAY_SIZE(omap36xx_clks));
omap_clocks_register(omap36xx_omap3430es2plus_clks,
ARRAY_SIZE(omap36xx_omap3430es2plus_clks));
omap_clocks_register(omap34xx_omap36xx_clks,
ARRAY_SIZE(omap34xx_omap36xx_clks));
omap_clocks_register(omap36xx_am35xx_omap3430es2plus_clks,
ARRAY_SIZE(omap36xx_am35xx_omap3430es2plus_clks));
omap_clocks_register(omap3xxx_clks, ARRAY_SIZE(omap3xxx_clks));
} else if (soc_is_am33xx()) {
cpu_mask = RATE_IN_AM33XX;
} else if (cpu_is_ti814x()) {
cpu_mask = RATE_IN_TI814X;
} else if (cpu_is_omap34xx()) {
if (omap_rev() == OMAP3430_REV_ES1_0) {
cpu_mask = RATE_IN_3430ES1;
omap_clocks_register(omap3430es1_clks,
ARRAY_SIZE(omap3430es1_clks));
omap_clocks_register(omap34xx_omap36xx_clks,
ARRAY_SIZE(omap34xx_omap36xx_clks));
omap_clocks_register(omap3xxx_clks,
ARRAY_SIZE(omap3xxx_clks));
} else {
cpu_mask = RATE_IN_3430ES2PLUS;
omap_clocks_register(omap34xx_omap36xx_clks,
ARRAY_SIZE(omap34xx_omap36xx_clks));
omap_clocks_register(omap36xx_omap3430es2plus_clks,
ARRAY_SIZE(omap36xx_omap3430es2plus_clks));
omap_clocks_register(omap36xx_am35xx_omap3430es2plus_clks,
ARRAY_SIZE(omap36xx_am35xx_omap3430es2plus_clks));
omap_clocks_register(omap3xxx_clks,
ARRAY_SIZE(omap3xxx_clks));
}
} else {
WARN(1, "clock: could not identify OMAP3 variant\n");
}
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
pr_info("Clocking rate (Crystal/Core/MPU): %ld.%01ld/%ld/%ld MHz\n",
(clk_get_rate(&osc_sys_ck) / 1000000),
(clk_get_rate(&osc_sys_ck) / 100000) % 10,
(clk_get_rate(&core_ck) / 1000000),
(clk_get_rate(&arm_fck) / 1000000));
if (!cpu_is_ti81xx() && (omap_rev() >= OMAP3430_REV_ES2_0))
omap3_clk_lock_dpll5();
sdrc_ick_p = clk_get(NULL, "sdrc_ick");
arm_fck_p = clk_get(NULL, "arm_fck");
return 0;
}
