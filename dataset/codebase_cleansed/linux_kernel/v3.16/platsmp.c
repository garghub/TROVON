static int keystone_smp_boot_secondary(unsigned int cpu,
struct task_struct *idle)
{
unsigned long start = virt_to_idmap(&secondary_startup);
int error;
pr_debug("keystone-smp: booting cpu %d, vector %08lx\n",
cpu, start);
error = keystone_cpu_smc(KEYSTONE_MON_CPU_UP_IDX, cpu, start);
if (error)
pr_err("CPU %d bringup failed with %d\n", cpu, error);
return error;
}
static void __cpuinit keystone_smp_secondary_initmem(unsigned int cpu)
{
pgd_t *pgd0 = pgd_offset_k(0);
cpu_set_ttbr(1, __pa(pgd0) + TTBR1_OFFSET);
local_flush_tlb_all();
}
static inline void __cpuinit keystone_smp_secondary_initmem(unsigned int cpu)
{}
