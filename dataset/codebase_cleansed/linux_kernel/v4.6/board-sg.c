static void __init sg_init(void)\r\n{\r\nks8695_add_device_lan();\r\nks8695_add_device_wan();\r\nif (machine_is_sg310())\r\nplatform_device_register(&sg_mtd_device);\r\n}
