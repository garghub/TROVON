static int tc2_pm_cpu_powerup(unsigned int cpu, unsigned int cluster)
{
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (cluster >= TC2_CLUSTERS || cpu >= tc2_nr_cpus[cluster])
return -EINVAL;
ve_spc_set_resume_addr(cluster, cpu,
__pa_symbol(mcpm_entry_point));
ve_spc_cpu_wakeup_irq(cluster, cpu, true);
return 0;
}
static int tc2_pm_cluster_powerup(unsigned int cluster)
{
pr_debug("%s: cluster %u\n", __func__, cluster);
if (cluster >= TC2_CLUSTERS)
return -EINVAL;
ve_spc_powerdown(cluster, false);
return 0;
}
static void tc2_pm_cpu_powerdown_prepare(unsigned int cpu, unsigned int cluster)
{
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cluster >= TC2_CLUSTERS || cpu >= TC2_MAX_CPUS_PER_CLUSTER);
ve_spc_cpu_wakeup_irq(cluster, cpu, true);
gic_cpu_if_down(0);
}
static void tc2_pm_cluster_powerdown_prepare(unsigned int cluster)
{
pr_debug("%s: cluster %u\n", __func__, cluster);
BUG_ON(cluster >= TC2_CLUSTERS);
ve_spc_powerdown(cluster, true);
ve_spc_global_wakeup_irq(true);
}
static void tc2_pm_cpu_cache_disable(void)
{
v7_exit_coherency_flush(louis);
}
static void tc2_pm_cluster_cache_disable(void)
{
if (read_cpuid_part() == ARM_CPU_PART_CORTEX_A15) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3 \n\t"
"isb \n\t"
"dsb "
: : "r" (0x400) );
}
v7_exit_coherency_flush(all);
cci_disable_port_by_cpu(read_cpuid_mpidr());
}
static int tc2_core_in_reset(unsigned int cpu, unsigned int cluster)
{
u32 mask = cluster ?
RESET_A7_NCORERESET(cpu)
: RESET_A15_NCORERESET(cpu);
return !(readl_relaxed(scc + RESET_CTRL) & mask);
}
static int tc2_pm_wait_for_powerdown(unsigned int cpu, unsigned int cluster)
{
unsigned tries;
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cluster >= TC2_CLUSTERS || cpu >= TC2_MAX_CPUS_PER_CLUSTER);
for (tries = 0; tries < TIMEOUT_MSEC / POLL_MSEC; ++tries) {
pr_debug("%s(cpu=%u, cluster=%u): RESET_CTRL = 0x%08X\n",
__func__, cpu, cluster,
readl_relaxed(scc + RESET_CTRL));
if (tc2_core_in_reset(cpu, cluster) ||
ve_spc_cpu_in_wfi(cpu, cluster))
return 0;
msleep(POLL_MSEC);
}
return -ETIMEDOUT;
}
static void tc2_pm_cpu_suspend_prepare(unsigned int cpu, unsigned int cluster)
{
ve_spc_set_resume_addr(cluster, cpu, __pa_symbol(mcpm_entry_point));
}
static void tc2_pm_cpu_is_up(unsigned int cpu, unsigned int cluster)
{
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cluster >= TC2_CLUSTERS || cpu >= TC2_MAX_CPUS_PER_CLUSTER);
ve_spc_cpu_wakeup_irq(cluster, cpu, false);
ve_spc_set_resume_addr(cluster, cpu, 0);
}
static void tc2_pm_cluster_is_up(unsigned int cluster)
{
pr_debug("%s: cluster %u\n", __func__, cluster);
BUG_ON(cluster >= TC2_CLUSTERS);
ve_spc_powerdown(cluster, false);
ve_spc_global_wakeup_irq(false);
}
static void __naked tc2_pm_power_up_setup(unsigned int affinity_level)
{
asm volatile (" \n"
" cmp r0, #1 \n"
" bxne lr \n"
" b cci_enable_port_for_self ");
}
static int __init tc2_pm_init(void)
{
unsigned int mpidr, cpu, cluster;
int ret, irq;
u32 a15_cluster_id, a7_cluster_id, sys_info;
struct device_node *np;
np = of_find_compatible_node(NULL, NULL,
"arm,vexpress-scc,v2p-ca15_a7");
scc = of_iomap(np, 0);
if (!scc)
return -ENODEV;
a15_cluster_id = readl_relaxed(scc + A15_CONF) & 0xf;
a7_cluster_id = readl_relaxed(scc + A7_CONF) & 0xf;
if (a15_cluster_id >= TC2_CLUSTERS || a7_cluster_id >= TC2_CLUSTERS)
return -EINVAL;
sys_info = readl_relaxed(scc + SYS_INFO);
tc2_nr_cpus[a15_cluster_id] = (sys_info >> 16) & 0xf;
tc2_nr_cpus[a7_cluster_id] = (sys_info >> 20) & 0xf;
irq = irq_of_parse_and_map(np, 0);
ret = ve_spc_init(scc + SPC_BASE, a15_cluster_id, irq);
if (ret)
return ret;
if (!cci_probed())
return -ENODEV;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (cluster >= TC2_CLUSTERS || cpu >= tc2_nr_cpus[cluster]) {
pr_err("%s: boot CPU is out of bound!\n", __func__);
return -EINVAL;
}
ret = mcpm_platform_register(&tc2_pm_power_ops);
if (!ret) {
mcpm_sync_init(tc2_pm_power_up_setup);
BUG_ON(mcpm_loopback(tc2_pm_cluster_cache_disable) != 0);
pr_info("TC2 power management initialized\n");
}
return ret;
}
