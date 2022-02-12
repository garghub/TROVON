const struct cpumask *cpu_coregroup_mask(int cpu)
{
return &cpu_topology[cpu].core_sibling;
}
void store_cpu_topology(unsigned int cpuid)
{
struct cputopo_arm *cpuid_topo = &cpu_topology[cpuid];
unsigned int mpidr;
unsigned int cpu;
if (cpuid_topo->core_id != -1)
return;
mpidr = read_cpuid_mpidr();
if ((mpidr & MPIDR_SMP_BITMASK) == MPIDR_SMP_VALUE) {
if (mpidr & MPIDR_MT_BITMASK) {
cpuid_topo->thread_id = (mpidr >> MPIDR_LEVEL0_SHIFT)
& MPIDR_LEVEL0_MASK;
cpuid_topo->core_id = (mpidr >> MPIDR_LEVEL1_SHIFT)
& MPIDR_LEVEL1_MASK;
cpuid_topo->socket_id = (mpidr >> MPIDR_LEVEL2_SHIFT)
& MPIDR_LEVEL2_MASK;
} else {
cpuid_topo->thread_id = -1;
cpuid_topo->core_id = (mpidr >> MPIDR_LEVEL0_SHIFT)
& MPIDR_LEVEL0_MASK;
cpuid_topo->socket_id = (mpidr >> MPIDR_LEVEL1_SHIFT)
& MPIDR_LEVEL1_MASK;
}
} else {
cpuid_topo->thread_id = -1;
cpuid_topo->core_id = 0;
cpuid_topo->socket_id = -1;
}
for_each_possible_cpu(cpu) {
struct cputopo_arm *cpu_topo = &cpu_topology[cpu];
if (cpuid_topo->socket_id == cpu_topo->socket_id) {
cpumask_set_cpu(cpuid, &cpu_topo->core_sibling);
if (cpu != cpuid)
cpumask_set_cpu(cpu,
&cpuid_topo->core_sibling);
if (cpuid_topo->core_id == cpu_topo->core_id) {
cpumask_set_cpu(cpuid,
&cpu_topo->thread_sibling);
if (cpu != cpuid)
cpumask_set_cpu(cpu,
&cpuid_topo->thread_sibling);
}
}
}
smp_wmb();
printk(KERN_INFO "CPU%u: thread %d, cpu %d, socket %d, mpidr %x\n",
cpuid, cpu_topology[cpuid].thread_id,
cpu_topology[cpuid].core_id,
cpu_topology[cpuid].socket_id, mpidr);
}
void init_cpu_topology(void)
{
unsigned int cpu;
for_each_possible_cpu(cpu) {
struct cputopo_arm *cpu_topo = &(cpu_topology[cpu]);
cpu_topo->thread_id = -1;
cpu_topo->core_id = -1;
cpu_topo->socket_id = -1;
cpumask_clear(&cpu_topo->core_sibling);
cpumask_clear(&cpu_topo->thread_sibling);
}
smp_wmb();
}
