void __init plat_time_init(void)\r\n{\r\nralink_of_remap();\r\nof_clk_init(NULL);\r\ntimer_probe();\r\n}
