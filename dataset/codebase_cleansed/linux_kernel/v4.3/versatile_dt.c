static void __init versatile_dt_init(void)\r\n{\r\nof_platform_populate(NULL, of_default_bus_match_table,\r\nversatile_auxdata_lookup, NULL);\r\n}
