unsigned long arch_scale_freq_power(struct sched_domain *sd, int cpu)
{
return per_cpu(cpu_scale, cpu);
}
static void set_power_scale(unsigned int cpu, unsigned long power)
{
per_cpu(cpu_scale, cpu) = power;
}
static void __init parse_dt_topology(void)
{
struct cpu_efficiency *cpu_eff;
struct device_node *cn = NULL;
unsigned long min_capacity = (unsigned long)(-1);
unsigned long max_capacity = 0;
unsigned long capacity = 0;
int alloc_size, cpu = 0;
alloc_size = nr_cpu_ids * sizeof(struct cpu_capacity);
cpu_capacity = kzalloc(alloc_size, GFP_NOWAIT);
while ((cn = of_find_node_by_type(cn, "cpu"))) {
const u32 *rate, *reg;
int len;
if (cpu >= num_possible_cpus())
break;
for (cpu_eff = table_efficiency; cpu_eff->compatible; cpu_eff++)
if (of_device_is_compatible(cn, cpu_eff->compatible))
break;
if (cpu_eff->compatible == NULL)
continue;
rate = of_get_property(cn, "clock-frequency", &len);
if (!rate || len != 4) {
pr_err("%s missing clock-frequency property\n",
cn->full_name);
continue;
}
reg = of_get_property(cn, "reg", &len);
if (!reg || len != 4) {
pr_err("%s missing reg property\n", cn->full_name);
continue;
}
capacity = ((be32_to_cpup(rate)) >> 20) * cpu_eff->efficiency;
if (capacity < min_capacity)
min_capacity = capacity;
if (capacity > max_capacity)
max_capacity = capacity;
cpu_capacity[cpu].capacity = capacity;
cpu_capacity[cpu++].hwid = be32_to_cpup(reg);
}
if (cpu < num_possible_cpus())
cpu_capacity[cpu].hwid = (unsigned long)(-1);
if (min_capacity == max_capacity)
cpu_capacity[0].hwid = (unsigned long)(-1);
else if (4*max_capacity < (3*(max_capacity + min_capacity)))
middle_capacity = (min_capacity + max_capacity)
>> (SCHED_POWER_SHIFT+1);
else
middle_capacity = ((max_capacity / 3)
>> (SCHED_POWER_SHIFT-1)) + 1;
}
void update_cpu_power(unsigned int cpu, unsigned long hwid)
{
unsigned int idx = 0;
for (idx = 0; idx < num_possible_cpus(); idx++) {
if (cpu_capacity[idx].hwid == hwid)
break;
if (cpu_capacity[idx].hwid == -1)
return;
}
if (idx == num_possible_cpus())
return;
set_power_scale(cpu, cpu_capacity[idx].capacity / middle_capacity);
printk(KERN_INFO "CPU%u: update cpu_power %lu\n",
cpu, arch_scale_freq_power(NULL, cpu));
}
static inline void parse_dt_topology(void) {}
static inline void update_cpu_power(unsigned int cpuid, unsigned int mpidr) {}
const struct cpumask *cpu_coregroup_mask(int cpu)
{
return &cpu_topology[cpu].core_sibling;
}
void update_siblings_masks(unsigned int cpuid)
{
struct cputopo_arm *cpu_topo, *cpuid_topo = &cpu_topology[cpuid];
int cpu;
for_each_possible_cpu(cpu) {
cpu_topo = &cpu_topology[cpu];
if (cpuid_topo->socket_id != cpu_topo->socket_id)
continue;
cpumask_set_cpu(cpuid, &cpu_topo->core_sibling);
if (cpu != cpuid)
cpumask_set_cpu(cpu, &cpuid_topo->core_sibling);
if (cpuid_topo->core_id != cpu_topo->core_id)
continue;
cpumask_set_cpu(cpuid, &cpu_topo->thread_sibling);
if (cpu != cpuid)
cpumask_set_cpu(cpu, &cpuid_topo->thread_sibling);
}
smp_wmb();
}
void store_cpu_topology(unsigned int cpuid)
{
struct cputopo_arm *cpuid_topo = &cpu_topology[cpuid];
unsigned int mpidr;
if (cpuid_topo->core_id != -1)
return;
mpidr = read_cpuid_mpidr();
if ((mpidr & MPIDR_SMP_BITMASK) == MPIDR_SMP_VALUE) {
if (mpidr & MPIDR_MT_BITMASK) {
cpuid_topo->thread_id = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cpuid_topo->core_id = MPIDR_AFFINITY_LEVEL(mpidr, 1);
cpuid_topo->socket_id = MPIDR_AFFINITY_LEVEL(mpidr, 2);
} else {
cpuid_topo->thread_id = -1;
cpuid_topo->core_id = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cpuid_topo->socket_id = MPIDR_AFFINITY_LEVEL(mpidr, 1);
}
} else {
cpuid_topo->thread_id = -1;
cpuid_topo->core_id = 0;
cpuid_topo->socket_id = -1;
}
update_siblings_masks(cpuid);
update_cpu_power(cpuid, mpidr & MPIDR_HWID_BITMASK);
printk(KERN_INFO "CPU%u: thread %d, cpu %d, socket %d, mpidr %x\n",
cpuid, cpu_topology[cpuid].thread_id,
cpu_topology[cpuid].core_id,
cpu_topology[cpuid].socket_id, mpidr);
}
void __init init_cpu_topology(void)
{
unsigned int cpu;
for_each_possible_cpu(cpu) {
struct cputopo_arm *cpu_topo = &(cpu_topology[cpu]);
cpu_topo->thread_id = -1;
cpu_topo->core_id = -1;
cpu_topo->socket_id = -1;
cpumask_clear(&cpu_topo->core_sibling);
cpumask_clear(&cpu_topo->thread_sibling);
set_power_scale(cpu, SCHED_POWER_SCALE);
}
smp_wmb();
parse_dt_topology();
}
