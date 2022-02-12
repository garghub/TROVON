static void exynos5250_pmu_init(void)
{
unsigned int value;
value = pmu_raw_readl(EXYNOS5_AUTO_WDTRESET_DISABLE);
value &= ~EXYNOS5_SYS_WDTRESET;
pmu_raw_writel(value, EXYNOS5_AUTO_WDTRESET_DISABLE);
value = pmu_raw_readl(EXYNOS5_MASK_WDTRESET_REQUEST);
value &= ~EXYNOS5_SYS_WDTRESET;
pmu_raw_writel(value, EXYNOS5_MASK_WDTRESET_REQUEST);
}
static void exynos5_powerdown_conf(enum sys_powerdown mode)
{
unsigned int i;
unsigned int tmp;
for (i = 0; i < ARRAY_SIZE(exynos5_list_both_cnt_feed); i++) {
tmp = pmu_raw_readl(exynos5_list_both_cnt_feed[i]);
tmp |= (EXYNOS5_USE_SC_FEEDBACK |
EXYNOS5_USE_SC_COUNTER);
pmu_raw_writel(tmp, exynos5_list_both_cnt_feed[i]);
}
tmp = pmu_raw_readl(EXYNOS5_ARM_COMMON_OPTION);
tmp |= EXYNOS5_SKIP_DEACTIVATE_ACEACP_IN_PWDN;
pmu_raw_writel(tmp, EXYNOS5_ARM_COMMON_OPTION);
for (i = 0; i < ARRAY_SIZE(exynos5_list_disable_wfi_wfe); i++) {
tmp = pmu_raw_readl(exynos5_list_disable_wfi_wfe[i]);
tmp &= ~(EXYNOS5_OPTION_USE_STANDBYWFE |
EXYNOS5_OPTION_USE_STANDBYWFI);
pmu_raw_writel(tmp, exynos5_list_disable_wfi_wfe[i]);
}
}
