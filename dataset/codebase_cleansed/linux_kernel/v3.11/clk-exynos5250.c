void __init exynos5250_clk_init(struct device_node *np)
{
void __iomem *reg_base;
struct clk *apll, *mpll, *epll, *vpll, *bpll, *gpll, *cpll;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
} else {
panic("%s: unable to determine soc\n", __func__);
}
samsung_clk_init(np, reg_base, nr_clks,
exynos5250_clk_regs, ARRAY_SIZE(exynos5250_clk_regs),
NULL, 0);
samsung_clk_of_register_fixed_ext(exynos5250_fixed_rate_ext_clks,
ARRAY_SIZE(exynos5250_fixed_rate_ext_clks),
ext_clk_match);
apll = samsung_clk_register_pll35xx("fout_apll", "fin_pll",
reg_base + 0x100);
mpll = samsung_clk_register_pll35xx("fout_mpll", "fin_pll",
reg_base + 0x4100);
bpll = samsung_clk_register_pll35xx("fout_bpll", "fin_pll",
reg_base + 0x20110);
gpll = samsung_clk_register_pll35xx("fout_gpll", "fin_pll",
reg_base + 0x10150);
cpll = samsung_clk_register_pll35xx("fout_cpll", "fin_pll",
reg_base + 0x10120);
epll = samsung_clk_register_pll36xx("fout_epll", "fin_pll",
reg_base + 0x10130);
vpll = samsung_clk_register_pll36xx("fout_vpll", "mout_vpllsrc",
reg_base + 0x10140);
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
_get_rate("armclk"));
}
