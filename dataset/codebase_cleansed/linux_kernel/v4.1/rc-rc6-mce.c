static int __init init_rc_map_rc6_mce(void)\r\n{\r\nreturn rc_map_register(&rc6_mce_map);\r\n}\r\nstatic void __exit exit_rc_map_rc6_mce(void)\r\n{\r\nrc_map_unregister(&rc6_mce_map);\r\n}
