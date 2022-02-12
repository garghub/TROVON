void __init omap54xx_powerdomains_init(void)\r\n{\r\npwrdm_register_platform_funcs(&omap4_pwrdm_operations);\r\npwrdm_register_pwrdms(powerdomains_omap54xx);\r\npwrdm_complete_init();\r\n}
