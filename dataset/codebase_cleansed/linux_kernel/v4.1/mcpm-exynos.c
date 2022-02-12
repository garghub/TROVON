static int exynos_cpu_powerup(unsigned int cpu, unsigned int cluster)
{
unsigned int cpunr = cpu + (cluster * EXYNOS5420_CPUS_PER_CLUSTER);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (cpu >= EXYNOS5420_CPUS_PER_CLUSTER ||
cluster >= EXYNOS5420_NR_CLUSTERS)
return -EINVAL;
exynos_cpu_power_up(cpunr);
return 0;
}
static int exynos_cluster_powerup(unsigned int cluster)
{
pr_debug("%s: cluster %u\n", __func__, cluster);
if (cluster >= EXYNOS5420_NR_CLUSTERS)
return -EINVAL;
exynos_cluster_power_up(cluster);
return 0;
}
static void exynos_cpu_powerdown_prepare(unsigned int cpu, unsigned int cluster)
{
unsigned int cpunr = cpu + (cluster * EXYNOS5420_CPUS_PER_CLUSTER);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cpu >= EXYNOS5420_CPUS_PER_CLUSTER ||
cluster >= EXYNOS5420_NR_CLUSTERS);
exynos_cpu_power_down(cpunr);
}
static void exynos_cluster_powerdown_prepare(unsigned int cluster)
{
pr_debug("%s: cluster %u\n", __func__, cluster);
BUG_ON(cluster >= EXYNOS5420_NR_CLUSTERS);
exynos_cluster_power_down(cluster);
}
static void exynos_cpu_cache_disable(void)
{
exynos_v7_exit_coherency_flush(louis);
}
static void exynos_cluster_cache_disable(void)
{
if (read_cpuid_part() == ARM_CPU_PART_CORTEX_A15) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3\n\t"
"isb\n\t"
"dsb"
: : "r" (0x400));
}
exynos_v7_exit_coherency_flush(all);
cci_disable_port_by_cpu(read_cpuid_mpidr());
}
static int exynos_wait_for_powerdown(unsigned int cpu, unsigned int cluster)
{
unsigned int tries = 100;
unsigned int cpunr = cpu + (cluster * EXYNOS5420_CPUS_PER_CLUSTER);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cpu >= EXYNOS5420_CPUS_PER_CLUSTER ||
cluster >= EXYNOS5420_NR_CLUSTERS);
while (tries--) {
if ((exynos_cpu_power_state(cpunr) == 0))
return 0;
msleep(1);
}
return -ETIMEDOUT;
}
static void exynos_cpu_is_up(unsigned int cpu, unsigned int cluster)
{
exynos_cpu_powerup(cpu, cluster);
}
static void __naked exynos_pm_power_up_setup(unsigned int affinity_level)
{
asm volatile ("\n"
"cmp r0, #1\n"
"bxne lr\n"
"b cci_enable_port_for_self");
}
static void exynos_mcpm_setup_entry_point(void)
{
__raw_writel(0xe59f0000, ns_sram_base_addr);
__raw_writel(0xe12fff10, ns_sram_base_addr + 4);
__raw_writel(virt_to_phys(mcpm_entry_point), ns_sram_base_addr + 8);
}
static int __init exynos_mcpm_init(void)
{
struct device_node *node;
unsigned int value, i;
int ret;
node = of_find_matching_node(NULL, exynos_dt_mcpm_match);
if (!node)
return -ENODEV;
of_node_put(node);
if (!cci_probed())
return -ENODEV;
node = of_find_compatible_node(NULL, NULL,
"samsung,exynos4210-sysram-ns");
if (!node)
return -ENODEV;
ns_sram_base_addr = of_iomap(node, 0);
of_node_put(node);
if (!ns_sram_base_addr) {
pr_err("failed to map non-secure iRAM base address\n");
return -ENOMEM;
}
pmu_raw_writel(EXYNOS5420_SWRESET_KFC_SEL, S5P_PMU_SPARE3);
ret = mcpm_platform_register(&exynos_power_ops);
if (!ret)
ret = mcpm_sync_init(exynos_pm_power_up_setup);
if (!ret)
ret = mcpm_loopback(exynos_cluster_cache_disable);
if (ret) {
iounmap(ns_sram_base_addr);
return ret;
}
mcpm_smp_set_ops();
pr_info("Exynos MCPM support installed\n");
for (i = 0; i < EXYNOS5420_NR_CLUSTERS; i++) {
value = pmu_raw_readl(EXYNOS_COMMON_OPTION(i));
value |= EXYNOS5420_ENABLE_AUTOMATIC_CORE_DOWN |
EXYNOS5420_USE_ARM_CORE_DOWN_STATE |
EXYNOS5420_USE_L2_COMMON_UP_STATE;
pmu_raw_writel(value, EXYNOS_COMMON_OPTION(i));
}
exynos_mcpm_setup_entry_point();
register_syscore_ops(&exynos_mcpm_syscore_ops);
return ret;
}
