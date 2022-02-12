static int __init hid_init(void)\r\n{\r\nreturn hid_register_driver(&hid_generic);\r\n}\r\nstatic void __exit hid_exit(void)\r\n{\r\nhid_unregister_driver(&hid_generic);\r\n}
