int __init tegra20_cpuidle_init(void)
{
int ret;
unsigned int cpu;
struct cpuidle_device *dev;
struct cpuidle_driver *drv = &tegra_idle_driver;
ret = cpuidle_register_driver(&tegra_idle_driver);
if (ret) {
pr_err("CPUidle driver registration failed\n");
return ret;
}
for_each_possible_cpu(cpu) {
dev = &per_cpu(tegra_idle_device, cpu);
dev->cpu = cpu;
dev->state_count = drv->state_count;
ret = cpuidle_register_device(dev);
if (ret) {
pr_err("CPU%u: CPUidle device registration failed\n",
cpu);
return ret;
}
}
return 0;
}
