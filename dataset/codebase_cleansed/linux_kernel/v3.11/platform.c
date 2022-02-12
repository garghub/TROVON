static int __init platform_devices_setup(void)\r\n{\r\nreturn platform_add_devices(devices, ARRAY_SIZE(devices));\r\n}
