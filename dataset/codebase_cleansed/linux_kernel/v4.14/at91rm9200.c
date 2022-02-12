static void __init at91rm9200_dt_device_init(void)\r\n{\r\nof_platform_default_populate(NULL, NULL, NULL);\r\nat91rm9200_pm_init();\r\n}
