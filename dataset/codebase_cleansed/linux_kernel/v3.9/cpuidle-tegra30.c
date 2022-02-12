static bool tegra30_cpu_cluster_power_down(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct cpuidle_state *state = &drv->states[index];
u32 cpu_on_time = state->exit_latency;
u32 cpu_off_time = state->target_residency - state->exit_latency;
if (num_online_cpus() > 1 || !tegra_cpu_rail_off_ready()) {
cpu_do_idle();
return false;
}
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &dev->cpu);
tegra_idle_lp2_last(cpu_on_time, cpu_off_time);
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_EXIT, &dev->cpu);
return true;
}
static bool tegra30_cpu_core_power_down(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &dev->cpu);
smp_wmb();
save_cpu_arch_register();
cpu_suspend(0, tegra30_sleep_cpu_secondary_finish);
restore_cpu_arch_register();
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_EXIT, &dev->cpu);
return true;
}
static inline bool tegra30_cpu_core_power_down(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
return true;
}
static int tegra30_idle_lp2(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
u32 cpu = is_smp() ? cpu_logical_map(dev->cpu) : dev->cpu;
bool entered_lp2 = false;
bool last_cpu;
local_fiq_disable();
last_cpu = tegra_set_cpu_in_lp2(cpu);
cpu_pm_enter();
if (cpu == 0) {
if (last_cpu)
entered_lp2 = tegra30_cpu_cluster_power_down(dev, drv,
index);
else
cpu_do_idle();
} else {
entered_lp2 = tegra30_cpu_core_power_down(dev, drv, index);
}
cpu_pm_exit();
tegra_clear_cpu_in_lp2(cpu);
local_fiq_enable();
smp_rmb();
return (entered_lp2) ? index : 0;
}
int __init tegra30_cpuidle_init(void)
{
int ret;
unsigned int cpu;
struct cpuidle_device *dev;
struct cpuidle_driver *drv = &tegra_idle_driver;
#ifdef CONFIG_PM_SLEEP
tegra_tear_down_cpu = tegra30_tear_down_cpu;
#endif
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
