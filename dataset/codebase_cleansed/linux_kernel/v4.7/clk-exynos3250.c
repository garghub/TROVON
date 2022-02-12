static void __init exynos3_core_down_clock(void __iomem *reg_base)
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
ctx = samsung_cmu_register_one(np, &cmu_info);
if (!ctx)
return;
exynos_register_cpu_clock(ctx, CLK_ARM_CLK, "armclk",
mout_core_p[0], mout_core_p[1], 0x14200,
e3250_armclk_d, ARRAY_SIZE(e3250_armclk_d),
CLK_CPU_HAS_DIV1);
exynos3_core_down_clock(ctx->reg_base);
}
static void __init exynos3250_cmu_dmc_init(struct device_node *np)
{
samsung_cmu_register_one(np, &dmc_cmu_info);
}
static int __init exynos3250_cmu_isp_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
samsung_cmu_register_one(np, &isp_cmu_info);
return 0;
}
static int __init exynos3250_cmu_platform_init(void)
{
return platform_driver_probe(&exynos3250_cmu_isp_driver,
exynos3250_cmu_isp_probe);
}
