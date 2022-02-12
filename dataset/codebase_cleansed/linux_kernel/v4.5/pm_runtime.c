static int __init sh_pm_runtime_init(void)
{
if (IS_ENABLED(CONFIG_OF) && IS_ENABLED(CONFIG_ARCH_SHMOBILE)) {
if (!of_find_compatible_node(NULL, NULL,
"renesas,cpg-mstp-clocks"))
return 0;
if (IS_ENABLED(CONFIG_PM_GENERIC_DOMAINS_OF) &&
of_find_node_with_property(NULL, "#power-domain-cells"))
return 0;
}
pm_clk_add_notifier(&platform_bus_type, &platform_bus_notifier);
return 0;
}
