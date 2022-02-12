static int __init init_rc_map_tivo(void)\r\n{\r\nreturn rc_map_register(&tivo_map);\r\n}\r\nstatic void __exit exit_rc_map_tivo(void)\r\n{\r\nrc_map_unregister(&tivo_map);\r\n}
