static int imx6q_suspend_finish(unsigned long val)
{
cpu_do_idle();
return 0;
}
static int imx6q_pm_enter(suspend_state_t state)
{
switch (state) {
case PM_SUSPEND_MEM:
imx6q_set_lpm(STOP_POWER_OFF);
imx_gpc_pre_suspend();
imx_set_cpu_jump(0, v7_cpu_resume);
cpu_suspend(0, imx6q_suspend_finish);
imx_smp_prepare();
imx_gpc_post_resume();
imx6q_set_lpm(WAIT_CLOCKED);
break;
default:
return -EINVAL;
}
return 0;
}
void __init imx6q_pm_init(void)
{
#ifdef CONFIG_CACHE_L2X0
phys_l2x0_saved_regs = __pa(&l2x0_saved_regs);
#endif
suspend_set_ops(&imx6q_pm_ops);
}
