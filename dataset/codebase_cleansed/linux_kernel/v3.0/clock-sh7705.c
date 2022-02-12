static void master_clk_init(struct clk *clk)
{
clk->rate *= pfc_divisors[__raw_readw(FRQCR) & 0x0003];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int idx = __raw_readw(FRQCR) & 0x0003;
return clk->parent->rate / pfc_divisors[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FRQCR) & 0x0300) >> 8;
return clk->parent->rate / stc_multipliers[idx];
}
static unsigned long cpu_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FRQCR) & 0x0030) >> 4;
return clk->parent->rate / ifc_divisors[idx];
}
void __init arch_init_clk_ops(struct clk_ops **ops, int idx)
{
if (idx < ARRAY_SIZE(sh7705_clk_ops))
*ops = sh7705_clk_ops[idx];
}
