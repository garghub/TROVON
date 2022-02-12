static int tc2_pm_power_up(unsigned int cpu, unsigned int cluster)
{
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (cluster >= TC2_CLUSTERS || cpu >= tc2_nr_cpus[cluster])
return -EINVAL;
local_irq_disable();
arch_spin_lock(&tc2_pm_lock);
if (tc2_cluster_unused(cluster))
ve_spc_powerdown(cluster, false);
tc2_pm_use_count[cpu][cluster]++;
if (tc2_pm_use_count[cpu][cluster] == 1) {
ve_spc_set_resume_addr(cluster, cpu,
virt_to_phys(mcpm_entry_point));
ve_spc_cpu_wakeup_irq(cluster, cpu, true);
} else if (tc2_pm_use_count[cpu][cluster] != 2) {
BUG();
}
arch_spin_unlock(&tc2_pm_lock);
local_irq_enable();
return 0;
}
static void tc2_pm_down(u64 residency)
{
unsigned int mpidr, cpu, cluster;
bool last_man = false, skip_wfi = false;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cluster >= TC2_CLUSTERS || cpu >= TC2_MAX_CPUS_PER_CLUSTER);
__mcpm_cpu_going_down(cpu, cluster);
arch_spin_lock(&tc2_pm_lock);
BUG_ON(__mcpm_cluster_state(cluster) != CLUSTER_UP);
tc2_pm_use_count[cpu][cluster]--;
if (tc2_pm_use_count[cpu][cluster] == 0) {
ve_spc_cpu_wakeup_irq(cluster, cpu, true);
if (tc2_cluster_unused(cluster)) {
ve_spc_powerdown(cluster, true);
ve_spc_global_wakeup_irq(true);
last_man = true;
}
} else if (tc2_pm_use_count[cpu][cluster] == 1) {
skip_wfi = true;
} else
BUG();
if (!skip_wfi)
gic_cpu_if_down();
if (last_man && __mcpm_outbound_enter_critical(cpu, cluster)) {
arch_spin_unlock(&tc2_pm_lock);
if (read_cpuid_part() == ARM_CPU_PART_CORTEX_A15) {
asm volatile(
"mcr p15, 1, %0, c15, c0, 3 \n\t"
"isb \n\t"
"dsb "
: : "r" (0x400) );
}
v7_exit_coherency_flush(all);
cci_disable_port_by_cpu(mpidr);
__mcpm_outbound_leave_critical(cluster, CLUSTER_DOWN);
} else {
if (last_man) {
ve_spc_powerdown(cluster, false);
ve_spc_global_wakeup_irq(false);
}
arch_spin_unlock(&tc2_pm_lock);
v7_exit_coherency_flush(louis);
}
__mcpm_cpu_down(cpu, cluster);
if (!skip_wfi)
wfi();
}
static void tc2_pm_power_down(void)
{
tc2_pm_down(0);
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
if (ACCESS_ONCE(tc2_pm_use_count[cpu][cluster]) == 0) {
pr_debug("%s(cpu=%u, cluster=%u): RESET_CTRL = 0x%08X\n",
__func__, cpu, cluster,
readl_relaxed(scc + RESET_CTRL));
if (tc2_core_in_reset(cpu, cluster) ||
ve_spc_cpu_in_wfi(cpu, cluster))
return 0;
}
msleep(POLL_MSEC);
}
return -ETIMEDOUT;
}
static void tc2_pm_suspend(u64 residency)
{
unsigned int mpidr, cpu, cluster;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
ve_spc_set_resume_addr(cluster, cpu, virt_to_phys(mcpm_entry_point));
tc2_pm_down(residency);
}
static void tc2_pm_powered_up(void)
{
unsigned int mpidr, cpu, cluster;
unsigned long flags;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cluster >= TC2_CLUSTERS || cpu >= TC2_MAX_CPUS_PER_CLUSTER);
local_irq_save(flags);
arch_spin_lock(&tc2_pm_lock);
if (tc2_cluster_unused(cluster)) {
ve_spc_powerdown(cluster, false);
ve_spc_global_wakeup_irq(false);
}
if (!tc2_pm_use_count[cpu][cluster])
tc2_pm_use_count[cpu][cluster] = 1;
ve_spc_cpu_wakeup_irq(cluster, cpu, false);
ve_spc_set_resume_addr(cluster, cpu, 0);
arch_spin_unlock(&tc2_pm_lock);
local_irq_restore(flags);
}
static bool __init tc2_pm_usage_count_init(void)
{
unsigned int mpidr, cpu, cluster;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (cluster >= TC2_CLUSTERS || cpu >= tc2_nr_cpus[cluster]) {
pr_err("%s: boot CPU is out of bound!\n", __func__);
return false;
}
tc2_pm_use_count[cpu][cluster] = 1;
return true;
}
static void __naked tc2_pm_power_up_setup(unsigned int affinity_level)
{
asm volatile (" \n"
" cmp r0, #1 \n"
" bxne lr \n"
" b cci_enable_port_for_self ");
}
static void __init tc2_cache_off(void)
{
pr_info("TC2: disabling cache during MCPM loopback test\n");
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
static int __init tc2_pm_init(void)
{
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
if (!tc2_pm_usage_count_init())
return -EINVAL;
ret = mcpm_platform_register(&tc2_pm_power_ops);
if (!ret) {
mcpm_sync_init(tc2_pm_power_up_setup);
BUG_ON(mcpm_loopback(tc2_cache_off) != 0);
pr_info("TC2 power management initialized\n");
}
return ret;
}
