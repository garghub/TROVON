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
static void __init exynos3_core_down_clock(void)
{
unsigned int tmp;
tmp = (PWR_CTRL1_CORE2_DOWN_RATIO(7) | PWR_CTRL1_CORE1_DOWN_RATIO(7) |
PWR_CTRL1_DIV2_DOWN_EN | PWR_CTRL1_DIV1_DOWN_EN |
PWR_CTRL1_USE_CORE1_WFE | PWR_CTRL1_USE_CORE0_WFE |
PWR_CTRL1_USE_CORE1_WFI | PWR_CTRL1_USE_CORE0_WFI);
__raw_writel(tmp, reg_base + PWR_CTRL1);
__raw_writel(0x0, reg_base + PWR_CTRL2);
}
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
exynos3_core_down_clock();
exynos3250_clk_sleep_init();
samsung_clk_of_add_provider(np, ctx);
}
static int exynos3250_dmc_clk_suspend(void)
{
samsung_clk_save(dmc_reg_base, exynos3250_dmc_clk_regs,
ARRAY_SIZE(exynos3250_cmu_dmc_clk_regs));
return 0;
}
static void exynos3250_dmc_clk_resume(void)
{
samsung_clk_restore(dmc_reg_base, exynos3250_dmc_clk_regs,
ARRAY_SIZE(exynos3250_cmu_dmc_clk_regs));
}
static void exynos3250_dmc_clk_sleep_init(void)
{
exynos3250_dmc_clk_regs =
samsung_clk_alloc_reg_dump(exynos3250_cmu_dmc_clk_regs,
ARRAY_SIZE(exynos3250_cmu_dmc_clk_regs));
if (!exynos3250_dmc_clk_regs) {
pr_warn("%s: Failed to allocate sleep save data\n", __func__);
goto err;
}
register_syscore_ops(&exynos3250_dmc_clk_syscore_ops);
return;
err:
kfree(exynos3250_dmc_clk_regs);
}
static inline void exynos3250_dmc_clk_sleep_init(void) { }
static void __init exynos3250_cmu_dmc_init(struct device_node *np)
{
struct samsung_clk_provider *ctx;
dmc_reg_base = of_iomap(np, 0);
if (!dmc_reg_base)
panic("%s: failed to map registers\n", __func__);
ctx = samsung_clk_init(np, dmc_reg_base, NR_CLKS_DMC);
if (!ctx)
panic("%s: unable to allocate context.\n", __func__);
exynos3250_dmc_plls[bpll].rate_table = exynos3250_pll_rates;
exynos3250_dmc_plls[epll].rate_table = exynos3250_epll_rates;
pr_err("CLK registering epll bpll: %d, %d, %d, %d\n",
exynos3250_dmc_plls[bpll].rate_table[0].rate,
exynos3250_dmc_plls[bpll].rate_table[0].mdiv,
exynos3250_dmc_plls[bpll].rate_table[0].pdiv,
exynos3250_dmc_plls[bpll].rate_table[0].sdiv
);
samsung_clk_register_pll(ctx, exynos3250_dmc_plls,
ARRAY_SIZE(exynos3250_dmc_plls), dmc_reg_base);
samsung_clk_register_mux(ctx, dmc_mux_clks, ARRAY_SIZE(dmc_mux_clks));
samsung_clk_register_div(ctx, dmc_div_clks, ARRAY_SIZE(dmc_div_clks));
exynos3250_dmc_clk_sleep_init();
samsung_clk_of_add_provider(np, ctx);
}
