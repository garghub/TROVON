static unsigned long fll_recalc(struct clk *clk)
{
unsigned long mult = 0;
unsigned long div = 1;
if (__raw_readl(PLLCR) & 0x1000)
mult = __raw_readl(FLLFRQ) & 0x3ff;
if (__raw_readl(FLLFRQ) & 0x4000)
div = 2;
return (clk->parent->rate * mult) / div;
}
static unsigned long pll_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (__raw_readl(PLLCR) & 0x4000)
mult = (((__raw_readl(FRQCRA) >> 24) & 0x3f) + 1) * 2;
return clk->parent->rate * mult;
}
static unsigned long div3_recalc(struct clk *clk)
{
return clk->parent->rate / 3;
}
static void div4_kick(struct clk *clk)
{
unsigned long value;
value = __raw_readl(FRQCRA);
value |= (1 << 31);
__raw_writel(value, FRQCRA);
}
int __init arch_clk_init(void)
{
int k, ret = 0;
if (__raw_readl(PLLCR) & 0x1000)
pll_clk.parent = &fll_clk;
else
pll_clk.parent = &extal_clk;
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_div6_reparent_register(div6_clks, DIV6_NR);
if (!ret)
ret = sh_clk_mstp32_register(mstp_clks, HWBLK_NR);
return ret;
}
