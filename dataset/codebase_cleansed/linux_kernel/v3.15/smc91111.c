static int __init unit_device_init(void)\r\n{\r\nplatform_device_register(&smc91c111_device);\r\nreturn 0;\r\n}
