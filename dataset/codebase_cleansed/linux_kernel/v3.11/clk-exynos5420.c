void __init exynos5420_clk_init(struct device_node *np)
{
void __iomem *reg_base;
struct clk *apll, *bpll, *cpll, *dpll, *epll, *ipll, *kpll, *mpll;
struct clk *rpll, *spll, *vpll;
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
apll = samsung_clk_register_pll35xx("fout_apll", "fin_pll",
reg_base + 0x100);
bpll = samsung_clk_register_pll35xx("fout_bpll", "fin_pll",
reg_base + 0x20110);
cpll = samsung_clk_register_pll35xx("fout_cpll", "fin_pll",
reg_base + 0x10120);
dpll = samsung_clk_register_pll35xx("fout_dpll", "fin_pll",
reg_base + 0x10128);
epll = samsung_clk_register_pll36xx("fout_epll", "fin_pll",
reg_base + 0x10130);
ipll = samsung_clk_register_pll35xx("fout_ipll", "fin_pll",
reg_base + 0x10150);
kpll = samsung_clk_register_pll35xx("fout_kpll", "fin_pll",
reg_base + 0x28100);
mpll = samsung_clk_register_pll35xx("fout_mpll", "fin_pll",
reg_base + 0x10180);
rpll = samsung_clk_register_pll36xx("fout_rpll", "fin_pll",
reg_base + 0x10140);
spll = samsung_clk_register_pll35xx("fout_spll", "fin_pll",
reg_base + 0x10160);
vpll = samsung_clk_register_pll35xx("fout_vpll", "fin_pll",
reg_base + 0x10170);
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
