void __init am43xx_clockdomains_init(void)\r\n{\r\nclkdm_register_platform_funcs(&am43xx_clkdm_operations);\r\nclkdm_register_clkdms(clockdomains_am43xx);\r\nclkdm_complete_init();\r\n}
