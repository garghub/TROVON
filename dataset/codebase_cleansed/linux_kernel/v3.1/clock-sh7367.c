static unsigned long div2_recalc(struct clk *clk)
{
return clk->parent->rate / 2;
}
static unsigned long pllc1_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (__raw_readl(PLLC1CR) & (1 << 14))
mult = (((__raw_readl(RTFRQCR) >> 24) & 0x3f) + 1) * 2;
return clk->parent->rate * mult;
}
static unsigned long pllc2_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (__raw_readl(PLLC2CR) & (1 << 31))
mult = (((__raw_readl(PLLC2CR) >> 24) & 0x3f) + 1) * 2;
return clk->parent->rate * mult;
}
static void div4_kick(struct clk *clk)
{
unsigned long value;
value = __raw_readl(SYFRQCR);
value |= (1 << 31);
__raw_writel(value, SYFRQCR);
}
void __init sh7367_clock_init(void)
{
int k, ret = 0;
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_div6_register(div6_clks, DIV6_NR);
if (!ret)
ret = sh_clk_mstp32_register(mstp_clks, MSTP_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
clk_init();
else
panic("failed to setup sh7367 clocks\n");
}
