static void write_pen_release(u64 val)
{
void *start = (void *)&secondary_holding_pen_release;
unsigned long size = sizeof(secondary_holding_pen_release);
secondary_holding_pen_release = val;
__flush_dcache_area(start, size);
}
static int smp_spin_table_cpu_init(struct device_node *dn, unsigned int cpu)
{
if (of_property_read_u64(dn, "cpu-release-addr",
&cpu_release_addr[cpu])) {
pr_err("CPU %d: missing or invalid cpu-release-addr property\n",
cpu);
return -1;
}
return 0;
}
static int smp_spin_table_cpu_prepare(unsigned int cpu)
{
void **release_addr;
if (!cpu_release_addr[cpu])
return -ENODEV;
release_addr = __va(cpu_release_addr[cpu]);
release_addr[0] = (void *) cpu_to_le64(__pa(secondary_holding_pen));
__flush_dcache_area(release_addr, sizeof(release_addr[0]));
sev();
return 0;
}
static int smp_spin_table_cpu_boot(unsigned int cpu)
{
write_pen_release(cpu_logical_map(cpu));
sev();
return 0;
}
