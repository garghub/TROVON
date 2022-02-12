static int omap_enter_idle_simple(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
omap_do_wfi();
return index;
}
static int omap_enter_idle_coupled(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct idle_statedata *cx = state_ptr + index;
if (dev->cpu == 0 && cpumask_test_cpu(1, cpu_online_mask)) {
while (pwrdm_read_pwrst(cpu_pd[1]) != PWRDM_POWER_OFF) {
cpu_relax();
if (cpu_done[1])
goto fail;
}
}
cpu_pm_enter();
if (dev->cpu == 0) {
pwrdm_set_logic_retst(mpu_pd, cx->mpu_logic_state);
omap_set_pwrdm_state(mpu_pd, cx->mpu_state);
if ((cx->mpu_state == PWRDM_POWER_RET) &&
(cx->mpu_logic_state == PWRDM_POWER_OFF))
cpu_cluster_pm_enter();
}
omap4_enter_lowpower(dev->cpu, cx->cpu_state);
cpu_done[dev->cpu] = true;
if (dev->cpu == 0 && cpumask_test_cpu(1, cpu_online_mask)) {
clkdm_wakeup(cpu_clkdm[1]);
omap_set_pwrdm_state(cpu_pd[1], PWRDM_POWER_ON);
clkdm_allow_idle(cpu_clkdm[1]);
}
cpu_pm_exit();
if (dev->cpu == 0 && (cx->mpu_state == PWRDM_POWER_RET) &&
(cx->mpu_logic_state == PWRDM_POWER_OFF))
cpu_cluster_pm_exit();
fail:
cpuidle_coupled_parallel_barrier(dev, &abort_barrier);
cpu_done[dev->cpu] = false;
return index;
}
int __init omap4_idle_init(void)
{
mpu_pd = pwrdm_lookup("mpu_pwrdm");
cpu_pd[0] = pwrdm_lookup("cpu0_pwrdm");
cpu_pd[1] = pwrdm_lookup("cpu1_pwrdm");
if ((!mpu_pd) || (!cpu_pd[0]) || (!cpu_pd[1]))
return -ENODEV;
cpu_clkdm[0] = clkdm_lookup("mpu0_clkdm");
cpu_clkdm[1] = clkdm_lookup("mpu1_clkdm");
if (!cpu_clkdm[0] || !cpu_clkdm[1])
return -ENODEV;
return cpuidle_register(&omap4_idle_driver, cpu_online_mask);
}
