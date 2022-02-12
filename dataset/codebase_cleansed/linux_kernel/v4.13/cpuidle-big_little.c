static int notrace bl_powerdown_finisher(unsigned long arg)
{
unsigned int mpidr = read_cpuid_mpidr();
unsigned int cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
unsigned int cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
mcpm_set_entry_vector(cpu, cluster, cpu_resume);
mcpm_cpu_suspend();
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
static int __init bl_idle_driver_init(struct cpuidle_driver *drv, int part_id)
{
struct cpumask *cpumask;
int cpu;
cpumask = kzalloc(cpumask_size(), GFP_KERNEL);
if (!cpumask)
return -ENOMEM;
for_each_possible_cpu(cpu)
if (smp_cpuid_part(cpu) == part_id)
cpumask_set_cpu(cpu, cpumask);
drv->cpumask = cpumask;
return 0;
}
static int __init bl_idle_init(void)
{
int ret;
struct device_node *root = of_find_node_by_path("/");
if (!root)
return -ENODEV;
if (!of_match_node(compatible_machine_match, root))
return -ENODEV;
if (!mcpm_is_available())
return -EUNATCH;
ret = bl_idle_driver_init(&bl_idle_little_driver,
ARM_CPU_PART_CORTEX_A7);
if (ret)
return ret;
ret = bl_idle_driver_init(&bl_idle_big_driver, ARM_CPU_PART_CORTEX_A15);
if (ret)
goto out_uninit_little;
ret = dt_init_idle_driver(&bl_idle_big_driver, bl_idle_state_match, 1);
if (ret < 0)
goto out_uninit_big;
ret = dt_init_idle_driver(&bl_idle_little_driver,
bl_idle_state_match, 1);
if (ret < 0)
goto out_uninit_big;
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
