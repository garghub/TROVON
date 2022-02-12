void __init ltq_soc_setup(void)\r\n{\r\nltq_register_asc(0);\r\nltq_register_asc(1);\r\nltq_register_gpio();\r\nltq_register_wdt();\r\n}
