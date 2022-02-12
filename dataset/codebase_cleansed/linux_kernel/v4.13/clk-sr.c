static int sr_genpll0_clk_init(struct platform_device *pdev)
{
iproc_pll_clk_setup(pdev->dev.of_node,
&sr_genpll0, NULL, 0, sr_genpll0_clk,
ARRAY_SIZE(sr_genpll0_clk));
return 0;
}
static void sr_genpll3_clk_init(struct device_node *node)
{
iproc_pll_clk_setup(node, &sr_genpll3, NULL, 0, sr_genpll3_clk,
ARRAY_SIZE(sr_genpll3_clk));
}
static int sr_genpll4_clk_init(struct platform_device *pdev)
{
iproc_pll_clk_setup(pdev->dev.of_node,
&sr_genpll4, NULL, 0, sr_genpll4_clk,
ARRAY_SIZE(sr_genpll4_clk));
return 0;
}
static int sr_genpll5_clk_init(struct platform_device *pdev)
{
iproc_pll_clk_setup(pdev->dev.of_node,
&sr_genpll5, NULL, 0, sr_genpll5_clk,
ARRAY_SIZE(sr_genpll5_clk));
return 0;
}
static int sr_lcpll0_clk_init(struct platform_device *pdev)
{
iproc_pll_clk_setup(pdev->dev.of_node,
&sr_lcpll0, NULL, 0, sr_lcpll0_clk,
ARRAY_SIZE(sr_lcpll0_clk));
return 0;
}
static int sr_lcpll1_clk_init(struct platform_device *pdev)
{
iproc_pll_clk_setup(pdev->dev.of_node,
&sr_lcpll1, NULL, 0, sr_lcpll1_clk,
ARRAY_SIZE(sr_lcpll1_clk));
return 0;
}
static int sr_lcpll_pcie_clk_init(struct platform_device *pdev)
{
iproc_pll_clk_setup(pdev->dev.of_node,
&sr_lcpll_pcie, NULL, 0, sr_lcpll_pcie_clk,
ARRAY_SIZE(sr_lcpll_pcie_clk));
return 0;
}
static int sr_clk_probe(struct platform_device *pdev)
{
int (*probe_func)(struct platform_device *);
probe_func = of_device_get_match_data(&pdev->dev);
if (!probe_func)
return -ENODEV;
return probe_func(pdev);
}
