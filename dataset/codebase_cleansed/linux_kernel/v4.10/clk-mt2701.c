static int mtk_topckgen_init(struct platform_device *pdev)
{
struct clk_onecell_data *clk_data;
void __iomem *base;
struct device_node *node = pdev->dev.of_node;
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
clk_data = mtk_alloc_clk_data(CLK_TOP_NR);
mtk_clk_register_fixed_clks(top_fixed_clks, ARRAY_SIZE(top_fixed_clks),
clk_data);
mtk_clk_register_factors(top_fixed_divs, ARRAY_SIZE(top_fixed_divs),
clk_data);
mtk_clk_register_composites(top_muxes, ARRAY_SIZE(top_muxes),
base, &mt2701_clk_lock, clk_data);
mtk_clk_register_dividers(top_adj_divs, ARRAY_SIZE(top_adj_divs),
base, &mt2701_clk_lock, clk_data);
mtk_clk_register_gates(node, top_clks, ARRAY_SIZE(top_clks),
clk_data);
return of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
}
static void mtk_infrasys_init_early(struct device_node *node)
{
int r, i;
if (!infra_clk_data) {
infra_clk_data = mtk_alloc_clk_data(CLK_INFRA_NR);
for (i = 0; i < CLK_INFRA_NR; i++)
infra_clk_data->clks[i] = ERR_PTR(-EPROBE_DEFER);
}
mtk_clk_register_factors(infra_fixed_divs, ARRAY_SIZE(infra_fixed_divs),
infra_clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, infra_clk_data);
if (r)
pr_err("%s(): could not register clock provider: %d\n",
__func__, r);
}
static int mtk_infrasys_init(struct platform_device *pdev)
{
int r, i;
struct device_node *node = pdev->dev.of_node;
if (!infra_clk_data) {
infra_clk_data = mtk_alloc_clk_data(CLK_INFRA_NR);
} else {
for (i = 0; i < CLK_INFRA_NR; i++) {
if (infra_clk_data->clks[i] == ERR_PTR(-EPROBE_DEFER))
infra_clk_data->clks[i] = ERR_PTR(-ENOENT);
}
}
mtk_clk_register_gates(node, infra_clks, ARRAY_SIZE(infra_clks),
infra_clk_data);
mtk_clk_register_factors(infra_fixed_divs, ARRAY_SIZE(infra_fixed_divs),
infra_clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, infra_clk_data);
if (r)
return r;
mtk_register_reset_controller(node, 2, 0x30);
return 0;
}
static int mtk_pericfg_init(struct platform_device *pdev)
{
struct clk_onecell_data *clk_data;
void __iomem *base;
int r;
struct device_node *node = pdev->dev.of_node;
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
clk_data = mtk_alloc_clk_data(CLK_PERI_NR);
mtk_clk_register_gates(node, peri_clks, ARRAY_SIZE(peri_clks),
clk_data);
mtk_clk_register_composites(peri_muxs, ARRAY_SIZE(peri_muxs), base,
&mt2701_clk_lock, clk_data);
r = of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
if (r)
return r;
mtk_register_reset_controller(node, 2, 0x0);
return 0;
}
static int mtk_apmixedsys_init(struct platform_device *pdev)
{
struct clk_onecell_data *clk_data;
struct device_node *node = pdev->dev.of_node;
clk_data = mtk_alloc_clk_data(CLK_APMIXED_NR);
if (!clk_data)
return -ENOMEM;
mtk_clk_register_plls(node, apmixed_plls, ARRAY_SIZE(apmixed_plls),
clk_data);
return of_clk_add_provider(node, of_clk_src_onecell_get, clk_data);
}
static int clk_mt2701_probe(struct platform_device *pdev)
{
int (*clk_init)(struct platform_device *);
int r;
clk_init = of_device_get_match_data(&pdev->dev);
if (!clk_init)
return -EINVAL;
r = clk_init(pdev);
if (r)
dev_err(&pdev->dev,
"could not register clock provider: %s: %d\n",
pdev->name, r);
return r;
}
static int __init clk_mt2701_init(void)
{
return platform_driver_register(&clk_mt2701_drv);
}
