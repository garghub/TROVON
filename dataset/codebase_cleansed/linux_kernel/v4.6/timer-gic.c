void __init plat_time_init(void)\r\n{\r\nralink_of_remap();\r\nof_clk_init(NULL);\r\nclocksource_probe();\r\n}
