static int tegra114_idle_power_down(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
local_fiq_disable();
tegra_set_cpu_in_lp2();
cpu_pm_enter();
tick_broadcast_enter();
call_firmware_op(prepare_idle);
if (call_firmware_op(do_idle, 0) == -ENOSYS)
cpu_suspend(0, tegra30_sleep_cpu_secondary_finish);
tick_broadcast_exit();
cpu_pm_exit();
tegra_clear_cpu_in_lp2();
local_fiq_enable();
return index;
}
int __init tegra114_cpuidle_init(void)
{
return cpuidle_register(&tegra_idle_driver, NULL);
}
