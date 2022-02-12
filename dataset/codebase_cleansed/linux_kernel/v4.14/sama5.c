static void __init sama5_dt_device_init(void)\r\n{\r\nof_platform_default_populate(NULL, NULL, NULL);\r\nsama5_pm_init();\r\n}
