static unsigned long pll_recalc(struct clk *clk)
{
int multiplier;
multiplier = test_mode_pin(MODE_PIN4) ? 36 : 72;
return clk->parent->rate * multiplier;
}
int __init arch_clk_init(void)
{
int i, ret = 0;
for (i = 0; i < ARRAY_SIZE(clks); i++)
ret |= clk_register(clks[i]);
for (i = 0; i < ARRAY_SIZE(lookups); i++)
clkdev_add(&lookups[i]);
if (!ret)
ret = sh_clk_div4_register(div4_clks, ARRAY_SIZE(div4_clks),
&div4_table);
if (!ret)
ret = sh_clk_mstp32_register(mstp_clks, MSTP_NR);
return ret;
}
