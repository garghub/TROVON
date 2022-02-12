static int imx5_cpuidle_enter(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
arm_pm_idle();
return index;
}
int __init imx5_cpuidle_init(void)
{
return cpuidle_register(&imx5_cpuidle_driver, NULL);
}
