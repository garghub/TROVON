static int default_platform_runtime_idle(struct device *dev)
{
return 0;
}
static int __init sh_pm_runtime_init(void)
{
pm_clk_add_notifier(&platform_bus_type, &platform_bus_notifier);
return 0;
}
static int __init sh_pm_runtime_late_init(void)
{
pm_genpd_poweroff_unused();
return 0;
}
