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
imc->vco1name = kasprintf(GFP_KERNEL, "lm%x-vco1", id);
clk = icst_clk_register(NULL, &impd1_icst1_desc, imc->vco1name, NULL,
base);
imc->vco1clk = clk;
imc->clks[0] = clkdev_alloc(clk, NULL, "lm%x:01000", id);
imc->vco2name = kasprintf(GFP_KERNEL, "lm%x-vco2", id);
clk = icst_clk_register(NULL, &impd1_icst2_desc, imc->vco2name, NULL,
base);
imc->vco2clk = clk;
imc->clks[1] = clkdev_alloc(clk, NULL, "lm%x:00700", id);
imc->uartname = kasprintf(GFP_KERNEL, "lm%x-uartclk", id);
clk = clk_register_fixed_factor(NULL, imc->uartname, imc->vco2name,
CLK_IGNORE_UNUSED, 1, 4);
imc->uartclk = clk;
imc->clks[2] = clkdev_alloc(clk, NULL, "lm%x:00100", id);
imc->clks[3] = clkdev_alloc(clk, NULL, "lm%x:00200", id);
imc->spiname = kasprintf(GFP_KERNEL, "lm%x-spiclk", id);
clk = clk_register_fixed_factor(NULL, imc->spiname, imc->vco2name,
CLK_IGNORE_UNUSED, 1, 64);
imc->clks[4] = clkdev_alloc(clk, NULL, "lm%x:00300", id);
imc->scname = kasprintf(GFP_KERNEL, "lm%x-scclk", id);
clk = clk_register_fixed_factor(NULL, imc->scname, imc->vco2name,
CLK_IGNORE_UNUSED, 1, 4);
imc->scclk = clk;
imc->clks[5] = clkdev_alloc(clk, NULL, "lm%x:00600", id);
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
clk_unregister(imc->spiclk);
clk_unregister(imc->uartclk);
clk_unregister(imc->vco2clk);
clk_unregister(imc->vco1clk);
kfree(imc->scname);
kfree(imc->spiname);
kfree(imc->uartname);
kfree(imc->vco2name);
kfree(imc->vco1name);
}
