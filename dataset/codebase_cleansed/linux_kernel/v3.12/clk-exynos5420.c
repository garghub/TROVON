static void __init exynos5420_clk_init(struct device_node *np)
{
void __iomem *reg_base;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
} else {
panic("%s: unable to determine soc\n", __func__);
}
samsung_clk_init(np, reg_base, nr_clks,
exynos5420_clk_regs, ARRAY_SIZE(exynos5420_clk_regs),
NULL, 0);
samsung_clk_of_register_fixed_ext(exynos5420_fixed_rate_ext_clks,
ARRAY_SIZE(exynos5420_fixed_rate_ext_clks),
ext_clk_match);
samsung_clk_register_pll(exynos5420_plls, ARRAY_SIZE(exynos5420_plls),
reg_base);
samsung_clk_register_fixed_rate(exynos5420_fixed_rate_clks,
ARRAY_SIZE(exynos5420_fixed_rate_clks));
samsung_clk_register_fixed_factor(exynos5420_fixed_factor_clks,
ARRAY_SIZE(exynos5420_fixed_factor_clks));
samsung_clk_register_mux(exynos5420_mux_clks,
ARRAY_SIZE(exynos5420_mux_clks));
samsung_clk_register_div(exynos5420_div_clks,
ARRAY_SIZE(exynos5420_div_clks));
samsung_clk_register_gate(exynos5420_gate_clks,
ARRAY_SIZE(exynos5420_gate_clks));
}
