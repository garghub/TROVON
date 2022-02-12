static int omap4_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct omap4_idle_statedata *cx = &omap4_idle_data[index];
u32 cpu1_state;
int cpu_id = smp_processor_id();
local_fiq_disable();
cpu1_state = pwrdm_read_pwrst(cpu1_pd);
if (cpu1_state != PWRDM_POWER_OFF) {
index = drv->safe_state_index;
cx = &omap4_idle_data[index];
}
if (index > 0)
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &cpu_id);
if (cx->cpu_state == PWRDM_POWER_OFF)
cpu_pm_enter();
pwrdm_set_logic_retst(mpu_pd, cx->mpu_logic_state);
omap_set_pwrdm_state(mpu_pd, cx->mpu_state);
if ((cx->mpu_state == PWRDM_POWER_RET) &&
(cx->mpu_logic_state == PWRDM_POWER_OFF))
cpu_cluster_pm_enter();
omap4_enter_lowpower(dev->cpu, cx->cpu_state);
if (pwrdm_read_prev_pwrst(cpu0_pd) == PWRDM_POWER_OFF)
cpu_pm_exit();
if (omap4_mpuss_read_prev_context_state())
cpu_cluster_pm_exit();
if (index > 0)
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_EXIT, &cpu_id);
local_fiq_enable();
return index;
}
int __init omap4_idle_init(void)
{
struct cpuidle_device *dev;
unsigned int cpu_id = 0;
mpu_pd = pwrdm_lookup("mpu_pwrdm");
cpu0_pd = pwrdm_lookup("cpu0_pwrdm");
cpu1_pd = pwrdm_lookup("cpu1_pwrdm");
if ((!mpu_pd) || (!cpu0_pd) || (!cpu1_pd))
return -ENODEV;
dev = &per_cpu(omap4_idle_dev, cpu_id);
dev->cpu = cpu_id;
cpuidle_register_driver(&omap4_idle_driver);
if (cpuidle_register_device(dev)) {
pr_err("%s: CPUidle register device failed\n", __func__);
return -EIO;
}
return 0;
}
int __init omap4_idle_init(void)
{
return 0;
}
