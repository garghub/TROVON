static void __init exynos5410_clk_init(struct device_node *np)
{
struct samsung_clk_provider *ctx;
void __iomem *reg_base;
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
ctx = samsung_clk_init(np, reg_base, CLK_NR_CLKS);
samsung_clk_register_pll(ctx, exynos5410_plls,
ARRAY_SIZE(exynos5410_plls), reg_base);
samsung_clk_register_mux(ctx, exynos5410_mux_clks,
ARRAY_SIZE(exynos5410_mux_clks));
samsung_clk_register_div(ctx, exynos5410_div_clks,
ARRAY_SIZE(exynos5410_div_clks));
samsung_clk_register_gate(ctx, exynos5410_gate_clks,
ARRAY_SIZE(exynos5410_gate_clks));
samsung_clk_of_add_provider(np, ctx);
pr_debug("Exynos5410: clock setup completed.\n");
}
