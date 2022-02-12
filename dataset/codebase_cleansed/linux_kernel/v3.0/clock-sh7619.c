static void master_clk_init(struct clk *clk)
{
clk->rate *= pll2_mult * pll1rate[(__raw_readw(FREQCR) >> 8) & 7];
}
static unsigned long module_clk_recalc(struct clk *clk)
{
int idx = (__raw_readw(FREQCR) & 0x0007);
return clk->parent->rate / pfc_divisors[idx];
}
static unsigned long bus_clk_recalc(struct clk *clk)
{
return clk->parent->rate / pll1rate[(__raw_readw(FREQCR) >> 8) & 7];
}
void __init arch_init_clk_ops(struct clk_ops **ops, int idx)
{
if (test_mode_pin(MODE_PIN2 | MODE_PIN0) ||
test_mode_pin(MODE_PIN2 | MODE_PIN1))
pll2_mult = 2;
else if (test_mode_pin(MODE_PIN0) || test_mode_pin(MODE_PIN1))
pll2_mult = 4;
BUG_ON(!pll2_mult);
if (idx < ARRAY_SIZE(sh7619_clk_ops))
*ops = sh7619_clk_ops[idx];
}
