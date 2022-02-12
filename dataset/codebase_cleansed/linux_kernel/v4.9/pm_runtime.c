static int __init sh_pm_runtime_init(void)\r\n{\r\npm_clk_add_notifier(&platform_bus_type, &platform_bus_notifier);\r\nreturn 0;\r\n}
