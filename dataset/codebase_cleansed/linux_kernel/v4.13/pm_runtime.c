static int __init sh_pm_runtime_init(void)
{
pm_clk_add_notifier(&platform_bus_type, &platform_bus_notifier);
return 0;
}
