static void __init berlin_init_late(void)\r\n{\r\nplatform_device_register_simple("cpufreq-dt", -1, NULL, 0);\r\n}
