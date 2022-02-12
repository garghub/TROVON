static int tegra20_reset_sleeping_cpu_1(void)
{
int ret = 0;
tegra_pen_lock();
if (readl(pmc + PMC_SCRATCH41) == CPU_RESETTABLE)
tegra20_cpu_shutdown(1);
else
ret = -EINVAL;
tegra_pen_unlock();
return ret;
}
static void tegra20_wake_cpu1_from_reset(void)
{
tegra_pen_lock();
tegra20_cpu_clear_resettable();
tegra_enable_cpu_clock(1);
tegra_cpu_out_of_reset(1);
flowctrl_write_cpu_halt(1, 0);
tegra_pen_unlock();
}
static int tegra20_reset_cpu_1(void)
{
if (!cpu_online(1) || !tegra20_reset_sleeping_cpu_1())
return 0;
tegra20_wake_cpu1_from_reset();
return -EBUSY;
}
static inline void tegra20_wake_cpu1_from_reset(void)
{
}
static inline int tegra20_reset_cpu_1(void)
{
return 0;
}
static bool tegra20_cpu_cluster_power_down(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
while (tegra20_cpu_is_resettable_soon())
cpu_relax();
if (tegra20_reset_cpu_1() || !tegra_cpu_rail_off_ready())
return false;
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &dev->cpu);
tegra_idle_lp2_last();
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_EXIT, &dev->cpu);
if (cpu_online(1))
tegra20_wake_cpu1_from_reset();
return true;
}
static bool tegra20_idle_enter_lp2_cpu_1(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &dev->cpu);
cpu_suspend(0, tegra20_sleep_cpu_secondary_finish);
tegra20_cpu_clear_resettable();
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_EXIT, &dev->cpu);
return true;
}
static inline bool tegra20_idle_enter_lp2_cpu_1(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
return true;
}
static int tegra20_idle_lp2_coupled(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
bool entered_lp2 = false;
if (tegra_pending_sgi())
ACCESS_ONCE(abort_flag) = true;
cpuidle_coupled_parallel_barrier(dev, &abort_barrier);
if (abort_flag) {
cpuidle_coupled_parallel_barrier(dev, &abort_barrier);
abort_flag = false;
return -EINTR;
}
local_fiq_disable();
tegra_set_cpu_in_lp2();
cpu_pm_enter();
if (dev->cpu == 0)
entered_lp2 = tegra20_cpu_cluster_power_down(dev, drv, index);
else
entered_lp2 = tegra20_idle_enter_lp2_cpu_1(dev, drv, index);
cpu_pm_exit();
tegra_clear_cpu_in_lp2();
local_fiq_enable();
smp_rmb();
return entered_lp2 ? index : 0;
}
void tegra20_cpuidle_pcie_irqs_in_use(void)
{
pr_info_once(
"Disabling cpuidle LP2 state, since PCIe IRQs are in use\n");
tegra_idle_driver.states[1].disabled = true;
}
int __init tegra20_cpuidle_init(void)
{
return cpuidle_register(&tegra_idle_driver, cpu_possible_mask);
}
