static int __init mcf8390_platform_init(void)\r\n{\r\nplatform_device_register_simple("mcf8390", -1, mcf8390_resources,\r\nARRAY_SIZE(mcf8390_resources));\r\nreturn 0;\r\n}
