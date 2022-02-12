static void master_clk_init(struct clk *clk)
{
clk->rate *= pll1rate[(__raw_readw(FREQCR) >> 8) & 0x0003] * pll2_mult;
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FREQCR) & 0x0007);
return clk->parent->rate / pfc_divisors[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FREQCR) & 0x0007);
return clk->parent->rate / pfc_divisors[idx-2];
}
void __init arch_init_clk_ops(struct sh_clk_ops **ops, int idx)
{
if (test_mode_pin(MODE_PIN1))
pll2_mult = 4;
else if (test_mode_pin(MODE_PIN0))
pll2_mult = 2;
else
pll2_mult = 1;
if (idx < ARRAY_SIZE(sh7203_clk_ops))
*ops = sh7203_clk_ops[idx];
}
