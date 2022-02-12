void __init am33xx_powerdomains_init(void)\r\n{\r\npwrdm_register_platform_funcs(&am33xx_pwrdm_operations);\r\npwrdm_register_pwrdms(powerdomains_am33xx);\r\npwrdm_complete_init();\r\n}
