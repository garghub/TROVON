static int s3c64xx_clk_suspend(void)
{
samsung_clk_save(reg_base, s3c64xx_save_common,
ARRAY_SIZE(s3c64xx_clk_regs));
if (!is_s3c6400)
samsung_clk_save(reg_base, s3c64xx_save_soc,
ARRAY_SIZE(s3c6410_clk_regs));
return 0;
}
static void s3c64xx_clk_resume(void)
{
samsung_clk_restore(reg_base, s3c64xx_save_common,
ARRAY_SIZE(s3c64xx_clk_regs));
if (!is_s3c6400)
samsung_clk_restore(reg_base, s3c64xx_save_soc,
ARRAY_SIZE(s3c6410_clk_regs));
}
static void s3c64xx_clk_sleep_init(void)
{
s3c64xx_save_common = samsung_clk_alloc_reg_dump(s3c64xx_clk_regs,
ARRAY_SIZE(s3c64xx_clk_regs));
if (!s3c64xx_save_common)
goto err_warn;
if (!is_s3c6400) {
s3c64xx_save_soc = samsung_clk_alloc_reg_dump(s3c6410_clk_regs,
ARRAY_SIZE(s3c6410_clk_regs));
if (!s3c64xx_save_soc)
goto err_soc;
}
register_syscore_ops(&s3c64xx_clk_syscore_ops);
return;
err_soc:
kfree(s3c64xx_save_common);
err_warn:
pr_warn("%s: failed to allocate sleep save data, no sleep support!\n",
__func__);
}
static void s3c64xx_clk_sleep_init(void) {}
static void __init s3c64xx_clk_register_fixed_ext(unsigned long fin_pll_f,
unsigned long xusbxti_f)
{
s3c64xx_fixed_rate_ext_clks[0].fixed_rate = fin_pll_f;
s3c64xx_fixed_rate_ext_clks[1].fixed_rate = xusbxti_f;
samsung_clk_register_fixed_rate(s3c64xx_fixed_rate_ext_clks,
ARRAY_SIZE(s3c64xx_fixed_rate_ext_clks));
}
void __init s3c64xx_clk_init(struct device_node *np, unsigned long xtal_f,
unsigned long xusbxti_f, bool s3c6400,
void __iomem *base)
{
reg_base = base;
is_s3c6400 = s3c6400;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
}
samsung_clk_init(np, reg_base, NR_CLKS);
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
s3c64xx_clk_sleep_init();
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
