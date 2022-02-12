static int calxeda_idle_finish(unsigned long val)
{
return psci_ops.cpu_suspend(CALXEDA_IDLE_PARAM, __pa(cpu_resume));
}
static int calxeda_pwrdown_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
cpu_pm_enter();
cpu_suspend(0, calxeda_idle_finish);
cpu_pm_exit();
return index;
}
static int calxeda_cpuidle_probe(struct platform_device *pdev)
{
return cpuidle_register(&calxeda_idle_driver, NULL);
}
