static void exynos5420_powerdown_conf(enum sys_powerdown mode)
{
u32 this_cluster;
this_cluster = MPIDR_AFFINITY_LEVEL(read_cpuid_mpidr(), 1);
pmu_raw_writel(this_cluster, EXYNOS_IROM_DATA2);
}
static void exynos5420_pmu_init(void)
{
unsigned int value;
int i;
for (i = 0; i < ARRAY_SIZE(exynos5420_list_disable_pmu_reg); i++)
pmu_raw_writel(0, exynos5420_list_disable_pmu_reg[i]);
pmu_raw_writel(EXYNOS5420_USE_STANDBY_WFI_ALL, S5P_CENTRAL_SEQ_OPTION);
value = pmu_raw_readl(EXYNOS_L2_OPTION(0));
value &= ~EXYNOS_L2_USE_RETENTION;
pmu_raw_writel(value, EXYNOS_L2_OPTION(0));
value = pmu_raw_readl(EXYNOS_L2_OPTION(1));
value &= ~EXYNOS_L2_USE_RETENTION;
pmu_raw_writel(value, EXYNOS_L2_OPTION(1));
value = pmu_raw_readl(EXYNOS5420_LPI_MASK);
value |= EXYNOS5420_ATB_ISP_ARM;
pmu_raw_writel(value, EXYNOS5420_LPI_MASK);
value = pmu_raw_readl(EXYNOS5420_LPI_MASK1);
value |= EXYNOS5420_ATB_KFC;
pmu_raw_writel(value, EXYNOS5420_LPI_MASK1);
value = pmu_raw_readl(EXYNOS5420_ARM_COMMON_OPTION);
value |= EXYNOS5_SKIP_DEACTIVATE_ACEACP_IN_PWDN;
pmu_raw_writel(value, EXYNOS5420_ARM_COMMON_OPTION);
value = pmu_raw_readl(EXYNOS5420_KFC_COMMON_OPTION);
value |= EXYNOS5_SKIP_DEACTIVATE_ACEACP_IN_PWDN;
pmu_raw_writel(value, EXYNOS5420_KFC_COMMON_OPTION);
pmu_raw_writel(DUR_WAIT_RESET, EXYNOS5420_LOGIC_RESET_DURATION3);
pmu_raw_writel(SPREAD_ENABLE, EXYNOS5420_ARM_INTR_SPREAD_ENABLE);
pmu_raw_writel(SPREAD_USE_STANDWFI,
EXYNOS5420_ARM_INTR_SPREAD_USE_STANDBYWFI);
pmu_raw_writel(0x1, EXYNOS5420_UP_SCHEDULER);
pr_info("EXYNOS5420 PMU initialized\n");
}
