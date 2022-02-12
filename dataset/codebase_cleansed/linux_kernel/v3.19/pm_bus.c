static int omap1_pm_runtime_suspend(struct device *dev)
{
int ret;
dev_dbg(dev, "%s\n", __func__);
ret = pm_generic_runtime_suspend(dev);
if (ret)
return ret;
ret = pm_clk_suspend(dev);
if (ret) {
pm_generic_runtime_resume(dev);
return ret;
}
return 0;
}
static int omap1_pm_runtime_resume(struct device *dev)
{
dev_dbg(dev, "%s\n", __func__);
pm_clk_resume(dev);
return pm_generic_runtime_resume(dev);
}
static int __init omap1_pm_runtime_init(void)
{
if (!cpu_class_is_omap1())
return -ENODEV;
pm_clk_add_notifier(&platform_bus_type, &platform_bus_notifier);
return 0;
}
