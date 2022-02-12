static void __init ns2_genpll_scr_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &genpll_scr, NULL, 0, genpll_scr_clk,
ARRAY_SIZE(genpll_scr_clk));
}
static void __init ns2_genpll_sw_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &genpll_sw, NULL, 0, genpll_sw_clk,
ARRAY_SIZE(genpll_sw_clk));
}
static void __init ns2_lcpll_ddr_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &lcpll_ddr, NULL, 0, lcpll_ddr_clk,
ARRAY_SIZE(lcpll_ddr_clk));
}
static void __init ns2_lcpll_ports_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &lcpll_ports, NULL, 0, lcpll_ports_clk,
ARRAY_SIZE(lcpll_ports_clk));
}
