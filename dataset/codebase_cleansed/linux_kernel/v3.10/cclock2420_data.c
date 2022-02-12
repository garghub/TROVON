int __init omap2420_clk_init(void)
{
prcm_clksrc_ctrl = OMAP2420_PRCM_CLKSRC_CTRL;
cpu_mask = RATE_IN_242X;
rate_table = omap2420_rate_table;
omap2xxx_clkt_dpllcore_init(&dpll_ck_hw.hw);
omap2xxx_clkt_vps_check_bootloader_rates();
omap_clocks_register(omap2420_clks, ARRAY_SIZE(omap2420_clks));
omap2xxx_clkt_vps_late_init();
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
pr_info("Clocking rate (Crystal/DPLL/MPU): %ld.%01ld/%ld/%ld MHz\n",
(clk_get_rate(&sys_ck) / 1000000),
(clk_get_rate(&sys_ck) / 100000) % 10,
(clk_get_rate(&dpll_ck) / 1000000),
(clk_get_rate(&mpu_ck) / 1000000));
return 0;
}
