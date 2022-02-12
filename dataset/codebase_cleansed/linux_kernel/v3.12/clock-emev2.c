static void emev2_smu_write(unsigned long value, int offs)
{
BUG_ON(!smu_base || (offs >= PAGE_SIZE));
iowrite32(value, smu_base + offs);
}
static unsigned long pll3_recalc(struct clk *clk)
{
return clk->parent->rate * 7000;
}
static int emev2_gclk_enable(struct clk *clk)
{
iowrite32(ioread32(clk->mapped_reg) | (1 << clk->enable_bit),
clk->mapped_reg);
return 0;
}
static void emev2_gclk_disable(struct clk *clk)
{
iowrite32(ioread32(clk->mapped_reg) & ~(1 << clk->enable_bit),
clk->mapped_reg);
}
static int __init emev2_gclk_register(struct clk *clks, int nr)
{
struct clk *clkp;
int ret = 0;
int k;
for (k = 0; !ret && (k < nr); k++) {
clkp = clks + k;
clkp->ops = &emev2_gclk_clk_ops;
ret |= clk_register(clkp);
}
return ret;
}
static unsigned long emev2_sclkdiv_recalc(struct clk *clk)
{
unsigned int sclk_div;
sclk_div = (ioread32(clk->mapped_reg) >> clk->enable_bit) & 0xff;
return clk->parent->rate / (sclk_div + 1);
}
static int __init emev2_sclkdiv_register(struct clk *clks, int nr)
{
struct clk *clkp;
int ret = 0;
int k;
for (k = 0; !ret && (k < nr); k++) {
clkp = clks + k;
clkp->ops = &emev2_sclkdiv_clk_ops;
ret |= clk_register(clkp);
}
return ret;
}
void __init emev2_clock_init(void)
{
int k, ret = 0;
smu_base = ioremap(EMEV2_SMU_BASE, PAGE_SIZE);
BUG_ON(!smu_base);
emev2_smu_write(0, STI_CLKSEL);
emev2_smu_write(1, STI_RSTCTRL);
emev2_smu_write(2, USIAU0_RSTCTRL);
emev2_smu_write(2, USIBU1_RSTCTRL);
emev2_smu_write(2, USIBU2_RSTCTRL);
emev2_smu_write(2, USIBU3_RSTCTRL);
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = emev2_sclkdiv_register(sclkdiv_clks, SCLKDIV_NR);
if (!ret)
ret = emev2_gclk_register(gclk_clks, GCLK_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup emev2 clocks\n");
}
