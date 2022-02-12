static int __init init_rc_map_manli(void)\r\n{\r\nreturn rc_map_register(&manli_map);\r\n}\r\nstatic void __exit exit_rc_map_manli(void)\r\n{\r\nrc_map_unregister(&manli_map);\r\n}
