static int notrace bl_powerdown_finisher(unsigned long arg)
{
unsigned int mpidr = read_cpuid_mpidr();
unsigned int cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
unsigned int cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
mcpm_set_entry_vector(cpu, cluster, cpu_resume);
mcpm_cpu_suspend(0);
return 1;
}
static int bl_enter_powerdown(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int idx)
{
cpu_pm_enter();
cpu_suspend(0, bl_powerdown_finisher);
mcpm_cpu_powered_up();
cpu_pm_exit();
return idx;
}
static int __init bl_idle_driver_init(struct cpuidle_driver *drv, int cpu_id)
{
struct cpuinfo_arm *cpu_info;
struct cpumask *cpumask;
unsigned long cpuid;
int cpu;
cpumask = kzalloc(cpumask_size(), GFP_KERNEL);
if (!cpumask)
return -ENOMEM;
for_each_possible_cpu(cpu) {
cpu_info = &per_cpu(cpu_data, cpu);
cpuid = is_smp() ? cpu_info->cpuid : read_cpuid_id();
if ((cpuid & 0xFFF0) == cpu_id)
cpumask_set_cpu(cpu, cpumask);
}
drv->cpumask = cpumask;
return 0;
}
static int __init bl_idle_init(void)
{
int ret;
if (!of_machine_is_compatible("arm,vexpress,v2p-ca15_a7"))
return -ENODEV;
ret = bl_idle_driver_init(&bl_idle_little_driver,
ARM_CPU_PART_CORTEX_A7);
if (ret)
return ret;
ret = bl_idle_driver_init(&bl_idle_big_driver, ARM_CPU_PART_CORTEX_A15);
if (ret)
goto out_uninit_little;
ret = cpuidle_register(&bl_idle_little_driver, NULL);
if (ret)
goto out_uninit_big;
ret = cpuidle_register(&bl_idle_big_driver, NULL);
if (ret)
goto out_unregister_little;
return 0;
out_unregister_little:
cpuidle_unregister(&bl_idle_little_driver);
out_uninit_big:
kfree(bl_idle_big_driver.cpumask);
out_uninit_little:
kfree(bl_idle_little_driver.cpumask);
return ret;
}
