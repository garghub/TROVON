void __init dra7xx_clockdomains_init(void)\r\n{\r\nclkdm_register_platform_funcs(&omap4_clkdm_operations);\r\nclkdm_register_clkdms(clockdomains_dra7xx);\r\nclkdm_complete_init();\r\n}
