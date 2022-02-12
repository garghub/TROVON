static int arm64_enter_idle_state(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int idx)
{
int ret;
if (!idx) {
cpu_do_idle();
return idx;
}
ret = cpu_pm_enter();
if (!ret) {
ret = cpu_suspend(idx);
cpu_pm_exit();
}
return ret ? -1 : idx;
}
static int __init arm64_idle_init(void)
{
int cpu, ret;
struct cpuidle_driver *drv = &arm64_idle_driver;
ret = dt_init_idle_driver(drv, arm64_idle_state_match, 1);
if (ret <= 0)
return ret ? : -ENODEV;
for_each_possible_cpu(cpu) {
ret = cpu_init_idle(cpu);
if (ret) {
pr_err("CPU %d failed to init idle CPU ops\n", cpu);
return ret;
}
}
return cpuidle_register(drv, NULL);
}
