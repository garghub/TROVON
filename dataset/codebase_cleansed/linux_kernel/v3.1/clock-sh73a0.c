static unsigned long div2_recalc(struct clk *clk)
{
return clk->parent->rate / 2;
}
static unsigned long pll_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (__raw_readl(PLLECR) & (1 << clk->enable_bit)) {
mult = (((__raw_readl(clk->enable_reg) >> 24) & 0x3f) + 1);
switch (clk->enable_bit) {
case 1:
case 2:
if (__raw_readl(clk->enable_reg) & (1 << 20))
mult *= 2;
}
}
return clk->parent->rate * mult;
}
static void div4_kick(struct clk *clk)
{
unsigned long value;
value = __raw_readl(FRQCRB);
value |= (1 << 31);
__raw_writel(value, FRQCRB);
}
void __init sh73a0_clock_init(void)
{
int k, ret = 0;
__raw_writel(0x108, SD0CKCR);
__raw_writel(0x108, SD1CKCR);
__raw_writel(0x108, SD2CKCR);
switch ((__raw_readl(CKSCR) >> 28) & 0x03) {
case 0:
main_clk.parent = &sh73a0_extal1_clk;
break;
case 1:
main_clk.parent = &extal1_div2_clk;
break;
case 2:
main_clk.parent = &sh73a0_extal2_clk;
break;
case 3:
main_clk.parent = &extal2_div2_clk;
break;
}
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
panic("failed to setup sh73a0 clocks\n");
}
