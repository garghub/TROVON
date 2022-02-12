static void __init spear1340_dt_init(void)\r\n{\r\nof_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);\r\nplatform_device_register_simple("spear-cpufreq", -1, NULL, 0);\r\n}
