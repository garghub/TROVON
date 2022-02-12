static int __init asb2303_mtd_init(void)\r\n{\r\nplatform_device_register(&asb2303_bootprom);\r\nplatform_device_register(&asb2303_sysflash);\r\nreturn 0;\r\n}
