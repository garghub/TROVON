static int exynos_power_up(unsigned int cpu, unsigned int cluster)
{
unsigned int cpunr = cpu + (cluster * EXYNOS5420_CPUS_PER_CLUSTER);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (cpu >= EXYNOS5420_CPUS_PER_CLUSTER ||
cluster >= EXYNOS5420_NR_CLUSTERS)
return -EINVAL;
local_irq_disable();
arch_spin_lock(&exynos_mcpm_lock);
cpu_use_count[cpu][cluster]++;
if (cpu_use_count[cpu][cluster] == 1) {
bool was_cluster_down =
(exynos_cluster_usecnt(cluster) == 1);
if (was_cluster_down)
exynos_cluster_power_up(cluster);
exynos_cpu_power_up(cpunr);
} else if (cpu_use_count[cpu][cluster] != 2) {
BUG();
}
arch_spin_unlock(&exynos_mcpm_lock);
local_irq_enable();
return 0;
}
static void exynos_power_down(void)
{
unsigned int mpidr, cpu, cluster;
bool last_man = false, skip_wfi = false;
unsigned int cpunr;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
cpunr = cpu + (cluster * EXYNOS5420_CPUS_PER_CLUSTER);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cpu >= EXYNOS5420_CPUS_PER_CLUSTER ||
cluster >= EXYNOS5420_NR_CLUSTERS);
__mcpm_cpu_going_down(cpu, cluster);
arch_spin_lock(&exynos_mcpm_lock);
BUG_ON(__mcpm_cluster_state(cluster) != CLUSTER_UP);
cpu_use_count[cpu][cluster]--;
if (cpu_use_count[cpu][cluster] == 0) {
exynos_cpu_power_down(cpunr);
if (exynos_cluster_unused(cluster)) {
exynos_cluster_power_down(cluster);
last_man = true;
}
} else if (cpu_use_count[cpu][cluster] == 1) {
skip_wfi = true;
} else {
BUG();
}
if (last_man && __mcpm_outbound_enter_critical(cpu, cluster)) {
arch_spin_unlock(&exynos_mcpm_lock);
if (read_cpuid_part() == ARM_CPU_PART_CORTEX_A15) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3\n\t"
"isb\n\t"
"dsb"
: : "r" (0x400));
}
exynos_v7_exit_coherency_flush(all);
cci_disable_port_by_cpu(mpidr);
__mcpm_outbound_leave_critical(cluster, CLUSTER_DOWN);
} else {
arch_spin_unlock(&exynos_mcpm_lock);
exynos_v7_exit_coherency_flush(louis);
}
__mcpm_cpu_down(cpu, cluster);
if (!skip_wfi)
wfi();
}
static int exynos_wait_for_powerdown(unsigned int cpu, unsigned int cluster)
{
unsigned int tries = 100;
unsigned int cpunr = cpu + (cluster * EXYNOS5420_CPUS_PER_CLUSTER);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cpu >= EXYNOS5420_CPUS_PER_CLUSTER ||
cluster >= EXYNOS5420_NR_CLUSTERS);
while (tries--) {
if (ACCESS_ONCE(cpu_use_count[cpu][cluster]) == 0) {
if ((exynos_cpu_power_state(cpunr) == 0))
return 0;
}
msleep(1);
}
return -ETIMEDOUT;
}
static void exynos_powered_up(void)
{
unsigned int mpidr, cpu, cluster;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
arch_spin_lock(&exynos_mcpm_lock);
if (cpu_use_count[cpu][cluster] == 0)
cpu_use_count[cpu][cluster] = 1;
arch_spin_unlock(&exynos_mcpm_lock);
}
static void exynos_suspend(u64 residency)
{
unsigned int mpidr, cpunr;
exynos_power_down();
mpidr = read_cpuid_mpidr();
cpunr = exynos_pmu_cpunr(mpidr);
exynos_cpu_power_up(cpunr);
}
static void __init exynos_mcpm_usage_count_init(void)
{
unsigned int mpidr, cpu, cluster;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cpu >= EXYNOS5420_CPUS_PER_CLUSTER ||
cluster >= EXYNOS5420_NR_CLUSTERS);
cpu_use_count[cpu][cluster] = 1;
}
static void __naked exynos_pm_power_up_setup(unsigned int affinity_level)
{
asm volatile ("\n"
"cmp r0, #1\n"
"bxne lr\n"
"b cci_enable_port_for_self");
}
static void __init exynos_cache_off(void)
{
if (read_cpuid_part() == ARM_CPU_PART_CORTEX_A15) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3\n\t"
"isb\n\t"
"dsb"
: : "r" (0x400));
}
exynos_v7_exit_coherency_flush(all);
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
exynos_mcpm_usage_count_init();
ret = mcpm_platform_register(&exynos_power_ops);
if (!ret)
ret = mcpm_sync_init(exynos_pm_power_up_setup);
if (!ret)
ret = mcpm_loopback(exynos_cache_off);
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
