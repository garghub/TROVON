static int __init sead3_mtd_init(void)\r\n{\r\nplatform_device_register(&sead3_flash);\r\nreturn 0;\r\n}
