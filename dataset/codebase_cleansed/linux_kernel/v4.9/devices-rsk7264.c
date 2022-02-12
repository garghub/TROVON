static int __init rsk7264_devices_setup(void)\r\n{\r\nreturn platform_add_devices(rsk7264_devices,\r\nARRAY_SIZE(rsk7264_devices));\r\n}
