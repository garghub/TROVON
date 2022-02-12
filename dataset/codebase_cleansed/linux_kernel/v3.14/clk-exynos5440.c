static void __init exynos5440_clk_init(struct device_node *np)
{
void __iomem *reg_base;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("%s: failed to map clock controller registers,"
" aborting clock initialization\n", __func__);
return;
}
samsung_clk_init(np, reg_base, CLK_NR_CLKS, NULL, 0, NULL, 0);
samsung_clk_of_register_fixed_ext(exynos5440_fixed_rate_ext_clks,
ARRAY_SIZE(exynos5440_fixed_rate_ext_clks), ext_clk_match);
samsung_clk_register_pll2550x("cplla", "xtal", reg_base + 0x1c, 0x10);
samsung_clk_register_pll2550x("cpllb", "xtal", reg_base + 0x20, 0x10);
samsung_clk_register_fixed_rate(exynos5440_fixed_rate_clks,
ARRAY_SIZE(exynos5440_fixed_rate_clks));
samsung_clk_register_fixed_factor(exynos5440_fixed_factor_clks,
ARRAY_SIZE(exynos5440_fixed_factor_clks));
samsung_clk_register_mux(exynos5440_mux_clks,
ARRAY_SIZE(exynos5440_mux_clks));
samsung_clk_register_div(exynos5440_div_clks,
ARRAY_SIZE(exynos5440_div_clks));
samsung_clk_register_gate(exynos5440_gate_clks,
ARRAY_SIZE(exynos5440_gate_clks));
pr_info("Exynos5440: arm_clk = %ldHz\n", _get_rate("arm_clk"));
pr_info("exynos5440 clock initialization complete\n");
}
