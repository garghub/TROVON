static void __init marzen_init(void)\r\n{\r\npinctrl_register_mappings(marzen_pinctrl_map,\r\nARRAY_SIZE(marzen_pinctrl_map));\r\nr8a7779_pinmux_init();\r\nr8a7779_add_standard_devices_dt();\r\n}
