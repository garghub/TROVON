static int __init smp_spin_table_init_cpu(struct device_node *dn, int cpu)
{
if (of_property_read_u64(dn, "cpu-release-addr",
&cpu_release_addr[cpu])) {
pr_err("CPU %d: missing or invalid cpu-release-addr property\n",
cpu);
return -1;
}
return 0;
}
static int __init smp_spin_table_prepare_cpu(int cpu)
{
void **release_addr;
if (!cpu_release_addr[cpu])
return -ENODEV;
release_addr = __va(cpu_release_addr[cpu]);
release_addr[0] = (void *)__pa(secondary_holding_pen);
__flush_dcache_area(release_addr, sizeof(release_addr[0]));
sev();
return 0;
}
