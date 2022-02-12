static void __init omap3_clk_legacy_common_init(void)
{
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
pr_info("Clocking rate (Crystal/Core/MPU): %ld.%01ld/%ld/%ld MHz\n",
(clk_get_rate(osc_sys_ck.clk) / 1000000),
(clk_get_rate(osc_sys_ck.clk) / 100000) % 10,
(clk_get_rate(core_ck.clk) / 1000000),
(clk_get_rate(arm_fck.clk) / 1000000));
}
int __init omap3430es1_clk_legacy_init(void)
{
int r;
r = ti_clk_register_legacy_clks(omap3430es1_clks);
r |= ti_clk_register_legacy_clks(omap34xx_omap36xx_clks);
r |= ti_clk_register_legacy_clks(omap3xxx_clks);
omap3_clk_legacy_common_init();
return r;
}
int __init omap3430_clk_legacy_init(void)
{
int r;
r = ti_clk_register_legacy_clks(omap34xx_omap36xx_clks);
r |= ti_clk_register_legacy_clks(omap36xx_omap3430es2plus_clks);
r |= ti_clk_register_legacy_clks(omap36xx_am35xx_omap3430es2plus_clks);
r |= ti_clk_register_legacy_clks(omap3xxx_clks);
omap3_clk_legacy_common_init();
omap3_clk_lock_dpll5();
return r;
}
int __init omap36xx_clk_legacy_init(void)
{
int r;
ti_clk_patch_legacy_clks(omap36xx_clk_patches);
r = ti_clk_register_legacy_clks(omap36xx_clks);
r |= ti_clk_register_legacy_clks(omap36xx_omap3430es2plus_clks);
r |= ti_clk_register_legacy_clks(omap34xx_omap36xx_clks);
r |= ti_clk_register_legacy_clks(omap36xx_am35xx_omap3430es2plus_clks);
r |= ti_clk_register_legacy_clks(omap3xxx_clks);
omap3_clk_legacy_common_init();
omap3_clk_lock_dpll5();
return r;
}
int __init am35xx_clk_legacy_init(void)
{
int r;
r = ti_clk_register_legacy_clks(am35xx_clks);
r |= ti_clk_register_legacy_clks(omap36xx_am35xx_omap3430es2plus_clks);
r |= ti_clk_register_legacy_clks(omap3xxx_clks);
omap3_clk_legacy_common_init();
omap3_clk_lock_dpll5();
return r;
}
