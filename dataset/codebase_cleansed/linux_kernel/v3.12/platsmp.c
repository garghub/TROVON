static int keystone_smp_boot_secondary(unsigned int cpu,
struct task_struct *idle)
{
unsigned long start = virt_to_phys(&secondary_startup);
int error;
pr_debug("keystone-smp: booting cpu %d, vector %08lx\n",
cpu, start);
error = keystone_cpu_smc(KEYSTONE_MON_CPU_UP_IDX, cpu, start);
if (error)
pr_err("CPU %d bringup failed with %d\n", cpu, error);
return error;
}
