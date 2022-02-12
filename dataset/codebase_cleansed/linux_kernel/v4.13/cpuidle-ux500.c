static inline int ux500_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
int this_cpu = smp_processor_id();
bool recouple = false;
if (atomic_inc_return(&master) == num_online_cpus()) {
if (!spin_trylock(&master_lock))
goto wfi;
if (prcmu_gic_decouple()) {
spin_unlock(&master_lock);
goto out;
}
recouple = true;
if (!prcmu_is_cpu_in_wfi(this_cpu ? 0 : 1))
goto out;
if (prcmu_copy_gic_settings())
goto out;
if (prcmu_gic_pending_irq())
goto out;
if (prcmu_pending_irq())
goto out;
if (prcmu_set_power_state(PRCMU_AP_IDLE, true, true))
goto out;
recouple = false;
spin_unlock(&master_lock);
}
wfi:
cpu_do_idle();
out:
atomic_dec(&master);
if (recouple) {
prcmu_gic_recouple();
spin_unlock(&master_lock);
}
return index;
}
static int dbx500_cpuidle_probe(struct platform_device *pdev)
{
prcmu_enable_wakeups(PRCMU_WAKEUP(ARM) | PRCMU_WAKEUP(RTC) |
PRCMU_WAKEUP(ABB));
return cpuidle_register(&ux500_idle_driver, NULL);
}
