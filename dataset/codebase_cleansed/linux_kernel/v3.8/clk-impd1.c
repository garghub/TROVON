void integrator_impd1_clk_init(void __iomem *base, unsigned int id)
{
struct impd1_clk *imc;
struct clk *clk;
int i;
if (id > 3) {
pr_crit("no more than 4 LMs can be attached\n");
return;
}
imc = &impd1_clks[id];
clk = icst_clk_register(NULL, &impd1_icst1_desc, base);
imc->vcoclk = clk;
imc->clks[0] = clkdev_alloc(clk, NULL, "lm%x:01000", id);
clk = clk_register_fixed_rate(NULL, "uartclk", NULL, CLK_IS_ROOT,
14745600);
imc->uartclk = clk;
imc->clks[1] = clkdev_alloc(clk, NULL, "lm%x:00100", id);
imc->clks[2] = clkdev_alloc(clk, NULL, "lm%x:00200", id);
for (i = 0; i < ARRAY_SIZE(imc->clks); i++)
clkdev_add(imc->clks[i]);
}
void integrator_impd1_clk_exit(unsigned int id)
{
int i;
struct impd1_clk *imc;
if (id > 3)
return;
imc = &impd1_clks[id];
for (i = 0; i < ARRAY_SIZE(imc->clks); i++)
clkdev_drop(imc->clks[i]);
clk_unregister(imc->uartclk);
clk_unregister(imc->vcoclk);
}
