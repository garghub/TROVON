static void __init atlas6_clk_init(struct device_node *np)
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
atlas6_clks[rtc] = clk_register_fixed_rate(NULL, "rtc", NULL,
CLK_IS_ROOT, 32768);
atlas6_clks[osc] = clk_register_fixed_rate(NULL, "osc", NULL,
CLK_IS_ROOT, 26000000);
for (i = pll1; i < maxclk; i++) {
atlas6_clks[i] = clk_register(NULL, atlas6_clk_hw_array[i]);
BUG_ON(!atlas6_clks[i]);
}
clk_register_clkdev(atlas6_clks[cpu], NULL, "cpu");
clk_register_clkdev(atlas6_clks[io], NULL, "io");
clk_register_clkdev(atlas6_clks[mem], NULL, "mem");
clk_register_clkdev(atlas6_clks[mem], NULL, "osc");
clk_data.clks = atlas6_clks;
clk_data.clk_num = maxclk;
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
}
