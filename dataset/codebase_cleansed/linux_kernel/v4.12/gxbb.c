static int gxbb_clkc_probe(struct platform_device *pdev)
{
const struct clkc_data *clkc_data;
void __iomem *clk_base;
int ret, clkid, i;
struct clk_hw *parent_hw;
struct clk *parent_clk;
struct device *dev = &pdev->dev;
clkc_data = of_device_get_match_data(&pdev->dev);
if (!clkc_data)
return -EINVAL;
clk_base = of_iomap(dev->of_node, 0);
if (!clk_base) {
pr_err("%s: Unable to map clk base\n", __func__);
return -ENXIO;
}
for (i = 0; i < clkc_data->clk_plls_count; i++)
clkc_data->clk_plls[i]->base = clk_base;
for (i = 0; i < clkc_data->clk_mplls_count; i++)
clkc_data->clk_mplls[i]->base = clk_base;
clkc_data->cpu_clk->base = clk_base;
for (i = 0; i < clkc_data->clk_gates_count; i++)
clkc_data->clk_gates[i]->reg = clk_base +
(u64)clkc_data->clk_gates[i]->reg;
for (i = 0; i < clkc_data->clk_muxes_count; i++)
clkc_data->clk_muxes[i]->reg = clk_base +
(u64)clkc_data->clk_muxes[i]->reg;
for (i = 0; i < clkc_data->clk_dividers_count; i++)
clkc_data->clk_dividers[i]->reg = clk_base +
(u64)clkc_data->clk_dividers[i]->reg;
for (i = 0; i < clkc_data->clk_audio_dividers_count; i++)
clkc_data->clk_audio_dividers[i]->base = clk_base;
for (clkid = 0; clkid < clkc_data->hw_onecell_data->num; clkid++) {
if (!clkc_data->hw_onecell_data->hws[clkid])
continue;
ret = devm_clk_hw_register(dev,
clkc_data->hw_onecell_data->hws[clkid]);
if (ret)
goto iounmap;
}
parent_hw = clk_hw_get_parent(&clkc_data->cpu_clk->hw);
parent_clk = parent_hw->clk;
ret = clk_notifier_register(parent_clk, &clkc_data->cpu_clk->clk_nb);
if (ret) {
pr_err("%s: failed to register clock notifier for cpu_clk\n",
__func__);
goto iounmap;
}
return of_clk_add_hw_provider(dev->of_node, of_clk_hw_onecell_get,
clkc_data->hw_onecell_data);
iounmap:
iounmap(clk_base);
return ret;
}
