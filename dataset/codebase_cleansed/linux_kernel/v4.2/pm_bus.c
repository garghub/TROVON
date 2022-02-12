static int __init omap1_pm_runtime_init(void)
{
if (!cpu_class_is_omap1())
return -ENODEV;
pm_clk_add_notifier(&platform_bus_type, &platform_bus_notifier);
return 0;
}
