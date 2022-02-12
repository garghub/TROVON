static int clk_mt2701_hif_probe(struct platform_device *pdev)
{
struct clk_onecell_data *clk_data;
int r;
struct device_node *node = pdev->dev.of_node;
clk_data = mtk_alloc_clk_data(CLK_HIFSYS_NR);
mtk_clk_register_gates(node, hif_clks, ARRAY_SIZE(hif_clks),
clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r) {
dev_err(&pdev->dev,
"could not register clock provider: %s: %d\n",
pdev->name, r);
return r;
}
mtk_register_reset_controller(node, 1, 0x34);
return 0;
}
