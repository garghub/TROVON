static void master_clk_init(struct clk *clk)
{
clk->rate *= pfc_divisors[__raw_readl(FRQCR) & 0x0003];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int idx = (__raw_readl(FRQCR) & 0x0003);
return clk->parent->rate / pfc_divisors[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
int idx = ((__raw_readl(FRQCR) >> 16) & 0x0007);
return clk->parent->rate / bfc_divisors[idx];
}
static unsigned long cpu_clk_recalc(struct clk *clk)
{
int idx = ((__raw_readl(FRQCR) >> 24) & 0x0001);
return clk->parent->rate / ifc_divisors[idx];
}
void __init arch_init_clk_ops(struct clk_ops **ops, int idx)
{
if (idx < ARRAY_SIZE(sh7780_clk_ops))
*ops = sh7780_clk_ops[idx];
}
static unsigned long shyway_clk_recalc(struct clk *clk)
{
int idx = ((__raw_readl(FRQCR) >> 20) & 0x0007);
return clk->parent->rate / cfc_divisors[idx];
}
int __init arch_clk_init(void)
{
struct clk *clk;
int i, ret = 0;
cpg_clk_init();
clk = clk_get(NULL, "master_clk");
for (i = 0; i < ARRAY_SIZE(sh7780_onchip_clocks); i++) {
struct clk *clkp = sh7780_onchip_clocks[i];
clkp->parent = clk;
ret |= clk_register(clkp);
}
clk_put(clk);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
return ret;
}
