static int exynos4415_clk_suspend(void)
{
samsung_clk_save(exynos4415_ctx->reg_base, exynos4415_clk_regs,
ARRAY_SIZE(exynos4415_cmu_clk_regs));
return 0;
}
static void exynos4415_clk_resume(void)
{
samsung_clk_restore(exynos4415_ctx->reg_base, exynos4415_clk_regs,
ARRAY_SIZE(exynos4415_cmu_clk_regs));
}
static void exynos4415_clk_sleep_init(void)
{
exynos4415_clk_regs =
samsung_clk_alloc_reg_dump(exynos4415_cmu_clk_regs,
ARRAY_SIZE(exynos4415_cmu_clk_regs));
if (!exynos4415_clk_regs) {
pr_warn("%s: Failed to allocate sleep save data\n", __func__);
return;
}
register_syscore_ops(&exynos4415_clk_syscore_ops);
}
static inline void exynos4415_clk_sleep_init(void) { }
static void __init exynos4415_cmu_init(struct device_node *np)
{
void __iomem *reg_base;
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
exynos4415_ctx = samsung_clk_init(np, reg_base, CLK_NR_CLKS);
if (!exynos4415_ctx)
panic("%s: unable to allocate context.\n", __func__);
exynos4415_plls[apll].rate_table = exynos4415_pll_rates;
exynos4415_plls[epll].rate_table = exynos4415_epll_rates;
exynos4415_plls[g3d_pll].rate_table = exynos4415_pll_rates;
exynos4415_plls[isp_pll].rate_table = exynos4415_pll_rates;
exynos4415_plls[disp_pll].rate_table = exynos4415_pll_rates;
samsung_clk_register_fixed_factor(exynos4415_ctx,
exynos4415_fixed_factor_clks,
ARRAY_SIZE(exynos4415_fixed_factor_clks));
samsung_clk_register_fixed_rate(exynos4415_ctx,
exynos4415_fixed_rate_clks,
ARRAY_SIZE(exynos4415_fixed_rate_clks));
samsung_clk_register_pll(exynos4415_ctx, exynos4415_plls,
ARRAY_SIZE(exynos4415_plls), reg_base);
samsung_clk_register_mux(exynos4415_ctx, exynos4415_mux_clks,
ARRAY_SIZE(exynos4415_mux_clks));
samsung_clk_register_div(exynos4415_ctx, exynos4415_div_clks,
ARRAY_SIZE(exynos4415_div_clks));
samsung_clk_register_gate(exynos4415_ctx, exynos4415_gate_clks,
ARRAY_SIZE(exynos4415_gate_clks));
exynos4415_clk_sleep_init();
samsung_clk_of_add_provider(np, exynos4415_ctx);
}
static int exynos4415_dmc_clk_suspend(void)
{
samsung_clk_save(exynos4415_dmc_ctx->reg_base,
exynos4415_dmc_clk_regs,
ARRAY_SIZE(exynos4415_cmu_dmc_clk_regs));
return 0;
}
static void exynos4415_dmc_clk_resume(void)
{
samsung_clk_restore(exynos4415_dmc_ctx->reg_base,
exynos4415_dmc_clk_regs,
ARRAY_SIZE(exynos4415_cmu_dmc_clk_regs));
}
static void exynos4415_dmc_clk_sleep_init(void)
{
exynos4415_dmc_clk_regs =
samsung_clk_alloc_reg_dump(exynos4415_cmu_dmc_clk_regs,
ARRAY_SIZE(exynos4415_cmu_dmc_clk_regs));
if (!exynos4415_dmc_clk_regs) {
pr_warn("%s: Failed to allocate sleep save data\n", __func__);
return;
}
register_syscore_ops(&exynos4415_dmc_clk_syscore_ops);
}
static inline void exynos4415_dmc_clk_sleep_init(void) { }
static void __init exynos4415_cmu_dmc_init(struct device_node *np)
{
void __iomem *reg_base;
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
exynos4415_dmc_ctx = samsung_clk_init(np, reg_base, NR_CLKS_DMC);
if (!exynos4415_dmc_ctx)
panic("%s: unable to allocate context.\n", __func__);
exynos4415_dmc_plls[mpll].rate_table = exynos4415_pll_rates;
exynos4415_dmc_plls[bpll].rate_table = exynos4415_pll_rates;
samsung_clk_register_pll(exynos4415_dmc_ctx, exynos4415_dmc_plls,
ARRAY_SIZE(exynos4415_dmc_plls), reg_base);
samsung_clk_register_mux(exynos4415_dmc_ctx, exynos4415_dmc_mux_clks,
ARRAY_SIZE(exynos4415_dmc_mux_clks));
samsung_clk_register_div(exynos4415_dmc_ctx, exynos4415_dmc_div_clks,
ARRAY_SIZE(exynos4415_dmc_div_clks));
exynos4415_dmc_clk_sleep_init();
samsung_clk_of_add_provider(np, exynos4415_dmc_ctx);
}
