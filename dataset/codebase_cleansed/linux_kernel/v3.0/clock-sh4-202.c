static unsigned long emi_clk_recalc(struct clk *clk)
{
int idx = __raw_readl(CPG2_FRQCR3) & 0x0007;
return clk->parent->rate / frqcr3_divisors[idx];
}
static inline int frqcr3_lookup(struct clk *clk, unsigned long rate)
{
int divisor = clk->parent->rate / rate;
int i;
for (i = 0; i < ARRAY_SIZE(frqcr3_divisors); i++)
if (frqcr3_divisors[i] == divisor)
return frqcr3_values[i];
return 5;
}
static unsigned long femi_clk_recalc(struct clk *clk)
{
int idx = (__raw_readl(CPG2_FRQCR3) >> 3) & 0x0007;
return clk->parent->rate / frqcr3_divisors[idx];
}
static void shoc_clk_init(struct clk *clk)
{
int i;
for (i = 0; i < ARRAY_SIZE(frqcr3_divisors); i++) {
int divisor = frqcr3_divisors[i];
if (clk->ops->set_rate(clk, clk->parent->rate / divisor) == 0)
break;
}
WARN_ON(i == ARRAY_SIZE(frqcr3_divisors));
}
static unsigned long shoc_clk_recalc(struct clk *clk)
{
int idx = (__raw_readl(CPG2_FRQCR3) >> 6) & 0x0007;
return clk->parent->rate / frqcr3_divisors[idx];
}
static int shoc_clk_verify_rate(struct clk *clk, unsigned long rate)
{
struct clk *bclk = clk_get(NULL, "bus_clk");
unsigned long bclk_rate = clk_get_rate(bclk);
clk_put(bclk);
if (rate > bclk_rate)
return 1;
if (rate > 66000000)
return 1;
return 0;
}
static int shoc_clk_set_rate(struct clk *clk, unsigned long rate)
{
unsigned long frqcr3;
unsigned int tmp;
if (shoc_clk_verify_rate(clk, rate) != 0)
return -EINVAL;
tmp = frqcr3_lookup(clk, rate);
frqcr3 = __raw_readl(CPG2_FRQCR3);
frqcr3 &= ~(0x0007 << 6);
frqcr3 |= tmp << 6;
__raw_writel(frqcr3, CPG2_FRQCR3);
clk->rate = clk->parent->rate / frqcr3_divisors[tmp];
return 0;
}
int __init arch_clk_init(void)
{
struct clk *clk;
int i, ret = 0;
cpg_clk_init();
clk = clk_get(NULL, "master_clk");
for (i = 0; i < ARRAY_SIZE(sh4202_onchip_clocks); i++) {
struct clk *clkp = sh4202_onchip_clocks[i];
clkp->parent = clk;
ret |= clk_register(clkp);
}
clk_put(clk);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
return ret;
}
