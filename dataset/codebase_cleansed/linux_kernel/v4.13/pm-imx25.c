static int imx25_suspend_enter(suspend_state_t state)
{
if (!IS_ENABLED(CONFIG_PM))
return 0;
switch (state) {
case PM_SUSPEND_MEM:
cpu_do_idle();
break;
default:
return -EINVAL;
}
return 0;
}
void __init imx25_pm_init(void)
{
suspend_set_ops(&imx25_suspend_ops);
}
