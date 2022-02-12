static void __init s3c64xx_clk_register_fixed_ext(unsigned long fin_pll_f,
unsigned long xusbxti_f)
{
s3c64xx_fixed_rate_ext_clks[0].fixed_rate = fin_pll_f;
s3c64xx_fixed_rate_ext_clks[1].fixed_rate = xusbxti_f;
samsung_clk_register_fixed_rate(s3c64xx_fixed_rate_ext_clks,
ARRAY_SIZE(s3c64xx_fixed_rate_ext_clks));
}
void __init s3c64xx_clk_init(struct device_node *np, unsigned long xtal_f,
unsigned long xusbxti_f, bool is_s3c6400,
void __iomem *reg_base)
{
unsigned long *soc_regs = NULL;
unsigned long nr_soc_regs = 0;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
}
if (!is_s3c6400) {
soc_regs = s3c6410_clk_regs;
nr_soc_regs = ARRAY_SIZE(s3c6410_clk_regs);
}
samsung_clk_init(np, reg_base, NR_CLKS, s3c64xx_clk_regs,
ARRAY_SIZE(s3c64xx_clk_regs), soc_regs, nr_soc_regs);
if (!np)
s3c64xx_clk_register_fixed_ext(xtal_f, xusbxti_f);
samsung_clk_register_pll(s3c64xx_pll_clks,
ARRAY_SIZE(s3c64xx_pll_clks), reg_base);
samsung_clk_register_fixed_rate(s3c64xx_fixed_rate_clks,
ARRAY_SIZE(s3c64xx_fixed_rate_clks));
samsung_clk_register_mux(s3c64xx_mux_clks,
ARRAY_SIZE(s3c64xx_mux_clks));
samsung_clk_register_div(s3c64xx_div_clks,
ARRAY_SIZE(s3c64xx_div_clks));
samsung_clk_register_gate(s3c64xx_gate_clks,
ARRAY_SIZE(s3c64xx_gate_clks));
if (is_s3c6400) {
samsung_clk_register_mux(s3c6400_mux_clks,
ARRAY_SIZE(s3c6400_mux_clks));
samsung_clk_register_div(s3c6400_div_clks,
ARRAY_SIZE(s3c6400_div_clks));
samsung_clk_register_gate(s3c6400_gate_clks,
ARRAY_SIZE(s3c6400_gate_clks));
samsung_clk_register_alias(s3c6400_clock_aliases,
ARRAY_SIZE(s3c6400_clock_aliases));
} else {
samsung_clk_register_mux(s3c6410_mux_clks,
ARRAY_SIZE(s3c6410_mux_clks));
samsung_clk_register_div(s3c6410_div_clks,
ARRAY_SIZE(s3c6410_div_clks));
samsung_clk_register_gate(s3c6410_gate_clks,
ARRAY_SIZE(s3c6410_gate_clks));
samsung_clk_register_alias(s3c6410_clock_aliases,
ARRAY_SIZE(s3c6410_clock_aliases));
}
samsung_clk_register_alias(s3c64xx_clock_aliases,
ARRAY_SIZE(s3c64xx_clock_aliases));
pr_info("%s clocks: apll = %lu, mpll = %lu\n"
"\tepll = %lu, arm_clk = %lu\n",
is_s3c6400 ? "S3C6400" : "S3C6410",
_get_rate("fout_apll"), _get_rate("fout_mpll"),
_get_rate("fout_epll"), _get_rate("armclk"));
}
static void __init s3c6400_clk_init(struct device_node *np)
{
s3c64xx_clk_init(np, 0, 0, true, NULL);
}
static void __init s3c6410_clk_init(struct device_node *np)
{
s3c64xx_clk_init(np, 0, 0, false, NULL);
}
