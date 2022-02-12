static int armada_370_xp_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
int ret;
bool deepidle = false;
cpu_pm_enter();
if (drv->states[index].flags & ARMADA_370_XP_FLAG_DEEP_IDLE)
deepidle = true;
ret = armada_370_xp_cpu_suspend(deepidle);
if (ret)
return ret;
cpu_pm_exit();
return index;
}
static int armada_370_xp_cpuidle_probe(struct platform_device *pdev)
{
armada_370_xp_cpu_suspend = (void *)(pdev->dev.platform_data);
return cpuidle_register(&armada_370_xp_idle_driver, NULL);
}
