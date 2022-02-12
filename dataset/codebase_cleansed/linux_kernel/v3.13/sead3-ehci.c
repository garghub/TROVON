static int __init ehci_init(void)\r\n{\r\nreturn platform_device_register(&ehci_device);\r\n}
