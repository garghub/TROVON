static void __init cygnus_armpll_init(struct device_node *node)
{
iproc_armpll_setup(node);
}
static void __init cygnus_genpll_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &genpll, NULL, 0, genpll_clk,
ARRAY_SIZE(genpll_clk));
}
static void __init cygnus_lcpll0_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &lcpll0, NULL, 0, lcpll0_clk,
ARRAY_SIZE(lcpll0_clk));
}
static void __init cygnus_mipipll_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &mipipll, mipipll_vco_params,
ARRAY_SIZE(mipipll_vco_params), mipipll_clk,
ARRAY_SIZE(mipipll_clk));
}
static void __init cygnus_asiu_init(struct device_node *node)
{
iproc_asiu_setup(node, asiu_div, asiu_gate, ARRAY_SIZE(asiu_div));
}
