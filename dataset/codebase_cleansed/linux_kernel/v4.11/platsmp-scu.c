static int shmobile_scu_cpu_prepare(unsigned int cpu)
{
shmobile_smp_hook(cpu, __pa_symbol(shmobile_boot_scu),
shmobile_scu_base_phys);
return 0;
}
void __init shmobile_smp_scu_prepare_cpus(phys_addr_t scu_base_phys,
unsigned int max_cpus)
{
shmobile_boot_fn = __pa_symbol(shmobile_smp_boot);
shmobile_scu_base_phys = scu_base_phys;
shmobile_scu_base = ioremap(scu_base_phys, PAGE_SIZE);
scu_enable(shmobile_scu_base);
scu_power_mode(shmobile_scu_base, SCU_PM_NORMAL);
cpuhp_setup_state_nocalls(CPUHP_ARM_SHMOBILE_SCU_PREPARE,
"arm/shmobile-scu:prepare",
shmobile_scu_cpu_prepare, NULL);
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
