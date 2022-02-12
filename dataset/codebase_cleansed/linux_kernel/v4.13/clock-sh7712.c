static void master_clk_init(struct clk *clk)
{
int frqcr = __raw_readw(FRQCR);
int idx = (frqcr & 0x0300) >> 8;
clk->rate *= multipliers[idx];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int frqcr = __raw_readw(FRQCR);
int idx = frqcr & 0x0007;
return clk->parent->rate / divisors[idx];
}
static unsigned long cpu_clk_recalc(struct clk *clk)
{
int frqcr = __raw_readw(FRQCR);
int idx = (frqcr & 0x0030) >> 4;
return clk->parent->rate / divisors[idx];
}
void __init arch_init_clk_ops(struct sh_clk_ops **ops, int idx)
{
if (idx < ARRAY_SIZE(sh7712_clk_ops))
*ops = sh7712_clk_ops[idx];
}
