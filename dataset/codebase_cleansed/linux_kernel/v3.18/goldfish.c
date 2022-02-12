static int __init goldfish_init(void)\r\n{\r\nplatform_device_register_simple("goldfish_pdev_bus", -1,\r\ngoldfish_pdev_bus_resources, 2);\r\nreturn 0;\r\n}
