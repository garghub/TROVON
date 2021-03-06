static int _cpuidle_allow_idle(struct powerdomain *pwrdm,
struct clockdomain *clkdm)
{
clkdm_allow_idle(clkdm);
return 0;
}
static int _cpuidle_deny_idle(struct powerdomain *pwrdm,
struct clockdomain *clkdm)
{
clkdm_deny_idle(clkdm);
return 0;
}
static int __omap3_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct omap3_idle_statedata *cx =
cpuidle_get_statedata(&dev->states_usage[index]);
u32 mpu_state = cx->mpu_state, core_state = cx->core_state;
local_fiq_disable();
pwrdm_set_next_pwrst(mpu_pd, mpu_state);
pwrdm_set_next_pwrst(core_pd, core_state);
if (omap_irq_pending() || need_resched())
goto return_sleep_time;
if (index == 0) {
pwrdm_for_each_clkdm(mpu_pd, _cpuidle_deny_idle);
pwrdm_for_each_clkdm(core_pd, _cpuidle_deny_idle);
}
if (mpu_state == PWRDM_POWER_OFF)
cpu_pm_enter();
omap_sram_idle();
if (pwrdm_read_prev_pwrst(mpu_pd) == PWRDM_POWER_OFF)
cpu_pm_exit();
if (index == 0) {
pwrdm_for_each_clkdm(mpu_pd, _cpuidle_allow_idle);
pwrdm_for_each_clkdm(core_pd, _cpuidle_allow_idle);
}
return_sleep_time:
local_fiq_enable();
return index;
}
static inline int omap3_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
return cpuidle_wrap_enter(dev, drv, index, __omap3_enter_idle);
}
static int next_valid_state(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct cpuidle_state_usage *curr_usage = &dev->states_usage[index];
struct cpuidle_state *curr = &drv->states[index];
struct omap3_idle_statedata *cx = cpuidle_get_statedata(curr_usage);
u32 mpu_deepest_state = PWRDM_POWER_RET;
u32 core_deepest_state = PWRDM_POWER_RET;
int next_index = -1;
if (enable_off_mode) {
mpu_deepest_state = PWRDM_POWER_OFF;
if (!IS_PM34XX_ERRATUM(PM_SDRC_WAKEUP_ERRATUM_i583))
core_deepest_state = PWRDM_POWER_OFF;
}
if ((cx->valid) &&
(cx->mpu_state >= mpu_deepest_state) &&
(cx->core_state >= core_deepest_state)) {
return index;
} else {
int idx = OMAP3_NUM_STATES - 1;
for (; idx >= 0; idx--) {
if (&drv->states[idx] == curr) {
next_index = idx;
break;
}
}
WARN_ON(next_index == -1);
idx--;
for (; idx >= 0; idx--) {
cx = cpuidle_get_statedata(&dev->states_usage[idx]);
if ((cx->valid) &&
(cx->mpu_state >= mpu_deepest_state) &&
(cx->core_state >= core_deepest_state)) {
next_index = idx;
break;
}
}
}
return next_index;
}
static int omap3_enter_idle_bm(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
int new_state_idx;
u32 core_next_state, per_next_state = 0, per_saved_state = 0, cam_state;
struct omap3_idle_statedata *cx;
int ret;
cam_state = pwrdm_read_pwrst(cam_pd);
if (cam_state == PWRDM_POWER_ON) {
new_state_idx = drv->safe_state_index;
goto select_state;
}
cx = cpuidle_get_statedata(&dev->states_usage[index]);
core_next_state = cx->core_state;
per_next_state = per_saved_state = pwrdm_read_next_pwrst(per_pd);
if ((per_next_state == PWRDM_POWER_OFF) &&
(core_next_state > PWRDM_POWER_RET))
per_next_state = PWRDM_POWER_RET;
if (per_next_state != per_saved_state)
pwrdm_set_next_pwrst(per_pd, per_next_state);
new_state_idx = next_valid_state(dev, drv, index);
select_state:
ret = omap3_enter_idle(dev, drv, new_state_idx);
if (per_next_state != per_saved_state)
pwrdm_set_next_pwrst(per_pd, per_saved_state);
return ret;
}
void omap3_pm_init_cpuidle(struct cpuidle_params *cpuidle_board_params)
{
int i;
if (!cpuidle_board_params)
return;
for (i = 0; i < OMAP3_NUM_STATES; i++) {
cpuidle_params_table[i].valid = cpuidle_board_params[i].valid;
cpuidle_params_table[i].exit_latency =
cpuidle_board_params[i].exit_latency;
cpuidle_params_table[i].target_residency =
cpuidle_board_params[i].target_residency;
}
return;
}
static inline void _fill_cstate(struct cpuidle_driver *drv,
int idx, const char *descr)
{
struct cpuidle_state *state = &drv->states[idx];
state->exit_latency = cpuidle_params_table[idx].exit_latency;
state->target_residency = cpuidle_params_table[idx].target_residency;
state->flags = CPUIDLE_FLAG_TIME_VALID;
state->enter = omap3_enter_idle_bm;
sprintf(state->name, "C%d", idx + 1);
strncpy(state->desc, descr, CPUIDLE_DESC_LEN);
}
static inline struct omap3_idle_statedata *_fill_cstate_usage(
struct cpuidle_device *dev,
int idx)
{
struct omap3_idle_statedata *cx = &omap3_idle_data[idx];
struct cpuidle_state_usage *state_usage = &dev->states_usage[idx];
cx->valid = cpuidle_params_table[idx].valid;
cpuidle_set_statedata(state_usage, cx);
return cx;
}
int __init omap3_idle_init(void)
{
struct cpuidle_device *dev;
struct cpuidle_driver *drv = &omap3_idle_driver;
struct omap3_idle_statedata *cx;
mpu_pd = pwrdm_lookup("mpu_pwrdm");
core_pd = pwrdm_lookup("core_pwrdm");
per_pd = pwrdm_lookup("per_pwrdm");
cam_pd = pwrdm_lookup("cam_pwrdm");
drv->safe_state_index = -1;
dev = &per_cpu(omap3_idle_dev, smp_processor_id());
_fill_cstate(drv, 0, "MPU ON + CORE ON");
(&drv->states[0])->enter = omap3_enter_idle;
drv->safe_state_index = 0;
cx = _fill_cstate_usage(dev, 0);
cx->valid = 1;
cx->mpu_state = PWRDM_POWER_ON;
cx->core_state = PWRDM_POWER_ON;
_fill_cstate(drv, 1, "MPU ON + CORE ON");
cx = _fill_cstate_usage(dev, 1);
cx->mpu_state = PWRDM_POWER_ON;
cx->core_state = PWRDM_POWER_ON;
_fill_cstate(drv, 2, "MPU RET + CORE ON");
cx = _fill_cstate_usage(dev, 2);
cx->mpu_state = PWRDM_POWER_RET;
cx->core_state = PWRDM_POWER_ON;
_fill_cstate(drv, 3, "MPU OFF + CORE ON");
cx = _fill_cstate_usage(dev, 3);
cx->mpu_state = PWRDM_POWER_OFF;
cx->core_state = PWRDM_POWER_ON;
_fill_cstate(drv, 4, "MPU RET + CORE RET");
cx = _fill_cstate_usage(dev, 4);
cx->mpu_state = PWRDM_POWER_RET;
cx->core_state = PWRDM_POWER_RET;
_fill_cstate(drv, 5, "MPU OFF + CORE RET");
cx = _fill_cstate_usage(dev, 5);
cx->mpu_state = PWRDM_POWER_OFF;
cx->core_state = PWRDM_POWER_RET;
_fill_cstate(drv, 6, "MPU OFF + CORE OFF");
cx = _fill_cstate_usage(dev, 6);
if (IS_PM34XX_ERRATUM(PM_SDRC_WAKEUP_ERRATUM_i583)) {
cx->valid = 0;
pr_warn("%s: core off state C7 disabled due to i583\n",
__func__);
}
cx->mpu_state = PWRDM_POWER_OFF;
cx->core_state = PWRDM_POWER_OFF;
drv->state_count = OMAP3_NUM_STATES;
cpuidle_register_driver(&omap3_idle_driver);
dev->state_count = OMAP3_NUM_STATES;
if (cpuidle_register_device(dev)) {
printk(KERN_ERR "%s: CPUidle register device failed\n",
__func__);
return -EIO;
}
return 0;
}
int __init omap3_idle_init(void)
{
return 0;
}
