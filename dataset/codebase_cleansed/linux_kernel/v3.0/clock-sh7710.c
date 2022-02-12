static void master_clk_init(struct clk *clk)
{
clk->rate *= md_table[__raw_readw(FRQCR) & 0x0007];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FRQCR) & 0x0007);
return clk->parent->rate / md_table[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FRQCR) & 0x0700) >> 8;
return clk->parent->rate / md_table[idx];
}
static unsigned long cpu_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FRQCR) & 0x0070) >> 4;
return clk->parent->rate / md_table[idx];
}
void __init arch_init_clk_ops(struct clk_ops **ops, int idx)
{
if (idx < ARRAY_SIZE(sh7710_clk_ops))
*ops = sh7710_clk_ops[idx];
}
