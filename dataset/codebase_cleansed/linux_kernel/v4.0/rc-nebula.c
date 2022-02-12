static int __init init_rc_map_nebula(void)\r\n{\r\nreturn rc_map_register(&nebula_map);\r\n}\r\nstatic void __exit exit_rc_map_nebula(void)\r\n{\r\nrc_map_unregister(&nebula_map);\r\n}
