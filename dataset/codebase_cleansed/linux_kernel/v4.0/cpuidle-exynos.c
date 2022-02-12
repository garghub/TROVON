static int exynos_enter_coupled_lowpower(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
int ret;
exynos_cpuidle_pdata->pre_enter_aftr();
cpuidle_coupled_parallel_barrier(dev, &exynos_idle_barrier);
ret = dev->cpu ? exynos_cpuidle_pdata->cpu1_powerdown()
: exynos_cpuidle_pdata->cpu0_enter_aftr();
if (ret)
index = ret;
cpuidle_coupled_parallel_barrier(dev, &exynos_idle_barrier);
exynos_cpuidle_pdata->post_enter_aftr();
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
exynos_enter_aftr();
return new_index;
}
static int exynos_cpuidle_probe(struct platform_device *pdev)
{
int ret;
if (of_machine_is_compatible("samsung,exynos4210")) {
exynos_cpuidle_pdata = pdev->dev.platform_data;
ret = cpuidle_register(&exynos_coupled_idle_driver,
cpu_possible_mask);
} else {
exynos_enter_aftr = (void *)(pdev->dev.platform_data);
ret = cpuidle_register(&exynos_idle_driver, NULL);
}
if (ret) {
dev_err(&pdev->dev, "failed to register cpuidle driver\n");
return ret;
}
return 0;
}
