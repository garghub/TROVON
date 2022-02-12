static int exynos3250_clk_suspend(void)
{
samsung_clk_save(reg_base, exynos3250_clk_regs,
ARRAY_SIZE(exynos3250_cmu_clk_regs));
return 0;
}
static void exynos3250_clk_resume(void)
{
samsung_clk_restore(reg_base, exynos3250_clk_regs,
ARRAY_SIZE(exynos3250_cmu_clk_regs));
}
static void exynos3250_clk_sleep_init(void)
{
exynos3250_clk_regs =
samsung_clk_alloc_reg_dump(exynos3250_cmu_clk_regs,
ARRAY_SIZE(exynos3250_cmu_clk_regs));
if (!exynos3250_clk_regs) {
pr_warn("%s: Failed to allocate sleep save data\n", __func__);
goto err;
}
register_syscore_ops(&exynos3250_clk_syscore_ops);
return;
err:
kfree(exynos3250_clk_regs);
}
static inline void exynos3250_clk_sleep_init(void) { }
static void __init exynos3250_cmu_init(struct device_node *np)
{
struct samsung_clk_provider *ctx;
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
ctx = samsung_clk_init(np, reg_base, CLK_NR_CLKS);
if (!ctx)
panic("%s: unable to allocate context.\n", __func__);
samsung_clk_register_fixed_factor(ctx, fixed_factor_clks,
ARRAY_SIZE(fixed_factor_clks));
exynos3250_plls[apll].rate_table = exynos3250_pll_rates;
exynos3250_plls[mpll].rate_table = exynos3250_pll_rates;
exynos3250_plls[vpll].rate_table = exynos3250_vpll_rates;
exynos3250_plls[upll].rate_table = exynos3250_pll_rates;
samsung_clk_register_pll(ctx, exynos3250_plls,
ARRAY_SIZE(exynos3250_plls), reg_base);
samsung_clk_register_mux(ctx, mux_clks, ARRAY_SIZE(mux_clks));
samsung_clk_register_div(ctx, div_clks, ARRAY_SIZE(div_clks));
samsung_clk_register_gate(ctx, gate_clks, ARRAY_SIZE(gate_clks));
exynos3250_clk_sleep_init();
}
