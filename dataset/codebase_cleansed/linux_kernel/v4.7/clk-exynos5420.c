static int exynos5420_clk_suspend(void)
{
samsung_clk_save(reg_base, exynos5x_save,
ARRAY_SIZE(exynos5x_clk_regs));
if (exynos5x_soc == EXYNOS5800)
samsung_clk_save(reg_base, exynos5800_save,
ARRAY_SIZE(exynos5800_clk_regs));
samsung_clk_restore(reg_base, exynos5420_set_clksrc,
ARRAY_SIZE(exynos5420_set_clksrc));
return 0;
}
static void exynos5420_clk_resume(void)
{
samsung_clk_restore(reg_base, exynos5x_save,
ARRAY_SIZE(exynos5x_clk_regs));
if (exynos5x_soc == EXYNOS5800)
samsung_clk_restore(reg_base, exynos5800_save,
ARRAY_SIZE(exynos5800_clk_regs));
}
static void exynos5420_clk_sleep_init(void)
{
exynos5x_save = samsung_clk_alloc_reg_dump(exynos5x_clk_regs,
ARRAY_SIZE(exynos5x_clk_regs));
if (!exynos5x_save) {
pr_warn("%s: failed to allocate sleep save data, no sleep support!\n",
__func__);
return;
}
if (exynos5x_soc == EXYNOS5800) {
exynos5800_save =
samsung_clk_alloc_reg_dump(exynos5800_clk_regs,
ARRAY_SIZE(exynos5800_clk_regs));
if (!exynos5800_save)
goto err_soc;
}
register_syscore_ops(&exynos5420_clk_syscore_ops);
return;
err_soc:
kfree(exynos5x_save);
pr_warn("%s: failed to allocate sleep save data, no sleep support!\n",
__func__);
return;
}
static void exynos5420_clk_sleep_init(void) {}
static void __init exynos5x_clk_init(struct device_node *np,
enum exynos5x_soc soc)
{
struct samsung_clk_provider *ctx;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
} else {
panic("%s: unable to determine soc\n", __func__);
}
exynos5x_soc = soc;
ctx = samsung_clk_init(np, reg_base, CLK_NR_CLKS);
if (!ctx)
panic("%s: unable to allocate context.\n", __func__);
samsung_clk_of_register_fixed_ext(ctx, exynos5x_fixed_rate_ext_clks,
ARRAY_SIZE(exynos5x_fixed_rate_ext_clks),
ext_clk_match);
if (_get_rate("fin_pll") == 24 * MHZ) {
exynos5x_plls[apll].rate_table = exynos5420_pll2550x_24mhz_tbl;
exynos5x_plls[kpll].rate_table = exynos5420_pll2550x_24mhz_tbl;
}
samsung_clk_register_pll(ctx, exynos5x_plls, ARRAY_SIZE(exynos5x_plls),
reg_base);
samsung_clk_register_fixed_rate(ctx, exynos5x_fixed_rate_clks,
ARRAY_SIZE(exynos5x_fixed_rate_clks));
samsung_clk_register_fixed_factor(ctx, exynos5x_fixed_factor_clks,
ARRAY_SIZE(exynos5x_fixed_factor_clks));
samsung_clk_register_mux(ctx, exynos5x_mux_clks,
ARRAY_SIZE(exynos5x_mux_clks));
samsung_clk_register_div(ctx, exynos5x_div_clks,
ARRAY_SIZE(exynos5x_div_clks));
samsung_clk_register_gate(ctx, exynos5x_gate_clks,
ARRAY_SIZE(exynos5x_gate_clks));
if (soc == EXYNOS5420) {
samsung_clk_register_mux(ctx, exynos5420_mux_clks,
ARRAY_SIZE(exynos5420_mux_clks));
samsung_clk_register_div(ctx, exynos5420_div_clks,
ARRAY_SIZE(exynos5420_div_clks));
} else {
samsung_clk_register_fixed_factor(
ctx, exynos5800_fixed_factor_clks,
ARRAY_SIZE(exynos5800_fixed_factor_clks));
samsung_clk_register_mux(ctx, exynos5800_mux_clks,
ARRAY_SIZE(exynos5800_mux_clks));
samsung_clk_register_div(ctx, exynos5800_div_clks,
ARRAY_SIZE(exynos5800_div_clks));
samsung_clk_register_gate(ctx, exynos5800_gate_clks,
ARRAY_SIZE(exynos5800_gate_clks));
}
if (soc == EXYNOS5420) {
exynos_register_cpu_clock(ctx, CLK_ARM_CLK, "armclk",
mout_cpu_p[0], mout_cpu_p[1], 0x200,
exynos5420_eglclk_d, ARRAY_SIZE(exynos5420_eglclk_d), 0);
} else {
exynos_register_cpu_clock(ctx, CLK_ARM_CLK, "armclk",
mout_cpu_p[0], mout_cpu_p[1], 0x200,
exynos5800_eglclk_d, ARRAY_SIZE(exynos5800_eglclk_d), 0);
}
exynos_register_cpu_clock(ctx, CLK_KFC_CLK, "kfcclk",
mout_kfc_p[0], mout_kfc_p[1], 0x28200,
exynos5420_kfcclk_d, ARRAY_SIZE(exynos5420_kfcclk_d), 0);
exynos5420_clk_sleep_init();
samsung_clk_of_add_provider(np, ctx);
}
static void __init exynos5420_clk_init(struct device_node *np)
{
exynos5x_clk_init(np, EXYNOS5420);
}
static void __init exynos5800_clk_init(struct device_node *np)
{
exynos5x_clk_init(np, EXYNOS5800);
}
