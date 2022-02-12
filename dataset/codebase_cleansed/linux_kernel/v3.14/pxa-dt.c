static void __init pxa3xx_dt_init(void)\r\n{\r\nof_platform_populate(NULL, of_default_bus_match_table,\r\npxa3xx_auxdata_lookup, NULL);\r\n}
