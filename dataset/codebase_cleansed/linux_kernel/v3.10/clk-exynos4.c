static unsigned long exynos4_get_xom(void)
{
unsigned long xom = 0;
void __iomem *chipid_base;
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "samsung,exynos4210-chipid");
if (np) {
chipid_base = of_iomap(np, 0);
if (chipid_base)
xom = readl(chipid_base + 8);
iounmap(chipid_base);
}
return xom;
}
static void __init exynos4_clk_register_finpll(unsigned long xom)
{
struct samsung_fixed_rate_clock fclk;
struct clk *clk;
unsigned long finpll_f = 24000000;
char *parent_name;
parent_name = xom & 1 ? "xusbxti" : "xxti";
clk = clk_get(NULL, parent_name);
if (IS_ERR(clk)) {
pr_err("%s: failed to lookup parent clock %s, assuming "
"fin_pll clock frequency is 24MHz\n", __func__,
parent_name);
} else {
finpll_f = clk_get_rate(clk);
}
fclk.id = fin_pll;
fclk.name = "fin_pll";
fclk.parent_name = NULL;
fclk.flags = CLK_IS_ROOT;
fclk.fixed_rate = finpll_f;
samsung_clk_register_fixed_rate(&fclk, 1);
}
void __init exynos4_clk_register_fixed_ext(unsigned long xxti_f,
unsigned long xusbxti_f)
{
exynos4_fixed_rate_ext_clks[0].fixed_rate = xxti_f;
exynos4_fixed_rate_ext_clks[1].fixed_rate = xusbxti_f;
samsung_clk_register_fixed_rate(exynos4_fixed_rate_ext_clks,
ARRAY_SIZE(exynos4_fixed_rate_ext_clks));
}
void __init exynos4_clk_init(struct device_node *np, enum exynos4_soc exynos4_soc, void __iomem *reg_base, unsigned long xom)
{
struct clk *apll, *mpll, *epll, *vpll;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
}
if (exynos4_soc == EXYNOS4210)
samsung_clk_init(np, reg_base, nr_clks,
exynos4_clk_regs, ARRAY_SIZE(exynos4_clk_regs),
exynos4210_clk_save, ARRAY_SIZE(exynos4210_clk_save));
else
samsung_clk_init(np, reg_base, nr_clks,
exynos4_clk_regs, ARRAY_SIZE(exynos4_clk_regs),
exynos4x12_clk_save, ARRAY_SIZE(exynos4x12_clk_save));
if (np)
samsung_clk_of_register_fixed_ext(exynos4_fixed_rate_ext_clks,
ARRAY_SIZE(exynos4_fixed_rate_ext_clks),
ext_clk_match);
exynos4_clk_register_finpll(xom);
if (exynos4_soc == EXYNOS4210) {
apll = samsung_clk_register_pll45xx("fout_apll", "fin_pll",
reg_base + APLL_CON0, pll_4508);
mpll = samsung_clk_register_pll45xx("fout_mpll", "fin_pll",
reg_base + E4210_MPLL_CON0, pll_4508);
epll = samsung_clk_register_pll46xx("fout_epll", "fin_pll",
reg_base + EPLL_CON0, pll_4600);
vpll = samsung_clk_register_pll46xx("fout_vpll", "mout_vpllsrc",
reg_base + VPLL_CON0, pll_4650c);
} else {
apll = samsung_clk_register_pll35xx("fout_apll", "fin_pll",
reg_base + APLL_CON0);
mpll = samsung_clk_register_pll35xx("fout_mpll", "fin_pll",
reg_base + E4X12_MPLL_CON0);
epll = samsung_clk_register_pll36xx("fout_epll", "fin_pll",
reg_base + EPLL_CON0);
vpll = samsung_clk_register_pll36xx("fout_vpll", "fin_pll",
reg_base + VPLL_CON0);
}
samsung_clk_add_lookup(apll, fout_apll);
samsung_clk_add_lookup(mpll, fout_mpll);
samsung_clk_add_lookup(epll, fout_epll);
samsung_clk_add_lookup(vpll, fout_vpll);
samsung_clk_register_fixed_rate(exynos4_fixed_rate_clks,
ARRAY_SIZE(exynos4_fixed_rate_clks));
samsung_clk_register_mux(exynos4_mux_clks,
ARRAY_SIZE(exynos4_mux_clks));
samsung_clk_register_div(exynos4_div_clks,
ARRAY_SIZE(exynos4_div_clks));
samsung_clk_register_gate(exynos4_gate_clks,
ARRAY_SIZE(exynos4_gate_clks));
if (exynos4_soc == EXYNOS4210) {
samsung_clk_register_fixed_rate(exynos4210_fixed_rate_clks,
ARRAY_SIZE(exynos4210_fixed_rate_clks));
samsung_clk_register_mux(exynos4210_mux_clks,
ARRAY_SIZE(exynos4210_mux_clks));
samsung_clk_register_div(exynos4210_div_clks,
ARRAY_SIZE(exynos4210_div_clks));
samsung_clk_register_gate(exynos4210_gate_clks,
ARRAY_SIZE(exynos4210_gate_clks));
} else {
samsung_clk_register_mux(exynos4x12_mux_clks,
ARRAY_SIZE(exynos4x12_mux_clks));
samsung_clk_register_div(exynos4x12_div_clks,
ARRAY_SIZE(exynos4x12_div_clks));
samsung_clk_register_gate(exynos4x12_gate_clks,
ARRAY_SIZE(exynos4x12_gate_clks));
}
pr_info("%s clocks: sclk_apll = %ld, sclk_mpll = %ld\n"
"\tsclk_epll = %ld, sclk_vpll = %ld, arm_clk = %ld\n",
exynos4_soc == EXYNOS4210 ? "Exynos4210" : "Exynos4x12",
_get_rate("sclk_apll"), _get_rate("sclk_mpll"),
_get_rate("sclk_epll"), _get_rate("sclk_vpll"),
_get_rate("arm_clk"));
}
static void __init exynos4210_clk_init(struct device_node *np)
{
exynos4_clk_init(np, EXYNOS4210, NULL, exynos4_get_xom());
}
static void __init exynos4412_clk_init(struct device_node *np)
{
exynos4_clk_init(np, EXYNOS4X12, NULL, exynos4_get_xom());
}
