static int __init plat_pinmux_setup(void)\r\n{\r\nreturn register_pinmux(&sh7785_pinmux_info);\r\n}
