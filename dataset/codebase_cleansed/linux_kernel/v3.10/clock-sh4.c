static void master_clk_init(struct clk *clk)
{
clk->rate *= pfc_divisors[__raw_readw(FRQCR) & 0x0007];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FRQCR) & 0x0007);
return clk->parent->rate / pfc_divisors[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FRQCR) >> 3) & 0x0007;
return clk->parent->rate / bfc_divisors[idx];
}
static unsigned long cpu_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FRQCR) >> 6) & 0x0007;
return clk->parent->rate / ifc_divisors[idx];
}
void __init arch_init_clk_ops(struct sh_clk_ops **ops, int idx)
{
if (idx < ARRAY_SIZE(sh4_clk_ops))
*ops = sh4_clk_ops[idx];
}
