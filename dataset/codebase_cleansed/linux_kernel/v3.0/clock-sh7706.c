static void master_clk_init(struct clk *clk)
{
int frqcr = __raw_readw(FRQCR);
int idx = ((frqcr & 0x2000) >> 11) | (frqcr & 0x0003);
clk->rate *= pfc_divisors[idx];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int frqcr = __raw_readw(FRQCR);
int idx = ((frqcr & 0x2000) >> 11) | (frqcr & 0x0003);
return clk->parent->rate / pfc_divisors[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
int frqcr = __raw_readw(FRQCR);
int idx = ((frqcr & 0x8000) >> 13) | ((frqcr & 0x0030) >> 4);
return clk->parent->rate / stc_multipliers[idx];
}
static unsigned long cpu_clk_recalc(struct clk *clk)
{
int frqcr = __raw_readw(FRQCR);
int idx = ((frqcr & 0x4000) >> 12) | ((frqcr & 0x000c) >> 2);
return clk->parent->rate / ifc_divisors[idx];
}
void __init arch_init_clk_ops(struct clk_ops **ops, int idx)
{
if (idx < ARRAY_SIZE(sh7706_clk_ops))
*ops = sh7706_clk_ops[idx];
}
