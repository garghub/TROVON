static int default_platform_runtime_idle(struct device *dev)
{
return pm_runtime_suspend(dev);
}
static int __init sh_pm_runtime_init(void)
{
pm_runtime_clk_add_notifier(&platform_bus_type, &platform_bus_notifier);
return 0;
}
