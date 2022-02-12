static int __init malta_add_devices(void)\r\n{\r\nreturn platform_add_devices(malta_devices, ARRAY_SIZE(malta_devices));\r\n}
