static int omap4_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct omap4_idle_statedata *cx =
cpuidle_get_statedata(&dev->states_usage[index]);
u32 cpu1_state;
int cpu_id = smp_processor_id();
local_fiq_disable();
cpu1_state = pwrdm_read_pwrst(cpu1_pd);
if (cpu1_state != PWRDM_POWER_OFF) {
index = drv->safe_state_index;
cx = cpuidle_get_statedata(&dev->states_usage[index]);
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
static inline void _fill_cstate(struct cpuidle_driver *drv,
int idx, const char *descr)
{
struct cpuidle_state *state = &drv->states[idx];
state->exit_latency = cpuidle_params_table[idx].exit_latency;
state->target_residency = cpuidle_params_table[idx].target_residency;
state->flags = CPUIDLE_FLAG_TIME_VALID;
state->enter = omap4_enter_idle;
sprintf(state->name, "C%d", idx + 1);
strncpy(state->desc, descr, CPUIDLE_DESC_LEN);
}
static inline struct omap4_idle_statedata *_fill_cstate_usage(
struct cpuidle_device *dev,
int idx)
{
struct omap4_idle_statedata *cx = &omap4_idle_data[idx];
struct cpuidle_state_usage *state_usage = &dev->states_usage[idx];
cx->valid = cpuidle_params_table[idx].valid;
cpuidle_set_statedata(state_usage, cx);
return cx;
}
int __init omap4_idle_init(void)
{
struct omap4_idle_statedata *cx;
struct cpuidle_device *dev;
struct cpuidle_driver *drv = &omap4_idle_driver;
unsigned int cpu_id = 0;
mpu_pd = pwrdm_lookup("mpu_pwrdm");
cpu0_pd = pwrdm_lookup("cpu0_pwrdm");
cpu1_pd = pwrdm_lookup("cpu1_pwrdm");
if ((!mpu_pd) || (!cpu0_pd) || (!cpu1_pd))
return -ENODEV;
drv->safe_state_index = -1;
dev = &per_cpu(omap4_idle_dev, cpu_id);
dev->cpu = cpu_id;
_fill_cstate(drv, 0, "MPUSS ON");
drv->safe_state_index = 0;
cx = _fill_cstate_usage(dev, 0);
cx->valid = 1;
cx->cpu_state = PWRDM_POWER_ON;
cx->mpu_state = PWRDM_POWER_ON;
cx->mpu_logic_state = PWRDM_POWER_RET;
_fill_cstate(drv, 1, "MPUSS CSWR");
cx = _fill_cstate_usage(dev, 1);
cx->cpu_state = PWRDM_POWER_OFF;
cx->mpu_state = PWRDM_POWER_RET;
cx->mpu_logic_state = PWRDM_POWER_RET;
_fill_cstate(drv, 2, "MPUSS OSWR");
cx = _fill_cstate_usage(dev, 2);
cx->cpu_state = PWRDM_POWER_OFF;
cx->mpu_state = PWRDM_POWER_RET;
cx->mpu_logic_state = PWRDM_POWER_OFF;
drv->state_count = OMAP4_NUM_STATES;
cpuidle_register_driver(&omap4_idle_driver);
dev->state_count = OMAP4_NUM_STATES;
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
