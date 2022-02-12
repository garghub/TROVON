static void __init prima2_clk_init(struct device_node *np)
{
struct device_node *rscnp;
int i;
rscnp = of_find_compatible_node(NULL, NULL, "sirf,prima2-rsc");
sirfsoc_rsc_vbase = of_iomap(rscnp, 0);
if (!sirfsoc_rsc_vbase)
panic("unable to map rsc registers\n");
of_node_put(rscnp);
sirfsoc_clk_vbase = of_iomap(np, 0);
if (!sirfsoc_clk_vbase)
panic("unable to map clkc registers\n");
prima2_clks[rtc] = clk_register_fixed_rate(NULL, "rtc", NULL, 0, 32768);
prima2_clks[osc] = clk_register_fixed_rate(NULL, "osc", NULL, 0,
26000000);
for (i = pll1; i < maxclk; i++) {
prima2_clks[i] = clk_register(NULL, prima2_clk_hw_array[i]);
BUG_ON(!prima2_clks[i]);
}
clk_register_clkdev(prima2_clks[cpu], NULL, "cpu");
clk_register_clkdev(prima2_clks[io], NULL, "io");
clk_register_clkdev(prima2_clks[mem], NULL, "mem");
clk_register_clkdev(prima2_clks[mem], NULL, "osc");
clk_data.clks = prima2_clks;
clk_data.clk_num = maxclk;
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
}
