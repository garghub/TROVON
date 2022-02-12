static int omap4_enter_idle_simple(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
local_fiq_disable();
omap_do_wfi();
local_fiq_enable();
return index;
}
static int omap4_enter_idle_coupled(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct omap4_idle_statedata *cx = &omap4_idle_data[index];
int cpu_id = smp_processor_id();
local_fiq_disable();
if (dev->cpu == 0 && cpumask_test_cpu(1, cpu_online_mask)) {
while (pwrdm_read_pwrst(cpu_pd[1]) != PWRDM_POWER_OFF) {
cpu_relax();
if (cpu_done[1])
goto fail;
}
}
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &cpu_id);
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
clkdm_allow_idle(cpu_clkdm[1]);
}
cpu_pm_exit();
if (omap4_mpuss_read_prev_context_state())
cpu_cluster_pm_exit();
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_EXIT, &cpu_id);
fail:
cpuidle_coupled_parallel_barrier(dev, &abort_barrier);
cpu_done[dev->cpu] = false;
local_fiq_enable();
return index;
}
static void omap_setup_broadcast_timer(void *arg)
{
int cpu = smp_processor_id();
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ON, &cpu);
}
int __init omap4_idle_init(void)
{
struct cpuidle_device *dev;
unsigned int cpu_id = 0;
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
for_each_cpu(cpu_id, cpu_online_mask) {
dev = &per_cpu(omap4_idle_dev, cpu_id);
dev->cpu = cpu_id;
#ifdef CONFIG_ARCH_NEEDS_CPU_IDLE_COUPLED
dev->coupled_cpus = *cpu_online_mask;
#endif
cpuidle_register_driver(&omap4_idle_driver);
if (cpuidle_register_device(dev)) {
pr_err("%s: CPUidle register failed\n", __func__);
return -EIO;
}
}
return 0;
}
