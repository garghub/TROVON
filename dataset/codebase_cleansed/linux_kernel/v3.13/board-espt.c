static int __init espt_devices_setup(void)\r\n{\r\nreturn platform_add_devices(espt_devices,\r\nARRAY_SIZE(espt_devices));\r\n}
