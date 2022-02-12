static int __init init_rc_map_reddo(void)\r\n{\r\nreturn rc_map_register(&reddo_map);\r\n}\r\nstatic void __exit exit_rc_map_reddo(void)\r\n{\r\nrc_map_unregister(&reddo_map);\r\n}
