static int __init mca_init(void)\r\n{\r\nif (!MCA_bus)\r\nreturn -ENODEV;\r\nreturn platform_device_register(&mca_device);\r\n}
