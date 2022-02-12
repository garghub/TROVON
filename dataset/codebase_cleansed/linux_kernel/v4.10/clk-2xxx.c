static int __init omap2xxx_dt_clk_init(int soc_type)
{
ti_dt_clocks_register(omap2xxx_clks);
if (soc_type == OMAP2_SOC_OMAP2420)
ti_dt_clocks_register(omap2420_clks);
else
ti_dt_clocks_register(omap2430_clks);
omap2xxx_clkt_vps_init();
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
pr_info("Clocking rate (Crystal/DPLL/MPU): %ld.%01ld/%ld/%ld MHz\n",
(clk_get_rate(clk_get_sys(NULL, "sys_ck")) / 1000000),
(clk_get_rate(clk_get_sys(NULL, "sys_ck")) / 100000) % 10,
(clk_get_rate(clk_get_sys(NULL, "dpll_ck")) / 1000000),
(clk_get_rate(clk_get_sys(NULL, "mpu_ck")) / 1000000));
return 0;
}
int __init omap2420_dt_clk_init(void)
{
return omap2xxx_dt_clk_init(OMAP2_SOC_OMAP2420);
}
int __init omap2430_dt_clk_init(void)
{
return omap2xxx_dt_clk_init(OMAP2_SOC_OMAP2430);
}
