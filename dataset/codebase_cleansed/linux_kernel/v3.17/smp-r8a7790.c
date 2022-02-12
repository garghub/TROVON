static void __init r8a7790_smp_prepare_cpus(unsigned int max_cpus)
{
shmobile_smp_apmu_prepare_cpus(max_cpus);
r8a7790_pm_init();
rcar_sysc_power_up(&r8a7790_ca15_scu);
rcar_sysc_power_up(&r8a7790_ca7_scu);
}
