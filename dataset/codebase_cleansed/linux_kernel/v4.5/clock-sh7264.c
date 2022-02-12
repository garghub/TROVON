static unsigned long pll_recalc(struct clk *clk)
{
unsigned long rate = clk->parent->rate / pll1_div;
return rate * pll1rate[(__raw_readw(FRQCR) >> 8) & 1];
}
int __init arch_clk_init(void)
{
int k, ret = 0;
if (test_mode_pin(MODE_PIN0)) {
if (test_mode_pin(MODE_PIN1))
pll1_div = 3;
else
pll1_div = 4;
} else
pll1_div = 1;
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
return ret;
}
