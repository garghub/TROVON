static int imx6sx_idle_finish(unsigned long val)
{
cpu_do_idle();
return 0;
}
static int imx6sx_enter_wait(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
imx6_set_lpm(WAIT_UNCLOCKED);
switch (index) {
case 1:
cpu_do_idle();
break;
case 2:
imx6_enable_rbc(true);
imx_gpc_set_arm_power_in_lpm(true);
imx_set_cpu_jump(0, v7_cpu_resume);
cpu_pm_enter();
cpu_cluster_pm_enter();
cpu_suspend(0, imx6sx_idle_finish);
cpu_cluster_pm_exit();
cpu_pm_exit();
imx_gpc_set_arm_power_in_lpm(false);
imx6_enable_rbc(false);
break;
default:
break;
}
imx6_set_lpm(WAIT_CLOCKED);
return index;
}
int __init imx6sx_cpuidle_init(void)
{
imx6_enable_rbc(false);
imx_gpc_set_arm_power_up_timing(2, 1);
imx_gpc_set_arm_power_down_timing(1, 1);
return cpuidle_register(&imx6sx_cpuidle_driver, NULL);
}
