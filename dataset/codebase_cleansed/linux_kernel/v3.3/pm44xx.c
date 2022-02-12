static int omap4_pm_suspend(void)
{
struct power_state *pwrst;
int state, ret = 0;
u32 cpu_id = smp_processor_id();
list_for_each_entry(pwrst, &pwrst_list, node) {
pwrst->saved_state = pwrdm_read_next_pwrst(pwrst->pwrdm);
pwrst->saved_logic_state = pwrdm_read_logic_retst(pwrst->pwrdm);
}
list_for_each_entry(pwrst, &pwrst_list, node) {
omap_set_pwrdm_state(pwrst->pwrdm, pwrst->next_state);
pwrdm_set_logic_retst(pwrst->pwrdm, PWRDM_POWER_OFF);
}
omap4_enter_lowpower(cpu_id, PWRDM_POWER_OFF);
list_for_each_entry(pwrst, &pwrst_list, node) {
state = pwrdm_read_prev_pwrst(pwrst->pwrdm);
if (state > pwrst->next_state) {
pr_info("Powerdomain (%s) didn't enter "
"target state %d\n",
pwrst->pwrdm->name, pwrst->next_state);
ret = -1;
}
omap_set_pwrdm_state(pwrst->pwrdm, pwrst->saved_state);
pwrdm_set_logic_retst(pwrst->pwrdm, pwrst->saved_logic_state);
}
if (ret)
pr_crit("Could not enter target state in pm_suspend\n");
else
pr_info("Successfully put all powerdomains to target state\n");
return 0;
}
static int omap4_pm_enter(suspend_state_t suspend_state)
{
int ret = 0;
switch (suspend_state) {
case PM_SUSPEND_STANDBY:
case PM_SUSPEND_MEM:
ret = omap4_pm_suspend();
break;
default:
ret = -EINVAL;
}
return ret;
}
static int omap4_pm_begin(suspend_state_t state)
{
disable_hlt();
return 0;
}
static void omap4_pm_end(void)
{
enable_hlt();
return;
}
static int __init clkdms_setup(struct clockdomain *clkdm, void *unused)
{
if (clkdm->flags & CLKDM_CAN_ENABLE_AUTO)
clkdm_allow_idle(clkdm);
else if (clkdm->flags & CLKDM_CAN_FORCE_SLEEP &&
atomic_read(&clkdm->usecount) == 0)
clkdm_sleep(clkdm);
return 0;
}
static int __init pwrdms_setup(struct powerdomain *pwrdm, void *unused)
{
struct power_state *pwrst;
if (!pwrdm->pwrsts)
return 0;
if (!strncmp(pwrdm->name, "cpu", 3))
return 0;
if (strcmp(pwrdm->name, "mpu_pwrdm"))
return 0;
pwrst = kmalloc(sizeof(struct power_state), GFP_ATOMIC);
if (!pwrst)
return -ENOMEM;
pwrst->pwrdm = pwrdm;
pwrst->next_state = PWRDM_POWER_RET;
list_add(&pwrst->node, &pwrst_list);
return omap_set_pwrdm_state(pwrst->pwrdm, pwrst->next_state);
}
static void omap_default_idle(void)
{
local_irq_disable();
local_fiq_disable();
omap_do_wfi();
local_fiq_enable();
local_irq_enable();
}
static int __init omap4_pm_init(void)
{
int ret;
struct clockdomain *emif_clkdm, *mpuss_clkdm, *l3_1_clkdm;
struct clockdomain *ducati_clkdm, *l3_2_clkdm, *l4_per_clkdm;
if (!cpu_is_omap44xx())
return -ENODEV;
if (omap_rev() == OMAP4430_REV_ES1_0) {
WARN(1, "Power Management not supported on OMAP4430 ES1.0\n");
return -ENODEV;
}
pr_err("Power Management for TI OMAP4.\n");
ret = pwrdm_for_each(pwrdms_setup, NULL);
if (ret) {
pr_err("Failed to setup powerdomains\n");
goto err2;
}
mpuss_clkdm = clkdm_lookup("mpuss_clkdm");
emif_clkdm = clkdm_lookup("l3_emif_clkdm");
l3_1_clkdm = clkdm_lookup("l3_1_clkdm");
l3_2_clkdm = clkdm_lookup("l3_2_clkdm");
l4_per_clkdm = clkdm_lookup("l4_per_clkdm");
ducati_clkdm = clkdm_lookup("ducati_clkdm");
if ((!mpuss_clkdm) || (!emif_clkdm) || (!l3_1_clkdm) ||
(!l3_2_clkdm) || (!ducati_clkdm) || (!l4_per_clkdm))
goto err2;
ret = clkdm_add_wkdep(mpuss_clkdm, emif_clkdm);
ret |= clkdm_add_wkdep(mpuss_clkdm, l3_1_clkdm);
ret |= clkdm_add_wkdep(mpuss_clkdm, l3_2_clkdm);
ret |= clkdm_add_wkdep(mpuss_clkdm, l4_per_clkdm);
ret |= clkdm_add_wkdep(ducati_clkdm, l3_1_clkdm);
ret |= clkdm_add_wkdep(ducati_clkdm, l3_2_clkdm);
if (ret) {
pr_err("Failed to add MPUSS -> L3/EMIF/L4PER, DUCATI -> L3 "
"wakeup dependency\n");
goto err2;
}
ret = omap4_mpuss_init();
if (ret) {
pr_err("Failed to initialise OMAP4 MPUSS\n");
goto err2;
}
(void) clkdm_for_each(clkdms_setup, NULL);
#ifdef CONFIG_SUSPEND
suspend_set_ops(&omap_pm_ops);
#endif
pm_idle = omap_default_idle;
omap4_idle_init();
err2:
return ret;
}
