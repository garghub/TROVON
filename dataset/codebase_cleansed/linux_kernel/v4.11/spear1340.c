static void __init spear1340_dt_init(void)\r\n{\r\nplatform_device_register_simple("spear-cpufreq", -1, NULL, 0);\r\n}
