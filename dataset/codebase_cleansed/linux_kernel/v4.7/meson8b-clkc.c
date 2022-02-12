static void __init meson8b_clkc_init(struct device_node *np)
{
void __iomem *clk_base;
if (!meson_clk_init(np, CLK_NR_CLKS))
return;
clk_base = of_iomap(np, 0);
if (!clk_base) {
pr_err("%s: Unable to map xtal base\n", __func__);
return;
}
meson_clk_register_clks(&meson8b_xtal_conf, 1, clk_base);
iounmap(clk_base);
clk_base = of_iomap(np, 1);
if (!clk_base) {
pr_err("%s: Unable to map clk base\n", __func__);
return;
}
meson_clk_register_clks(meson8b_clk_confs,
ARRAY_SIZE(meson8b_clk_confs),
clk_base);
}
