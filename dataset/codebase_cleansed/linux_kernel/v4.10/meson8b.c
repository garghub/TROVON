static int meson8b_clkc_probe(struct platform_device *pdev)
{
void __iomem *clk_base;
int ret, clkid, i;
struct clk_hw *parent_hw;
struct clk *parent_clk;
struct device *dev = &pdev->dev;
clk_base = of_iomap(dev->of_node, 1);
if (!clk_base) {
pr_err("%s: Unable to map clk base\n", __func__);
return -ENXIO;
}
for (i = 0; i < ARRAY_SIZE(meson8b_clk_plls); i++)
meson8b_clk_plls[i]->base = clk_base;
meson8b_cpu_clk.base = clk_base;
meson8b_mpeg_clk_sel.reg = clk_base + (u32)meson8b_mpeg_clk_sel.reg;
meson8b_mpeg_clk_div.reg = clk_base + (u32)meson8b_mpeg_clk_div.reg;
meson8b_clk81.reg = clk_base + (u32)meson8b_clk81.reg;
for (i = 0; i < ARRAY_SIZE(meson8b_clk_gates); i++)
meson8b_clk_gates[i]->reg = clk_base +
(u32)meson8b_clk_gates[i]->reg;
for (clkid = CLKID_XTAL; clkid < CLK_NR_CLKS; clkid++) {
if (!meson8b_hw_onecell_data.hws[clkid])
continue;
ret = devm_clk_hw_register(dev, meson8b_hw_onecell_data.hws[clkid]);
if (ret)
goto iounmap;
}
parent_hw = clk_hw_get_parent(&meson8b_cpu_clk.hw);
parent_clk = parent_hw->clk;
ret = clk_notifier_register(parent_clk, &meson8b_cpu_clk.clk_nb);
if (ret) {
pr_err("%s: failed to register clock notifier for cpu_clk\n",
__func__);
goto iounmap;
}
return of_clk_add_hw_provider(dev->of_node, of_clk_hw_onecell_get,
&meson8b_hw_onecell_data);
iounmap:
iounmap(clk_base);
return ret;
}
