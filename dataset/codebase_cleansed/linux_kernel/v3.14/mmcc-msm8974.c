static int mmcc_msm8974_probe(struct platform_device *pdev)
{
void __iomem *base;
struct resource *res;
int i, ret;
struct device *dev = &pdev->dev;
struct clk *clk;
struct clk_onecell_data *data;
struct clk **clks;
struct regmap *regmap;
size_t num_clks;
struct qcom_reset_controller *reset;
struct qcom_cc *cc;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
regmap = devm_regmap_init_mmio(dev, base, &mmcc_msm8974_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
num_clks = ARRAY_SIZE(mmcc_msm8974_clocks);
cc = devm_kzalloc(dev, sizeof(*cc) + sizeof(*clks) * num_clks,
GFP_KERNEL);
if (!cc)
return -ENOMEM;
clks = cc->clks;
data = &cc->data;
data->clks = clks;
data->clk_num = num_clks;
clk_pll_configure_sr_hpm_lp(&mmpll1, regmap, &mmpll1_config, true);
clk_pll_configure_sr_hpm_lp(&mmpll3, regmap, &mmpll3_config, false);
for (i = 0; i < num_clks; i++) {
if (!mmcc_msm8974_clocks[i])
continue;
clk = devm_clk_register_regmap(dev, mmcc_msm8974_clocks[i]);
if (IS_ERR(clk))
return PTR_ERR(clk);
clks[i] = clk;
}
ret = of_clk_add_provider(dev->of_node, of_clk_src_onecell_get, data);
if (ret)
return ret;
reset = &cc->reset;
reset->rcdev.of_node = dev->of_node;
reset->rcdev.ops = &qcom_reset_ops,
reset->rcdev.owner = THIS_MODULE,
reset->rcdev.nr_resets = ARRAY_SIZE(mmcc_msm8974_resets),
reset->regmap = regmap;
reset->reset_map = mmcc_msm8974_resets,
platform_set_drvdata(pdev, &reset->rcdev);
ret = reset_controller_register(&reset->rcdev);
if (ret)
of_clk_del_provider(dev->of_node);
return ret;
}
static int mmcc_msm8974_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
reset_controller_unregister(platform_get_drvdata(pdev));
return 0;
}
