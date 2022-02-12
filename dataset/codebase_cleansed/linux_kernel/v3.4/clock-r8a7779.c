static unsigned long mul4_recalc(struct clk *clk)
{
return clk->parent->rate * 4;
}
void __init r8a7779_clock_init(void)
{
int k, ret = 0;
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_mstp32_register(mstp_clks, MSTP_NR);
for (k = 0; !ret && (k < ARRAY_SIZE(late_main_clks)); k++)
ret = clk_register(late_main_clks[k]);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup r8a7779 clocks\n");
}
