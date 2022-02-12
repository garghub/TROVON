void __init shmobile_smp_scu_prepare_cpus(unsigned int max_cpus)
{
shmobile_boot_fn = virt_to_phys(shmobile_smp_boot);
shmobile_boot_arg = MPIDR_HWID_BITMASK;
scu_enable(shmobile_scu_base);
scu_power_mode(shmobile_scu_base, SCU_PM_NORMAL);
}
int shmobile_smp_scu_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
shmobile_smp_hook(cpu, virt_to_phys(shmobile_boot_scu),
(unsigned long)shmobile_scu_base);
return 0;
}
void shmobile_smp_scu_cpu_die(unsigned int cpu)
{
shmobile_smp_hook(cpu, 0, 0);
dsb();
flush_cache_all();
scu_power_mode(shmobile_scu_base, SCU_PM_POWEROFF);
shmobile_smp_sleep();
}
static int shmobile_smp_scu_psr_core_disabled(int cpu)
{
unsigned long mask = SCU_PM_POWEROFF << (cpu * 8);
if ((__raw_readl(shmobile_scu_base + 8) & mask) == mask)
return 1;
return 0;
}
int shmobile_smp_scu_cpu_kill(unsigned int cpu)
{
int k;
for (k = 0; k < 1000; k++) {
if (shmobile_smp_scu_psr_core_disabled(cpu))
return 1;
mdelay(1);
}
return 0;
}
