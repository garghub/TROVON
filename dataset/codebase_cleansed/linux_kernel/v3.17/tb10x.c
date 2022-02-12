static void __init tb10x_platform_init(void)\r\n{\r\nof_clk_init(NULL);\r\nof_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);\r\n}
