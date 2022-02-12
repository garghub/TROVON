static int dcscb_cpu_powerup(unsigned int cpu, unsigned int cluster)
{
unsigned int rst_hold, cpumask = (1 << cpu);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (cluster >= 2 || !(cpumask & dcscb_allcpus_mask[cluster]))
return -EINVAL;
rst_hold = readl_relaxed(dcscb_base + RST_HOLD0 + cluster * 4);
rst_hold &= ~(cpumask | (cpumask << 4));
writel_relaxed(rst_hold, dcscb_base + RST_HOLD0 + cluster * 4);
return 0;
}
static int dcscb_cluster_powerup(unsigned int cluster)
{
unsigned int rst_hold;
pr_debug("%s: cluster %u\n", __func__, cluster);
if (cluster >= 2)
return -EINVAL;
rst_hold = readl_relaxed(dcscb_base + RST_HOLD0 + cluster * 4);
rst_hold &= ~(1 << 8);
rst_hold |= dcscb_allcpus_mask[cluster];
writel_relaxed(rst_hold, dcscb_base + RST_HOLD0 + cluster * 4);
return 0;
}
static void dcscb_cpu_powerdown_prepare(unsigned int cpu, unsigned int cluster)
{
unsigned int rst_hold;
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
BUG_ON(cluster >= 2 || !((1 << cpu) & dcscb_allcpus_mask[cluster]));
rst_hold = readl_relaxed(dcscb_base + RST_HOLD0 + cluster * 4);
rst_hold |= (1 << cpu);
writel_relaxed(rst_hold, dcscb_base + RST_HOLD0 + cluster * 4);
}
static void dcscb_cluster_powerdown_prepare(unsigned int cluster)
{
unsigned int rst_hold;
pr_debug("%s: cluster %u\n", __func__, cluster);
BUG_ON(cluster >= 2);
rst_hold = readl_relaxed(dcscb_base + RST_HOLD0 + cluster * 4);
rst_hold |= (1 << 8);
writel_relaxed(rst_hold, dcscb_base + RST_HOLD0 + cluster * 4);
}
static void dcscb_cpu_cache_disable(void)
{
v7_exit_coherency_flush(louis);
}
static void dcscb_cluster_cache_disable(void)
{
v7_exit_coherency_flush(all);
cci_disable_port_by_cpu(read_cpuid_mpidr());
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
ret = mcpm_platform_register(&dcscb_power_ops);
if (!ret)
ret = mcpm_sync_init(dcscb_power_up_setup);
if (ret) {
iounmap(dcscb_base);
return ret;
}
pr_info("VExpress DCSCB support installed\n");
vexpress_flags_set(__pa_symbol(mcpm_entry_point));
return 0;
}
