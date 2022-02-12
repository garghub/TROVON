void __init am33xx_clockdomains_init(void)\r\n{\r\nclkdm_register_platform_funcs(&am33xx_clkdm_operations);\r\nclkdm_register_clkdms(clockdomains_am33xx);\r\nclkdm_complete_init();\r\n}
