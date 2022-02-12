int __init am33xx_clk_init(void)
{
struct omap_clk *c;
u32 cpu_clkflg;
if (soc_is_am33xx()) {
cpu_mask = RATE_IN_AM33XX;
cpu_clkflg = CK_AM33XX;
}
for (c = am33xx_clks; c < am33xx_clks + ARRAY_SIZE(am33xx_clks); c++) {
if (c->cpu & cpu_clkflg) {
clkdev_add(&c->lk);
if (!__clk_init(NULL, c->lk.clk))
omap2_init_clk_hw_omap_clocks(c->lk.clk);
}
}
omap2_clk_disable_autoidle_all();
omap2_clk_enable_init_clocks(enable_init_clks,
ARRAY_SIZE(enable_init_clks));
clk_set_parent(&timer3_fck, &sys_clkin_ck);
clk_set_parent(&timer6_fck, &sys_clkin_ck);
return 0;
}
