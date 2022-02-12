static void __init vf610_init_machine(void)\r\n{\r\nmxc_arch_reset_init_dt();\r\nof_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);\r\n}
