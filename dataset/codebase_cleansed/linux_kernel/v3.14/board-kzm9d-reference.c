static void __init kzm9d_add_standard_devices(void)\r\n{\r\nif (!IS_ENABLED(CONFIG_COMMON_CLK))\r\nemev2_clock_init();\r\nof_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);\r\n}
