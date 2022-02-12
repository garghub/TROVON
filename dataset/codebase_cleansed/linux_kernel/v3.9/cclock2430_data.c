int __init omap2430_clk_init(void)
{
struct omap_clk *c;
prcm_clksrc_ctrl = OMAP2430_PRCM_CLKSRC_CTRL;
cpu_mask = RATE_IN_243X;
rate_table = omap2430_rate_table;
omap2xxx_clkt_dpllcore_init(&dpll_ck_hw.hw);
omap2xxx_clkt_vps_check_bootloader_rates();
for (c = omap2430_clks; c < omap2430_clks + ARRAY_SIZE(omap2430_clks);
c++) {
clkdev_add(&c->lk);
if (!__clk_init(NULL, c->lk.clk))
omap2_init_clk_hw_omap_clocks(c->lk.clk);
}
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
