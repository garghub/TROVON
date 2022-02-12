static int __init init_rc_map_cinergy(void)\r\n{\r\nreturn rc_map_register(&cinergy_map);\r\n}\r\nstatic void __exit exit_rc_map_cinergy(void)\r\n{\r\nrc_map_unregister(&cinergy_map);\r\n}
