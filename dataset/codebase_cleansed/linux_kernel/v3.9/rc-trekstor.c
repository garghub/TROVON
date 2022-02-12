static int __init init_rc_map_trekstor(void)\r\n{\r\nreturn rc_map_register(&trekstor_map);\r\n}\r\nstatic void __exit exit_rc_map_trekstor(void)\r\n{\r\nrc_map_unregister(&trekstor_map);\r\n}
