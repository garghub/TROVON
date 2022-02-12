static int __init malta_add_devices(void)\r\n{\r\nint err;\r\nerr = platform_add_devices(malta_devices, ARRAY_SIZE(malta_devices));\r\nif (err)\r\nreturn err;\r\nreturn 0;\r\n}
