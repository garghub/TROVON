static int gxbb_clkc_probe(struct platform_device *pdev)
{
void __iomem *clk_base;
int ret, clkid, i;
struct clk_hw *parent_hw;
struct clk *parent_clk;
struct device *dev = &pdev->dev;
clk_base = of_iomap(dev->of_node, 0);
if (!clk_base) {
pr_err("%s: Unable to map clk base\n", __func__);
return -ENXIO;
}
for (i = 0; i < ARRAY_SIZE(gxbb_clk_plls); i++)
gxbb_clk_plls[i]->base = clk_base;
for (i = 0; i < ARRAY_SIZE(gxbb_clk_mplls); i++)
gxbb_clk_mplls[i]->base = clk_base;
gxbb_cpu_clk.base = clk_base;
gxbb_mpeg_clk_sel.reg = clk_base + (u64)gxbb_mpeg_clk_sel.reg;
gxbb_mpeg_clk_div.reg = clk_base + (u64)gxbb_mpeg_clk_div.reg;
gxbb_sar_adc_clk_sel.reg = clk_base + (u64)gxbb_sar_adc_clk_sel.reg;
gxbb_sar_adc_clk_div.reg = clk_base + (u64)gxbb_sar_adc_clk_div.reg;
for (i = 0; i < ARRAY_SIZE(gxbb_clk_gates); i++)
gxbb_clk_gates[i]->reg = clk_base +
(u64)gxbb_clk_gates[i]->reg;
for (clkid = 0; clkid < NR_CLKS; clkid++) {
ret = devm_clk_hw_register(dev, gxbb_hw_onecell_data.hws[clkid]);
if (ret)
goto iounmap;
}
parent_hw = clk_hw_get_parent(&gxbb_cpu_clk.hw);
parent_clk = parent_hw->clk;
ret = clk_notifier_register(parent_clk, &gxbb_cpu_clk.clk_nb);
if (ret) {
pr_err("%s: failed to register clock notifier for cpu_clk\n",
__func__);
goto iounmap;
}
return of_clk_add_hw_provider(dev->of_node, of_clk_hw_onecell_get,
&gxbb_hw_onecell_data);
iounmap:
iounmap(clk_base);
return ret;
}
