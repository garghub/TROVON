static int omap_enter_idle_simple(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
omap_do_wfi();
return index;
}
static int omap_enter_idle_smp(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct idle_statedata *cx = state_ptr + index;
unsigned long flag;
raw_spin_lock_irqsave(&mpu_lock, flag);
cx->mpu_state_vote++;
if (cx->mpu_state_vote == num_online_cpus()) {
pwrdm_set_logic_retst(mpu_pd, cx->mpu_logic_state);
omap_set_pwrdm_state(mpu_pd, cx->mpu_state);
}
raw_spin_unlock_irqrestore(&mpu_lock, flag);
omap4_enter_lowpower(dev->cpu, cx->cpu_state);
raw_spin_lock_irqsave(&mpu_lock, flag);
if (cx->mpu_state_vote == num_online_cpus())
omap_set_pwrdm_state(mpu_pd, PWRDM_POWER_ON);
cx->mpu_state_vote--;
raw_spin_unlock_irqrestore(&mpu_lock, flag);
return index;
}
static int omap_enter_idle_coupled(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct idle_statedata *cx = state_ptr + index;
u32 mpuss_can_lose_context = 0;
if (dev->cpu == 0 && cpumask_test_cpu(1, cpu_online_mask)) {
while (pwrdm_read_pwrst(cpu_pd[1]) != PWRDM_POWER_OFF) {
cpu_relax();
if (cpu_done[1])
goto fail;
}
}
mpuss_can_lose_context = (cx->mpu_state == PWRDM_POWER_RET) &&
(cx->mpu_logic_state == PWRDM_POWER_OFF);
tick_broadcast_enter();
cpu_pm_enter();
if (dev->cpu == 0) {
pwrdm_set_logic_retst(mpu_pd, cx->mpu_logic_state);
omap_set_pwrdm_state(mpu_pd, cx->mpu_state);
if (mpuss_can_lose_context)
cpu_cluster_pm_enter();
}
omap4_enter_lowpower(dev->cpu, cx->cpu_state);
cpu_done[dev->cpu] = true;
if (dev->cpu == 0 && cpumask_test_cpu(1, cpu_online_mask)) {
if (IS_PM44XX_ERRATUM(PM_OMAP4_ROM_SMP_BOOT_ERRATUM_GICD) &&
mpuss_can_lose_context)
gic_dist_disable();
clkdm_deny_idle(cpu_clkdm[1]);
omap_set_pwrdm_state(cpu_pd[1], PWRDM_POWER_ON);
clkdm_allow_idle(cpu_clkdm[1]);
if (IS_PM44XX_ERRATUM(PM_OMAP4_ROM_SMP_BOOT_ERRATUM_GICD) &&
mpuss_can_lose_context) {
while (gic_dist_disabled()) {
udelay(1);
cpu_relax();
}
gic_timer_retrigger();
}
}
cpu_pm_exit();
if (dev->cpu == 0 && mpuss_can_lose_context)
cpu_cluster_pm_exit();
tick_broadcast_exit();
fail:
cpuidle_coupled_parallel_barrier(dev, &abort_barrier);
cpu_done[dev->cpu] = false;
return index;
}
static void omap_setup_broadcast_timer(void *arg)
{
tick_broadcast_enable();
}
int __init omap4_idle_init(void)
{
struct cpuidle_driver *idle_driver;
if (soc_is_omap54xx()) {
state_ptr = &omap5_idle_data[0];
idle_driver = &omap5_idle_driver;
} else {
state_ptr = &omap4_idle_data[0];
idle_driver = &omap4_idle_driver;
}
mpu_pd = pwrdm_lookup("mpu_pwrdm");
cpu_pd[0] = pwrdm_lookup("cpu0_pwrdm");
cpu_pd[1] = pwrdm_lookup("cpu1_pwrdm");
if ((!mpu_pd) || (!cpu_pd[0]) || (!cpu_pd[1]))
return -ENODEV;
cpu_clkdm[0] = clkdm_lookup("mpu0_clkdm");
cpu_clkdm[1] = clkdm_lookup("mpu1_clkdm");
if (!cpu_clkdm[0] || !cpu_clkdm[1])
return -ENODEV;
on_each_cpu(omap_setup_broadcast_timer, NULL, 1);
return cpuidle_register(idle_driver, cpu_online_mask);
}
