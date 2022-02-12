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
static int omap3_enter_idle(struct cpuidle_device *dev,
struct cpuidle_state *state)
{
struct omap3_idle_statedata *cx = cpuidle_get_statedata(state);
struct timespec ts_preidle, ts_postidle, ts_idle;
u32 mpu_state = cx->mpu_state, core_state = cx->core_state;
getnstimeofday(&ts_preidle);
local_irq_disable();
local_fiq_disable();
pwrdm_set_next_pwrst(mpu_pd, mpu_state);
pwrdm_set_next_pwrst(core_pd, core_state);
if (omap_irq_pending() || need_resched())
goto return_sleep_time;
if (state == &dev->states[0]) {
pwrdm_for_each_clkdm(mpu_pd, _cpuidle_deny_idle);
pwrdm_for_each_clkdm(core_pd, _cpuidle_deny_idle);
}
omap_sram_idle();
if (state == &dev->states[0]) {
pwrdm_for_each_clkdm(mpu_pd, _cpuidle_allow_idle);
pwrdm_for_each_clkdm(core_pd, _cpuidle_allow_idle);
}
return_sleep_time:
getnstimeofday(&ts_postidle);
ts_idle = timespec_sub(ts_postidle, ts_preidle);
local_irq_enable();
local_fiq_enable();
return ts_idle.tv_nsec / NSEC_PER_USEC + ts_idle.tv_sec * USEC_PER_SEC;
}
static struct cpuidle_state *next_valid_state(struct cpuidle_device *dev,
struct cpuidle_state *curr)
{
struct cpuidle_state *next = NULL;
struct omap3_idle_statedata *cx = cpuidle_get_statedata(curr);
u32 mpu_deepest_state = PWRDM_POWER_RET;
u32 core_deepest_state = PWRDM_POWER_RET;
if (enable_off_mode) {
mpu_deepest_state = PWRDM_POWER_OFF;
if (!IS_PM34XX_ERRATUM(PM_SDRC_WAKEUP_ERRATUM_i583))
core_deepest_state = PWRDM_POWER_OFF;
}
if ((cx->valid) &&
(cx->mpu_state >= mpu_deepest_state) &&
(cx->core_state >= core_deepest_state)) {
return curr;
} else {
int idx = OMAP3_NUM_STATES - 1;
for (; idx >= 0; idx--) {
if (&dev->states[idx] == curr) {
next = &dev->states[idx];
break;
}
}
WARN_ON(next == NULL);
idx--;
for (; idx >= 0; idx--) {
cx = cpuidle_get_statedata(&dev->states[idx]);
if ((cx->valid) &&
(cx->mpu_state >= mpu_deepest_state) &&
(cx->core_state >= core_deepest_state)) {
next = &dev->states[idx];
break;
}
}
}
return next;
}
static int omap3_enter_idle_bm(struct cpuidle_device *dev,
struct cpuidle_state *state)
{
struct cpuidle_state *new_state;
u32 core_next_state, per_next_state = 0, per_saved_state = 0, cam_state;
struct omap3_idle_statedata *cx;
int ret;
if (!omap3_can_sleep()) {
new_state = dev->safe_state;
goto select_state;
}
cam_state = pwrdm_read_pwrst(cam_pd);
if (cam_state == PWRDM_POWER_ON) {
new_state = dev->safe_state;
goto select_state;
}
cx = cpuidle_get_statedata(state);
core_next_state = cx->core_state;
per_next_state = per_saved_state = pwrdm_read_next_pwrst(per_pd);
if ((per_next_state == PWRDM_POWER_OFF) &&
(core_next_state > PWRDM_POWER_RET))
per_next_state = PWRDM_POWER_RET;
if (per_next_state != per_saved_state)
pwrdm_set_next_pwrst(per_pd, per_next_state);
new_state = next_valid_state(dev, state);
select_state:
dev->last_state = new_state;
ret = omap3_enter_idle(dev, new_state);
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
static inline struct omap3_idle_statedata *_fill_cstate(
struct cpuidle_device *dev,
int idx, const char *descr)
{
struct omap3_idle_statedata *cx = &omap3_idle_data[idx];
struct cpuidle_state *state = &dev->states[idx];
state->exit_latency = cpuidle_params_table[idx].exit_latency;
state->target_residency = cpuidle_params_table[idx].target_residency;
state->flags = CPUIDLE_FLAG_TIME_VALID;
state->enter = omap3_enter_idle_bm;
cx->valid = cpuidle_params_table[idx].valid;
sprintf(state->name, "C%d", idx + 1);
strncpy(state->desc, descr, CPUIDLE_DESC_LEN);
cpuidle_set_statedata(state, cx);
return cx;
}
int __init omap3_idle_init(void)
{
struct cpuidle_device *dev;
struct omap3_idle_statedata *cx;
mpu_pd = pwrdm_lookup("mpu_pwrdm");
core_pd = pwrdm_lookup("core_pwrdm");
per_pd = pwrdm_lookup("per_pwrdm");
cam_pd = pwrdm_lookup("cam_pwrdm");
cpuidle_register_driver(&omap3_idle_driver);
dev = &per_cpu(omap3_idle_dev, smp_processor_id());
cx = _fill_cstate(dev, 0, "MPU ON + CORE ON");
(&dev->states[0])->enter = omap3_enter_idle;
dev->safe_state = &dev->states[0];
cx->valid = 1;
cx->mpu_state = PWRDM_POWER_ON;
cx->core_state = PWRDM_POWER_ON;
cx = _fill_cstate(dev, 1, "MPU ON + CORE ON");
cx->mpu_state = PWRDM_POWER_ON;
cx->core_state = PWRDM_POWER_ON;
cx = _fill_cstate(dev, 2, "MPU RET + CORE ON");
cx->mpu_state = PWRDM_POWER_RET;
cx->core_state = PWRDM_POWER_ON;
cx = _fill_cstate(dev, 3, "MPU OFF + CORE ON");
cx->mpu_state = PWRDM_POWER_OFF;
cx->core_state = PWRDM_POWER_ON;
cx = _fill_cstate(dev, 4, "MPU RET + CORE RET");
cx->mpu_state = PWRDM_POWER_RET;
cx->core_state = PWRDM_POWER_RET;
cx = _fill_cstate(dev, 5, "MPU OFF + CORE RET");
cx->mpu_state = PWRDM_POWER_OFF;
cx->core_state = PWRDM_POWER_RET;
cx = _fill_cstate(dev, 6, "MPU OFF + CORE OFF");
if (IS_PM34XX_ERRATUM(PM_SDRC_WAKEUP_ERRATUM_i583)) {
cx->valid = 0;
pr_warn("%s: core off state C7 disabled due to i583\n",
__func__);
}
cx->mpu_state = PWRDM_POWER_OFF;
cx->core_state = PWRDM_POWER_OFF;
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
