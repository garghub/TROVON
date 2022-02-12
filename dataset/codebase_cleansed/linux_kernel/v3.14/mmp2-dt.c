static void __init mmp2_dt_init(void)\r\n{\r\nof_platform_populate(NULL, of_default_bus_match_table,\r\nmmp2_auxdata_lookup, NULL);\r\n}
