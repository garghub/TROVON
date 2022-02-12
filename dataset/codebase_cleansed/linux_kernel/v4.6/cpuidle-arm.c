static int arm_enter_idle_state(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int idx)
{
int ret;
if (!idx) {
cpu_do_idle();
return idx;
}
ret = cpu_pm_enter();
if (!ret) {
ret = arm_cpuidle_suspend(idx);
cpu_pm_exit();
}
return ret ? -1 : idx;
}
static int __init arm_idle_init(void)
{
int cpu, ret;
struct cpuidle_driver *drv = &arm_idle_driver;
struct cpuidle_device *dev;
ret = dt_init_idle_driver(drv, arm_idle_state_match, 1);
if (ret <= 0)
return ret ? : -ENODEV;
ret = cpuidle_register_driver(drv);
if (ret) {
pr_err("Failed to register cpuidle driver\n");
return ret;
}
for_each_possible_cpu(cpu) {
ret = arm_cpuidle_init(cpu);
if (ret == -ENXIO)
continue;
if (ret) {
pr_err("CPU %d failed to init idle CPU ops\n", cpu);
goto out_fail;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
pr_err("Failed to allocate cpuidle device\n");
goto out_fail;
}
dev->cpu = cpu;
ret = cpuidle_register_device(dev);
if (ret) {
pr_err("Failed to register cpuidle device for CPU %d\n",
cpu);
kfree(dev);
goto out_fail;
}
}
return 0;
out_fail:
while (--cpu >= 0) {
dev = per_cpu(cpuidle_devices, cpu);
cpuidle_unregister_device(dev);
kfree(dev);
}
cpuidle_unregister_driver(drv);
return ret;
}
