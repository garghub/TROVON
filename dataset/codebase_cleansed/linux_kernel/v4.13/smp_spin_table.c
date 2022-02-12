static void write_pen_release(u64 val)
{
void *start = (void *)&secondary_holding_pen_release;
unsigned long size = sizeof(secondary_holding_pen_release);
secondary_holding_pen_release = val;
__flush_dcache_area(start, size);
}
static int smp_spin_table_cpu_init(unsigned int cpu)
{
struct device_node *dn;
int ret;
dn = of_get_cpu_node(cpu, NULL);
if (!dn)
return -ENODEV;
ret = of_property_read_u64(dn, "cpu-release-addr",
&cpu_release_addr[cpu]);
if (ret)
pr_err("CPU %d: missing or invalid cpu-release-addr property\n",
cpu);
of_node_put(dn);
return ret;
}
static int smp_spin_table_cpu_prepare(unsigned int cpu)
{
__le64 __iomem *release_addr;
if (!cpu_release_addr[cpu])
return -ENODEV;
release_addr = ioremap_cache(cpu_release_addr[cpu],
sizeof(*release_addr));
if (!release_addr)
return -ENOMEM;
writeq_relaxed(__pa_symbol(secondary_holding_pen), release_addr);
__flush_dcache_area((__force void *)release_addr,
sizeof(*release_addr));
sev();
iounmap(release_addr);
return 0;
}
static int smp_spin_table_cpu_boot(unsigned int cpu)
{
write_pen_release(cpu_logical_map(cpu));
sev();
return 0;
}
