static int __init init_rc_map_lirc(void)\r\n{\r\nreturn rc_map_register(&lirc_map);\r\n}\r\nstatic void __exit exit_rc_map_lirc(void)\r\n{\r\nrc_map_unregister(&lirc_map);\r\n}
