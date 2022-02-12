static void master_clk_init(struct clk *clk)
{
clk->rate = 10000000 * pll2_mult *
pll1rate[(__raw_readw(FREQCR) >> 8) & 0x0007];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FREQCR) & 0x0007);
return clk->parent->rate / pfc_divisors[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FREQCR) & 0x0007);
return clk->parent->rate / pfc_divisors[idx];
}
static unsigned long cpu_clk_recalc(struct clk *clk)
{
int idx = ((__raw_readw(FREQCR) >> 4) & 0x0007);
return clk->parent->rate / ifc_divisors[idx];
}
void __init arch_init_clk_ops(struct sh_clk_ops **ops, int idx)
{
if (test_mode_pin(MODE_PIN1 | MODE_PIN0))
pll2_mult = 1;
else if (test_mode_pin(MODE_PIN1))
pll2_mult = 2;
else
pll2_mult = 4;
if (idx < ARRAY_SIZE(sh7201_clk_ops))
*ops = sh7201_clk_ops[idx];
}
