static void __init exynos5250_clk_init(struct device_node *np)
{
void __iomem *reg_base;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
} else {
panic("%s: unable to determine soc\n", __func__);
}
samsung_clk_init(np, reg_base, CLK_NR_CLKS,
exynos5250_clk_regs, ARRAY_SIZE(exynos5250_clk_regs),
NULL, 0);
samsung_clk_of_register_fixed_ext(exynos5250_fixed_rate_ext_clks,
ARRAY_SIZE(exynos5250_fixed_rate_ext_clks),
ext_clk_match);
samsung_clk_register_mux(exynos5250_pll_pmux_clks,
ARRAY_SIZE(exynos5250_pll_pmux_clks));
if (_get_rate("fin_pll") == 24 * MHZ) {
exynos5250_plls[epll].rate_table = epll_24mhz_tbl;
exynos5250_plls[apll].rate_table = apll_24mhz_tbl;
}
if (_get_rate("mout_vpllsrc") == 24 * MHZ)
exynos5250_plls[vpll].rate_table = vpll_24mhz_tbl;
samsung_clk_register_pll(exynos5250_plls, ARRAY_SIZE(exynos5250_plls),
reg_base);
samsung_clk_register_fixed_rate(exynos5250_fixed_rate_clks,
ARRAY_SIZE(exynos5250_fixed_rate_clks));
samsung_clk_register_fixed_factor(exynos5250_fixed_factor_clks,
ARRAY_SIZE(exynos5250_fixed_factor_clks));
samsung_clk_register_mux(exynos5250_mux_clks,
ARRAY_SIZE(exynos5250_mux_clks));
samsung_clk_register_div(exynos5250_div_clks,
ARRAY_SIZE(exynos5250_div_clks));
samsung_clk_register_gate(exynos5250_gate_clks,
ARRAY_SIZE(exynos5250_gate_clks));
pr_info("Exynos5250: clock setup completed, armclk=%ld\n",
_get_rate("div_arm2"));
}
