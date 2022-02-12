static int idle_finisher(unsigned long flags)
{
exynos_enter_aftr();
cpu_do_idle();
return 1;
}
static int exynos_enter_core0_aftr(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
cpu_pm_enter();
cpu_suspend(0, idle_finisher);
cpu_pm_exit();
return index;
}
static int exynos_enter_lowpower(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
int new_index = index;
if (num_online_cpus() > 1 || dev->cpu != 0)
new_index = drv->safe_state_index;
if (new_index == 0)
return arm_cpuidle_simple_enter(dev, drv, new_index);
else
return exynos_enter_core0_aftr(dev, drv, new_index);
}
static int exynos_cpuidle_probe(struct platform_device *pdev)
{
int ret;
exynos_enter_aftr = (void *)(pdev->dev.platform_data);
ret = cpuidle_register(&exynos_idle_driver, NULL);
if (ret) {
dev_err(&pdev->dev, "failed to register cpuidle driver\n");
return ret;
}
return 0;
}
