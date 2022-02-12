static void cpu_to_pcpu(unsigned int cpu,
unsigned int *pcpu, unsigned int *pcluster)
{
unsigned int mpidr;
mpidr = cpu_logical_map(cpu);
*pcpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
*pcluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
}
static int mcpm_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
unsigned int pcpu, pcluster, ret;
extern void secondary_startup(void);
cpu_to_pcpu(cpu, &pcpu, &pcluster);
pr_debug("%s: logical CPU %d is physical CPU %d cluster %d\n",
__func__, cpu, pcpu, pcluster);
mcpm_set_entry_vector(pcpu, pcluster, NULL);
ret = mcpm_cpu_power_up(pcpu, pcluster);
if (ret)
return ret;
mcpm_set_entry_vector(pcpu, pcluster, secondary_startup);
arch_send_wakeup_ipi_mask(cpumask_of(cpu));
dsb_sev();
return 0;
}
static void mcpm_secondary_init(unsigned int cpu)
{
mcpm_cpu_powered_up();
}
static int mcpm_cpu_kill(unsigned int cpu)
{
unsigned int pcpu, pcluster;
cpu_to_pcpu(cpu, &pcpu, &pcluster);
return !mcpm_cpu_power_down_finish(pcpu, pcluster);
}
static int mcpm_cpu_disable(unsigned int cpu)
{
return 0;
}
static void mcpm_cpu_die(unsigned int cpu)
{
unsigned int mpidr, pcpu, pcluster;
mpidr = read_cpuid_mpidr();
pcpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
pcluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
mcpm_set_entry_vector(pcpu, pcluster, NULL);
mcpm_cpu_power_down();
}
void __init mcpm_smp_set_ops(void)
{
smp_set_ops(&mcpm_smp_ops);
}
