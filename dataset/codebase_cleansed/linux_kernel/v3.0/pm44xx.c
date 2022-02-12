static int omap4_pm_suspend(void)
{
do_wfi();
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
static int __init pwrdms_setup(struct powerdomain *pwrdm, void *unused)
{
struct power_state *pwrst;
if (!pwrdm->pwrsts)
return 0;
pwrst = kmalloc(sizeof(struct power_state), GFP_ATOMIC);
if (!pwrst)
return -ENOMEM;
pwrst->pwrdm = pwrdm;
pwrst->next_state = PWRDM_POWER_ON;
list_add(&pwrst->node, &pwrst_list);
return pwrdm_set_next_pwrst(pwrst->pwrdm, pwrst->next_state);
}
static int __init omap4_pm_init(void)
{
int ret;
if (!cpu_is_omap44xx())
return -ENODEV;
pr_err("Power Management for TI OMAP4.\n");
ret = pwrdm_for_each(pwrdms_setup, NULL);
if (ret) {
pr_err("Failed to setup powerdomains\n");
goto err2;
}
#ifdef CONFIG_SUSPEND
suspend_set_ops(&omap_pm_ops);
#endif
err2:
return ret;
}
