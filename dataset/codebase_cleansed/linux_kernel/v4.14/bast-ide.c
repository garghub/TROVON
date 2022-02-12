static __init int bast_ide_init(void)\r\n{\r\nif (machine_is_bast() || machine_is_vr1000())\r\nreturn platform_add_devices(bast_ide_devices,\r\nARRAY_SIZE(bast_ide_devices));\r\nreturn 0;\r\n}
