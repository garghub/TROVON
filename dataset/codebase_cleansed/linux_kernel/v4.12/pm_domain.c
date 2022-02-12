int __init keystone_pm_runtime_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, of_keystone_table);
if (!np)
return 0;
pm_clk_add_notifier(&platform_bus_type, &platform_domain_notifier);
return 0;
}
