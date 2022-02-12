int __init __deprecated cpg_clk_init(void)
{
int i, ret = 0;
for (i = 0; i < ARRAY_SIZE(onchip_clocks); i++) {
struct clk *clk = onchip_clocks[i];
arch_init_clk_ops(&clk->ops, i);
if (clk->ops)
ret |= clk_register(clk);
}
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
clk_add_alias("tmu_fck", NULL, "peripheral_clk", NULL);
clk_add_alias("mtu2_fck", NULL, "peripheral_clk", NULL);
clk_add_alias("cmt_fck", NULL, "peripheral_clk", NULL);
clk_add_alias("sci_ick", NULL, "peripheral_clk", NULL);
return ret;
}
int __init __weak arch_clk_init(void)
{
return cpg_clk_init();
}
