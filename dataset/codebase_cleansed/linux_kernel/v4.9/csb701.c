static int __init csb701_init(void)\r\n{\r\nif (!machine_is_csb726())\r\nreturn -ENODEV;\r\nreturn platform_add_devices(devices, ARRAY_SIZE(devices));\r\n}
