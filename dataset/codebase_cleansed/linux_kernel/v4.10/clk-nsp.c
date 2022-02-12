static void __init nsp_armpll_init(struct device_node *node)
{
iproc_armpll_setup(node);
}
static void __init nsp_genpll_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &genpll, NULL, 0, genpll_clk,
ARRAY_SIZE(genpll_clk));
}
static void __init nsp_lcpll0_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &lcpll0, NULL, 0, lcpll0_clk,
ARRAY_SIZE(lcpll0_clk));
}
