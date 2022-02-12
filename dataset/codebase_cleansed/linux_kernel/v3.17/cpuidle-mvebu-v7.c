static int mvebu_v7_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
int ret;
bool deepidle = false;
cpu_pm_enter();
if (drv->states[index].flags & MVEBU_V7_FLAG_DEEP_IDLE)
deepidle = true;
ret = mvebu_v7_cpu_suspend(deepidle);
if (ret)
return ret;
cpu_pm_exit();
return index;
}
static int mvebu_v7_cpuidle_probe(struct platform_device *pdev)
{
mvebu_v7_cpu_suspend = pdev->dev.platform_data;
if (!strcmp(pdev->dev.driver->name, "cpuidle-armada-xp"))
return cpuidle_register(&armadaxp_idle_driver, NULL);
else if (!strcmp(pdev->dev.driver->name, "cpuidle-armada-370"))
return cpuidle_register(&armada370_idle_driver, NULL);
else if (!strcmp(pdev->dev.driver->name, "cpuidle-armada-38x"))
return cpuidle_register(&armada38x_idle_driver, NULL);
else
return -EINVAL;
}
