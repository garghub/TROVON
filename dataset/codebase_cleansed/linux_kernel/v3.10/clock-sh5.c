static void master_clk_init(struct clk *clk)
{
int idx = (__raw_readl(cprc_base + 0x00) >> 6) & 0x0007;
clk->rate *= ifc_table[idx];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(cprc_base) >> 12) & 0x0007;
return clk->parent->rate / ifc_table[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(cprc_base) >> 3) & 0x0007;
return clk->parent->rate / ifc_table[idx];
}
static unsigned long cpu_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(cprc_base) & 0x0007);
return clk->parent->rate / ifc_table[idx];
}
void __init arch_init_clk_ops(struct sh_clk_ops **ops, int idx)
{
cprc_base = (unsigned long)ioremap_nocache(CPRC_BASE, 1024);
BUG_ON(!cprc_base);
if (idx < ARRAY_SIZE(sh5_clk_ops))
*ops = sh5_clk_ops[idx];
}
