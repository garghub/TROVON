static int dcscb_power_up(unsigned int cpu, unsigned int cluster)
{
unsigned int rst_hold, cpumask = (1 << cpu);
unsigned int all_mask = dcscb_allcpus_mask[cluster];
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (cpu >= 4 || cluster >= 2)
return -EINVAL;
local_irq_disable();
arch_spin_lock(&dcscb_lock);
dcscb_use_count[cpu][cluster]++;
if (dcscb_use_count[cpu][cluster] == 1) {
rst_hold = readl_relaxed(dcscb_base + RST_HOLD0 + cluster * 4);
if (rst_hold & (1 << 8)) {
rst_hold &= ~(1 << 8);
rst_hold |= all_mask;
}
rst_hold &= ~(cpumask | (cpumask << 4));
writel_relaxed(rst_hold, dcscb_base + RST_HOLD0 + cluster * 4);
} else if (dcscb_use_count[cpu][cluster] != 2) {
BUG();
}
arch_spin_unlock(&dcscb_lock);
local_irq_enable();
return 0;
}
static void dcscb_power_down(void)
{
unsigned int mpidr, cpu, cluster, rst_hold, cpumask, all_mask;
bool last_man = false, skip_wfi = false;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
cpumask = (1 << cpu);
all_mask = dcscb_allcpus_mask[cluster];
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cpu >= 4 || cluster >= 2);
__mcpm_cpu_going_down(cpu, cluster);
arch_spin_lock(&dcscb_lock);
BUG_ON(__mcpm_cluster_state(cluster) != CLUSTER_UP);
dcscb_use_count[cpu][cluster]--;
if (dcscb_use_count[cpu][cluster] == 0) {
rst_hold = readl_relaxed(dcscb_base + RST_HOLD0 + cluster * 4);
rst_hold |= cpumask;
if (((rst_hold | (rst_hold >> 4)) & all_mask) == all_mask) {
rst_hold |= (1 << 8);
last_man = true;
}
writel_relaxed(rst_hold, dcscb_base + RST_HOLD0 + cluster * 4);
} else if (dcscb_use_count[cpu][cluster] == 1) {
skip_wfi = true;
} else
BUG();
if (last_man && __mcpm_outbound_enter_critical(cpu, cluster)) {
arch_spin_unlock(&dcscb_lock);
flush_cache_all();
set_cr(get_cr() & ~CR_C);
flush_cache_all();
outer_flush_all();
set_auxcr(get_auxcr() & ~(1 << 6));
cci_disable_port_by_cpu(mpidr);
__mcpm_outbound_leave_critical(cluster, CLUSTER_DOWN);
} else {
arch_spin_unlock(&dcscb_lock);
flush_cache_louis();
set_cr(get_cr() & ~CR_C);
flush_cache_louis();
set_auxcr(get_auxcr() & ~(1 << 6));
}
__mcpm_cpu_down(cpu, cluster);
dsb();
if (!skip_wfi)
wfi();
}
static void __init dcscb_usage_count_init(void)
{
unsigned int mpidr, cpu, cluster;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cpu >= 4 || cluster >= 2);
dcscb_use_count[cpu][cluster] = 1;
}
static int __init dcscb_init(void)
{
struct device_node *node;
unsigned int cfg;
int ret;
if (!cci_probed())
return -ENODEV;
node = of_find_compatible_node(NULL, NULL, "arm,rtsm,dcscb");
if (!node)
return -ENODEV;
dcscb_base = of_iomap(node, 0);
if (!dcscb_base)
return -EADDRNOTAVAIL;
cfg = readl_relaxed(dcscb_base + DCS_CFG_R);
dcscb_allcpus_mask[0] = (1 << (((cfg >> 16) >> (0 << 2)) & 0xf)) - 1;
dcscb_allcpus_mask[1] = (1 << (((cfg >> 16) >> (1 << 2)) & 0xf)) - 1;
dcscb_usage_count_init();
ret = mcpm_platform_register(&dcscb_power_ops);
if (!ret)
ret = mcpm_sync_init(dcscb_power_up_setup);
if (ret) {
iounmap(dcscb_base);
return ret;
}
pr_info("VExpress DCSCB support installed\n");
vexpress_flags_set(virt_to_phys(mcpm_entry_point));
return 0;
}
