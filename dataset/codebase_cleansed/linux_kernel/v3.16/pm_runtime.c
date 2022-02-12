static int sh_pm_runtime_suspend(struct device *dev)
{
int ret;
ret = pm_generic_runtime_suspend(dev);
if (ret) {
dev_err(dev, "failed to suspend device\n");
return ret;
}
ret = pm_clk_suspend(dev);
if (ret) {
dev_err(dev, "failed to suspend clock\n");
pm_generic_runtime_resume(dev);
return ret;
}
return 0;
}
static int sh_pm_runtime_resume(struct device *dev)
{
int ret;
ret = pm_clk_resume(dev);
if (ret) {
dev_err(dev, "failed to resume clock\n");
return ret;
}
return pm_generic_runtime_resume(dev);
}
static int __init sh_pm_runtime_init(void)
{
if (IS_ENABLED(CONFIG_ARCH_SHMOBILE_MULTI)) {
if (!of_machine_is_compatible("renesas,emev2") &&
!of_machine_is_compatible("renesas,r7s72100") &&
!of_machine_is_compatible("renesas,r8a73a4") &&
!of_machine_is_compatible("renesas,r8a7740") &&
!of_machine_is_compatible("renesas,r8a7778") &&
!of_machine_is_compatible("renesas,r8a7779") &&
!of_machine_is_compatible("renesas,r8a7790") &&
!of_machine_is_compatible("renesas,r8a7791") &&
!of_machine_is_compatible("renesas,r8a7792") &&
!of_machine_is_compatible("renesas,r8a7793") &&
!of_machine_is_compatible("renesas,r8a7794") &&
!of_machine_is_compatible("renesas,sh7372") &&
!of_machine_is_compatible("renesas,sh73a0"))
return 0;
}
default_pm_on = true;
pm_clk_add_notifier(&platform_bus_type, &platform_bus_notifier);
return 0;
}
static int __init sh_pm_runtime_late_init(void)
{
if (default_pm_on)
pm_genpd_poweroff_unused();
return 0;
}
