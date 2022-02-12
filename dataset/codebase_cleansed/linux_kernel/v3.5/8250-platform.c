static int __init uart8250_init(void)\r\n{\r\nreturn platform_device_register(&uart8250_device);\r\n}
