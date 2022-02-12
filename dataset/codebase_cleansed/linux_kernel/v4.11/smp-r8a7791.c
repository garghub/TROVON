static void __init r8a7791_smp_prepare_cpus(unsigned int max_cpus)
{
shmobile_smp_apmu_prepare_cpus(max_cpus,
r8a7791_apmu_config,
ARRAY_SIZE(r8a7791_apmu_config));
rcar_gen2_pm_init();
}
