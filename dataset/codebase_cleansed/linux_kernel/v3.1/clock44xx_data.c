int __init omap4xxx_clk_init(void)
{
struct omap_clk *c;
u32 cpu_clkflg;
if (cpu_is_omap44xx()) {
cpu_mask = RATE_IN_4430;
cpu_clkflg = CK_443X;
} else if (cpu_is_omap446x()) {
cpu_mask = RATE_IN_4460;
cpu_clkflg = CK_446X;
} else {
return 0;
}
clk_init(&omap2_clk_functions);
for (c = omap44xx_clks; c < omap44xx_clks + ARRAY_SIZE(omap44xx_clks);
c++)
clk_preinit(c->lk.clk);
for (c = omap44xx_clks; c < omap44xx_clks + ARRAY_SIZE(omap44xx_clks);
c++)
if (c->cpu & cpu_clkflg) {
clkdev_add(&c->lk);
clk_register(c->lk.clk);
omap2_init_clk_clkdm(c->lk.clk);
}
omap_clk_disable_autoidle_all();
recalculate_root_clocks();
clk_enable_init_clocks();
return 0;
}
