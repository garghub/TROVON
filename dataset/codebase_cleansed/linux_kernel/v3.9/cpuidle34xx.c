static int __omap3_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
struct omap3_idle_statedata *cx = &omap3_idle_data[index];
local_fiq_disable();
if (omap_irq_pending() || need_resched())
goto return_sleep_time;
if (cx->flags & OMAP_CPUIDLE_CX_NO_CLKDM_IDLE) {
clkdm_deny_idle(mpu_pd->pwrdm_clkdms[0]);
} else {
pwrdm_set_next_pwrst(mpu_pd, cx->mpu_state);
pwrdm_set_next_pwrst(core_pd, cx->core_state);
}
if (cx->mpu_state == PWRDM_POWER_OFF)
cpu_pm_enter();
omap_sram_idle();
if (cx->mpu_state == PWRDM_POWER_OFF &&
pwrdm_read_prev_pwrst(mpu_pd) == PWRDM_POWER_OFF)
cpu_pm_exit();
if (cx->flags & OMAP_CPUIDLE_CX_NO_CLKDM_IDLE)
clkdm_allow_idle(mpu_pd->pwrdm_clkdms[0]);
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
struct cpuidle_driver *drv, int index)
{
struct omap3_idle_statedata *cx = &omap3_idle_data[index];
u32 mpu_deepest_state = PWRDM_POWER_RET;
u32 core_deepest_state = PWRDM_POWER_RET;
int idx;
int next_index = 0;
if (enable_off_mode) {
mpu_deepest_state = PWRDM_POWER_OFF;
if (!IS_PM34XX_ERRATUM(PM_SDRC_WAKEUP_ERRATUM_i583))
core_deepest_state = PWRDM_POWER_OFF;
}
if ((cx->mpu_state >= mpu_deepest_state) &&
(cx->core_state >= core_deepest_state))
return index;
for (idx = index - 1; idx >= 0; idx--) {
cx = &omap3_idle_data[idx];
if ((cx->mpu_state >= mpu_deepest_state) &&
(cx->core_state >= core_deepest_state)) {
next_index = idx;
break;
}
}
return next_index;
}
static int omap3_enter_idle_bm(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
int new_state_idx, ret;
u8 per_next_state, per_saved_state;
struct omap3_idle_statedata *cx;
if (pwrdm_read_pwrst(cam_pd) == PWRDM_POWER_ON)
new_state_idx = drv->safe_state_index;
else
new_state_idx = next_valid_state(dev, drv, index);
cx = &omap3_idle_data[new_state_idx];
per_next_state = pwrdm_read_next_pwrst(per_pd);
per_saved_state = per_next_state;
if (per_next_state < cx->per_min_state) {
per_next_state = cx->per_min_state;
pwrdm_set_next_pwrst(per_pd, per_next_state);
}
ret = omap3_enter_idle(dev, drv, new_state_idx);
if (per_next_state != per_saved_state)
pwrdm_set_next_pwrst(per_pd, per_saved_state);
return ret;
}
int __init omap3_idle_init(void)
{
struct cpuidle_device *dev;
mpu_pd = pwrdm_lookup("mpu_pwrdm");
core_pd = pwrdm_lookup("core_pwrdm");
per_pd = pwrdm_lookup("per_pwrdm");
cam_pd = pwrdm_lookup("cam_pwrdm");
if (!mpu_pd || !core_pd || !per_pd || !cam_pd)
return -ENODEV;
cpuidle_register_driver(&omap3_idle_driver);
dev = &per_cpu(omap3_idle_dev, smp_processor_id());
dev->cpu = 0;
if (cpuidle_register_device(dev)) {
printk(KERN_ERR "%s: CPUidle register device failed\n",
__func__);
return -EIO;
}
return 0;
}
