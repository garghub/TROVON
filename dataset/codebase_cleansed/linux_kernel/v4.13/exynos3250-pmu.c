static void exynos3250_powerdown_conf_extra(enum sys_powerdown mode)
{
unsigned int i;
unsigned int tmp;
for (i = 0; i < ARRAY_SIZE(exynos3250_list_feed); i++) {
tmp = pmu_raw_readl(exynos3250_list_feed[i]);
tmp &= ~(EXYNOS3_OPTION_USE_SC_COUNTER);
tmp |= EXYNOS3_OPTION_USE_SC_FEEDBACK;
pmu_raw_writel(tmp, exynos3250_list_feed[i]);
}
if (mode != SYS_SLEEP)
return;
pmu_raw_writel(XUSBXTI_DURATION, EXYNOS3_XUSBXTI_DURATION);
pmu_raw_writel(XXTI_DURATION, EXYNOS3_XXTI_DURATION);
pmu_raw_writel(EXT_REGULATOR_DURATION, EXYNOS3_EXT_REGULATOR_DURATION);
pmu_raw_writel(EXT_REGULATOR_COREBLK_DURATION,
EXYNOS3_EXT_REGULATOR_COREBLK_DURATION);
}
static void exynos3250_pmu_init(void)
{
unsigned int value;
value = pmu_raw_readl(EXYNOS3_ARM_COMMON_OPTION);
value |= EXYNOS3_OPTION_SKIP_DEACTIVATE_ACEACP_IN_PWDN;
pmu_raw_writel(value, EXYNOS3_ARM_COMMON_OPTION);
pmu_raw_writel(S5P_USE_STANDBY_WFI_ALL, S5P_CENTRAL_SEQ_OPTION);
value = pmu_raw_readl(S5P_PS_HOLD_CONTROL);
value |= S5P_PS_HOLD_OUTPUT_HIGH;
pmu_raw_writel(value, S5P_PS_HOLD_CONTROL);
value = pmu_raw_readl(S5P_PS_HOLD_CONTROL);
value |= S5P_PS_HOLD_EN;
pmu_raw_writel(value, S5P_PS_HOLD_CONTROL);
}
