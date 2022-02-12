static void __init r8a7791_smp_prepare_cpus(unsigned int max_cpus)
{
shmobile_smp_apmu_prepare_cpus(max_cpus);
r8a7791_pm_init();
}
static int r8a7791_smp_boot_secondary(unsigned int cpu,
struct task_struct *idle)
{
if (rcar_gen2_read_mode_pins() & BIT(21)) {
pr_warn("Unable to boot CPU%u when MD21 is set\n", cpu);
return -ENOTSUPP;
}
return shmobile_smp_apmu_boot_secondary(cpu, idle);
}
