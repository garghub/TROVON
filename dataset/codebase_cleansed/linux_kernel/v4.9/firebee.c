static int __init init_firebee(void)\r\n{\r\nplatform_device_register(&firebee_flash);\r\nreturn 0;\r\n}
