static int exynos5250_clk_suspend(void)
{
samsung_clk_save(reg_base, exynos5250_save,
ARRAY_SIZE(exynos5250_clk_regs));
return 0;
}
static void exynos5250_clk_resume(void)
{
samsung_clk_restore(reg_base, exynos5250_save,
ARRAY_SIZE(exynos5250_clk_regs));
}
static void __init exynos5250_clk_sleep_init(void)
{
exynos5250_save = samsung_clk_alloc_reg_dump(exynos5250_clk_regs,
ARRAY_SIZE(exynos5250_clk_regs));
if (!exynos5250_save) {
pr_warn("%s: failed to allocate sleep save data, no sleep support!\n",
__func__);
return;
}
register_syscore_ops(&exynos5250_clk_syscore_ops);
}
static void __init exynos5250_clk_sleep_init(void) {}
static void __init exynos5250_clk_init(struct device_node *np)
{
struct samsung_clk_provider *ctx;
unsigned int tmp;
if (np) {
reg_base = of_iomap(np, 0);
if (!reg_base)
panic("%s: failed to map registers\n", __func__);
} else {
panic("%s: unable to determine soc\n", __func__);
}
ctx = samsung_clk_init(np, reg_base, CLK_NR_CLKS);
samsung_clk_of_register_fixed_ext(ctx, exynos5250_fixed_rate_ext_clks,
ARRAY_SIZE(exynos5250_fixed_rate_ext_clks),
ext_clk_match);
samsung_clk_register_mux(ctx, exynos5250_pll_pmux_clks,
ARRAY_SIZE(exynos5250_pll_pmux_clks));
if (_get_rate("fin_pll") == 24 * MHZ) {
exynos5250_plls[epll].rate_table = epll_24mhz_tbl;
exynos5250_plls[apll].rate_table = apll_24mhz_tbl;
}
if (_get_rate("mout_vpllsrc") == 24 * MHZ)
exynos5250_plls[vpll].rate_table = vpll_24mhz_tbl;
samsung_clk_register_pll(ctx, exynos5250_plls,
ARRAY_SIZE(exynos5250_plls),
reg_base);
samsung_clk_register_fixed_rate(ctx, exynos5250_fixed_rate_clks,
ARRAY_SIZE(exynos5250_fixed_rate_clks));
samsung_clk_register_fixed_factor(ctx, exynos5250_fixed_factor_clks,
ARRAY_SIZE(exynos5250_fixed_factor_clks));
samsung_clk_register_mux(ctx, exynos5250_mux_clks,
ARRAY_SIZE(exynos5250_mux_clks));
samsung_clk_register_div(ctx, exynos5250_div_clks,
ARRAY_SIZE(exynos5250_div_clks));
samsung_clk_register_gate(ctx, exynos5250_gate_clks,
ARRAY_SIZE(exynos5250_gate_clks));
exynos_register_cpu_clock(ctx, CLK_ARM_CLK, "armclk",
mout_cpu_p[0], mout_cpu_p[1], 0x200,
exynos5250_armclk_d, ARRAY_SIZE(exynos5250_armclk_d),
CLK_CPU_HAS_DIV1);
tmp = (PWR_CTRL1_CORE2_DOWN_RATIO | PWR_CTRL1_CORE1_DOWN_RATIO |
PWR_CTRL1_DIV2_DOWN_EN | PWR_CTRL1_DIV1_DOWN_EN |
PWR_CTRL1_USE_CORE1_WFE | PWR_CTRL1_USE_CORE0_WFE |
PWR_CTRL1_USE_CORE1_WFI | PWR_CTRL1_USE_CORE0_WFI);
__raw_writel(tmp, reg_base + PWR_CTRL1);
tmp = (PWR_CTRL2_DIV2_UP_EN | PWR_CTRL2_DIV1_UP_EN |
PWR_CTRL2_DUR_STANDBY2_VAL | PWR_CTRL2_DUR_STANDBY1_VAL |
PWR_CTRL2_CORE2_UP_RATIO | PWR_CTRL2_CORE1_UP_RATIO);
__raw_writel(tmp, reg_base + PWR_CTRL2);
exynos5250_clk_sleep_init();
samsung_clk_of_add_provider(np, ctx);
pr_info("Exynos5250: clock setup completed, armclk=%ld\n",
_get_rate("div_arm2"));
}
