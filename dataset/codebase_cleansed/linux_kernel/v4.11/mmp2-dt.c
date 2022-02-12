static void __init mmp_init_time(void)\r\n{\r\n#ifdef CONFIG_CACHE_TAUROS2\r\ntauros2_init(0);\r\n#endif\r\nmmp_dt_init_timer();\r\nof_clk_init(NULL);\r\n}
