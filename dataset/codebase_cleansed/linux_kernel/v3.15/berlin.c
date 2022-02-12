static void __init berlin_init_machine(void)\r\n{\r\nl2x0_of_init(0x70c00000, 0xfeffffff);\r\nof_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);\r\n}
