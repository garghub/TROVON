static int __init omap1_pm_runtime_init(void)\r\n{\r\nif (!cpu_class_is_omap1())\r\nreturn -ENODEV;\r\npm_clk_add_notifier(&platform_bus_type, &platform_bus_notifier);\r\nreturn 0;\r\n}
