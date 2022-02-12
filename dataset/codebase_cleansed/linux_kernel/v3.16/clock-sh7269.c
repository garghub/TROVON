static unsigned long pll_recalc(struct clk *clk)
{
return clk->parent->rate * PLL_RATE;
}
static unsigned long peripheral0_recalc(struct clk *clk)
{
return clk->parent->rate / 8;
}
static unsigned long peripheral1_recalc(struct clk *clk)
{
return clk->parent->rate / 4;
}
int __init arch_clk_init(void)
{
int k, ret = 0;
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
return ret;
}
