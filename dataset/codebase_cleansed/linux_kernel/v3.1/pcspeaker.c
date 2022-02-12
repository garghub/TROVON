static __init int add_pcspkr(void)\r\n{\r\nstruct platform_device *pd;\r\npd = platform_device_register_simple("pcspkr", -1, NULL, 0);\r\nreturn IS_ERR(pd) ? PTR_ERR(pd) : 0;\r\n}
