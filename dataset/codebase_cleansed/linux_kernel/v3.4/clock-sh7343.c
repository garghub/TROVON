static unsigned long dll_recalc(struct clk *clk)
{
unsigned long mult;
if (__raw_readl(PLLCR) & 0x1000)
mult = __raw_readl(DLLFRQ);
else
mult = 0;
return clk->parent->rate * mult;
}
static unsigned long pll_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (__raw_readl(PLLCR) & 0x4000)
mult = (((__raw_readl(FRQCR) >> 24) & 0x1f) + 1);
return clk->parent->rate * mult;
}
int __init arch_clk_init(void)
{
int k, ret = 0;
if (__raw_readl(PLLCR) & 0x1000)
pll_clk.parent = &dll_clk;
else
pll_clk.parent = &extal_clk;
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_div6_register(div6_clks, DIV6_NR);
if (!ret)
ret = sh_clk_mstp32_register(mstp_clks, MSTP_NR);
return ret;
}
