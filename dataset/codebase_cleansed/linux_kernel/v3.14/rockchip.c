static void __init rockchip_dt_init(void)\r\n{\r\nl2x0_of_init(0, ~0UL);\r\nof_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);\r\n}
