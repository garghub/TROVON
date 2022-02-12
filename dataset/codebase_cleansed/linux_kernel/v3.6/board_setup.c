void __init board_setup(void)\r\n{\r\nunsigned long configpr;\r\nconfigpr = read_c0_config7();\r\nconfigpr |= (1<<19);\r\nwrite_c0_config7(configpr);\r\n}
