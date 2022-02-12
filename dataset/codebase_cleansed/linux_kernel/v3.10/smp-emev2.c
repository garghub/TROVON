static int __cpuinit emev2_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
arch_send_wakeup_ipi_mask(cpumask_of(cpu_logical_map(cpu)));
return 0;
}
static void __init emev2_smp_prepare_cpus(unsigned int max_cpus)
{
scu_enable(shmobile_scu_base);
emev2_set_boot_vector(__pa(shmobile_secondary_vector_scu));
scu_power_mode(shmobile_scu_base, SCU_PM_NORMAL);
}
static void __init emev2_smp_init_cpus(void)
{
unsigned int ncores;
shmobile_scu_base = ioremap(EMEV2_SCU_BASE, PAGE_SIZE);
emev2_clock_init();
ncores = shmobile_scu_base ? scu_get_core_count(shmobile_scu_base) : 1;
shmobile_smp_init_cpus(ncores);
}
