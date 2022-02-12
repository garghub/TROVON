static void __init dove_init(void)\r\n{\r\npr_info("Dove 88AP510 SoC\n");\r\n#ifdef CONFIG_CACHE_TAUROS2\r\ntauros2_init(0);\r\n#endif\r\nBUG_ON(mvebu_mbus_dt_init(false));\r\ndove_init_pmu();\r\n}
