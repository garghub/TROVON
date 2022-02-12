static unsigned long pll_recalc(struct clk *clk)
{
int mode = 12;
u32 r = __raw_readl(MODEMR);
if ((r & MODEMR_MASK) & MODEMR_533MHZ)
mode = 16;
return clk->parent->rate * mode;
}
int __init arch_clk_init(void)
{
int i, ret = 0;
for (i = 0; i < ARRAY_SIZE(main_clks); i++)
ret |= clk_register(main_clks[i]);
for (i = 0; i < ARRAY_SIZE(lookups); i++)
clkdev_add(&lookups[i]);
if (!ret)
ret = sh_clk_div4_register(div4_clks, ARRAY_SIZE(div4_clks),
&div4_table);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
return ret;
}
