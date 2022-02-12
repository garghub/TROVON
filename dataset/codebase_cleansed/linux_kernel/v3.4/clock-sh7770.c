static void master_clk_init(struct clk *clk)
{
clk->rate *= pfc_divisors[(__raw_readl(FRQCR) >> 28) & 0x000f];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int idx = ((__raw_readl(FRQCR) >> 28) & 0x000f);
return clk->parent->rate / pfc_divisors[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
int idx = (__raw_readl(FRQCR) & 0x000f);
return clk->parent->rate / bfc_divisors[idx];
}
static unsigned long cpu_clk_recalc(struct clk *clk)
{
int idx = ((__raw_readl(FRQCR) >> 24) & 0x000f);
return clk->parent->rate / ifc_divisors[idx];
}
void __init arch_init_clk_ops(struct sh_clk_ops **ops, int idx)
{
if (idx < ARRAY_SIZE(sh7770_clk_ops))
*ops = sh7770_clk_ops[idx];
}
