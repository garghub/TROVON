static int __init omap3xxx_dt_clk_init(int soc_type)
{
if (soc_type == OMAP3_SOC_AM35XX || soc_type == OMAP3_SOC_OMAP3630 ||
soc_type == OMAP3_SOC_OMAP3430_ES1 ||
soc_type == OMAP3_SOC_OMAP3430_ES2_PLUS)
ti_dt_clocks_register(omap3xxx_clks);
if (soc_type == OMAP3_SOC_AM35XX)
ti_dt_clocks_register(am35xx_clks);
if (soc_type == OMAP3_SOC_OMAP3630 || soc_type == OMAP3_SOC_AM35XX ||
soc_type == OMAP3_SOC_OMAP3430_ES2_PLUS)
ti_dt_clocks_register(omap36xx_am35xx_omap3430es2plus_clks);
if (soc_type == OMAP3_SOC_OMAP3430_ES1)
ti_dt_clocks_register(omap3430es1_clks);
if (soc_type == OMAP3_SOC_OMAP3430_ES2_PLUS ||
soc_type == OMAP3_SOC_OMAP3630)
ti_dt_clocks_register(omap36xx_omap3430es2plus_clks);
if (soc_type == OMAP3_SOC_OMAP3430_ES1 ||
soc_type == OMAP3_SOC_OMAP3430_ES2_PLUS ||
soc_type == OMAP3_SOC_OMAP3630)
ti_dt_clocks_register(omap34xx_omap36xx_clks);
if (soc_type == OMAP3_SOC_OMAP3630)
ti_dt_clocks_register(omap36xx_clks);
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
pr_info("Clocking rate (Crystal/Core/MPU): %ld.%01ld/%ld/%ld MHz\n",
(clk_get_rate(clk_get_sys(NULL, "osc_sys_ck")) / 1000000),
(clk_get_rate(clk_get_sys(NULL, "osc_sys_ck")) / 100000) % 10,
(clk_get_rate(clk_get_sys(NULL, "core_ck")) / 1000000),
(clk_get_rate(clk_get_sys(NULL, "arm_fck")) / 1000000));
if (soc_type != OMAP3_SOC_OMAP3430_ES1)
omap3_clk_lock_dpll5();
return 0;
}
int __init omap3430_dt_clk_init(void)
{
return omap3xxx_dt_clk_init(OMAP3_SOC_OMAP3430_ES2_PLUS);
}
int __init omap3630_dt_clk_init(void)
{
return omap3xxx_dt_clk_init(OMAP3_SOC_OMAP3630);
}
int __init am35xx_dt_clk_init(void)
{
return omap3xxx_dt_clk_init(OMAP3_SOC_AM35XX);
}
