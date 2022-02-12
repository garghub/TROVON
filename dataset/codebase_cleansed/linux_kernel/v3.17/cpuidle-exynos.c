static int exynos_enter_lowpower(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
int new_index = index;
if (num_online_cpus() > 1 || dev->cpu != 0)
new_index = drv->safe_state_index;
if (new_index == 0)
return arm_cpuidle_simple_enter(dev, drv, new_index);
exynos_enter_aftr();
return new_index;
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
