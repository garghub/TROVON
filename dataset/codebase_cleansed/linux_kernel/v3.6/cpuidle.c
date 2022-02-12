static int tegra_idle_enter_lp3(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
ktime_t enter, exit;
s64 us;
local_irq_disable();
local_fiq_disable();
enter = ktime_get();
cpu_do_idle();
exit = ktime_sub(ktime_get(), enter);
us = ktime_to_us(exit);
local_fiq_enable();
local_irq_enable();
dev->last_residency = us;
return index;
}
static int __init tegra_cpuidle_init(void)
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
