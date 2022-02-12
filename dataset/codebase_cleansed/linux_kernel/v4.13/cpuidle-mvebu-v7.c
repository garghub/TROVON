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
cpu_pm_exit();
if (ret)
return ret;
return index;
}
static int mvebu_v7_cpuidle_probe(struct platform_device *pdev)
{
const struct platform_device_id *id = pdev->id_entry;
if (!id)
return -EINVAL;
mvebu_v7_cpu_suspend = pdev->dev.platform_data;
return cpuidle_register((struct cpuidle_driver *)id->driver_data, NULL);
}
