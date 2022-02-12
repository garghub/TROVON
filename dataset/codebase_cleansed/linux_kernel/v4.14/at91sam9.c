static void __init at91sam9_init(void)\r\n{\r\nof_platform_default_populate(NULL, NULL, NULL);\r\nat91sam9_pm_init();\r\n}
