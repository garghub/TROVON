static int __init led_init(void)\r\n{\r\nplatform_device_register(&pled_device);\r\nreturn platform_device_register(&fled_device);\r\n}
