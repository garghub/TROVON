static inline void am33xx_init_timer_parent(struct clk *clk)
{
omap2_clksel_set_parent(clk, clk->parent);
}
int __init am33xx_clk_init(void)
{
struct omap_clk *c;
u32 cpu_clkflg;
if (soc_is_am33xx()) {
cpu_mask = RATE_IN_AM33XX;
cpu_clkflg = CK_AM33XX;
}
clk_init(&omap2_clk_functions);
for (c = am33xx_clks; c < am33xx_clks + ARRAY_SIZE(am33xx_clks); c++)
clk_preinit(c->lk.clk);
for (c = am33xx_clks; c < am33xx_clks + ARRAY_SIZE(am33xx_clks); c++) {
if (c->cpu & cpu_clkflg) {
clkdev_add(&c->lk);
clk_register(c->lk.clk);
omap2_init_clk_clkdm(c->lk.clk);
}
}
recalculate_root_clocks();
clk_enable_init_clocks();
return 0;
}
