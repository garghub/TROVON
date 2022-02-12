static int arm_enter_idle_state(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int idx)
{
return CPU_PM_CPU_IDLE_ENTER(arm_cpuidle_suspend, idx);
}
static int __init arm_idle_init(void)
{
int cpu, ret;
struct cpuidle_driver *drv;
struct cpuidle_device *dev;
for_each_possible_cpu(cpu) {
drv = kmemdup(&arm_idle_driver, sizeof(*drv), GFP_KERNEL);
if (!drv) {
ret = -ENOMEM;
goto out_fail;
}
drv->cpumask = (struct cpumask *)cpumask_of(cpu);
ret = dt_init_idle_driver(drv, arm_idle_state_match, 1);
if (ret <= 0) {
ret = ret ? : -ENODEV;
goto out_fail;
}
ret = cpuidle_register_driver(drv);
if (ret) {
pr_err("Failed to register cpuidle driver\n");
goto out_fail;
}
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
ret = -ENOMEM;
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
drv = cpuidle_get_driver();
cpuidle_unregister_driver(drv);
kfree(drv);
}
return ret;
}
