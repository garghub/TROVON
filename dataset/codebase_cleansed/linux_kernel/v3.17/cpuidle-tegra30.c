static bool tegra30_cpu_cluster_power_down(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
if (num_online_cpus() > 1 || !tegra_cpu_rail_off_ready()) {
cpu_do_idle();
return false;
}
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &dev->cpu);
tegra_idle_lp2_last();
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_EXIT, &dev->cpu);
return true;
}
static bool tegra30_cpu_core_power_down(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &dev->cpu);
smp_wmb();
cpu_suspend(0, tegra30_sleep_cpu_secondary_finish);
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
bool entered_lp2 = false;
bool last_cpu;
local_fiq_disable();
last_cpu = tegra_set_cpu_in_lp2();
cpu_pm_enter();
if (dev->cpu == 0) {
if (last_cpu)
entered_lp2 = tegra30_cpu_cluster_power_down(dev, drv,
index);
else
cpu_do_idle();
} else {
entered_lp2 = tegra30_cpu_core_power_down(dev, drv, index);
}
cpu_pm_exit();
tegra_clear_cpu_in_lp2();
local_fiq_enable();
smp_rmb();
return (entered_lp2) ? index : 0;
}
int __init tegra30_cpuidle_init(void)
{
return cpuidle_register(&tegra_idle_driver, NULL);
}
